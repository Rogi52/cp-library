---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
    title: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/montmort.test.cpp
    title: verify/library_checker/number/montmort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/number/runtime_modint.hpp\"\nstruct runtime_modint {\n\
    \  public:\n    ll v = 0;\n    runtime_modint(ll v = 0) { s(v % get_mod() + get_mod());\
    \ }\n    static void set_mod(ll m) { mod() = m; }\n    static void set_mod(ll\
    \ m, int isp) { mod() = m; prime() = isp; }\n    static ll get_mod() { return\
    \ mod(); }\n    static int is_prime() { return prime(); }\n    using rtmint =\
    \ runtime_modint;\n    rtmint& s(ll v) { this->v = v < get_mod() ? v : v - get_mod();\
    \ return *this; }\n    rtmint operator-() const { return rtmint() - *this; }\n\
    \    rtmint& operator+=(const rtmint& rhs) { return s(v + rhs.v); }\n    rtmint&\
    \ operator-=(const rtmint& rhs) { return s(v + get_mod() - rhs.v); }\n    rtmint&\
    \ operator*=(const rtmint& rhs) { v = ull(v) * rhs.v % get_mod(); return *this;\
    \ }\n    rtmint& operator/=(const rtmint& rhs) { return *this *= inv(rhs); }\n\
    \    rtmint operator+(const rtmint& rhs) const { return rtmint(*this) += rhs;\
    \ }\n    rtmint operator-(const rtmint& rhs) const { return rtmint(*this) -= rhs;\
    \ }\n    rtmint operator*(const rtmint& rhs) const { return rtmint(*this) *= rhs;\
    \ }\n    rtmint operator/(const rtmint& rhs) const { return rtmint(*this) /= rhs;\
    \ }\n    friend rtmint pow(rtmint x, ll n) { rtmint res(1); while(n > 0) { if(n\
    \ & 1) res *= x; x *= x; n >>= 1; } return res; }\n    friend rtmint inv(rtmint\
    \ v) {\n        if(prime()) {\n            return pow(v, get_mod() - 2);\n   \
    \     } else {\n            ll a = v.v, b = get_mod(), x = 1, y = 0, t;\n    \
    \        while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); }\n\
    \            return rtmint(x);\n        }\n    }\n    friend rtmint operator+(int\
    \ x, const rtmint& y) { return rtmint(x) + y; }\n    friend rtmint operator-(int\
    \ x, const rtmint& y) { return rtmint(x) - y; }\n    friend rtmint operator*(int\
    \ x, const rtmint& y) { return rtmint(x) * y; }\n    friend rtmint operator/(int\
    \ x, const rtmint& y) { return rtmint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, rtmint& m) { ll x; is >> x; m = rtmint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const rtmint& m) { return os << m.v; }\n    bool operator==(const\
    \ rtmint& r) const { return v == r.v; }\n    bool operator!=(const rtmint& r)\
    \ const { return v != r.v; }\n  private:\n    static ll &mod() {\n        static\
    \ ll mod_ = 0;\n        return mod_;\n    }\n    static int &prime() {\n     \
    \   static int prime_ = 0;\n        return prime_;\n    }\n};\n"
  code: "struct runtime_modint {\n  public:\n    ll v = 0;\n    runtime_modint(ll\
    \ v = 0) { s(v % get_mod() + get_mod()); }\n    static void set_mod(ll m) { mod()\
    \ = m; }\n    static void set_mod(ll m, int isp) { mod() = m; prime() = isp; }\n\
    \    static ll get_mod() { return mod(); }\n    static int is_prime() { return\
    \ prime(); }\n    using rtmint = runtime_modint;\n    rtmint& s(ll v) { this->v\
    \ = v < get_mod() ? v : v - get_mod(); return *this; }\n    rtmint operator-()\
    \ const { return rtmint() - *this; }\n    rtmint& operator+=(const rtmint& rhs)\
    \ { return s(v + rhs.v); }\n    rtmint& operator-=(const rtmint& rhs) { return\
    \ s(v + get_mod() - rhs.v); }\n    rtmint& operator*=(const rtmint& rhs) { v =\
    \ ull(v) * rhs.v % get_mod(); return *this; }\n    rtmint& operator/=(const rtmint&\
    \ rhs) { return *this *= inv(rhs); }\n    rtmint operator+(const rtmint& rhs)\
    \ const { return rtmint(*this) += rhs; }\n    rtmint operator-(const rtmint& rhs)\
    \ const { return rtmint(*this) -= rhs; }\n    rtmint operator*(const rtmint& rhs)\
    \ const { return rtmint(*this) *= rhs; }\n    rtmint operator/(const rtmint& rhs)\
    \ const { return rtmint(*this) /= rhs; }\n    friend rtmint pow(rtmint x, ll n)\
    \ { rtmint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return\
    \ res; }\n    friend rtmint inv(rtmint v) {\n        if(prime()) {\n         \
    \   return pow(v, get_mod() - 2);\n        } else {\n            ll a = v.v, b\
    \ = get_mod(), x = 1, y = 0, t;\n            while(b > 0) { t = a / b; swap(a\
    \ -= t * b, b); swap(x -= t * y, y); }\n            return rtmint(x);\n      \
    \  }\n    }\n    friend rtmint operator+(int x, const rtmint& y) { return rtmint(x)\
    \ + y; }\n    friend rtmint operator-(int x, const rtmint& y) { return rtmint(x)\
    \ - y; }\n    friend rtmint operator*(int x, const rtmint& y) { return rtmint(x)\
    \ * y; }\n    friend rtmint operator/(int x, const rtmint& y) { return rtmint(x)\
    \ / y; }\n    friend istream& operator>>(istream& is, rtmint& m) { ll x; is >>\
    \ x; m = rtmint(x); return is; }\n    friend ostream& operator<<(ostream& os,\
    \ const rtmint& m) { return os << m.v; }\n    bool operator==(const rtmint& r)\
    \ const { return v == r.v; }\n    bool operator!=(const rtmint& r) const { return\
    \ v != r.v; }\n  private:\n    static ll &mod() {\n        static ll mod_ = 0;\n\
    \        return mod_;\n    }\n    static int &prime() {\n        static int prime_\
    \ = 0;\n        return prime_;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/runtime_modint.hpp
  requiredBy: []
  timestamp: '2023-10-24 23:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number/montmort.test.cpp
  - verify/library_checker/number/binom_coeff_prime_mod.test.cpp
documentation_of: src/number/runtime_modint.hpp
layout: document
redirect_from:
- /library/src/number/runtime_modint.hpp
- /library/src/number/runtime_modint.hpp.html
title: src/number/runtime_modint.hpp
---