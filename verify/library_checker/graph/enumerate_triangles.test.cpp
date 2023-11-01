#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/triangle.hpp"
#include "../../../src/number/modint.hpp"

int main(){
    int N = in(), M = in();
    using mint = mint998244353;
    std::vector<mint> x = in(N);
    std::vector<std::vector<int>> g(N);
    for(int i : rep(M)) {
        int u = in(), v = in();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    mint ans = 0;
    for_each_triangle(g, [&](int a, int b, int c) {
        ans += x[a] * x[b] * x[c];
    });
    print(ans);
}
