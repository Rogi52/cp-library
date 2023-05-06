---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root,\
    \ isprime; };\ntemplate < modinfo const &ref >\nstruct modint {\n    static constexpr\
    \ uint const &mod = ref.mod;\n    static constexpr uint const &root = ref.root;\n\
    \    static constexpr uint const &isprime = ref.isprime;\n    uint v = 0;\n  \
    \  constexpr modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this;\
    \ }\n    constexpr modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-()\
    \ const { return modint() - *this; }\n    modint& operator+=(const modint& rhs)\
    \ { return s(v + rhs.v); }\n    modint& operator-=(const modint& rhs) { return\
    \ s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v)\
    \ * rhs.v % mod; return *this; }\n    modint& operator/=(const modint& rhs) {\
    \ return *this *= inv(rhs); }\n    modint operator+(const modint& rhs) const {\
    \ return modint(*this) += rhs; }\n    modint operator-(const modint& rhs) const\
    \ { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs) const\
    \ { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs) const\
    \ { return modint(*this) /= rhs; }\n    friend modint pow(modint x, ll n) { modint\
    \ res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n\
    \    friend modint inv(modint v) {\n        if(isprime) {\n            return\
    \ pow(v, mod - 2);\n        } else {\n            ll a = v.v, b = modint::mod,\
    \ x = 1, y = 0, t;\n            while(b > 0) { t = a / b; swap(a -= t * b, b);\
    \ swap(x -= t * y, y); }\n            return modint(x);\n        }\n    }\n  \
    \  friend modint operator+(int x, const modint& y) { return modint(x) + y; }\n\
    \    friend modint operator-(int x, const modint& y) { return modint(x) - y; }\n\
    \    friend modint operator*(int x, const modint& y) { return modint(x) * y; }\n\
    \    friend modint operator/(int x, const modint& y) { return modint(x) / y; }\n\
    \    friend istream& operator>>(istream& is, modint& m) { ll x; is >> x; m = modint(x);\
    \ return is; }\n    friend ostream& operator<<(ostream& os, const modint& m) {\
    \ return os << m.v; }\n    bool operator==(const modint& r) const { return v ==\
    \ r.v; }\n    bool operator!=(const modint& r) const { return v != r.v; }\n};\n\
    constexpr modinfo base998244353 { 998244353, 3, 1 };\nconstexpr modinfo base1000000007\
    \ { 1000000007, 0, 1 };\nusing mint = modint< base998244353 >;\n//using mint =\
    \ modint< base1000000007 >;\n"
  code: "struct modinfo { uint mod, root, isprime; };\ntemplate < modinfo const &ref\
    \ >\nstruct modint {\n    static constexpr uint const &mod = ref.mod;\n    static\
    \ constexpr uint const &root = ref.root;\n    static constexpr uint const &isprime\
    \ = ref.isprime;\n    uint v = 0;\n    constexpr modint& s(uint v) { this->v =\
    \ v < mod ? v : v - mod; return *this; }\n    constexpr modint(ll v = 0) { s(v\
    \ % mod + mod); }\n    modint operator-() const { return modint() - *this; }\n\
    \    modint& operator+=(const modint& rhs) { return s(v + rhs.v); }\n    modint&\
    \ operator-=(const modint& rhs) { return s(v + mod - rhs.v); }\n    modint& operator*=(const\
    \ modint& rhs) { v = ull(v) * rhs.v % mod; return *this; }\n    modint& operator/=(const\
    \ modint& rhs) { return *this *= inv(rhs); }\n    modint operator+(const modint&\
    \ rhs) const { return modint(*this) += rhs; }\n    modint operator-(const modint&\
    \ rhs) const { return modint(*this) -= rhs; }\n    modint operator*(const modint&\
    \ rhs) const { return modint(*this) *= rhs; }\n    modint operator/(const modint&\
    \ rhs) const { return modint(*this) /= rhs; }\n    friend modint pow(modint x,\
    \ ll n) { modint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; }\
    \ return res; }\n    friend modint inv(modint v) {\n        if(isprime) {\n  \
    \          return pow(v, mod - 2);\n        } else {\n            ll a = v.v,\
    \ b = modint::mod, x = 1, y = 0, t;\n            while(b > 0) { t = a / b; swap(a\
    \ -= t * b, b); swap(x -= t * y, y); }\n            return modint(x);\n      \
    \  }\n    }\n    friend modint operator+(int x, const modint& y) { return modint(x)\
    \ + y; }\n    friend modint operator-(int x, const modint& y) { return modint(x)\
    \ - y; }\n    friend modint operator*(int x, const modint& y) { return modint(x)\
    \ * y; }\n    friend modint operator/(int x, const modint& y) { return modint(x)\
    \ / y; }\n    friend istream& operator>>(istream& is, modint& m) { ll x; is >>\
    \ x; m = modint(x); return is; }\n    friend ostream& operator<<(ostream& os,\
    \ const modint& m) { return os << m.v; }\n    bool operator==(const modint& r)\
    \ const { return v == r.v; }\n    bool operator!=(const modint& r) const { return\
    \ v != r.v; }\n};\nconstexpr modinfo base998244353 { 998244353, 3, 1 };\nconstexpr\
    \ modinfo base1000000007 { 1000000007, 0, 1 };\nusing mint = modint< base998244353\
    \ >;\n//using mint = modint< base1000000007 >;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/modint.hpp
  requiredBy: []
  timestamp: '2023-05-06 07:51:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
documentation_of: src/number/modint.hpp
layout: document
title: modint
---

自動でmodを取る構造体
