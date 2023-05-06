---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/algebra/range_affine_range_sum.hpp
    title: src/algebra/range_affine_range_sum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algebra/affine.hpp\"\ntemplate < class T > class affine\
    \ {\n  public:\n    T a, b;\n    constexpr affine() = default;\n    constexpr\
    \ affine(const T &a, const T &b) : a(a), b(b) {}\n    constexpr T eval(const T\
    \ &x) const { return x * a + b; }\n    constexpr affine composite(const affine\
    \ &r) const {\n        return affine(a * r.a, b * r.a + r.b);\n    }\n    static\
    \ constexpr affine id() {\n        return affine(T(1), T(0));\n    }\n};\n\ntemplate\
    \ < class T > class affine_composite_monoid {\n  public:\n    using F = affine<\
    \ T >;\n    using set = F;\n    static constexpr F op(const F &l, const F &r)\
    \ { return l.composite(r); }\n    static constexpr F id = F::id();\n};\ntemplate\
    \ < class T > constexpr affine< T > affine_composite_monoid< T >::id;\n"
  code: "template < class T > class affine {\n  public:\n    T a, b;\n    constexpr\
    \ affine() = default;\n    constexpr affine(const T &a, const T &b) : a(a), b(b)\
    \ {}\n    constexpr T eval(const T &x) const { return x * a + b; }\n    constexpr\
    \ affine composite(const affine &r) const {\n        return affine(a * r.a, b\
    \ * r.a + r.b);\n    }\n    static constexpr affine id() {\n        return affine(T(1),\
    \ T(0));\n    }\n};\n\ntemplate < class T > class affine_composite_monoid {\n\
    \  public:\n    using F = affine< T >;\n    using set = F;\n    static constexpr\
    \ F op(const F &l, const F &r) { return l.composite(r); }\n    static constexpr\
    \ F id = F::id();\n};\ntemplate < class T > constexpr affine< T > affine_composite_monoid<\
    \ T >::id;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/affine.hpp
  requiredBy:
  - src/algebra/range_affine_range_sum.hpp
  timestamp: '2023-03-26 14:34:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
documentation_of: src/algebra/affine.hpp
layout: document
redirect_from:
- /library/src/algebra/affine.hpp
- /library/src/algebra/affine.hpp.html
title: src/algebra/affine.hpp
---
