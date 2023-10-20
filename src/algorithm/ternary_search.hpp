template < class K, class V, class F >
std::pair< K, V > ternary_search(K L, K R, F f) {
    while(R - L >= K(3)) {
        K kL = (L + L + R) / 3, kR = (L + R + R) / 3;
        V vL = f(kL), vR = f(kR);
        if(vL < vR) R = kR; else L = kL;
    }
    std::pair< K, V > res = {R, f(R)};
    for(K k : rep(L, R)) {
        V v = f(k);
        if(v < res.second) res = std::make_pair(k, v);
    }
    return res;
}

template < class K, class V, class F >
std::pair< K, V > ternary_search_real(K L, K R, F f, int step = 80) {
    while(step--) {
        K kL = (L + L + R) / 3, kR = (L + R + R) / 3;
        V vL = f(kL), vR = f(kR);
        if(vL < vR) R = kR; else L = kL;
    }
    return std::make_pair(L, f(L));
}
