template < class mint > struct formal_power_series : vector<mint> {
    using vector<mint>::vector;
    formal_power_series(const vector<mint>& f) : vector<mint>(f) {}
    using fps = formal_power_series<mint>;
    int size() const { return vector<mint>::size(); }
    void ups(int s) { if(size() < s) this->resize(s, 0); }
    fps low(int s) const {
        return fps(this->begin(), this->begin() + min(this->size(), s));
    }
    fps rev() const {
        fps res = *this;
        reverse(res.begin(), res.end());
        return res;
    }
    fps operator-() const {
        fps res = *this;
        for(int i = 0; i < int(res.size()); i++) res[i] = -res[i];
        return res;
    }
    fps operator+(const mint& v) const { return fps(*this) += v; }
    fps operator+(const fps&  r) const { return fps(*this) += r; }
    fps operator-(const mint& v) const { return fps(*this) -= v; }
    fps operator-(const fps&  r) const { return fps(*this) -= r; }
    fps operator*(const mint& v) const { return fps(*this) *= v; }
    fps operator*(const fps&  r) const { return fps(*this) *= r; }
    fps operator/(const mint& v) const { return fps(*this) /= v; }
    fps operator<<(int x) const { return fps(*this) <<= x; }
    fps operator>>(int x) const { return fps(*this) >>= x; }
    fps& operator+=(const fps&  r) { ups(r.size()); rep(i,r.size()) (*this)[i] += r[i]; return *this; }
    fps& operator-=(const fps&  r) { ups(r.size()); rep(i,r.size()) (*this)[i] -= r[i]; return *this; }
    fps& operator*=(const fps&  r) { return *this = ntt::mul(*this, r); }
    template < class T > fps& operator+=(T v) { ups(1); (*this)[0] += v; return *this; }
    template < class T > fps& operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }
    template < class T > fps& operator*=(T v) { for(auto &x : *this) x *= v; return *this; }
    template < class T > fps& operator/=(T v) { assert(v != T(0)); return *this *= modinv(v); }
    fps& operator<<=(int x) {
        fps res(x, 0);
        res.insert(res.end(), this->begin(), this->end());
        return *this = res;
    }
    fps& operator>>=(int x) {
        fps res;
        res.insert(res.end(), this->begin() + x, this->end());
        return *this = res;
    }

    friend fps diff(const fps& f) {
        int n = f.size();
        fps g(n - 1);
        for(int i = 1; i < n; i++) g[i - 1] = f[i] * i;
        return g;
    }
    friend fps integral(const fps& f) {
        int n = f.size();
        fps g(n + 1, 0);
        for(int i = 0; i < n; i++) g[i + 1] = f[i] / (i + 1);
        return g;
    }
    friend fps inv(const fps& f, int deg) {
        assert(f[0] != 0);
        fps g({mint(1) / f[0]});
        for(int i = 1; i < deg; i <<= 1) {
            g = (g + g - g * g * f.low(i << 1)).low(i << 1);
        }
        g.resize(deg);
        return g;
    }
    friend fps log(const fps& f, int deg) {
        assert(f[0] == 1);
        fps g = integral(diff(f) * inv(f, deg));
        g.resize(deg);
        return g;
    }
    friend fps exp(const fps& f, int deg) {
        assert(f[0] == 0);
        fps g(1, 1);
        for(int i = 1; i < deg; i <<= 1) {
            g = g * (f.low(i << 1) - log(g, i << 1) + 1).low(i << 1);
        }
        g.resize(deg);
        return g;
    }
    friend fps pow(const fps& f, ll n, int deg) {
        if(n == 0) { fps g(deg, 0); g[0] = 1; return g; }
        int i = 0;
        while(i < f.size() && f[i] == 0) i++;
        if(i == f.size() || __int128_t(i) * n >= deg) return fps(deg, 0);
        mint k = f[i];
        fps g = exp(log((f >> i) / k, deg) * n, deg) * modpow(k, n) << (i * n);
        g.resize(deg);
        return g;
    }
    friend fps inner_sqrt(const fps& f, int deg) {
        assert(f[0] == 1);
        mint inv2 = mint(1) / 2;
        fps g(1, 1);
        for(int i = 1; i < deg; i <<= 1) {
            g = (g + f.low(i << 1) * inv(g, i << 1)).low(i << 1);
            for(mint& a : g) a *= inv2;
        }
        g.resize(deg);
        return g;
    }
    friend fps sqrt(const fps& f, int deg) {
        int n = f.size(), d = n;
        for(int i = n - 1; i >= 0; i--) if(f[i] != 0) d = i;
        if(d == n) return f;
        if(d % 2 == 1) return {};
        mint y = f[d], x = modsqrt(y);
        if(x * x != y) return {};
        mint c = mint(1) / y;
        fps g(n - d);
        rep(i,n-d) g[i] = f[d + i] * c;
        g = inner_sqrt(g, deg);
        rep(i,g.size()) g[i] *= x;
        for(int i = deg - 1; i >= 0; i--) g[i] = (i >= d / 2 ? g[i - d / 2] : 0);
        return g;
    }

    friend fps inv(const fps& f) { return inv(f, f.size()); }
    friend fps log(const fps& f) { return log(f, f.size()); }
    friend fps exp(const fps& f) { return exp(f, f.size()); }
    friend fps pow(const fps& f, ll n) { return pow(f, n, f.size()); }
    friend fps sqrt(const fps& f) { return sqrt(f, f.size()); }
};

using fps = formal_power_series<mint>;
