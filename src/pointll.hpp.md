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
  bundledCode: "#line 1 \"src/pointll.hpp\"\nstruct pointll {\n    ll x,y;\n    pointll(ll\
    \ x = 0, ll y = 0) : x(x), y(y) {}\n    bool operator==(pointll p) const { return\
    \ x == p.x && y == p.y; }\n};\n\nll det(pointll p, pointll q) { return p.x * q.y\
    \ - p.y * q.x; }\nll dot(pointll p, pointll q) { return p.x * q.x + p.y * q.y;\
    \ }\n"
  code: "struct pointll {\n    ll x,y;\n    pointll(ll x = 0, ll y = 0) : x(x), y(y)\
    \ {}\n    bool operator==(pointll p) const { return x == p.x && y == p.y; }\n\
    };\n\nll det(pointll p, pointll q) { return p.x * q.y - p.y * q.x; }\nll dot(pointll\
    \ p, pointll q) { return p.x * q.x + p.y * q.y; }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/pointll.hpp
  requiredBy: []
  timestamp: '2023-03-31 03:17:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/pointll.hpp
layout: document
redirect_from:
- /library/src/pointll.hpp
- /library/src/pointll.hpp.html
title: src/pointll.hpp
---
