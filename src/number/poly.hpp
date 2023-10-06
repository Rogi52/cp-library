#pragma once
#include "../cp-template.hpp"
#include "../number/ntt.hpp"
#include "../number/fps.hpp"

template < class mint > struct poly : std::vector<mint> {
    using std::vector<mint>::vector;
    poly(const std::vector<mint>& f) : std::vector<mint>(f) {}
    int size() const { return int(std::vector<mint>::size()); }
    void ups(int s) { if(size() < s) this->resize(s, 0); }
    poly low(int s) const {
        return poly(this->begin(), this->begin() + min(this->size(), s));
    }
    friend poly rev(const poly& f) {
        return poly(f.rbegin(), f.rend());
    }
    poly operator-() const {
        poly g = *this;
        for(int i : rep(g.size())) g[i] = -g[i];
        return g;
    }
    poly operator+(const mint& v) const { return poly(*this) += v; }
    poly operator-(const mint& v) const { return poly(*this) -= v; }
    poly operator*(const mint& v) const { return poly(*this) *= v; }
    poly operator/(const mint& v) const { return poly(*this) /= v; }
    poly operator+(const poly& r) const { return poly(*this) += r; }
    poly operator-(const poly& r) const { return poly(*this) -= r; }
    poly operator*(const poly& r) const { return poly(*this) *= r; }
    poly operator/(const poly& r) const { return poly(*this) /= r; }
    poly operator%(const poly& r) const { return poly(*this) %= r; }
    poly operator<<(int s) const { return poly(*this) <<= s; }
    poly operator>>(int s) const { return poly(*this) >>= s; }
    poly& operator+=(const poly& r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i] += r[i]; return *this; }
    poly& operator-=(const poly& r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i] -= r[i]; return *this; }
    poly& operator*=(const poly& r) { return *this = ntt::mul(*this, r); }
    poly& operator/=(const poly& r) {
        assert(r.size() > 0);
        assert(r.back() != 0);
        int s = size() - r.size() + 1;
        if(s <= 0) return poly{0};
        return rev((rev(*this).low(s) * inv(fps<mint>(rev(r)), s).low(s)).low(s));
    }
    poly& operator%=(const poly& r) {
        *this -= *this / r * r;
        return *this = low(r.size() - 1);
    }
    template < class T > poly& operator+=(T v) { ups(1); (*this)[0] += v; return *this; }
    template < class T > poly& operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }
    template < class T > poly& operator*=(T v) { for(auto &x : *this) x *= v; return *this; }
    template < class T > poly& operator/=(T v) { assert(v != T(0)); return *this *= mint(1) / v; }
    poly& operator<<=(int s) {
        poly g(s, 0);
        g.insert(g.end(), this->begin(), this->end());
        return *this = g;
    }
    poly& operator>>=(int s) {
        return *this = {this->begin() + s, this->end()};
    }
    friend poly differential(const poly& f) {
        int n = f.size();
        poly g(n - 1);
        for(int i : rep(1, n)) g[i - 1] = f[i] * i;
        return g;
    }
    friend poly integral_(const poly& f) { // std と衝突
        int n = f.size();
        poly g(n + 1, 0);
        for(int i : rep(0, n)) g[i + 1] = f[i] / (i + 1);
        return g;
    }
};

template < class mint > int print(const poly<mint> f, char sep = ' ') {
    int n = f.size();
    for(int i : rep(n)) std::cout << f[i] << (i != n - 1 ? sep : '\n');
    return 0;
}


template < class mint >
poly<mint> all_product(vector< poly<mint> >& fs) {
    if(int(fs.size()) == 0) return {1};
    using P = std::pair<int, int>;
    std::priority_queue< P, std::vector< P >, std::greater< P >> pq;
    for(int i : rep(fs.size())) pq.push({fs[i].size(), i});
    while(int(pq.size()) >= 2) {
        auto [n1, i1] = pq.top(); pq.pop();
        auto [n2, i2] = pq.top(); pq.pop();
        fs[i1] *= fs[i2];
        pq.push({n1 + n2, i1});
    }
    return fs[pq.top().second];
}
