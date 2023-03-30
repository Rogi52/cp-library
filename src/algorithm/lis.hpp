template < class T, class Cmp >
tuple< vector< T >, vector<int>, vector<int> > l_s(const vector< T >& a, Cmp cmp) {
    int n = a.size();
    vector< T > lis;
    vector<int> rank(n), st(n, -1), nt(n, -1);
    rep(i,n) {
        int pos = lower_bound(lis.begin(), lis.end(), a[i], cmp) - lis.begin();
        st[pos] = i;
        if(pos >= 1) nt[i] = st[pos - 1];
        if(pos == int(lis.size())) lis.push_back(a[i]); else lis[pos] = a[i];
        rank[i] = pos + 1;
    }
    int len = lis.size();
    vector<int> idx(len);
    for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len] = i;
    return {lis, idx, rank};
}
