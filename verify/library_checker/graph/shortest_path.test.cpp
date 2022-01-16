#include "cp-template.hpp"
#include "graph/shortest_path.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,M,s,t; cin >> N >> M >> s >> t;
    vector<vector<pair<int,ll>>> G(N);
    rep(_,M) {
        int a,b,c; cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    auto [dist, path] = shortest_path(G, s, t);
    if(dist == numeric_limits<ll>::max()) {
        cout << -1 << endl;
    } else {
        int n = path.size();
        cout << dist << " " << n - 1 << endl;
        rep(i,n-1) cout << path[i] << " " << path[i + 1] << '\n';
    }
}
