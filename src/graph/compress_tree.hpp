// require: in, lca, depth
// 
// sort(X, [&](int i, int j) { return IN[i] < IN[j]; });
// const int m = X.size();

// auto add_edge = [&](int u, int v) {
//     v_tree[u].push_back(v);
//     v_tree[v].push_back(u);
// };

// vector<int> path;
// for(int i : rep(1, m)) {
//     if(!path.empty()) {
//         int w = lca.query(path.back(), X[i]);
//         auto ng = [&]() {
//             return not path.empty() and lca.depth[path.back()] > lca.depth[w];
//         };
//         while(ng()) {
//             int u = path.back(); path.pop_back();
//             add_edge(ng() ? path.back() : w, u);
//         }
//         if(path.empty() or path.back() != w) path.push_back(w);
//     }
//     path.push_back(X[i]);
// }
// for(int i : rep(int(path.size()) - 1)) add_edge(path[i], path[i + 1]);
// int root = path[0];

// struct LCA {
//     vector<vector<int>> parent; // parent[d][v] := 2^d-th parent of v
//     vector<int> depth;
//     LCA() { }
//     LCA(const vector<vector<int>> &G, int r = 0){ init(G, r); }

//     void init(const vector<vector<int>> &G, int r = 0) {
//         int V = (int)G.size();
//         int h = 1;
//         while((1 << h) < V) ++h;
//         parent.assign(h, vector<int> (V, -1));
//         depth.assign(V, -1);
//         dfs(G, r, -1, 0);
//         for(int i = 0; i + 1 < (int)parent.size(); ++i){
//             for(int v = 0; v < V; ++v) {
//                 if(parent[i][v] != -1){
//                     parent[i + 1][v] = parent[i][parent[i][v]];
//                 }
//             }
//         }
//     }

//     void dfs(const vector<vector<int>> &G, int v, int p, int d) {
//         parent[0][v] = p;
//         depth[v] = d;
//         for(auto e : G[v]) if(e != p) dfs(G, e, v, d + 1);
//     }

//     int query(int u, int v) {
//         if(depth[u] > depth[v]) swap(u, v);
//         for(int i = 0; i < (int)parent.size(); ++i) {
//             if((depth[v] - depth[u]) & (1 << i)) v = parent[i][v];
//         }
//         if(u == v) return u;
//         for(int i = (int)parent.size() - 1; i >= 0; --i) {
//             if(parent[i][u] != parent[i][v]) {
//                 u = parent[i][u];
//                 v = parent[i][v];
//             }
//         }
//         return parent[0][u];
//     }

//     int dist(int u, int v) { 
//         return depth[u] + depth[v] - 2 * depth[query(u, v)];
//     }

//     bool is_on_path(int u, int v, int x) {
//         return dist(u, x) + dist(x, v) == dist(u, v);
//     }
// };
