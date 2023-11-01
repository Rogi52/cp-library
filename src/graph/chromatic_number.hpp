#include "../../src/cp-template.hpp"

int chromatic_number(const std::vector<std::vector<int>>& g) {
    int N = g.size();
    std::vector<int> h(N);
    for(int i : rep(N)) for(int j : rep(N)) if(g[i][j]) h[i] |= 1 << j;

    const int mod = 1e9+7;
    std::vector<int> ind(1 << N), s(1 << N);
    for(int i : rep(1 << N)) s[i] = ((N - popcnt(i)) & 1 ? -1 : +1);
    ind[0] = 1;
    for(int i : rep(1, 1 << N)) {
        int ctz = __builtin_ctz(i);
        ind[i] = ind[i - (1 << ctz)] + ind[(i - (1 << ctz)) & ~h[ctz]];
        if(ind[i] >= mod) ind[i] -= mod;
    }
    for(int k : rep(1, N)) {
        i64 sum = 0;
        for(int i : rep(1 << N)) sum += (s[i] = i64(s[i]) * ind[i] % mod);
        if(sum % mod != 0) return k;
    }
    return N;
}