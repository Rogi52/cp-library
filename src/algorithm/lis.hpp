template < class T >
pair< vector< T >, vector<int> > lis(const vector< T >& a, bool strict) {
    int n = a.size();
    vector< T > lis;
    vector<int> res(n);
    rep(i,n) {
        auto it = (strict ? lower_bound(lis.begin(), lis.end(), a[i])
                          : upper_bound(lis.begin(), lis.end(), a[i]));
        (lis.end() == it ? lis.push_back(a[i]) : *it = a[i]);
        res[i] = lis.size();
    }
    return {lis, res};
}
