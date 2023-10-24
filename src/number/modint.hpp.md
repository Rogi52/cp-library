---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/number/fps.hpp
    title: src/number/fps.hpp
  - icon: ':x:'
    path: src/number/fps_sparse.hpp
    title: src/number/fps_sparse.hpp
  - icon: ':question:'
    path: src/number/ntt.hpp
    title: src/number/ntt.hpp
  - icon: ':x:'
    path: src/number/poly.hpp
    title: src/number/poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
    title: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/tree/rerooting.test.cpp
    title: verify/library_checker/graph/tree/rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/determinant.test.cpp
    title: verify/library_checker/matrix/determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/inverse.test.cpp
    title: verify/library_checker/matrix/inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/linear_equation.test.cpp
    title: verify/library_checker/matrix/linear_equation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/matrix/product.test.cpp
    title: verify/library_checker/matrix/product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_composition.test.cpp
    title: verify/library_checker/number/fps_composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_exp.test.cpp
    title: verify/library_checker/number/fps_exp.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_exp_sparse.test.cpp
    title: verify/library_checker/number/fps_exp_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_inv.test.cpp
    title: verify/library_checker/number/fps_inv.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_inv_sparse.test.cpp
    title: verify/library_checker/number/fps_inv_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_log.test.cpp
    title: verify/library_checker/number/fps_log.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_log_sparse.test.cpp
    title: verify/library_checker/number/fps_log_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_pow.test.cpp
    title: verify/library_checker/number/fps_pow.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_pow_sparse.test.cpp
    title: verify/library_checker/number/fps_pow_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_sqrt.test.cpp
    title: verify/library_checker/number/fps_sqrt.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_sqrt_sparse.test.cpp
    title: verify/library_checker/number/fps_sqrt_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/gcd_convolution.test.cpp
    title: verify/library_checker/number/gcd_convolution.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/lcm_convolution.test.cpp
    title: verify/library_checker/number/lcm_convolution.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/poly_all_product.test.cpp
    title: verify/library_checker/number/poly_all_product.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/poly_division.test.cpp
    title: verify/library_checker/number/poly_division.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/poly_taylor_shift.test.cpp
    title: verify/library_checker/number/poly_taylor_shift.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root,\
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
    \ r.v; }\n    bool operator!=(const modint& r) const { return v != r.v; }\n  \
    \  static uint get_mod() { return mod; }\n    static int is_prime() { return isprime;\
    \ }\n};\nconstexpr modinfo base998244353 { 998244353, 3, 1 };\nconstexpr modinfo\
    \ base1000000007 { 1000000007, 0, 1 };\nusing mint998244353 = modint< base998244353\
    \ >;\nusing mint1000000007 = modint< base1000000007 >;\n"
  code: "#pragma once\nstruct modinfo { uint mod, root, isprime; };\ntemplate < modinfo\
    \ const &ref >\nstruct modint {\n    static constexpr uint const &mod = ref.mod;\n\
    \    static constexpr uint const &root = ref.root;\n    static constexpr uint\
    \ const &isprime = ref.isprime;\n    uint v = 0;\n    constexpr modint& s(uint\
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
    \ const { return v != r.v; }\n    static uint get_mod() { return mod; }\n    static\
    \ int is_prime() { return isprime; }\n};\nconstexpr modinfo base998244353 { 998244353,\
    \ 3, 1 };\nconstexpr modinfo base1000000007 { 1000000007, 0, 1 };\nusing mint998244353\
    \ = modint< base998244353 >;\nusing mint1000000007 = modint< base1000000007 >;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/modint.hpp
  requiredBy:
  - src/number/ntt.hpp
  - src/number/poly.hpp
  - src/number/fps.hpp
  - src/number/fps_sparse.hpp
  timestamp: '2023-10-24 23:33:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/graph/tree/rerooting.test.cpp
  - verify/library_checker/number/fps_inv_sparse.test.cpp
  - verify/library_checker/number/fps_sqrt.test.cpp
  - verify/library_checker/number/fps_log.test.cpp
  - verify/library_checker/number/fps_pow.test.cpp
  - verify/library_checker/number/fps_pow_sparse.test.cpp
  - verify/library_checker/number/fps_sqrt_sparse.test.cpp
  - verify/library_checker/number/fps_composition.test.cpp
  - verify/library_checker/number/gcd_convolution.test.cpp
  - verify/library_checker/number/fps_inv.test.cpp
  - verify/library_checker/number/lcm_convolution.test.cpp
  - verify/library_checker/number/fps_exp_sparse.test.cpp
  - verify/library_checker/number/poly_division.test.cpp
  - verify/library_checker/number/poly_taylor_shift.test.cpp
  - verify/library_checker/number/fps_log_sparse.test.cpp
  - verify/library_checker/number/fps_exp.test.cpp
  - verify/library_checker/number/poly_all_product.test.cpp
  - verify/library_checker/matrix/determinant.test.cpp
  - verify/library_checker/matrix/linear_equation.test.cpp
  - verify/library_checker/matrix/inverse.test.cpp
  - verify/library_checker/matrix/product.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  - verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
documentation_of: src/number/modint.hpp
layout: document
title: modint
---

自動でmodを取る構造体
