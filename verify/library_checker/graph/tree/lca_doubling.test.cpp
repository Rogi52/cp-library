#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "src/cp-template.hpp"
#include "src/graph/tree/lca_doubling.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,Q; cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int p; cin >> p;
        G[p].push_back(i);
    }

    LCA lca(G);
    rep(_,Q) {
        int u,v; cin >> u >> v;
        cout << lca.query(u, v) << '\n';
    }
};
