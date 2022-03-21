#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "src/cp-template.hpp"
#include "src/data_structure/cht_offline_get_min.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N,Q; cin >> N >> Q;
    using Line = tuple<ll,ll,ll,ll>;
    vector< Line > lines(N);
    for(auto &[l, r, a, b] : lines) cin >> l >> r >> a >> b;

    vector< pair< int, Line > > query(Q);
    vector< ll > xs;
    rep(i,Q) {
        int t; cin >> t;
        if(t == 0) {
            ll l, r, a, b; cin >> l >> r >> a >> b;
            query[i] = {t, {l, r, a, b}};
        } else {
            ll x; cin >> x;
            query[i] = {t, {x, 0, 0, 0}};
            xs.push_back(x);
        }
    }

    CHT_offline_get_min<ll> cht(xs);
    for(auto [l, r, a, b] : lines) cht.add_segment(a, b, l, r);
    rep(i,Q) {
        int t = query[i].first;
        if(t == 0) {
            auto [l, r, a, b] = query[i].second;
            cht.add_segment(a, b, l, r);
        } else {
            auto [x, _, __, ___] = query[i].second;
            ll ans = cht.query(x);
            if(ans == cht.inf) {
                cout << "INFINITY" << '\n';
            } else {
                cout << ans << '\n';
            }
        }
    }
}
