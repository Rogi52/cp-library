---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/bicoef.hpp
    title: src/number/bicoef.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/runtime_modint.hpp
    title: src/number/runtime_modint.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"verify/library_checker/number/bicoef.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
    \n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
    \ itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n\
    \    const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t)\
    \ {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
    \ < class T > operator T() {\n            T s; cin >> s; return s;\n        }\n\
    \    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n    \
    \    template < class T > operator vector< T >() {\n            vector< T > v(n);\n\
    \            for(T& x : v) cin >> x;\n            return v;\n        }\n    };\n\
    \    struct mat {\n        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n\
    \        template < class T > operator vector< vector< T > >() {\n           \
    \ vector m(h, vector< T >(w));\n            for(vector< T >& v : m) for(T& x :\
    \ v) cin >> x;\n            return m;\n        }\n    };\n    struct speedup {\n\
    \        speedup() {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n\
    \        }\n    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec\
    \ in(int n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return\
    \ scanner::mat(h, w); }\n\nnamespace printer {\n    void precision(int d) {\n\
    \        cout << fixed << setprecision(d);\n    }\n    void flush() {\n      \
    \  cout.flush();\n    }\n}\nint print() { cout << '\\n'; return 0; }\ntemplate\
    \ < class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 1 \"src/number/runtime_modint.hpp\"\nstruct\
    \ runtime_modint {\n  public:\n    ll v = 0;\n    runtime_modint(ll v = 0) { s(v\
    \ % get_mod() + get_mod()); }\n    static void set_mod(ll m) { mod() = m; }\n\
    \    static void set_mod(ll m, int isp) { mod() = m; isprime() = isp; }\n    static\
    \ ll get_mod() { return mod(); }\n    using rtmint = runtime_modint;\n    rtmint&\
    \ s(ll v) { this->v = v < get_mod() ? v : v - get_mod(); return *this; }\n   \
    \ rtmint operator-() const { return rtmint() - *this; }\n    rtmint& operator+=(const\
    \ rtmint& rhs) { return s(v + rhs.v); }\n    rtmint& operator-=(const rtmint&\
    \ rhs) { return s(v + get_mod() - rhs.v); }\n    rtmint& operator*=(const rtmint&\
    \ rhs) { v = ull(v) * rhs.v % get_mod(); return *this; }\n    rtmint& operator/=(const\
    \ rtmint& rhs) { return *this *= inv(rhs); }\n    rtmint operator+(const rtmint&\
    \ rhs) const { return rtmint(*this) += rhs; }\n    rtmint operator-(const rtmint&\
    \ rhs) const { return rtmint(*this) -= rhs; }\n    rtmint operator*(const rtmint&\
    \ rhs) const { return rtmint(*this) *= rhs; }\n    rtmint operator/(const rtmint&\
    \ rhs) const { return rtmint(*this) /= rhs; }\n    friend rtmint pow(rtmint x,\
    \ ll n) { rtmint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; }\
    \ return res; }\n    friend rtmint inv(rtmint v) {\n        if(isprime()) {\n\
    \            return pow(v, get_mod() - 2);\n        } else {\n            ll a\
    \ = v.v, b = get_mod(), x = 1, y = 0, t;\n            while(b > 0) { t = a / b;\
    \ swap(a -= t * b, b); swap(x -= t * y, y); }\n            return rtmint(x);\n\
    \        }\n    }\n    friend rtmint operator+(int x, const rtmint& y) { return\
    \ rtmint(x) + y; }\n    friend rtmint operator-(int x, const rtmint& y) { return\
    \ rtmint(x) - y; }\n    friend rtmint operator*(int x, const rtmint& y) { return\
    \ rtmint(x) * y; }\n    friend rtmint operator/(int x, const rtmint& y) { return\
    \ rtmint(x) / y; }\n    friend istream& operator>>(istream& is, rtmint& m) { ll\
    \ x; is >> x; m = rtmint(x); return is; }\n    friend ostream& operator<<(ostream&\
    \ os, const rtmint& m) { return os << m.v; }\n    bool operator==(const rtmint&\
    \ r) const { return v == r.v; }\n    bool operator!=(const rtmint& r) const {\
    \ return v != r.v; }\n  private:\n    static ll &mod() {\n        static ll mod_\
    \ = 0;\n        return mod_;\n    }\n    static int &isprime() {\n        static\
    \ int isprime_ = 0;\n        return isprime_;\n    }\n};\nusing mint = runtime_modint;\n\
    #line 1 \"src/number/bicoef.hpp\"\ntemplate < class mint >\nclass bicoef {\n \
    \   int N;\n    vector<mint> fact_, inv_, finv_;\n  public:\n    bicoef(int N)\
    \ : N(N), fact_(N+1, 1), inv_(N+1, 1), finv_(N+1, 1) {\n        uint mod = mint::get_mod();\n\
    \        for(int i = 2; i <= N; i++) {\n            fact_[i] = fact_[i - 1] *\
    \ i;\n            inv_ [i] = - inv_[mod % i] * (mod / i);\n            finv_[i]\
    \ = finv_[i - 1] * inv_[i];\n        }\n    }\n    mint fact(int n) { assert(0\
    \ <= n && n <= N); return fact_[n]; }\n    mint inv (int n) { assert(0 <= n &&\
    \ n <= N); return inv_ [n]; }\n    mint finv(int n) { assert(0 <= n && n <= N);\
    \ return finv_[n]; }\n    mint comb(int n, int k) {\n        if(k < 0 || n < k)\
    \ return mint(0);\n        return fact(n) * finv(k) * finv(n - k);\n    }\n  \
    \  mint perm(int n, int k) { return fact(n) * finv(n - k); }\n    mint homo(int\
    \ n, int k) { return comb(n + k - 1, k); }\n};\n#line 6 \"verify/library_checker/number/bicoef.test.cpp\"\
    \n\nint main() {\n    int T = in();\n    int m = in();\n    mint::set_mod(m);\n\
    \    bicoef<mint> c(min(m, 10'000'000));\n    for(int i : rep(T)) {\n        int\
    \ n = in();\n        int k = in();\n        print(c.comb(n, k));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/number/runtime_modint.hpp\"\
    \n#include \"src/number/bicoef.hpp\"\n\nint main() {\n    int T = in();\n    int\
    \ m = in();\n    mint::set_mod(m);\n    bicoef<mint> c(min(m, 10'000'000));\n\
    \    for(int i : rep(T)) {\n        int n = in();\n        int k = in();\n   \
    \     print(c.comb(n, k));\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/number/runtime_modint.hpp
  - src/number/bicoef.hpp
  isVerificationFile: true
  path: verify/library_checker/number/bicoef.test.cpp
  requiredBy: []
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number/bicoef.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/bicoef.test.cpp
- /verify/verify/library_checker/number/bicoef.test.cpp.html
title: verify/library_checker/number/bicoef.test.cpp
---
