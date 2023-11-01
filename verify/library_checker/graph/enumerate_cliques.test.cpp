#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/clique.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in(), M = in();
    using mint = mint998244353;
    std::vector<mint> x = in(N);
    std::vector g(N, std::vector(N, 0));
    for(int i : rep(M)) {
        int u = in(), v = in();
        g[u][v] = g[v][u] = 1;
    }

    mint ans = 0;
    for_each_clique(g, [&](std::vector<int>& c) {
        mint prod = 1;
        for(int i : c) prod *= x[i];
        ans += prod;
    });
    print(ans);
}
