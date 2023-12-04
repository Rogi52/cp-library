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
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/cartesian_product_monoid.hpp
layout: document
redirect_from:
- /library/src/algebra/cartesian_product_monoid.hpp
- /library/src/algebra/cartesian_product_monoid.hpp.html
title: src/algebra/cartesian_product_monoid.hpp
---
