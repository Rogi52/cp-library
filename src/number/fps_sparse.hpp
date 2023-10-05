#pragma once
#include "../cp-template.hpp"
#include "../number/fps.hpp"

template< class mint > struct fps_sparse : std::vector<std::pair<int, mint>> {
    using std::vector<std::pair<int, mint>>::vector;
    friend fps_sparse differential(const fps_sparse& f) {
        fps_sparse g;
        for(auto [i, fi] : f) if(i != 0) g.push_back({i - 1, fi * i});
        return g;
    }
    friend fps_sparse integral_(const fps_sparse& f) {
        fps_sparse g;
        for(auto [i, fi] : f) g.push_back({i + 1, fi / (i + 1)});
        return g;
    }
};

template < class mint >
fps<mint> inv(const fps_sparse<mint>& f, int deg) {
    return to_dense(fps_sparse<mint>{{0, 1}}, deg) / f;
}

template < class mint >
fps<mint> to_dense(const fps_sparse<mint>& f, int deg) {
    fps<mint> g(deg, 0);
    for(auto [i, fi] : f) g[i] = fi;
    return g;
}

template < class mint >
fps<mint> log(const fps_sparse<mint>& f, int deg) {
    assert(f[0] == make_pair(0, mint(1)));
    return integral_(to_dense(differential(f), deg - 1) / f);
}

template < class mint >
fps<mint> exp(const fps_sparse<mint>& f, int deg) {
    if(f.size() == 0) return to_dense(fps_sparse<mint>{{0, 1}}, deg);
    assert(f[0] == make_pair(0, mint(1)));
    fps_sparse<mint> df = differential(f);
    fps<mint> g(deg, 0);
    g[0] = 1;
    for(int i : rep(1, deg)) for(auto [j, dfj] : df)
            if(0 <= i - 1 - j) g[i] += dfj * g[i - 1 - j] * inv(mint(i));
    return g;
}

template < class mint >
fps<mint> pow(const fps_sparse<mint>& f, ll n, int deg) {
    assert(0 <= n);
    if(n == 0) return to_dense(fps_sparse<mint>{{0, 1}}, deg);
    if(f.size() == 0) return fps<mint>(deg, 0);
    int d = f[0].first;
    if((deg + n - 1) / n <= d) return fps<mint>(deg, 0);
    int offset = d * n;
    mint c = f[0].second, c_inv = mint(1) / c;
    fps_sparse<mint> fr;
    for(auto [i, fi] : f) fr.push_back({i - d, fi * c_inv});

    fps<mint> g = to_dense(fps_sparse<mint>{{0, 1}}, deg);
    for(int i : rep(1, deg - offset)) for(auto [j, fj] : fr)
            if(j != 0 and 0 <= i - j) g[i] += fj * g[i - j] * (mint(n) * mint(j) - mint(i - j)) * inv(mint(i));
    g *= pow(c, n);
    g >>= offset;
    return g;
}

template < class mint >
fps<mint> sqrt(const fps_sparse<mint>& f, int deg) {

}