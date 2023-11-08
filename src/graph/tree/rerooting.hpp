#include "../../../src/cp-template.hpp"
#include "../../../src/graph/tree/tree.hpp"

template < class S, class TREE, class EE, class EV, class VP, class I >
struct dp_on_tree {
    TREE& tree;
    
    std::vector< S > dp, dp_rev, answer;
    std::vector<std::vector< S >> dp_sub;
    EE f_ee;
    EV f_ev;
    VP f_vp;
    I id;
    int root;
    dp_on_tree(TREE& tree, const EE f_ee, const EV f_ev, const VP f_vp, const I id) : tree(tree), f_ee(f_ee), f_ev(f_ev), f_vp(f_vp), id(id) {}
    
    void solve(int root) {
        this->root = root;
        dp.assign(tree.n, id());
        dp_sub.resize(tree.n);
        for(int v : rep(tree.n)) dp_sub[v].resize(tree.g_org[v].size());
        std::function<S(int,int)> dfs = [&](int v, int p) -> S {
            for(int i : rep(tree.g_org[v].size())) {
                auto e = tree.g_org[v][i];
                if(e.to != p) {
                    dp_sub[v][i] = dfs(e.to, v);
                    dp[v] = f_ee(dp[v], f_ev(dp_sub[v][i], e.id));
                }
            }
            return dp[v] = f_vp(dp[v], v);
        }; dfs(root, -1);
    }

    void reroot() {
        tree.heavy_light_decomposition(root);
        auto g = tree.g_org;
        dp_rev.assign(tree.n, id());
        std::function<void(int,int,S)> dfs = [&](int v, int p, S s) -> void {
            for(int i : rep(g[v].size())) {
                auto e = g[v][i];
                if(e.to == p) dp_sub[v][i] = s;
            }
            std::vector< S > R(g[v].size() + 1u);
            R[g[v].size()] = id();
            for(int i : revrep(g[v].size())) {
                auto e = g[v][i];
                R[i] = f_ee(R[i + 1], f_ev(dp_sub[v][i], e.id));
            }
            S L = id();
            for(int i : rep(g[v].size())) {
                auto e = g[v][i];
                if(e.to != p) {
                    dfs(e.to, v, f_vp(f_ee(L, R[i + 1]), v));
                }
                dp_rev[e.to] = f_vp(f_ee(L, R[i + 1]), v);
                L = f_ee(L, f_ev(dp_sub[v][i], e.id));
            }
        }; dfs(root, -1, id());
        
        answer.assign(tree.n, id());
        for(int v : rep(tree.n)) {
            for(int i : rep(g[v].size())) {
                auto e = g[v][i];
                answer[v] = f_ee(answer[v], f_ev(dp_sub[v][i], e.id));
            }
            answer[v] = f_vp(answer[v], v);
        }
    }

    S get(int root, int v) {
        if(root == v) return answer[v];
        if(not tree.in_subtree(root, v)) return dp[v];
        return dp_rev[tree.jump(v, root, 1)];
    }
};