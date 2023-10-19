#define PROBLEM "https://yukicoder.me/problems/no/789"

#include "../../src/cp-template.hpp"
#include "../../src/data_structure/sparse_segtree.hpp"
#include "../../src/algebra/sum.hpp"

int main() {
    const int M = 1'000'000'001;
    sparse_segtree< int, sum_monoid<int> > seg(M);

    int n = in();
    ll ans = 0;
    for(int _n : rep(n)) {
        int t = in();
        if(t == 0) {
            int x = in(), y = in();
            seg.set(x, seg.get(x) + y);
        }
        if(t == 1) {
            int l = in(), r = in(); r++;
            ans += seg.prod(l, r);
        }
    }
    print(ans);
}