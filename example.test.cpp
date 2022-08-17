#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"

#include "src/cp-template"

int main() {
    int n; cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    
    int q; cin >> q;
    int cnt = 0;
    while (q --) {
        int t; cin >> t;
        cnt += binary_search(s.begin(), s.end(), t);
    }
    cout << cnt << endl;
    return 0;
}
