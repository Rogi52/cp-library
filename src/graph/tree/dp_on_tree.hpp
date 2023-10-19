#include "../../../src/cp-template.hpp"

struct dp_on_tree {
    int n;
    std::vector< std::vector< std::pair<int, int> > > tree;
    dp_on_tree(int n) : n(n), tree(n) {}
    void add_edge(int u, int v, int i) {
        tree[u].push_back({v, i});
        tree[v].push_back({u, i});
    }

    template < class S, class M, class E, class V >
    vector< S > solve(int root, const M& merge, const E& fe, const V& fv, const S unit) {
        vector< S > dp(n);
        function<S(int,int)> dfs = [&](int v, int p) -> S {
            S res = unit;
            for(auto [to, id] : tree[v]) {
                if(to != p) res = merge(res, fe(dfs(to, v), id));
            }
            return dp[v] = fv(res, v);
        }; dfs(root, -1);
        return dp;
    }
};