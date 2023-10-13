#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/lazy_segtree.hpp"
#include "../../../src/algebra/range_update_range_sum.hpp"

int main() {
    int n = in(), q = in();
    lazy_segtree<range_update_range_sum<ll, ll(1e18)>> st(n, {0, 1});
    for(int _q : rep(q)) {
        int type = in();
        if(type == 0) {
            int s = in(), t = in(), x = in(); t++;
            st.apply(s, t, x);
        }
        if(type == 1) {
            int s = in(), t = in(); t++;
            print(st.prod(s, t).value);
        }
    }
}