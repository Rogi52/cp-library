#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "src/cp-template.hpp"
#include "src/graph/cartesian_tree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto [G, r] = cartesian_tree<int>(a);
    vector<int> ans(n);
    ans[r] = r;
    rep(i,n) for(int v : G[i]) ans[v] = i;
    for(int p : ans) cout << p << " "; cout << endl;
};
