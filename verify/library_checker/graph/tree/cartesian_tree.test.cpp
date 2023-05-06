#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "src/cp-template.hpp"
#include "src/graph/tree/cartesian_tree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    vector<int> a = in(n);
    auto [G, r] = cartesian_tree<int>(a);
    vector<int> ans(n);
    ans[r] = r;
    for(int i : rep(n)) for(int v : G[i]) ans[v] = i;
    for(int p : ans) cout << p << " "; cout << endl;
};
