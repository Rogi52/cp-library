template < class edge_type > struct eulerian_trail {};
namespace edge_type {
    struct directed;
    struct undirected;
}

template <> struct eulerian_trail< edge_type::directed >  {
    int n, m;
    vector<vector<pair<int,int>>> g;
    vector<vector<int>> self;
    vector<int> in_deg, out_deg;
    int s_, t_, o_;
    eulerian_trail() = default;
    eulerian_trail(int n) : n(n), m(0), g(n), self(n), in_deg(n, 0), out_deg(n, 0), s_(-1), t_(-1), o_(-1) {}
    
    void add_edge(int u, int v, int i) {
        if(u == v) {
            self[u].push_back(i);
        } else {
            g[u].emplace_back(v, i);
        }
        out_deg[u]++, in_deg[v]++, m++;
    }

    bool valid() {
        bool deg_ok = [&] {
            int s = 0, t = 0, o = 0;
            for(int v = 0; v < n; v++) {
                if(in_deg[v] + 1 == out_deg[v]    ) s++, s_ = v;
                if(in_deg[v]     == out_deg[v] + 1) t++, t_ = v;
                if(in_deg[v]     == out_deg[v]    ) o++;
            }
            return (s == 1 and t == 1 and o == n - 2) or (s == 0 and t == 0 and o == n);
        }();

        bool cc_ok = [&] {
            if(m == 0) return true;
            union_find uf(n);
            for(int u = 0; u < n; u++) for(auto [v, i] : g[u]) uf.unite(u, v);
            vector<int> ec(n, 0);
            for(int u = 0; u < n; u++) ec[uf.root(u)] += g[u].size() + self[u].size();
            int cnt = 0;
            for(int u = 0; u < n; u++) if(uf.root(u) == u and ec[u] >= 1) cnt++, o_ = u;
            return cnt == 1;
        }();

        return deg_ok and cc_ok;
    }

    pair<vector<int>, vector<int>> get() {
        if(m == 0) return {{0}, {}};
        vector<int> vs, es;
        vs.reserve(m + 1);
        es.reserve(m);
        auto dfs = [&](auto sf, int u, int e) -> void {
            while(not g[u].empty()) {
                auto [v, i] = g[u].back(); g[u].pop_back();
                sf(sf, v, i);
            }
            while(not self[u].empty()) {
                es.push_back(self[u].back()); self[u].pop_back();
                vs.push_back(u);
            }
            if(e != -1) es.push_back(e);
            vs.push_back(u);
        }; dfs(dfs, s_ != -1 ? s_ : o_, -1);
        reverse(vs.begin(), vs.end());
        reverse(es.begin(), es.end());
        return {vs, es};
    }
};

template <> struct eulerian_trail< edge_type::undirected >  {
    int n, m;
    vector<vector<pair<int,int>>> g;
    vector<vector<int>> self;
    vector<int> deg;
    int s_, t_, o_;
    eulerian_trail() = default;
    eulerian_trail(int n) : n(n), m(0), g(n), self(n), deg(n, 0), s_(-1), t_(-1), o_(-1) {}
    
    void add_edge(int u, int v, int i) {
        if(u == v) {
            self[u].push_back(i);
        } else {
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
        }
        deg[u]++, deg[v]++, m++;
    }

    bool valid() {
        bool deg_ok = [&] {
            int odd = 0;
            for(int v = 0; v < n; v++) {
                if(deg[v] % 2 == 1) odd++, s_ = v;
            }
            return (odd == 0) or (odd == 2);
        }();

        bool cc_ok = [&] {
            if(m == 0) return true;
            union_find uf(n);
            for(int u = 0; u < n; u++) for(auto [v, i] : g[u]) uf.unite(u, v);
            vector<int> ec(n, 0);
            for(int u = 0; u < n; u++) ec[uf.root(u)] += g[u].size() + self[u].size();
            int cnt = 0;
            for(int u = 0; u < n; u++) if(uf.root(u) == u and ec[u] >= 1) cnt++, o_ = u;
            return cnt == 1;
        }();

        return deg_ok and cc_ok;
    }

    pair<vector<int>, vector<int>> get() {
        if(m == 0) return {{0}, {}};
        vector<int> vs, es;
        vs.reserve(m + 1);
        es.reserve(m);
        vector<int> erased(m, 0);
        auto dfs = [&](auto sf, int u, int e) -> void {
            while(not g[u].empty()) {
                auto [v, i] = g[u].back(); g[u].pop_back();
                if(erased[i]) continue;
                erased[i] = 1;
                sf(sf, v, i);
            }
            while(not self[u].empty()) {
                es.push_back(self[u].back()); self[u].pop_back();
                vs.push_back(u);
            }
            if(e != -1) es.push_back(e);
            vs.push_back(u);
        }; dfs(dfs, s_ != -1 ? s_ : o_, -1);
        return {vs, es};
    }
};
