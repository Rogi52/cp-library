#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/data_structure/lazy_segtree.hpp"
#include "../../../src/algebra/range_affine_range_sum.hpp"

int main() {
    int N = in(), Q = in();
    using mint = mint998244353;
    using V = range_affine_range_sum<mint>::value_structure::set;
    vector< V > a(N);
    for(int i : rep(N)) {
        mint x = in();
        a[i] = V{x, 1};
    }

    lazy_segtree< range_affine_range_sum<mint> > lzst(a);
    for(int _ : rep(Q)) {
        int t = in();
        if(t == 0) {
            int l = in(), r = in(); mint b = in(), c = in();
            lzst.apply(l, r, {b, c});
        }
        if(t == 1) {
            int l = in(), r = in();
            print(lzst.prod(l, r).first);
        }
    }
}
