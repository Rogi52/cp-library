#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/max_flow.hpp"

int main() {
    int n = in(), m = in();
    mf_graph<int> g(n);
    for(int i : rep(m)) {
        int u = in(), v = in(), c = in();
        g.add_edge(u, v, c);
    }
    print(g.flow(0, n - 1));
}