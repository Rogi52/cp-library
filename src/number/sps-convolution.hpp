template < class T, int N >
vector<array< T, N + 1 >> rank_zeta(int n, const vector< T >& f) {
    assert(n <= N);
    const int m = 1 << n;
    assert(f.size() == m);
    vector<array< T, N + 1 >> rf(m);
    for(int s = 0; s < m; s++) rf[s][popcount((unsigned)s)] = f[s];
    for(int i = 0; i < n; i++) {
        for(int s = 0; s < m; s++) {
            if(s >> i & 1) {
                const int t = s ^ (1 << i);
                for(int d = 0; d <= n; d++) rf[s][d] += rf[t][d];
            }
        }
    }
    return rf;
}

template < class T, int N >
vector< T > rank_mobius(int n, vector<array< T, N + 1>>& rf) {
    assert(n <= N);
    const int m = 1 << n;
    assert(rf.size() == m);
    for(int i = 0; i < n; i++) {
        for(int s = 0; s < m; s++) {
            if(s >> i & 1) {
                const int t = s ^ (1 << i);
                for(int d = 0; d <= n; d++) rf[s][d] -= rf[t][d];
            }
        }
    }
    vector< T > f(m);
    for(int s = 0; s < m; s++) f[s] = rf[s][popcount((unsigned)s)];
    return f;
}

template < class T, int N >
vector< T > sps_conv(int n, const vector< T >& a, const vector< T >& b) {
    const int m = 1 << n;
    auto ra = rank_zeta< T, N >(n, a);
    auto rb = rank_zeta< T, N >(n, b);
    vector<array< T, N + 1 >> rc(m);
    for(int s = 0; s < m; s++) {
        for(int k = 0; k <= n; k++) {
            for(int i = 0; i <= k; i++) {
                const int j = k - i;
                rc[s][k] += ra[s][i] * rb[s][j];
            }
        }
    }
    return rank_mobius< T, N >(n, rc);
}
