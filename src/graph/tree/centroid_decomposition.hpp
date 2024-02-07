struct c_tree {
    using size_type = int;
    size_type n;
    std::vector<std::vector<size_type>> g;
    std::vector<size_type> size;
    std::vector<bool> active;
    c_tree(const size_type n) : n(n), g(n), size(n), active(n, true) {}

    void add_edge(const size_type u, const size_type v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    size_type centroid(const size_type root) {
        auto get_size = [&](auto self, const size_type v, const size_type p) -> void {
            size[v] = 1;
            for(const size_type to : g[v]) {
                if(to != p and active[to]) {
                    self(self, to, v);
                    size[v] += size[to];
                }
            }
        }; get_size(get_size, root, -1);

        const size_type m = size[root] / 2;
        auto get_centroid = [&](auto self, const size_type v, const size_type p) -> size_type {
            for(const size_type to : g[v])
                if(to != p and active[to] and size[to] > m) return self(self, to, v);
            return v;
        };
        return get_centroid(get_centroid, root, -1);
    }

    // calc : (int, int, vector<bool>&) -> void
    template < class function > void decomposition(const function& calc) {
        auto rec = [&](auto self, const size_type v, const size_type cp) -> void {
            const size_type c = centroid(v);
            calc(c, cp, active);
            active[c] = false;
            for(const size_type to : g[c])
                if(active[to]) self(self, to, c);
            active[c] = true;
        }; rec(rec, 0, -1);
    }
};
