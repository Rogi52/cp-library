---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/affine.hpp
    title: src/algebra/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/cartesian_product_monoid.hpp
    title: src/algebra/cartesian_product_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ < class T > constexpr affine< T > affine_composite_monoid< T >::id;\n#line 1\
    \ \"src/algebra/cartesian_product_monoid.hpp\"\ntemplate < class M, class N >\
    \ class cartesian_product_monoid {\n    using T = pair< typename M::set, typename\
    \ N::set >;\n  public:\n    using set = T;\n    static constexpr T op(const T\
    \ &l, const T &r) {\n        return T(M::op(l.first, r.first), N::op(l.second,\
    \ r.second));\n    }\n    static constexpr T id{M::id, N::id};\n};\n#line 1 \"\
    src/algebra/plus.hpp\"\ntemplate < class T > class PLUS {\n   public:\n     using\
    \ set = T;\n     static constexpr T op(const T &l, const T &r) { return l + r;\
    \ }\n     static constexpr T id = T(0);\n     static constexpr T inv(const T &x)\
    \ { return -x; }\n     static constexpr T pow(const T &x, const int n) { return\
    \ x * n; }\n     static constexpr bool comm = true;\n };\n#line 4 \"src/algebra/range_affine_range_sum.hpp\"\
    \n\ntemplate < class T > class range_affine_range_sum {\n  public:\n    using\
    \ value_structure = cartesian_product_monoid< PLUS< T >, PLUS< T > >;\n    using\
    \ operator_structure = affine_composite_monoid< T >;\n  private:\n    using S\
    \ = typename value_structure::set;\n    using F = typename operator_structure::set;\n\
    \  public:\n    static constexpr S op(const S &l, const F &r) {\n        return\
    \ S(l.first * r.a + l.second * r.b, l.second);\n    }\n};\n"
  code: "#include \"src/algebra/affine.hpp\"\n#include \"src/algebra/cartesian_product_monoid.hpp\"\
    \n#include \"src/algebra/plus.hpp\"\n\ntemplate < class T > class range_affine_range_sum\
    \ {\n  public:\n    using value_structure = cartesian_product_monoid< PLUS< T\
    \ >, PLUS< T > >;\n    using operator_structure = affine_composite_monoid< T >;\n\
    \  private:\n    using S = typename value_structure::set;\n    using F = typename\
    \ operator_structure::set;\n  public:\n    static constexpr S op(const S &l, const\
    \ F &r) {\n        return S(l.first * r.a + l.second * r.b, l.second);\n    }\n\
    };\n"
  dependsOn:
  - src/algebra/affine.hpp
  - src/algebra/cartesian_product_monoid.hpp
  - src/algebra/plus.hpp
  isVerificationFile: false
  path: src/algebra/range_affine_range_sum.hpp
  requiredBy: []
  timestamp: '2023-03-26 20:47:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
documentation_of: src/algebra/range_affine_range_sum.hpp
layout: document
redirect_from:
- /library/src/algebra/range_affine_range_sum.hpp
- /library/src/algebra/range_affine_range_sum.hpp.html
title: src/algebra/range_affine_range_sum.hpp
---
