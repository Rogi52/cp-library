#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "src/cp-template.hpp"
#include "src/data_structure/segtree.hpp"
#include "src/algebra/affine.hpp"
#include "src/number/modint.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,Q; cin >> N >> Q;
    using F = affine<mint>;
    vector< F > f(N);
    rep(i,N) {
        mint a,b; cin >> a >> b;
        f[i] = F(a, b);
    }

    segtree< affine_composite_monoid<mint> > seg(f);
    rep(_,Q) {
        int t; cin >> t;
        if(t == 0) {
            int p; mint c,d; cin >> p >> c >> d;
            seg.set(p, F(c, d));
        }

        if(t == 1) {
            int l,r; mint x; cin >> l >> r >> x;
            cout << seg.prod(l, r).eval(x) << "\n";
        }
    }
}
