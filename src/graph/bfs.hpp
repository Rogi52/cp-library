vector<int> bfs(vector<vector<int>> &graph, int s) {
    int INF = numeric_limits<int>::max();
    vector<int> dist(graph.size(), INF);
    queue<int> q;
    dist[s] = 0, q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]) if(dist[v] == INF)
            dist[v] = dist[u] + 1, q.push(v);
    }
    return dist;
}
