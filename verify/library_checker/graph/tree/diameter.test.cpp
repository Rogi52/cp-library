#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/graph/tree/tree.hpp"

int main() {
    int N = in();
    tree_graph<ll> g(N);
    for(int i : rep(N - 1)) {
        int a = in(), b = in(), c = in();
        g.add_edge(a, b, c);
    }

    auto [p, diameter] = g.diameter();
    auto [u, v] = p;
    std::vector<int> path = g.path(u, v);

    print(diameter, path.size());
    print(path);
}
