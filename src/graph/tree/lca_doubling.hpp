#pragma once

// Lowest Common Ancestor by doubling < O(NlogN), O(logN) >
struct LCA {
    vector<vector<int>> parent; // parent[d][v] := 2^d-th parent of v
    vector<int> depth;
    LCA() { }
    LCA(const vector<vector<int>> &tree, int r = 0){ init(tree, r); }

    void init(const vector<vector<int>> &tree, int r = 0) {
        int n = tree.size(), h = 1;
        while((1 << h) < n) ++h;
        parent.assign(h, vector<int> (n, -1));
        depth.assign(n, -1);
        depth[r] = 0; dfs(tree, r, -1);
        for(int i = 0; i + 1 < h; ++i) for(int v = 0; v < n; ++v)
            if(parent[i][v] != -1) parent[i + 1][v] = parent[i][parent[i][v]];
    }

    void dfs(const vector<vector<int>> &tree, int v, int p) {
        parent[0][v] = p;
        for(int to : tree[v]) if(to != p) depth[to] = depth[v] + 1, dfs(tree, to, v);
    }

    int query(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        int n = parent.size();
        for(int i = 0; i < n; ++i) {
            if((depth[v] - depth[u]) & (1 << i)) v = parent[i][v];
        }
        if(u == v) return u;
        for(int i = n - 1; i >= 0; --i) {
            if(parent[i][u] != parent[i][v])
                u = parent[i][u], v = parent[i][v];
        }
        return parent[0][u];
    }

    int dist(int u, int v) { 
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

    bool is_on_path(int u, int v, int x) {
        return dist(u, x) + dist(x, v) == dist(u, v);
    }
};
