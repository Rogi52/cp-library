---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root;\
    \ };\ntemplate < modinfo const &ref >\nstruct modint {\n    static constexpr uint\
    \ const &mod = ref.mod;\n    static modint root() { return modint(ref.root); }\n\
    \    uint v;\n    modint& s(uint v) { this->v = v < mod ? v : v - mod; return\
    \ *this; }\n    modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-()\
    \ const { return modint() - *this; }\n    modint& operator+=(const modint& rhs)\
    \ { return s(v + rhs.v); }\n    modint& operator-=(const modint& rhs) { return\
    \ s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v)\
    \ * rhs.v % mod; return *this; }\n    modint& operator/=(const modint& rhs) {\
    \ return *this *= rhs.inv(); }\n    modint operator+(const modint& rhs) const\
    \ { return modint(*this) += rhs; }\n    modint operator-(const modint& rhs) const\
    \ { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs) const\
    \ { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs) const\
    \ { return modint(*this) /= rhs; }\n    modint pow(ll n) const { modint res(1),\
    \ x(*this); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res;\
    \ }\n    modint inv() const { int a = v, b = mod, x = 1, y = 0, t; while(b > 0)\
    \ { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); } return modint(x); }\n\
    \    // modint inv() const { return pow(mod - 2); }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n};\n\nconstexpr modinfo base { 998244353, 3 };\n\
    //constexpr modinfo base { 1000000007, 0 };\nusing mint = modint< base >;\n"
  code: "struct modinfo { uint mod, root; };\ntemplate < modinfo const &ref >\nstruct\
    \ modint {\n    static constexpr uint const &mod = ref.mod;\n    static modint\
    \ root() { return modint(ref.root); }\n    uint v;\n    modint& s(uint v) { this->v\
    \ = v < mod ? v : v - mod; return *this; }\n    modint(ll v = 0) { s(v % mod +\
    \ mod); }\n    modint operator-() const { return modint() - *this; }\n    modint&\
    \ operator+=(const modint& rhs) { return s(v + rhs.v); }\n    modint& operator-=(const\
    \ modint& rhs) { return s(v + mod - rhs.v); }\n    modint& operator*=(const modint&\
    \ rhs) { v = ull(v) * rhs.v % mod; return *this; }\n    modint& operator/=(const\
    \ modint& rhs) { return *this *= rhs.inv(); }\n    modint operator+(const modint&\
    \ rhs) const { return modint(*this) += rhs; }\n    modint operator-(const modint&\
    \ rhs) const { return modint(*this) -= rhs; }\n    modint operator*(const modint&\
    \ rhs) const { return modint(*this) *= rhs; }\n    modint operator/(const modint&\
    \ rhs) const { return modint(*this) /= rhs; }\n    modint pow(ll n) const { modint\
    \ res(1), x(*this); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return\
    \ res; }\n    modint inv() const { int a = v, b = mod, x = 1, y = 0, t; while(b\
    \ > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); } return modint(x);\
    \ }\n    // modint inv() const { return pow(mod - 2); }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n};\n\nconstexpr modinfo base { 998244353, 3 };\n\
    //constexpr modinfo base { 1000000007, 0 };\nusing mint = modint< base >;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/modint.hpp
  requiredBy: []
  timestamp: '2023-03-26 00:56:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/modint.hpp
layout: document
title: modint
---

## うおおお
自動でmodを取る構造体
