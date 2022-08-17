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
  bundledCode: "#line 1 \"src/algebra/all.hpp\"\nnamespace algebra {\n\ntemplate <\
    \ class T > class PLUS {\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T &l, const T &r) { return l + r; }\n    static constexpr T id =\
    \ T(0);\n    static constexpr T inv(const T &x) { return -x; }\n    static constexpr\
    \ T pow(const T &x, const int n) { return x * n; }\n    static constexpr bool\
    \ comm = true;\n};\n\ntemplate < class T > class XOR {\n  public:\n    using set\
    \ = T;\n    static constexpr T op(const T &l, const T &r) { return l ^ r; }\n\
    \    static constexpr T id = T(0);\n    static constexpr T inv(const T &x) { return\
    \ x; }\n    static constexpr T pow(const T &x, const int n) { return n & 1 ? x\
    \ : 0; }\n    static constexpr bool comm = true;\n};\n\n}\n"
  code: "namespace algebra {\n\ntemplate < class T > class PLUS {\n  public:\n   \
    \ using set = T;\n    static constexpr T op(const T &l, const T &r) { return l\
    \ + r; }\n    static constexpr T id = T(0);\n    static constexpr T inv(const\
    \ T &x) { return -x; }\n    static constexpr T pow(const T &x, const int n) {\
    \ return x * n; }\n    static constexpr bool comm = true;\n};\n\ntemplate < class\
    \ T > class XOR {\n  public:\n    using set = T;\n    static constexpr T op(const\
    \ T &l, const T &r) { return l ^ r; }\n    static constexpr T id = T(0);\n   \
    \ static constexpr T inv(const T &x) { return x; }\n    static constexpr T pow(const\
    \ T &x, const int n) { return n & 1 ? x : 0; }\n    static constexpr bool comm\
    \ = true;\n};\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/all.hpp
  requiredBy: []
  timestamp: '2022-05-28 14:10:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/all.hpp
layout: document
redirect_from:
- /library/src/algebra/all.hpp
- /library/src/algebra/all.hpp.html
title: src/algebra/all.hpp
---
