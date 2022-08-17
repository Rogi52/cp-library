#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "src/cp-template.hpp"
#include "src/data_structure/union_find.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,Q; cin >> N >> Q;
    union_find uf(N);

    rep(_,Q) {
        int t, u, v; cin >> t >> u >> v;
        switch(t) {
            case 0: {
                uf.unite(u, v);
            } break;

            case 1: {
                cout << uf.same(u, v) << '\n';
            } break;
        }
    }
}
