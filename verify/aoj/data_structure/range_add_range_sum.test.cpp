#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/lazy_segtree.hpp"
#include "../../../src/algebra/range_add_range_sum.hpp"

int main() {
    int n = in(), q = in();
    lazy_segtree<range_add_range_sum<ll>> st(n, {0, 1});
    for(int _q : rep(q)) {
        int type = in();
        if(type == 0) {
            int s = in(), t = in(), x = in(); s--;
            st.apply(s, t, x);
        }
        if(type == 1) {
            int s = in(), t = in(); s--;
            print(st.prod(s, t).value);
        }
    }
}