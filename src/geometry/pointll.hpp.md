---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/geometry/angle_sort.test.cpp
    title: verify/library_checker/geometry/angle_sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/geometry/pointll.hpp\"\nstruct pointll {\n    ll x,y;\n\
    \    pointll(ll x = 0, ll y = 0) : x(x), y(y) {}\n    bool operator==(pointll\
    \ p) const { return x == p.x && y == p.y; }\n};\n\nll det(pointll p, pointll q)\
    \ { return p.x * q.y - p.y * q.x; }\nll dot(pointll p, pointll q) { return p.x\
    \ * q.x + p.y * q.y; }\n"
  code: "struct pointll {\n    ll x,y;\n    pointll(ll x = 0, ll y = 0) : x(x), y(y)\
    \ {}\n    bool operator==(pointll p) const { return x == p.x && y == p.y; }\n\
    };\n\nll det(pointll p, pointll q) { return p.x * q.y - p.y * q.x; }\nll dot(pointll\
    \ p, pointll q) { return p.x * q.x + p.y * q.y; }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/pointll.hpp
  requiredBy: []
  timestamp: '2023-03-31 03:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/geometry/angle_sort.test.cpp
documentation_of: src/geometry/pointll.hpp
layout: document
redirect_from:
- /library/src/geometry/pointll.hpp
- /library/src/geometry/pointll.hpp.html
title: src/geometry/pointll.hpp
---
