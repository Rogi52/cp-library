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
  bundledCode: "#line 1 \"src/algebra/set_monoid.hpp\"\ntemplate < class T, T none\
    \ = T(-1) >\nstruct set_monoid {\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T& l, const T& r) { return (r == none ? l : r); }\n    static constexpr\
    \ T id() { return none; }\n    static constexpr bool comm = false;\n};\n"
  code: "template < class T, T none = T(-1) >\nstruct set_monoid {\n  public:\n  \
    \  using set = T;\n    static constexpr T op(const T& l, const T& r) { return\
    \ (r == none ? l : r); }\n    static constexpr T id() { return none; }\n    static\
    \ constexpr bool comm = false;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algebra/set_monoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algebra/set_monoid.hpp
layout: document
redirect_from:
- /library/src/algebra/set_monoid.hpp
- /library/src/algebra/set_monoid.hpp.html
title: src/algebra/set_monoid.hpp
---
