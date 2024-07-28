struct namori {
    int n;
    vector<vector<int>> g;
    namori(int n) : n(n), g(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> loop;
    vector<vector<int>> forest;
    void decomposition() {
        vector<int> in(n);
        for(int v = 0; v < n; v++) in[v] = g[v].size();
        forest.resize(n);

        queue<int> que;
        vector<int> vis(n, false);
        for(int v = 0; v < n; v++) {
            if(in[v] == 1) {
                que.push(v);
                vis[v] = true;
            }
        }
        while(not que.empty()) {
            const int v = que.front(); que.pop();
            for(int to : g[v]) if(not vis[to]) {
                forest[v].push_back(to);
                forest[to].push_back(v);
                if(--in[to] == 1) {
                    que.push(to);
                    vis[to] = true;
                }
            }
        }

        auto dfs = [&](auto self, int v) -> void {
            loop.push_back(v);
            for(int to : g[v]) if(not vis[to]) {
                vis[to] = true;
                self(self, to);
            }
        };
        for(int v = 0; v < n; v++) if(not vis[v]) {
            vis[v] = true;
            dfs(dfs, v);
        }
    }
};
