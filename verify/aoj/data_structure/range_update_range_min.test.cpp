#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/lazy_segtree.hpp"
#include "../../../src/algebra/range_update_range_minmax.hpp"

int main() {
    int n = in(), q = in();
    const ll INF = (1LL << 31) - 1;
    lazy_segtree<range_update_range_min<ll>> st(n, INF);
    for(int _q : rep(q)) {
        int type = in();
        if(type == 0) {
            int s = in(), t = in(), x = in(); t++;
            st.apply(s, t, x);
        }
        if(type == 1) {
            int s = in(), t = in(); t++;
            print(st.prod(s, t));
        }
    }
}