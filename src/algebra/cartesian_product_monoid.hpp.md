---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_affine_range_sum.hpp
    title: src/algebra/range_affine_range_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algebra/cartesian_product_monoid.hpp\"\ntemplate < class\
    \ M, class N > class cartesian_product_monoid {\n    using T = pair< typename\
    \ M::set, typename N::set >;\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T &l, const T &r) {\n        return T(M::op(l.first, r.first), N::op(l.second,\
    \ r.second));\n    }\n    static constexpr T id() { return T(M::id(), N::id());\
    \ }\n};\n"
  code: "template < class M, class N > class cartesian_product_monoid {\n    using\
    \ T = pair< typename M::set, typename N::set >;\n  public:\n    using set = T;\n\
    \    static constexpr T op(const T &l, const T &r) {\n        return T(M::op(l.first,\
    \ r.first), N::op(l.second, r.second));\n    }\n    static constexpr T id() {\
    \ return T(M::id(), N::id()); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/cartesian_product_monoid.hpp
  requiredBy:
  - src/algebra/range_affine_range_sum.hpp
  timestamp: '2023-10-14 00:28:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
documentation_of: src/algebra/cartesian_product_monoid.hpp
layout: document
redirect_from:
- /library/src/algebra/cartesian_product_monoid.hpp
- /library/src/algebra/cartesian_product_monoid.hpp.html
title: src/algebra/cartesian_product_monoid.hpp
---
