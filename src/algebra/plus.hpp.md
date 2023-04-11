---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_affine_range_sum.hpp
    title: src/algebra/range_affine_range_sum.hpp
  - icon: ':warning:'
    path: src/data_structure/offline_multiset.hpp
    title: src/data_structure/offline_multiset.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/fenwick_tree.test.cpp
    title: verify/library_checker/data_structure/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algebra/plus.hpp\"\ntemplate < class T > class PLUS\
    \ {\n  public:\n    using set = T;\n    static constexpr T op(const T &l, const\
    \ T &r) { return l + r; }\n    static constexpr T id = T(0);\n    static constexpr\
    \ T inv(const T &x) { return -x; }\n    static constexpr T pow(const T &x, const\
    \ int n) { return x * n; }\n    static constexpr bool comm = true;\n};\n"
  code: "template < class T > class PLUS {\n  public:\n    using set = T;\n    static\
    \ constexpr T op(const T &l, const T &r) { return l + r; }\n    static constexpr\
    \ T id = T(0);\n    static constexpr T inv(const T &x) { return -x; }\n    static\
    \ constexpr T pow(const T &x, const int n) { return x * n; }\n    static constexpr\
    \ bool comm = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/plus.hpp
  requiredBy:
  - src/data_structure/offline_multiset.hpp
  - src/algebra/range_affine_range_sum.hpp
  timestamp: '2023-03-26 22:09:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
documentation_of: src/algebra/plus.hpp
layout: document
redirect_from:
- /library/src/algebra/plus.hpp
- /library/src/algebra/plus.hpp.html
title: src/algebra/plus.hpp
---
