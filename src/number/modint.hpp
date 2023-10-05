#pragma once
struct modinfo { uint mod, root, isprime; };
template < modinfo const &ref >
struct modint {
    static constexpr uint const &mod = ref.mod;
    static constexpr uint const &root = ref.root;
    static constexpr uint const &isprime = ref.isprime;
    uint v = 0;
    constexpr modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this; }
    constexpr modint(ll v = 0) { s(v % mod + mod); }
    modint operator-() const { return modint() - *this; }
    modint& operator+=(const modint& rhs) { return s(v + rhs.v); }
    modint& operator-=(const modint& rhs) { return s(v + mod - rhs.v); }
    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v % mod; return *this; }
    modint& operator/=(const modint& rhs) { return *this *= inv(rhs); }
    modint operator+(const modint& rhs) const { return modint(*this) += rhs; }
    modint operator-(const modint& rhs) const { return modint(*this) -= rhs; }
    modint operator*(const modint& rhs) const { return modint(*this) *= rhs; }
    modint operator/(const modint& rhs) const { return modint(*this) /= rhs; }
    friend modint pow(modint x, ll n) { modint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }
    friend modint inv(modint v) {
        if(isprime) {
            return pow(v, mod - 2);
        } else {
            ll a = v.v, b = modint::mod, x = 1, y = 0, t;
            while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); }
            return modint(x);
        }
    }
    friend modint operator+(int x, const modint& y) { return modint(x) + y; }
    friend modint operator-(int x, const modint& y) { return modint(x) - y; }
    friend modint operator*(int x, const modint& y) { return modint(x) * y; }
    friend modint operator/(int x, const modint& y) { return modint(x) / y; }
    friend istream& operator>>(istream& is, modint& m) { ll x; is >> x; m = modint(x); return is; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.v; }
    bool operator==(const modint& r) const { return v == r.v; }
    bool operator!=(const modint& r) const { return v != r.v; }
    static uint get_mod() { return mod; }
};
constexpr modinfo base998244353 { 998244353, 3, 1 };
constexpr modinfo base1000000007 { 1000000007, 0, 1 };
using mint998244353 = modint< base998244353 >;
using mint1000000007 = modint< base1000000007 >;
