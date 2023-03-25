struct modinfo { uint mod, root; };
template < modinfo const &ref >
struct modint {
    static constexpr uint const &mod = ref.mod;
    static modint root() { return modint(ref.root); }
    uint v;
    modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this; }
    modint(ll v = 0) { s(v % mod + mod); }
    modint operator-() const { return modint() - *this; }
    modint& operator+=(const modint& rhs) { return s(v + rhs.v); }
    modint& operator-=(const modint& rhs) { return s(v + mod - rhs.v); }
    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v % mod; return *this; }
    modint& operator/=(const modint& rhs) { return *this *= rhs.inv(); }
    modint operator+(const modint& rhs) const { return modint(*this) += rhs; }
    modint operator-(const modint& rhs) const { return modint(*this) -= rhs; }
    modint operator*(const modint& rhs) const { return modint(*this) *= rhs; }
    modint operator/(const modint& rhs) const { return modint(*this) /= rhs; }
    modint pow(ll n) const { modint res(1), x(*this); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }
    modint inv() const { return pow(mod - 2); }
    //modint inv() const { int a = v, b = mod, x = 1, y = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); } return modint(x); }
    friend modint operator+(int x, const modint& y) { return modint(x) + y; }
    friend modint operator-(int x, const modint& y) { return modint(x) - y; }
    friend modint operator*(int x, const modint& y) { return modint(x) * y; }
    friend modint operator/(int x, const modint& y) { return modint(x) / y; }
    friend istream& operator>>(istream& is, modint& m) { ll x; is >> x; m = modint(x); return is; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.v; }
    bool operator==(const modint& r) const { return v == r.v; }
    bool operator!=(const modint& r) const { return v != r.v; }
};

constexpr modinfo base { 998244353, 3 };
//constexpr modinfo base { 1000000007, 0 };
using mint = modint< base >;
