#pragma once
#include "../cp-template.hpp"
#include "../number/ntt.hpp"

class undefined {};
template < class mint > struct fps : std::vector<mint> {
    using std::vector<mint>::vector;
    fps(const std::vector<mint>& f) : std::vector<mint>(f) {}
    int size() const { return int(std::vector<mint>::size()); }
    void ups(int s) { if(size() < s) this->resize(s, 0); }
    fps low(int s) const {
        return fps(this->begin(), this->begin() + min(this->size(), s));
    }
    fps rev() const {
        return fps(this->rbegin(), this->rend());
    }
    fps operator-() const {
        fps g = *this;
        for(int i : rep(g.size())) g[i] = -g[i];
        return g;
    }
    fps operator+(const mint& v) const { return fps(*this) += v; }
    fps operator-(const mint& v) const { return fps(*this) -= v; }
    fps operator*(const mint& v) const { return fps(*this) *= v; }
    fps operator/(const mint& v) const { return fps(*this) /= v; }
    fps operator+(const fps& r) const { return fps(*this) += r; }
    fps operator-(const fps& r) const { return fps(*this) -= r; }
    fps operator*(const fps& r) const { return fps(*this) *= r; }
    fps operator/(const fps& r) const { return fps(*this) /= r; }
    fps operator<<(int s) const { return fps(*this) <<= s; }
    fps operator>>(int s) const { return fps(*this) >>= s; }
    fps& operator+=(const fps& r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i] += r[i]; return *this; }
    fps& operator-=(const fps& r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i] -= r[i]; return *this; }
    fps& operator*=(const fps& r) { return *this = ntt::mul(*this, r); } // ntt
    fps& operator/=(const fps& r) { return *this *= inv(r); }
    template < class T > fps& operator+=(T v) { ups(1); (*this)[0] += v; return *this; }
    template < class T > fps& operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }
    template < class T > fps& operator*=(T v) { for(auto &x : *this) x *= v; return *this; }
    template < class T > fps& operator/=(T v) { assert(v != T(0)); return *this *= mint(1) / v; }

    fps& operator<<=(int s) {
        fps g(s, 0);
        g.insert(g.end(), this->begin(), this->end());
        return *this = g;
    }
    fps& operator>>=(int s) {
        return *this = {this->begin() + s, this->end()};
    }
    friend fps differential(const fps& f) {
        int n = f.size();
        fps g(n - 1);
        for(int i : rep(1, n)) g[i - 1] = f[i] * i;
        return g;
    }
    friend fps integral_(const fps& f) { // std と衝突
        int n = f.size();
        fps g(n + 1, 0);
        for(int i : rep(0, n)) g[i + 1] = f[i] / (i + 1);
        return g;
    }
    friend fps inv(const fps& f, int deg) {
        assert(f[0] != 0);
        fps g = {mint(1) / f[0]};
        for(int i = 1; i < deg; i <<= 1) {
            g = (g + g - g * g * f.low(i << 1)).low(i << 1);
        }
        g.resize(deg);
        return g;
    }
    friend fps log(const fps& f, int deg) {
        assert(f[0] == 1);
        fps g = integral_((differential(f) * inv(f, deg)));
        g.resize(deg);
        return g;
    }
    friend fps exp(const fps& f, int deg) {
        assert(f[0] == 0);
        fps g = {1};
        for(int i = 1; i < deg; i <<= 1) {
            g = g * (f.low(i << 1) - log(g, i << 1) + 1).low(i << 1);
        }
        g.resize(deg);
        return g;
    }
    friend fps pow(const fps& f, ll n, int deg) {
        if(n == 0) {
            fps g(deg, 0);
            g[0] = 1;
            return g;
        }
        int i = 0;
        while(i < f.size() and f[i] == 0) i++;
        if(i == f.size() or i128(i) * n >= deg) return fps(deg, 0);
        mint k = f[i];
        fps g = exp(log((f >> i) / k, deg) * n, deg) * pow(k, n) << (i * n);
        g.resize(deg);
        return g;
    }
    friend fps sqrt(const fps& f, int deg) {
        int n = f.size(), d = n;
        for(int i : revrep(0, n)) if(f[i] != 0) d = i;
        if(d == n) return f;
        if(d % 2 == 1) throw undefined();
        mint y = f[d], x = sqrt(y);
        if(x * x != y) throw undefined();
        mint c = mint(1) / y;
        fps g(n - d);
        for(int i : rep(n - d)) g[i] = f[d + i] * c;
        
        assert(g[0] == 1);
        mint inv2 = mint(1) / 2;
        fps h = {1};
        for(int i = 1; i < deg; i <<= 1) {
            h = (h + g.low(i << 1) * inv(h, i << 1)).low(i << 1);
            for(mint& a : h) a *= inv2;
        }
        h.resize(deg);

        for(int i : rep(deg)) h[i] *= x;
        for(int i : revrep(deg)) h[i] = (i >= d / 2 ? h[i - d / 2] : 0);
        return h;
    }

    friend fps inv(const fps& f) { return inv(f, f.size()); }
    friend fps log(const fps& f) { return log(f, f.size()); }
    friend fps exp(const fps& f) { return exp(f, f.size()); }
    friend fps pow(const fps& f, ll n) { return pow(f, n, f.size()); }
    friend fps sqrt(const fps& f) { return sqrt(f, f.size()); }
};

template < class mint > int print(const fps<mint> f, char sep = ' ') {
    int n = f.size();
    for(int i : rep(n)) std::cout << f[i] << (i != n - 1 ? sep : '\n');
    return 0;
}
