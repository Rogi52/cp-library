vector<int> topo_sort(vector<vector<int>> &G) {
    int N = G.size();
    vector<int> deg(N, 0), ord;
    queue<int> q;
    rep(v,N) for(int to : G[v]) deg[to]++;
    rep(v,N) if(deg[v] == 0) q.push(v);
    while(!q.empty()) {
        int v = q.front(); q.pop(); ord.push_back(v);
        for(int to : G[v]) if(--deg[to] == 0) q.push(to);
    }
    return ord;
}
