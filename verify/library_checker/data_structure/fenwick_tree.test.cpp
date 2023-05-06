#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "src/cp-template.hpp"
#include "src/data_structure/fenwick_tree.hpp"
#include "src/algebra/plus.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,Q; cin >> N >> Q;
    vector<ll> a = in(N);
    fenwick_tree< PLUS< ll > > tree(a);

    for(int _ : rep(Q)) {
        int t; cin >> t;
        switch(t) {
            case 0: {
                int p,x; cin >> p >> x;
                tree.add(p, x);
            } break;

            case 1: {
                int l,r; cin >> l >> r;
                cout << tree.fold(l, r) << '\n';
            }
        }
    }
}
