#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/graph/tree/tree.hpp"
#include "../../../../src/graph/tree/rerooting.hpp"
#include "../../../../src/number/modint.hpp"

int main() {
    int N = in();
    tree_graph<int> g(N);
    using mint = mint998244353;
    vector<mint> a = in(N), b(N - 1), c(N - 1);
    for(int i : rep(N - 1)) {
        int u = in(), v = in();
        g.add_edge(u, v, i);
        b[i] = in(), c[i] = in();
    }

    using S = pair<mint,mint>;
    auto merge = [&](S x, S y) -> S {
        return {x.first + y.first, x.second + y.second};
    };
    auto fe = [&](S x, int e) -> S {
        return {b[e] * x.first + c[e] * x.second, x.second};
    };
    auto fv = [&](S x, int v) -> S {
        return {x.first + a[v], x.second + 1};
    };
    auto id = [&]() {
        return S{0, 0};
    };

    dp_on_tree< S, tree_graph<int>, decltype(merge), decltype(fe), decltype(fv), decltype(id) > solver(g, merge, fe, fv, id);
    solver.solve(0);
    solver.reroot();
    vector<mint> ans(N);
    for(int i : rep(N)) ans[i] = solver.answer[i].first;
    print(ans);
}
