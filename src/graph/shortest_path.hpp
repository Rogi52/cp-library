// g <- pair < v , cost > 
template < class T >
vector< T > dijkstra(vector<vector<pair<int, T>>> &graph, int s) {
    T INF = numeric_limits< T >::max();
    vector<T> dist(graph.size(), INF);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> q;
    q.push({dist[s] = T(0), s});
    while(!q.empty()){
        auto [uc, ui] = q.top(); q.pop();
        if(uc != dist[ui]) continue;
        for(auto [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) 
            q.push({dist[vi] = uc + vc, vi});
    }
    return dist;
}

// g <- pair < v , cost > 
template < class T >
pair< T, vector<int> > shortest_path(vector<vector<pair<int, T>>> &graph, int s, int t) {
    T INF = numeric_limits< T >::max();
    vector<T> dist(graph.size(), INF);
    vector<int> prev(graph.size(), -1);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> q;
    q.push({dist[s] = T(0), s});
    while(!q.empty()){
        auto [uc, ui] = q.top(); q.pop();
        if(uc != dist[ui]) continue;
        for(auto [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) 
            q.push({dist[vi] = uc + vc, vi}), prev[vi] = ui;
    }

    vector<int> path;
    if(dist[t] != INF) {
        for(int v = t; v != -1; v = prev[v]) path.push_back(v);
        reverse(path.begin(), path.end());
    }
    return {dist[t], path};
}
