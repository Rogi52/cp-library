struct scc_graph {
    using size_type = int;
    size_type n;
    std::vector<std::vector<size_type>> g;

    size_type group_num;
    std::vector<size_type> ids;
    std::vector<std::vector<size_type>> scc;
    std::vector<std::vector<size_type>> dag;

    scc_graph(const size_type n) : n(n), g(n), group_num(0), ids(n) {}

    void add_edge(const size_type from, const size_type to) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        g[from].push_back(to);
    }

    void build() {
        int now_ord = 0;
        std::vector<size_type> visited, low(n), ord(n, -1);
        visited.reserve(n);
        auto dfs = [&](auto self, size_type v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for(size_type to : g[v]) {
                if(ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if(low[v] == ord[v]) {
                while(true) {
                    size_type u = visited.back(); visited.pop_back();
                    ord[u] = n;
                    ids[u] = group_num;
                    if(u == v) break;
                }
                group_num++;
            }
        };
        for(size_type i = 0; i < n; i++) if(ord[i] == -1) dfs(dfs, i);
        for(size_type& x : ids) x = group_num - 1 - x;

        scc.resize(group_num);
        for(size_type i = 0; i < n; i++) scc[ids[i]].push_back(i);

        dag.resize(group_num);
        for(size_type from = 0; from < n; from++) {
            for(size_type to : g[from]) {
                const size_type from_id = ids[from];
                const size_type to_id = ids[to];
                if(from_id != to_id) dag[from_id].push_back(to_id);
            }
        }
    }
};
