// https://atcoder.jp/contests/abc364/tasks/abc364_g
template < class Cost > struct steiner_tree {
    int n;
    vector<vector<pair<int, Cost>>> g;
    steiner_tree(int n) : n(n), g(n) {}
    void add_edge(int u, int v, Cost c) {
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    static constexpr Cost INF = std::numeric_limits<Cost>::max();
    vector<vector<Cost>> table(vector<int> terminal) {
        const int m = terminal.size();
        vector dp(1 << m, vector(n, INF));
        for(int i = 0; i < m; i++) dp[1 << i][terminal[i]] = 0;

        for(int S = 1; S < (1 << m); S++) {
            for(int v = 0; v < n; v++) {
                for(int T = S; T > 0; T = (T - 1) & S) {
                    if(dp[T][v] != INF and dp[S ^ T][v] != INF)
                        dp[S][v] = min(dp[S][v], dp[T][v] + dp[S ^ T][v]);
                }
            }
            priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> que;
            for(int v = 0; v < n; v++) que.push({dp[S][v], v});
            while(not que.empty()) {
                auto [cv, v] = que.top(); que.pop();
                if(dp[S][v] < cv) continue;
                for(auto [to, c] : g[v]) {
                    if(dp[S][to] > dp[S][v] + c) {
                        que.push({dp[S][to] = dp[S][v] + c, to});
                    }
                }
            }
        }
        return dp;
    }
    Cost answer(vector<int> terminal) {
        const int m = terminal.size();
        if(m == 0) return 0;
        return table(terminal)[(1 << m) - 1][terminal[0]];
    }
};
