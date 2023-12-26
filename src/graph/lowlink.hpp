struct lowlink {
    using size_t = std::size_t;
    std::vector<std::vector<std::pair<size_t, size_t>>> graph;
    std::vector<size_t> ord, low, articulation;
    std::vector<std::pair<size_t, size_t>> bridge;

    explicit lowlink(const size_t n) : graph(n), ord(n, 0), low(n, 0) {}

    void add_edge(const size_t u, const size_t v, const size_t i) {
        assert(u < graph.size());
        assert(v < graph.size());
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    virtual void build() {
        size_t t = 0;
        std::vector<bool> used(graph.size(), false);
        std::function<void(size_t,size_t)> dfs = [&](size_t v, size_t p) -> void {
            used[v] = true;
            ord[v] = low[v] = t++;

            bool is_articulation = false, parent_checked = false;
            size_t child_cnt = 0;
            for(auto [to, _] : graph[v]) {
                if(to == p and not std::exchange(parent_checked, true)) continue;
                if(not used[to]) {
                    child_cnt++;
                    dfs(to, v);
                    low[v] = std::min(low[v], low[to]);
                    is_articulation |= p != -1 and ord[v] <= low[to];
                    if(ord[v] < low[to]) bridge.push_back(std::minmax({v, to}));
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }

            is_articulation |= p == -1 and child_cnt >= 2;
            if(is_articulation) articulation.push_back(v);
        };
        for(size_t v = 0; v < graph.size(); v++) if(not used[v]) dfs(v, -1);
    }
};

struct two_edge_connected_components : lowlink {
    using lowlink::lowlink;
    using lowlink::graph;
    using lowlink::ord;
    using lowlink::low;
    using lowlink::bridge;

    using size_t = std::size_t;
    std::vector<size_t> id;
    std::vector<std::vector<size_t>> group, tree;

    explicit two_edge_connected_components(const size_t n) : lowlink(n), id(n, -1) {}

    void build() override {
        lowlink::build();

        size_t c = 0;
        function<void(size_t,size_t)> dfs = [&](size_t v, size_t p) -> void {
            id[v] = (p != -1 and low[v] <= ord[p] ? id[p] : c++);
            for(auto [to, _] : graph[v]) if(id[to] == -1) dfs(to, v);
        };
        for(size_t i = 0; i < graph.size(); i++) if(id[i] == -1) dfs(i, -1);

        group.resize(c);
        for(size_t i = 0; i < graph.size(); i++) group[id[i]].push_back(i);

        tree.resize(c);
        for(auto [u, v] : bridge) {
            u = id[u], v = id[v];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
};

struct biconnected_components : lowlink {
    using lowlink::lowlink;
    using lowlink::graph;
    using lowlink::ord;
    using lowlink::low;
    using size_t = std::size_t;
    std::vector<std::vector<std::tuple<size_t, size_t, size_t>>> bc;

    void build() override {
        lowlink::build();
        std::vector<bool> used(graph.size(), false);
        std::vector<std::tuple<size_t, size_t, size_t>> tmp;

        function<void(size_t,size_t)> dfs = [&](size_t v, size_t p) -> void {
            used[v] = true;
            bool parent_checked = false;
            for(auto [to, i] : graph[v]) {
                if(to == p and not exchange(parent_checked, true)) continue;
                if(not used[to] or ord[to] < ord[v]) tmp.emplace_back(v, to, i);
                if(not used[to]) {
                    dfs(to, v);
                    if(ord[v] <= low[to]) {
                        std::vector<std::tuple<size_t, size_t, size_t>> c;
                        while(true) {
                            auto e = tmp.back(); tmp.pop_back();
                            c.emplace_back(e);
                            if(get<2>(e) == i) break;
                        }
                        bc.emplace_back(std::move(c));
                    }
                }
            }
        };

        for(size_t i = 0; i < graph.size(); i++) if(not used[i]) dfs(i, -1);
    }
};

struct block_cut_tree : biconnected_components {
    using biconnected_components::biconnected_components;
    using biconnected_components::graph;
    using biconnected_components::articulation;
    using biconnected_components::bc;

    using size_t = std::size_t;
    std::vector<int> rev;
    std::vector<std::vector<size_t>> group, tree;

    explicit block_cut_tree(const size_t n) : biconnected_components(n), rev(n, -1) {}

    void build() override {
        biconnected_components::build();

        size_t c = bc.size();
        for(size_t v : articulation) rev[v] = c++;
        std::vector<size_t> last(c, -1);
        tree.resize(c);
        for(size_t i = 0; i < bc.size(); i++) {
            for(auto [u, v, _] : bc[i]) {
                for(size_t x : {u, v}) {
                    if(rev[x] != -1 and bc.size() <= rev[x]) {
                        if(std::exchange(last[rev[x]], i) != i) {
                            tree[rev[x]].push_back(i);
                            tree[i].push_back(rev[x]);
                        }
                    } else {
                        rev[x] = i;
                    }
                }
            }
        }
        group.resize(c);
        for(size_t i = 0; i < graph.size(); i++) group[rev[i]].push_back(i);
    }
};
