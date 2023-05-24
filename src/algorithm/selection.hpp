#include "../../src/cp-template.hpp"

template < class T >
T kth(const vector< T >& a, int k) {
    int n = a.size();
    T INF = numeric_limits< T >::max();
    vector< T > c;
    for(int i : rep(0, n, 5)) {
        vector< T > b;
        for(int d : rep(5)) {
            b.push_back(i + d < n ? a[i + d] : INF);
        }
        sort(b.begin(), b.end());
        c.push_back(b[2]);
    }

    T m = kth(c, n / 10);
    vector< T > s1, s2, s3;
    for(T& x : a) {
        if(x <  m) s1.push_back(x);
        if(x == m) s2.push_back(x);
        if(x >  m) s3.push_back(x);
    }

    if(k <= int(s1.size())) return kth(s1, k);
    if(k <= int(s1.size() + s2.size())) return m;
    return kth(s1, k - int(s1.size() + s2.size()));
}

template < class T >
vector< T > topk(const vector< T >& a, int k, bool sorted = false) {
    T v = kth(a, k);
    vector< T > s1, s2;
    for(T& x : a) {
        if(x <  v) s1.push_back(x);
        if(x == v) s2.push_back(x);
    }
    while(int(s1.size()) < k) s1.push_back(s2);
    if(sorted) sort(s1.begin(), s1.end());
    return s1;
}