#pragma once

// g <- pair < v , cost > 
template < class T >
pair< T, vector<int> > shortest_path(vector<vector<pair<int, T>>> &g, int s, int t) {
    T INF = numeric_limits< T >::max();
    vector<T> dist(g.size(), INF);
    vector<int> prev(g.size(), -1);
    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> Q;
    Q.push({dist[s] = T(0), s});
    while(!Q.empty()){
        auto [uc, ui] = Q.top(); Q.pop();
        if(uc != dist[ui]) continue;
        for(auto [vi, vc] : g[ui]) if(dist[vi] > uc + vc) 
            Q.push({dist[vi] = uc + vc, vi}), prev[vi] = ui;
    }

    vector<int> path;
    if(dist[t] != INF) {
        for(int v = t; v != -1; v = prev[v]) path.push_back(v);
        reverse(path.begin(), path.end());
    }
    return {dist[t], path};
}
