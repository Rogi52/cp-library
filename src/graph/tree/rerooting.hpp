#include "../../../src/cp-template.hpp"

struct rerooting {
    int N;
    vector<vector<pair<int,int>>> G;
    rerooting(int N) : N(N), G(N) {}
    void add_edge(int u, int v, int i) {
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    template < class S, class M, class E, class V >
    vector< S > solve(const M& merge, const E& fe, const V& fv, const S unit) {
        vector<vector< S >> dp(N);
        for(int i : rep(N)) dp[i].resize(G[i].size());

        function<S(int,int)> dfs1 = [&](int v, int p) -> S {
            S res = unit;
            for(int i : rep(G[v].size())) {
                auto [to, id] = G[v][i];
                if(to != p) {
                    dp[v][i] = dfs1(to, v);
                    res = merge(res, fe(dp[v][i], id));
                }
            }
            return fv(res, v);
        }; dfs1(0, -1);

        function<void(int,int,S)> dfs2 = [&](int v, int p, S dp_par) {
            for(int i : rep(G[v].size())) {
                auto [to, id] = G[v][i];
                if(to == p) {
                    dp[v][i] = dp_par;
                }
            }

            vector< S > R(G[v].size() + 1U);
            R[G[v].size()] = unit;
            for(int i : revrep(G[v].size())) {
                auto [to, id] = G[v][i];
                R[i] = merge(R[i + 1], fe(dp[v][i], id));
            }
            S L = unit;
            for(int i : rep(G[v].size())) {
                auto [to, id] = G[v][i];
                if(to != p) {
                    S val = merge(L, R[i + 1]);
                    dfs2(to, v, fv(val, v));
                }
                L = merge(L, fe(dp[v][i], id));
            }
        }; dfs2(0, -1, unit);

        vector< S > res(N, unit);
        for(int v : rep(N)) {
            for(int i : rep(G[v].size())) {
                auto [to, id] = G[v][i];
                res[v] = merge(res[v], fe(dp[v][i], id));
            }
            res[v] = fv(res[v], v);
        }
        return res;
    }
};