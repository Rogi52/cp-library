#include "../../src/cp-template.hpp"

std::vector<int> maximum_independent_set(const std::vector<std::vector<int>>& g) {
    int N = g.size();
    assert(N <= 64);
    std::vector<u64> h(N);
    for(int i : rep(N)) for(int j : rep(N)) if(g[i][j]) h[i] |= u64(1) << j;

    std::function<u64(u64)> dfs = [&](u64 S) -> u64 {
        u64 now = 0;
        int v, d, ok;
        do {
            v = -1, d = -1, ok = 0;
            for(int i : rep(N)) if(S & (u64(1) << i)) {
                int c = popcnt(h[i] & S);
                if(chmax(d, c)) v = i;
                if(c <= 1) {
                    S &= ~(h[i] | (u64(1) << i));
                    now |= u64(1) << i;
                    ok = 1;
                }
            }
        } while(ok);
        if(S == 0) return now;
        S &= ~(u64(1) << v);
        u64 x = now | dfs(S);
        u64 y = now | dfs(S & ~h[v]) | (u64(1) << v);
        return (popcnt(x) > popcnt(y) ? x : y);
    };

    u64 S = 0;
    for(int i : rep(N)) S |= u64(1) << i;
    S = dfs(S);
    std::vector<int> ans;
    for(int i : rep(N)) if(S & (u64(1) << i)) ans.push_back(i);
    return ans;
}