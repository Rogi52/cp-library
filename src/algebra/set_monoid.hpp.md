---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_update_range_minmax.hpp
    title: src/algebra/range_update_range_minmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_update_range_sum.hpp
    title: src/algebra/range_update_range_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/range_update_range_min.test.cpp
    title: verify/aoj/data_structure/range_update_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/range_update_range_sum.test.cpp
    title: verify/aoj/data_structure/range_update_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy:
  - src/algebra/range_update_range_sum.hpp
  - src/algebra/range_update_range_minmax.hpp
  timestamp: '2023-10-14 00:28:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/data_structure/range_update_range_min.test.cpp
  - verify/aoj/data_structure/range_update_range_sum.test.cpp
documentation_of: src/algebra/set_monoid.hpp
layout: document
redirect_from:
- /library/src/algebra/set_monoid.hpp
- /library/src/algebra/set_monoid.hpp.html
title: src/algebra/set_monoid.hpp
---
