#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/graph/tree/tree.hpp"

int main() {
    int N = in(), Q = in();
    tree_graph<int> g(N);
    for(int _ : rep(N - 1)) {
        int a = in(), b = in();
        g.add_edge(a, b);
    }
    
    g.heavy_light_decomposition();

    for(int _ : rep(Q)) {
        int s = in(), t = in(), i = in();
        print(g.jump(s, t, i));
    }
}
