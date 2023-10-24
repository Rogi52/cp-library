struct runtime_modint {
  public:
    ll v = 0;
    runtime_modint(ll v = 0) { s(v % get_mod() + get_mod()); }
    static void set_mod(ll m) { mod() = m; }
    static void set_mod(ll m, int isp) { mod() = m; prime() = isp; }
    static ll get_mod() { return mod(); }
    static int is_prime() { return prime(); }
    using rtmint = runtime_modint;
    rtmint& s(ll v) { this->v = v < get_mod() ? v : v - get_mod(); return *this; }
    rtmint operator-() const { return rtmint() - *this; }
    rtmint& operator+=(const rtmint& rhs) { return s(v + rhs.v); }
    rtmint& operator-=(const rtmint& rhs) { return s(v + get_mod() - rhs.v); }
    rtmint& operator*=(const rtmint& rhs) { v = ull(v) * rhs.v % get_mod(); return *this; }
    rtmint& operator/=(const rtmint& rhs) { return *this *= inv(rhs); }
    rtmint operator+(const rtmint& rhs) const { return rtmint(*this) += rhs; }
    rtmint operator-(const rtmint& rhs) const { return rtmint(*this) -= rhs; }
    rtmint operator*(const rtmint& rhs) const { return rtmint(*this) *= rhs; }
    rtmint operator/(const rtmint& rhs) const { return rtmint(*this) /= rhs; }
    friend rtmint pow(rtmint x, ll n) { rtmint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }
    friend rtmint inv(rtmint v) {
        if(prime()) {
            return pow(v, get_mod() - 2);
        } else {
            ll a = v.v, b = get_mod(), x = 1, y = 0, t;
            while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); }
            return rtmint(x);
        }
    }
    friend rtmint operator+(int x, const rtmint& y) { return rtmint(x) + y; }
    friend rtmint operator-(int x, const rtmint& y) { return rtmint(x) - y; }
    friend rtmint operator*(int x, const rtmint& y) { return rtmint(x) * y; }
    friend rtmint operator/(int x, const rtmint& y) { return rtmint(x) / y; }
    friend istream& operator>>(istream& is, rtmint& m) { ll x; is >> x; m = rtmint(x); return is; }
    friend ostream& operator<<(ostream& os, const rtmint& m) { return os << m.v; }
    bool operator==(const rtmint& r) const { return v == r.v; }
    bool operator!=(const rtmint& r) const { return v != r.v; }
  private:
    static ll &mod() {
        static ll mod_ = 0;
        return mod_;
    }
    static int &prime() {
        static int prime_ = 0;
        return prime_;
    }
};
