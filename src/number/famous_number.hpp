#include "../../src/cp-template.hpp"
#include "../../src/number/poly.hpp"
#include "../../src/number/fps.hpp"

template < class mint >
std::vector<mint> stirling_1st(int n) {
    if(n == 0) return {1};
    if(n == 1) return {0, 1};
    poly f = stirling_1st<mint>(n / 2);
    f *= taylor_shift(f, - mint(n / 2));
    if(n % 2 == 1) f *= poly<mint>{-(n - 1), 1};
    return f;
}

template < class mint >
std::vector<mint> stirling_2nd(int n) {
    poly<mint> f(n + 1), g(n + 1);
    for(int i : rep(n + 1)) {
        f[i] = fact_inv<mint>(i) * pow(mint(i), n);
        g[i] = fact_inv<mint>(i) * mint(i % 2 == 0 ? +1 : -1);
    }
    return (f * g).low(n + 1);
}

template < class mint >
std::vector<mint> bernoulli(int n) {
    fps<mint> f(n + 1);
    for(int i : rep(n + 1)) f[i] = fact_inv<mint>(i + 1);
    f = inv(f);
    for(int i : rep(n + 1)) f[i] *= fact<mint>(i);
    return f;
}

template < class mint >
std::vector<mint> partition(int n) {
    fps<mint> f(n + 1);
    f[0] = 1;
    for(int i : rep(1, n + 1)) {
        int p = +i * (3 * (+i) + 1) / 2;
        int q = -i * (3 * (-i) + 1) / 2;
        int c = i % 2 == 0 ? +1 : -1;
        if(p <= n) f[p] += c;
        if(q <= n) f[q] += c;
        if(n < p and n < q) break;
    }
    return inv(f);
}

template < class mint >
std::vector<mint> montmort(int n) {
    std::vector<mint> a(n + 1, 0);
    if(2 <= n) a[2] = 1;
    if(3 <= n) a[3] = 2;
    for(int i : rep(4, n + 1)) a[i] = (a[i - 1] + a[i - 2]) * (i - 1);
    return a;
}