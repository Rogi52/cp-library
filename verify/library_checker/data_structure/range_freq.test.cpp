#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/range_freq.hpp"

int main() {
    int N = in(), Q = in();
    using value_type = int;
    vector< value_type > a = in(N);
    range_freq< value_type > rf(a);
    
    for(int _ : rep(Q)) {
        int LI = in(), RI = in(), k = in();
        
        value_type LV = 0, RV = 1e9 + 1;
        while(RV - LV > 1) {
            value_type M = (LV + RV) / 2;
            (rf.query(LI, RI, M) <= k ? LV : RV) = M;
        }
        print(LV);
    }
}