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
  bundledCode: "#line 1 \"src/algebra/xor.hpp\"\ntemplate < class T > class xor_monoid\
    \ {\n  public:\n    using set = T;\n    static constexpr T op(const T &l, const\
    \ T &r) { return l ^ r; }\n    static constexpr T id() { return T(0); }\n    static\
    \ constexpr T inv(const T &x) { return x; }\n    static constexpr T pow(const\
    \ T &x, const int n) { return n & 1 ? x : 0; }\n    static constexpr bool comm\
    \ = true;\n};\n"
  code: "template < class T > class xor_monoid {\n  public:\n    using set = T;\n\
    \    static constexpr T op(const T &l, const T &r) { return l ^ r; }\n    static\
    \ constexpr T id() { return T(0); }\n    static constexpr T inv(const T &x) {\
    \ return x; }\n    static constexpr T pow(const T &x, const int n) { return n\
    \ & 1 ? x : 0; }\n    static constexpr bool comm = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/xor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/xor.hpp
layout: document
redirect_from:
- /library/src/algebra/xor.hpp
- /library/src/algebra/xor.hpp.html
title: src/algebra/xor.hpp
---
