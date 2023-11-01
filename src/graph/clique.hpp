#include "../../src/cp-template.hpp"

template < class F >
void for_each_clique(const std::vector<std::vector<int>>& g, const F& f) {
    int N = g.size();
    std::vector<int> deg(N, 0), S(N, 1);
    for(int i : rep(N)) for(int j : rep(N)) if(i < j and g[i][j]) deg[i]++, deg[j]++;

    for(int _ : rep(N)) {
        int v = -1, min_deg = N;
        for(int i : rep(N)) if(S[i] and chmin(min_deg, deg[i])) v = i;
        std::vector<int> c = {v}, to;
        for(int i : rep(N)) if(S[i] and g[v][i]) to.push_back(i);

        std::function<void(int)> dfs = [&](int i) -> void {
            f(c);
            for(int k : rep(i, int(to.size()))) {
                int ok = 1;
                for(int x : c) if(not g[x][to[k]]) { ok = 0; break; }
                if(ok) {
                    c.push_back(to[k]);
                    dfs(k + 1);
                    c.pop_back();
                }
            }
        }; dfs(0);
        
        S[v] = 0;
        for(int i : to) deg[i]--;
    }
}