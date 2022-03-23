#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "src/cp-template.hpp"
#include "src/data_structure/cht_offline_get_min.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,Q; cin >> N >> Q;
    vector<pair<ll,ll>> lines(N);
    for(auto &[a, b] : lines) cin >> a >> b;

    vector<tuple<ll,ll,ll>> query(Q);
    vector<ll> xs;
    rep(i,Q) {
        int t; cin >> t;
        if(t == 0) {
            ll a,b; cin >> a >> b;
            query[i] = {t, a, b};
        } else {
            ll x; cin >> x;
            query[i] = {t, x, 0};
            xs.push_back(x);
        }
    }

    CHT_offline_get_min<ll> cht(xs);
    for(auto [a, b] : lines) cht.add_line(a, b);
    rep(i,Q) {
        auto [t, a, b] = query[i];
        if(t == 0) {
            cht.add_line(a, b);
        } else {
            cout << cht.query(a) << '\n';
        }
    }
}
