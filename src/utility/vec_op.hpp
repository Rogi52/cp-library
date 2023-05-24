#pragma once
template < class T >
key_val< int, T > max_of(const vector< T >& a) {
    int i = max_element(a.begin(), a.end()) - a.begin();
    return {a[i], i};
}

template < class T >
key_val< int, T > min_of(const vector< T >& a) {
    int i = min_element(a.begin(), a.end()) - a.begin();
    return {a[i], i};
}

template < class T >
T sum_of(const vector< T >& a) {
    T sum = 0;
    for(const T x : a) sum += x;
    return sum;
}

template < class T >
vector<int> freq(const vector< T >& a, T L = 0, T R) {
    vector<int> res(R - L);
    for(const T x : a) res[x - L]++;
    return res;
}

template < class T >
struct prefix_sum {
    vector< T > s;
    prefix_sum(const vector< T >& a) : s(a) {
        s.insert(sum.begin(), T(0));
        for(int i : rep(a.size())) s[i + 1] += s[i];
    }
    // [L, R)
    T sum(int L, int R) {
        return s[R] - s[L];
    }
};
