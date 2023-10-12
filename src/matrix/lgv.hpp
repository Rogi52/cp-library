#include "../../src/cp-template.hpp"
#include "../../src/matrix/base.hpp"

template < class mint >
mint LGV(const std::vector< std::vector<int> >& g, const std::vector<int>& a, const std::vector<int>& b) {
    int n = g.size(), m = a.size();
    std::vector dp(m, std::vector(n, mint(0)));
    for(int i : rep(m)) dp[i][a[i]] = 1;
    std::vector<int> deg(n, 0);
    for(int i : rep(n)) for(int to : g[i]) deg[to]++;
    std::queue<int> q;
    for(int i : rep(n)) if(deg[i] == 0) q.push(i);
    while(not q.empty()) {
        int v = q.front(); q.pop();
        for(int i : rep(m)) {
            for(int to : g[v]) {
                dp[i][to] += dp[i][v];
                if(--deg[to] == 0) q.push(to);
            }
        }
    }

    int m = a.size();
    square_matrix<mint> X(m);
    for(int i : rep(m)) for(int j : rep(m)) X[i][j] = dp[i][b[j]];
    return det(X);
}
