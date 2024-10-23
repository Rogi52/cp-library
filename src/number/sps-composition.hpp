template < class T, int N >
vector< T > sps_exp(int n, const vector< T >& s) {
    const int m = 1 << n;
    assert(s.size() == m);
    assert(s[0] == T(0));
    vector< T > t(m);
    t[0] = T(1);
    for(int i = 0; i < n; i++) {
        vector a(s.begin() + (1 << i), s.begin() + (1 << (i + 1)));
        vector b(t.begin(), t.begin() + (1 << i));
        vector c = sps_conv< T, N >(i, a, b);
        copy(c.begin(), c.end(), t.begin() + (1 << i));
    }
    return t;
}

template < class T, int N >
vector< T > sps_egf(int n, vector< T > f, const vector< T >& s) {
    const int m = 1 << n;
    assert(s.size() == m);
    assert(s[0] == T(0));
    f.resize(n + 1, T(0));
    vector< T > t(m);
    t[0] = f[n];
    for(int d = n - 1; d >= 0; d--) {
        vector< T > u(m);
        u[0] = f[d];
        for(int i = 0; i < n - d; i++) {
            vector a(s.begin() + (1 << i), s.begin() + (1 << (i + 1)));
            vector b(t.begin(), t.begin() + (1 << i));
            vector c = sps_conv< T, N >(i, a, b);
            copy(c.begin(), c.end(), u.begin() + (1 << i));
        }
        t = move(u);
    }
    return t;
}

template < class T, int N >
vector< T > sps_poly(int n, vector< T > f, vector< T > s) {
    const int m = f.size();
    vector g(n + 1, T(0)), p(n + 1, T(0)); p[0] = 1;
    const T c = s[0]; s[0] = 0;
    for(int i = 0; i < m; i++) {
        for(int d = 0; d <= n; d++) g[d] += f[i] * p[d];
        for(int d = n; d >= 0; d--) {
            p[d] *= c;
            if(d != 0) p[d] += p[d - 1];
        }
    }
    T fact = 1;
    for(int d = 0; d <= n; d++) {
        g[d] *= fact;
        fact *= T(d + 1);
    }
    return sps_egf< T, N >(n, g, s);
}
