#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/graph/tree/tree.hpp"

int main() {
    int N = in(), Q = in();
    tree_graph<int> g(N);
    for(int i : rep(1, N)) {
        int p = in();
        g.add_edge(p, i);
    }

    g.heavy_light_decomposition(0);

    for(int _ : rep(Q)) {
        int u = in(), v = in();
        print(g.lca(u, v));
    }
}
