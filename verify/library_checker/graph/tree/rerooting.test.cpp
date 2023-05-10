#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/graph/tree/rerooting.hpp"
#include "../../../../src/number/modint.hpp"

int main() {
    int N = in();
    rerooting rr(N);
    using mint = mint998244353;
    vector<mint> a = in(N), b(N - 1), c(N - 1);
    for(int i : rep(N - 1)) {
        int u = in(), v = in(); rr.add_edge(u, v, i);
        b[i] = in(), c[i] = in();
    }

    using S = pair<mint,mint>;
    S id = {0, 0};
    auto merge = [&](S x, S y) -> S {
        return {x.first + y.first, x.second + y.second};
    };
    auto fe = [&](S x, int e) -> S {
        return {b[e] * x.first + c[e] * x.second, x.second};
    };
    auto fv = [&](S x, int v) -> S {
        return {x.first + a[v], x.second + 1};
    };

    vector< S > res = rr.solve(merge, fe, fv, id);
    vector<mint> ans(N);
    for(int i : rep(N)) ans[i] = res[i].first;
    print(ans);
}
