#pragma once

template < class T > class tree_diameter {
  public:
    vector<vector<pair<int,T>>> tree;
    T diameter;
    vector<int> path, parent;
    vector< T > dist;

    tree_diameter(vector<vector<pair<int,T>>> &tree) : tree(tree) {
        int n = tree.size();
        parent.assign(n, -1);
        dist.resize(n);

        dist[0] = T(0); dfs(0, -1);
        int u = max_element(dist.begin(), dist.end()) - dist.begin();
        dist[u] = T(0); dfs(u, -1);
        int v = max_element(dist.begin(), dist.end()) - dist.begin();
        diameter = dist[v];
        while(v != -1) path.push_back(v), v = parent[v];
    }

    void dfs(int v, int p) {
        parent[v] = p;
        for(auto [to, cost] : tree[v]) if(to != p) dist[to] = dist[v] + cost, dfs(to, v);
    }
};
