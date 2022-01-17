#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "src/cp-template.hpp"
#include "src/graph/tree/tree_diameter.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    vector<vector<pair<int,ll>>> G(N);
    rep(_,N-1) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    tree_diameter<ll> o(G);
    cout << o.diameter << " " << o.path.size() << endl;
    for(int u : o.path) cout << u << " "; cout << endl;
};
