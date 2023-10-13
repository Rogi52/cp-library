---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_affine_range_sum.hpp
    title: src/algebra/range_affine_range_sum.hpp
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algebra/affine.hpp\"\ntemplate < class T > class affine\
    \ {\n  public:\n    T a, b; // ax + b\n    constexpr affine() = default;\n   \
    \ constexpr affine(const T &a, const T &b) : a(a), b(b) {}\n    constexpr T eval(const\
    \ T &x) const { return x * a + b; }\n    constexpr affine composite(const affine\
    \ &r) const {\n        return affine(a * r.a, b * r.a + r.b);\n    }\n    static\
    \ constexpr affine id() {\n        return affine(T(1), T(0));\n    }\n};\n\ntemplate\
    \ < class T > class affine_composite_monoid {\n  public:\n    using F = affine<\
    \ T >;\n    using set = F;\n    static constexpr F op(const F &l, const F &r)\
    \ { return l.composite(r); }\n    static constexpr F id() { return F::id(); }\n\
    };\n"
  code: "template < class T > class affine {\n  public:\n    T a, b; // ax + b\n \
    \   constexpr affine() = default;\n    constexpr affine(const T &a, const T &b)\
    \ : a(a), b(b) {}\n    constexpr T eval(const T &x) const { return x * a + b;\
    \ }\n    constexpr affine composite(const affine &r) const {\n        return affine(a\
    \ * r.a, b * r.a + r.b);\n    }\n    static constexpr affine id() {\n        return\
    \ affine(T(1), T(0));\n    }\n};\n\ntemplate < class T > class affine_composite_monoid\
    \ {\n  public:\n    using F = affine< T >;\n    using set = F;\n    static constexpr\
    \ F op(const F &l, const F &r) { return l.composite(r); }\n    static constexpr\
    \ F id() { return F::id(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/affine.hpp
  requiredBy:
  - src/algebra/range_affine_range_sum.hpp
  timestamp: '2023-10-14 00:28:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
documentation_of: src/algebra/affine.hpp
layout: document
redirect_from:
- /library/src/algebra/affine.hpp
- /library/src/algebra/affine.hpp.html
title: src/algebra/affine.hpp
---
