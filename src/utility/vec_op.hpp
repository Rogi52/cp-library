#pragma once
template < class T > key_val< int, T > max_of(const vector< T >& a) {
    int i = std::max_element(a.begin(), a.end()) - a.begin();
    return {i, a[i]};
}
template < class T > key_val< int, T > min_of(const vector< T >& a) {
    int i = std::min_element(a.begin(), a.end()) - a.begin();
    return {i, a[i]};
}
template < class S, class T > S sum_of(const vector< T >& a) {
    S sum = 0;
    for(const T x : a) sum += x;
    return sum;
}
template < class S, class T > vector< S > freq_of(const vector< T >& a, T L, T R) {
    vector< S > res(R - L, S(0));
    for(const T x : a) res[x - L] += 1;
    return res;
}
template < class S, class T > struct prefix_sum {
    vector< S > s;
    prefix_sum(const vector< T >& a) : s(a) {
        s.insert(s.begin(), S(0));
        for(int i : rep(a.size())) s[i + 1] += s[i];
    }
    // [L, R)
    S sum(int L, int R) { return s[R] - s[L]; }
};
