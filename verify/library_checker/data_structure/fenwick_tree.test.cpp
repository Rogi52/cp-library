#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/fenwick_tree.hpp"
#include "../../../src/algebra/sum.hpp"

int main(){
    int N = in();
    int Q = in();
    vector<ll> a = in(N);
    fenwick_tree< sum_monoid< ll > > tree(a);

    for(int _ : rep(Q)) {
        int t = in();
        switch(t) {
            case 0: {
                int p = in(), x = in();
                tree.add(p, x);
            } break;

            case 1: {
                int l = in(), r = in();
                print(tree.fold(l, r));
            } break;
        }
    }
}
