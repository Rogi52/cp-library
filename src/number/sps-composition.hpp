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
