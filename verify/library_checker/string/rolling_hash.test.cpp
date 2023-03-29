#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "src/cp-template.hpp"
#include "src/string/rolling_hash.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();
    rolling_hash< 1 > rh(s);
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
        return rolling_hash< 1 >::cmp(s, rh, i, n, s, rh, j, n) < 0;
    });
    rep(i,n) cout << I[i] << " \n"[i == n - 1];
}
