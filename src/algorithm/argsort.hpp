template < class T > vector< int > argsort(vector< T > &a) {
    vector< int > ids((int)a.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] < a[j] || (a[i] == a[j] && i < j);
    });
    return ids;
}
