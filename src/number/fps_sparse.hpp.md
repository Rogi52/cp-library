---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/number/fps.hpp
    title: src/number/fps.hpp
  - icon: ':question:'
    path: src/number/modint.hpp
    title: modint
  - icon: ':x:'
    path: src/number/ntt.hpp
    title: src/number/ntt.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':question:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/number/fps_inv_sparse.test.cpp
    title: verify/library_checker/number/fps_inv_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate <\
    \ class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false;\
    \ }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true;\
    \ } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T\
    \ > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1)\
    \ {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n\
    \        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T >\
    \ struct rep {\n    const itr< T > s, t;\n    constexpr rep(const T t) noexcept\
    \ : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t)\
    \ {}\n    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t,\
    \ d) {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr\
    \ auto end() const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr < T > s, t;\n    constexpr revrep(const T t) noexcept : s(t\
    \ - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end() const noexcept { return\
    \ t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca\
    \ {\n        template < class T > operator T() {\n            T s; cin >> s; return\
    \ s;\n        }\n    };\n    struct vec {\n        int n;\n        vec(int n)\
    \ : n(n) {}\n        template < class T > operator vector< T >() {\n         \
    \   vector< T > v(n);\n            for(T& x : v) cin >> x;\n            return\
    \ v;\n        }\n    };\n    struct mat {\n        int h,w;\n        mat(int h,\
    \ int w) : h(h), w(w) {}\n        template < class T > operator vector< vector<\
    \ T > >() {\n            vector m(h, vector< T >(w));\n            for(vector<\
    \ T >& v : m) for(T& x : v) cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            cin.tie(0);\n        \
    \    ios::sync_with_stdio(0);\n        }\n    } su;\n}\nscanner::sca in() { return\
    \ scanner::sca(); }\nscanner::vec in(int n) { return scanner::vec(n); }\nscanner::mat\
    \ in(int h, int w) { return scanner::mat(h, w); }\n\nnamespace printer {\n   \
    \ void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    \    void flush() {\n        cout.flush();\n    }\n}\nint print() { cout << '\\\
    n'; return 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&...\
    \ t) {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/utility/key_val.hpp\"\ntemplate <\
    \ class K, class V >\nstruct key_val {\n    K key; V val;\n    key_val() {}\n\
    \    key_val(K key, V val) : key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T >\nkey_val< int, T > max_of(const vector< T >& a) {\n   \
    \ int i = max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nkey_val< int, T > min_of(const vector< T >& a) {\n\
    \    int i = min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nT sum_of(const vector< T >& a) {\n    T sum = 0;\n\
    \    for(const T x : a) sum += x;\n    return sum;\n}\n\ntemplate < class T >\n\
    vector<int> freq_of(const vector< T >& a, T L, T R) {\n    vector<int> res(R -\
    \ L);\n    for(const T x : a) res[x - L]++;\n    return res;\n}\n\ntemplate <\
    \ class T >\nvector<int> freq_of(const vector< T >& a, T R) {\n    return freq_of(a,\
    \ T(0), R);\n}\n\ntemplate < class T >\nstruct prefix_sum {\n    vector< T > s;\n\
    \    prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), T(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 2 \"\
    src/number/modint.hpp\"\nstruct modinfo { uint mod, root, isprime; };\ntemplate\
    \ < modinfo const &ref >\nstruct modint {\n    static constexpr uint const &mod\
    \ = ref.mod;\n    static constexpr uint const &root = ref.root;\n    static constexpr\
    \ uint const &isprime = ref.isprime;\n    uint v = 0;\n    constexpr modint& s(uint\
    \ v) { this->v = v < mod ? v : v - mod; return *this; }\n    constexpr modint(ll\
    \ v = 0) { s(v % mod + mod); }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint& operator+=(const modint& rhs) { return s(v + rhs.v);\
    \ }\n    modint& operator-=(const modint& rhs) { return s(v + mod - rhs.v); }\n\
    \    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v % mod; return\
    \ *this; }\n    modint& operator/=(const modint& rhs) { return *this *= inv(rhs);\
    \ }\n    modint operator+(const modint& rhs) const { return modint(*this) += rhs;\
    \ }\n    modint operator-(const modint& rhs) const { return modint(*this) -= rhs;\
    \ }\n    modint operator*(const modint& rhs) const { return modint(*this) *= rhs;\
    \ }\n    modint operator/(const modint& rhs) const { return modint(*this) /= rhs;\
    \ }\n    friend modint pow(modint x, ll n) { modint res(1); while(n > 0) { if(n\
    \ & 1) res *= x; x *= x; n >>= 1; } return res; }\n    friend modint inv(modint\
    \ v) {\n        if(isprime) {\n            return pow(v, mod - 2);\n        }\
    \ else {\n            ll a = v.v, b = modint::mod, x = 1, y = 0, t;\n        \
    \    while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); }\n \
    \           return modint(x);\n        }\n    }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n    static uint get_mod() { return mod; }\n};\n\
    constexpr modinfo base998244353 { 998244353, 3, 1 };\nconstexpr modinfo base1000000007\
    \ { 1000000007, 0, 1 };\nusing mint998244353 = modint< base998244353 >;\nusing\
    \ mint1000000007 = modint< base1000000007 >;\n#line 3 \"src/number/ntt.hpp\"\n\
    namespace ntt {\n\ntemplate < class mint >\nvoid trans(vector<mint>& v, bool is_inv)\
    \ {\n    if(v.empty()) return;\n    int n = v.size();\n    uint mod = mint::mod,\
    \ root = mint::root;\n    static bool first = true;\n    static vector<ll> vbw(30),\
    \ vibw(30);\n    if(first) {\n        first = false;\n        for(int k : rep(30))\
    \ {\n            vbw[k] = pow(mint(root), (mod - 1) >> (k + 1)).v;\n         \
    \   vibw[k] = inv(mint(vbw[k])).v;\n        }\n    }\n    for(int i = 0, j = 1;\
    \ j < n - 1; j++) {\n        for(int k = n >> 1; k > (i ^= k); k >>= 1);\n   \
    \     if(i > j) swap(v[i], v[j]);\n    }\n    for(int k = 0, t = 2; t <= n; ++k,\
    \ t <<= 1) {\n        mint bw = (is_inv ? vibw[k] : vbw[k]);\n        for (int\
    \ i = 0; i < n; i += t) {\n            mint w = 1;\n            for (int j = 0;\
    \ j < t / 2; ++j) {\n                int j1 = i + j, j2 = i + j + t/2;\n     \
    \           mint c1 = v[j1], c2 = v[j2] * w;\n                v[j1] = c1 + c2;\n\
    \                v[j2] = c1 - c2;\n                w *= bw;\n            }\n \
    \       }\n    }\n    if(is_inv) {\n        mint iv = inv(mint(n));\n        for(int\
    \ i : rep(n)) v[i] *= iv;\n    }\n}\ntemplate < class mint > void ntt(vector<mint>&\
    \ v) { trans(v, false); }\ntemplate < class mint > void intt(vector<mint>& v)\
    \ { trans(v, true); }\n\n// for garner\nconstexpr modinfo base0 { 754974721, 11,\
    \ 1};\nconstexpr modinfo base1 { 167772161,  3, 1};\nconstexpr modinfo base2 {\
    \ 469762049,  3, 1};\nusing mint0 = modint< base0 >;\nusing mint1 = modint< base1\
    \ >;\nusing mint2 = modint< base2 >;\nstatic const mint1 imod0  =  95869806; //\
    \ MOD0^-1 mod MOD1\nstatic const mint2 imod1  = 104391568; // MOD1^^1 mod MOD2\n\
    static const mint2 imod01 = 187290749; // imod1 / MOD0;\n\ntemplate < class T\
    \ >\nvector< T > naive(const vector< T >& a, const vector< T >& b) {\n    if(a.empty()\
    \ || b.empty()) return {};\n    int n = a.size(), m = b.size();\n    vector< T\
    \ > c(n + m - 1);\n    for(int i : rep(n)) for(int j : rep(m)) c[i + j] += a[i]\
    \ * b[j];\n    return c;\n}\n\ntemplate < class mint >\nvector<mint> mul(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    if(a.empty() || b.empty()) return\
    \ {};\n    int n = a.size(), m = b.size();\n    if(min(n, m) < 30) return naive(a,\
    \ b);\n    uint mod = mint::mod;\n\n    int sz = [&]() {\n        int n2 = 1,\
    \ m2 = 1;\n        while(n2 < n) n2 <<= 1;\n        while(m2 < m) m2 <<= 1;\n\
    \        return max(n2, m2) << 1;\n    }();\n\n    if(mod == 998244353) {\n  \
    \      vector<mint> a2(sz, 0), b2(sz, 0), c(sz, 0);\n        for(int i : rep(n))\
    \ a2[i] = a[i];\n        for(int i : rep(m)) b2[i] = b[i];\n        ntt(a2), ntt(b2);\n\
    \        for(int i : rep(sz)) c[i] = a2[i] * b2[i];\n        intt(c);\n      \
    \  c.resize(n + m - 1);\n        return c;\n    }\n\n    vector<mint0> a0(sz,\
    \ 0), b0(sz, 0), c0(sz, 0);\n    vector<mint1> a1(sz, 0), b1(sz, 0), c1(sz, 0);\n\
    \    vector<mint2> a2(sz, 0), b2(sz, 0), c2(sz, 0);\n    for(int i : rep(n)) a0[i].v\
    \ = a1[i].v = a2[i].v = a[i].v;\n    for(int i : rep(m)) b0[i].v = b1[i].v = b2[i].v\
    \ = b[i].v;\n    ntt(a0), ntt(b0), ntt(a1), ntt(b1), ntt(a2), ntt(b2);\n    for(int\
    \ i : rep(sz)) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] * b1[i];\n\
    \        c2[i] = a2[i] * b2[i];\n    }\n    intt(c0), intt(c1), intt(c2);\n  \
    \  \n    vector<mint> c(n + m - 1);\n    static const mint mod0 = mint0::mod,\
    \ mod01 = mod0 * mint1::mod;\n    for(int i : rep(n + m - 1)) {\n        ll y0\
    \ = c0[i].v;\n        ll y1 = (imod0 * (c1[i] - y0)).v;\n        ll y2 = (imod01\
    \ * (c2[i] - y0) - imod1 * y1).v;\n        c[i] = mod01 * y2 + mod0 * y1 + y0;\n\
    \    }\n    return c;\n}\n\n} // namespace ntt\n#line 4 \"src/number/fps.hpp\"\
    \n\nclass undefined {};\ntemplate < class mint > struct fps : std::vector<mint>\
    \ {\n    using std::vector<mint>::vector;\n    fps(const std::vector<mint>& f)\
    \ : std::vector<mint>(f) {}\n    int size() const { return int(std::vector<mint>::size());\
    \ }\n    void ups(int s) { if(size() < s) this->resize(s, 0); }\n    fps low(int\
    \ s) const {\n        return fps(this->begin(), this->begin() + min(this->size(),\
    \ s));\n    }\n    fps rev() const {\n        return fps(this->rbegin(), this->rend());\n\
    \    }\n    fps operator-() const {\n        fps g = *this;\n        for(int i\
    \ : rep(g.size())) g[i] = -g[i];\n        return g;\n    }\n    fps operator+(const\
    \ mint& v) const { return fps(*this) += v; }\n    fps operator-(const mint& v)\
    \ const { return fps(*this) -= v; }\n    fps operator*(const mint& v) const {\
    \ return fps(*this) *= v; }\n    fps operator/(const mint& v) const { return fps(*this)\
    \ /= v; }\n    fps operator+(const fps& r) const { return fps(*this) += r; }\n\
    \    fps operator-(const fps& r) const { return fps(*this) -= r; }\n    fps operator*(const\
    \ fps& r) const { return fps(*this) *= r; }\n    fps operator/(const fps& r) const\
    \ { return fps(*this) /= r; }\n    fps operator<<(int s) const { return fps(*this)\
    \ <<= s; }\n    fps operator>>(int s) const { return fps(*this) >>= s; }\n   \
    \ fps& operator+=(const fps& r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i]\
    \ += r[i]; return *this; }\n    fps& operator-=(const fps& r) { ups(r.size());\
    \ for(int i : rep(r.size())) (*this)[i] -= r[i]; return *this; }\n    fps& operator*=(const\
    \ fps& r) { return *this = ntt::mul(*this, r); } // ntt\n    fps& operator/=(const\
    \ fps& r) { return *this *= inv(r); }\n    template < class T > fps& operator+=(T\
    \ v) { ups(1); (*this)[0] += v; return *this; }\n    template < class T > fps&\
    \ operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }\n    template < class\
    \ T > fps& operator*=(T v) { for(auto &x : *this) x *= v; return *this; }\n  \
    \  template < class T > fps& operator/=(T v) { assert(v != T(0)); return *this\
    \ *= mint(1) / v; }\n\n    fps& operator<<=(int s) {\n        fps g(s, 0);\n \
    \       g.insert(g.end(), this->begin(), this->end());\n        return *this =\
    \ g;\n    }\n    fps& operator>>=(int s) {\n        return *this = {this->begin()\
    \ + s, this->end()};\n    }\n    friend fps differential(const fps& f) {\n   \
    \     int n = f.size();\n        fps g(n - 1);\n        for(int i : rep(1, n))\
    \ g[i - 1] = f[i] * i;\n        return g;\n    }\n    friend fps integral_(const\
    \ fps& f) { // std \u3068\u885D\u7A81\n        int n = f.size();\n        fps\
    \ g(n + 1, 0);\n        for(int i : rep(0, n)) g[i + 1] = f[i] / (i + 1);\n  \
    \      return g;\n    }\n    friend fps inv(const fps& f, int deg) {\n       \
    \ assert(f[0] != 0);\n        fps g = {mint(1) / f[0]};\n        for(int i = 1;\
    \ i < deg; i <<= 1) {\n            g = (g + g - g * g * f.low(i << 1)).low(i <<\
    \ 1);\n        }\n        g.resize(deg);\n        return g;\n    }\n    friend\
    \ fps log(const fps& f, int deg) {\n        assert(f[0] == 1);\n        fps g\
    \ = integral_((differential(f) * inv(f, deg)));\n        g.resize(deg);\n    \
    \    return g;\n    }\n    friend fps exp(const fps& f, int deg) {\n        assert(f[0]\
    \ == 0);\n        fps g = {1};\n        for(int i = 1; i < deg; i <<= 1) {\n \
    \           g = g * (f.low(i << 1) - log(g, i << 1) + 1).low(i << 1);\n      \
    \  }\n        g.resize(deg);\n        return g;\n    }\n    friend fps pow(const\
    \ fps& f, ll n, int deg) {\n        if(n == 0) {\n            fps g(deg, 0);\n\
    \            g[0] = 1;\n            return g;\n        }\n        int i = 0;\n\
    \        while(i < f.size() and f[i] == 0) i++;\n        if(i == f.size() or i128(i)\
    \ * n >= deg) return fps(deg, 0);\n        mint k = f[i];\n        fps g = exp(log((f\
    \ >> i) / k, deg) * n, deg) * pow(k, n) << (i * n);\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps sqrt(const fps& f, int deg) {\n    \
    \    int n = f.size(), d = n;\n        for(int i : revrep(0, n)) if(f[i] != 0)\
    \ d = i;\n        if(d == n) return f;\n        if(d % 2 == 1) throw undefined();\n\
    \        mint y = f[d], x = sqrt(y);\n        if(x * x != y) throw undefined();\n\
    \        mint c = mint(1) / y;\n        fps g(n - d);\n        for(int i : rep(n\
    \ - d)) g[i] = f[d + i] * c;\n        \n        assert(g[0] == 1);\n        mint\
    \ inv2 = mint(1) / 2;\n        fps h = {1};\n        for(int i = 1; i < deg; i\
    \ <<= 1) {\n            h = (h + g.low(i << 1) * inv(h, i << 1)).low(i << 1);\n\
    \            for(mint& a : h) a *= inv2;\n        }\n        h.resize(deg);\n\n\
    \        for(int i : rep(deg)) h[i] *= x;\n        for(int i : revrep(deg)) h[i]\
    \ = (i >= d / 2 ? h[i - d / 2] : 0);\n        return h;\n    }\n\n    friend fps\
    \ inv(const fps& f) { return inv(f, f.size()); }\n    friend fps log(const fps&\
    \ f) { return log(f, f.size()); }\n    friend fps exp(const fps& f) { return exp(f,\
    \ f.size()); }\n    friend fps pow(const fps& f, ll n) { return pow(f, n, f.size());\
    \ }\n    friend fps sqrt(const fps& f) { return sqrt(f, f.size()); }\n};\n#line\
    \ 4 \"src/number/fps_sparse.hpp\"\n\ntemplate< class mint > struct fps_sparse\
    \ : std::vector<std::pair<int, mint>> {\n    using std::vector<std::pair<int,\
    \ mint>>::vector;\n    friend fps_sparse differential(const fps_sparse& f) {\n\
    \        fps_sparse g;\n        for(auto [i, fi] : f) if(i != 0) g.push_back({i\
    \ - 1, fi * i});\n        return g;\n    }\n    friend fps_sparse integral_(const\
    \ fps_sparse& f) {\n        fps_sparse g;\n        for(auto [i, fi] : f) g.push_back({i\
    \ + 1, fi / (i + 1)});\n        return g;\n    }\n};\n\ntemplate < class mint\
    \ >\nfps<mint> inv(const fps_sparse<mint>& f, int deg) {\n    return to_dense(fps_sparse<mint>{{0,\
    \ 1}}, deg) / f;\n}\n\ntemplate < class mint >\nfps<mint> to_dense(const fps_sparse<mint>&\
    \ f, int deg) {\n    fps<mint> g(deg, 0);\n    for(auto [i, fi] : f) g[i] = fi;\n\
    \    return g;\n}\n\ntemplate < class mint >\nfps<mint> log(const fps_sparse<mint>&\
    \ f, int deg) {\n    assert(f[0] == make_pair(0, mint(1)));\n    return integral_(to_dense(differential(f),\
    \ deg - 1) / f);\n}\n\ntemplate < class mint >\nfps<mint> exp(const fps_sparse<mint>&\
    \ f, int deg) {\n    if(f.size() == 0) return to_dense(fps_sparse<mint>{{0, 1}},\
    \ deg);\n    assert(f[0] == make_pair(0, mint(1)));\n    fps_sparse<mint> df =\
    \ differential(f);\n    fps<mint> g(deg, 0);\n    g[0] = 1;\n    for(int i : rep(1,\
    \ deg)) for(auto [j, dfj] : df)\n            if(0 <= i - 1 - j) g[i] += dfj *\
    \ g[i - 1 - j] * inv(mint(i));\n    return g;\n}\n\ntemplate < class mint >\n\
    fps<mint> pow(const fps_sparse<mint>& f, ll n, int deg) {\n    assert(0 <= n);\n\
    \    if(n == 0) return to_dense(fps_sparse<mint>{{0, 1}}, deg);\n    if(f.size()\
    \ == 0) return fps<mint>(deg, 0);\n    int d = f[0].first;\n    if((deg + n -\
    \ 1) / n <= d) return fps<mint>(deg, 0);\n    int offset = d * n;\n    mint c\
    \ = f[0].second, c_inv = mint(1) / c;\n    fps_sparse<mint> fr;\n    for(auto\
    \ [i, fi] : f) fr.push_back({i - d, fi * c_inv});\n\n    fps<mint> g = to_dense(fps_sparse<mint>{{0,\
    \ 1}}, deg);\n    for(int i : rep(1, deg - offset)) for(auto [j, fj] : fr)\n \
    \           if(j != 0 and 0 <= i - j) g[i] += fj * g[i - j] * (mint(n) * mint(j)\
    \ - mint(i - j)) * inv(mint(i));\n    g *= pow(c, n);\n    g >>= offset;\n   \
    \ return g;\n}\n\ntemplate < class mint >\nfps<mint> sqrt(const fps_sparse<mint>&\
    \ f, int deg) {\n\n}\n"
  code: "#pragma once\n#include \"../cp-template.hpp\"\n#include \"../number/fps.hpp\"\
    \n\ntemplate< class mint > struct fps_sparse : std::vector<std::pair<int, mint>>\
    \ {\n    using std::vector<std::pair<int, mint>>::vector;\n    friend fps_sparse\
    \ differential(const fps_sparse& f) {\n        fps_sparse g;\n        for(auto\
    \ [i, fi] : f) if(i != 0) g.push_back({i - 1, fi * i});\n        return g;\n \
    \   }\n    friend fps_sparse integral_(const fps_sparse& f) {\n        fps_sparse\
    \ g;\n        for(auto [i, fi] : f) g.push_back({i + 1, fi / (i + 1)});\n    \
    \    return g;\n    }\n};\n\ntemplate < class mint >\nfps<mint> inv(const fps_sparse<mint>&\
    \ f, int deg) {\n    return to_dense(fps_sparse<mint>{{0, 1}}, deg) / f;\n}\n\n\
    template < class mint >\nfps<mint> to_dense(const fps_sparse<mint>& f, int deg)\
    \ {\n    fps<mint> g(deg, 0);\n    for(auto [i, fi] : f) g[i] = fi;\n    return\
    \ g;\n}\n\ntemplate < class mint >\nfps<mint> log(const fps_sparse<mint>& f, int\
    \ deg) {\n    assert(f[0] == make_pair(0, mint(1)));\n    return integral_(to_dense(differential(f),\
    \ deg - 1) / f);\n}\n\ntemplate < class mint >\nfps<mint> exp(const fps_sparse<mint>&\
    \ f, int deg) {\n    if(f.size() == 0) return to_dense(fps_sparse<mint>{{0, 1}},\
    \ deg);\n    assert(f[0] == make_pair(0, mint(1)));\n    fps_sparse<mint> df =\
    \ differential(f);\n    fps<mint> g(deg, 0);\n    g[0] = 1;\n    for(int i : rep(1,\
    \ deg)) for(auto [j, dfj] : df)\n            if(0 <= i - 1 - j) g[i] += dfj *\
    \ g[i - 1 - j] * inv(mint(i));\n    return g;\n}\n\ntemplate < class mint >\n\
    fps<mint> pow(const fps_sparse<mint>& f, ll n, int deg) {\n    assert(0 <= n);\n\
    \    if(n == 0) return to_dense(fps_sparse<mint>{{0, 1}}, deg);\n    if(f.size()\
    \ == 0) return fps<mint>(deg, 0);\n    int d = f[0].first;\n    if((deg + n -\
    \ 1) / n <= d) return fps<mint>(deg, 0);\n    int offset = d * n;\n    mint c\
    \ = f[0].second, c_inv = mint(1) / c;\n    fps_sparse<mint> fr;\n    for(auto\
    \ [i, fi] : f) fr.push_back({i - d, fi * c_inv});\n\n    fps<mint> g = to_dense(fps_sparse<mint>{{0,\
    \ 1}}, deg);\n    for(int i : rep(1, deg - offset)) for(auto [j, fj] : fr)\n \
    \           if(j != 0 and 0 <= i - j) g[i] += fj * g[i - j] * (mint(n) * mint(j)\
    \ - mint(i - j)) * inv(mint(i));\n    g *= pow(c, n);\n    g >>= offset;\n   \
    \ return g;\n}\n\ntemplate < class mint >\nfps<mint> sqrt(const fps_sparse<mint>&\
    \ f, int deg) {\n\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/number/fps.hpp
  - src/number/ntt.hpp
  - src/number/modint.hpp
  isVerificationFile: false
  path: src/number/fps_sparse.hpp
  requiredBy: []
  timestamp: '2023-10-06 17:13:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/number/fps_inv_sparse.test.cpp
documentation_of: src/number/fps_sparse.hpp
layout: document
redirect_from:
- /library/src/number/fps_sparse.hpp
- /library/src/number/fps_sparse.hpp.html
title: src/number/fps_sparse.hpp
---
