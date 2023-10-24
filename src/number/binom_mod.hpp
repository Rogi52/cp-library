#include "../../src/cp-template.hpp"

template < class mint >
mint fact(int n) {
    assert(0 <= n);
    assert(mint::is_prime());
    static const uint mod = mint::get_mod();
    static std::vector<mint> data = {1, 1};
    while(int(data.size()) <= n) {
        int i = data.size();
        data.push_back(data.back() * i);
    }
    return data[n];
}

template < class mint >
mint inv(int n) {
    assert(0 <= n);
    assert(mint::is_prime());
    static const uint mod = mint::get_mod();
    static std::vector<mint> data = {1, 1};
    while(int(data.size()) <= n) {
        int i = data.size();
        data.push_back(- data[mod % i] * (mod / i));
    }
    return data[n];
}

template < class mint >
mint fact_inv(int n) {
    assert(0 <= n);
    assert(mint::is_prime());
    static const uint mod = mint::get_mod();
    static std::vector<mint> data = {1, 1};
    while(int(data.size()) <= n) {
        int i = data.size();
        data.push_back(data.back() * inv<mint>(i));
    }
    return data[n];
}

template < class mint >
mint comb(int n, int k) {
    if(k < 0 or n < k) return 0;
    return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);
}

template < class mint >
mint perm(int n, int k) {
    return fact<mint>(n) * fact_inv<mint>(n - k);
}

template < class mint >
mint homo(int n, int k) {
    return comb<mint>(n + k - 1, k);
}
