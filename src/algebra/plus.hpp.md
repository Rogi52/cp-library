---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/offline_multiset.hpp
    title: src/data_structure/offline_multiset.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/fenwick_tree.test.cpp
    title: verify/library_checker/data_structure/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algebra/plus.hpp\"\nnamespace algebra {\n\ntemplate\
    \ < class T > class PLUS {\n   public:\n     using set = T;\n     static constexpr\
    \ T op(const T &l, const T &r) { return l + r; }\n     static constexpr T id =\
    \ T(0);\n     static constexpr T inv(const T &x) { return -x; }\n     static constexpr\
    \ T pow(const T &x, const int n) { return x * n; }\n     static constexpr bool\
    \ comm = true;\n };\n  \n}\n"
  code: "namespace algebra {\n\ntemplate < class T > class PLUS {\n   public:\n  \
    \   using set = T;\n     static constexpr T op(const T &l, const T &r) { return\
    \ l + r; }\n     static constexpr T id = T(0);\n     static constexpr T inv(const\
    \ T &x) { return -x; }\n     static constexpr T pow(const T &x, const int n) {\
    \ return x * n; }\n     static constexpr bool comm = true;\n };\n  \n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/plus.hpp
  requiredBy:
  - src/data_structure/offline_multiset.hpp
  timestamp: '2022-05-28 14:10:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
documentation_of: src/algebra/plus.hpp
layout: document
redirect_from:
- /library/src/algebra/plus.hpp
- /library/src/algebra/plus.hpp.html
title: src/algebra/plus.hpp
---
