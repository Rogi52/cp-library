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
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/affine.hpp
layout: document
redirect_from:
- /library/src/algebra/affine.hpp
- /library/src/algebra/affine.hpp.html
title: src/algebra/affine.hpp
---
