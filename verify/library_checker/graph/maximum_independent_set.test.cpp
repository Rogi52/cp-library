#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/maximum_independent_set.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in(), M = in();
    std::vector g(N, std::vector(N, 0));
    for(int i : rep(M)) {
        int u = in(), v = in();
        g[u][v] = g[v][u] = 1;
    }
    
    std::vector<int> ans = maximum_independent_set(g);
    print(ans.size());
    print(ans);
}
