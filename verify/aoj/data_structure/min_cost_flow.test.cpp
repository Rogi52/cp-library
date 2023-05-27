#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"

#include "../../../src/cp-template.hpp"
#include "../../../src/graph/min_cost_flow.hpp"

int main() {
    int n = in(), m = in(), f = in();
    mcf_graph<int,int> g(n);
    for(int i : rep(m)) {
        int u = in(), v = in(), c = in(), d = in();
        g.add_edge(u, v, c, d);
    }
    auto [flow, cost] = g.flow(0, n - 1, f);
    print(flow == f ? cost : -1);
}