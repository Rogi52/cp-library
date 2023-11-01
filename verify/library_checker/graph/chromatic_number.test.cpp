#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/chromatic_number.hpp"

int main() {
    int N = in(), M = in();
    std::vector g(N, std::vector(N, 0));
    for(int i : rep(M)) {
        int u = in(), v = in();
        g[u][v] = g[v][u] = 1;
    }
    print(chromatic_number(g));
}
