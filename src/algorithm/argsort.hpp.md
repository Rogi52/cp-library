---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/convex_hull.hpp
    title: src/geometry/convex_hull.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/argsort.hpp\"\ntemplate < class T > vector<\
    \ int > argsort(vector< T > &a) {\n    vector< int > ids((int)a.size());\n   \
    \ iota(ids.begin(), ids.end(), 0);\n    sort(ids.begin(), ids.end(), [&](int i,\
    \ int j) {\n        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n\
    \    return ids;\n}\n"
  code: "template < class T > vector< int > argsort(vector< T > &a) {\n    vector<\
    \ int > ids((int)a.size());\n    iota(ids.begin(), ids.end(), 0);\n    sort(ids.begin(),\
    \ ids.end(), [&](int i, int j) {\n        return a[i] < a[j] || (a[i] == a[j]\
    \ && i < j);\n    });\n    return ids;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/argsort.hpp
  requiredBy:
  - src/geometry/convex_hull.hpp
  timestamp: '2022-03-21 11:27:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/argsort.hpp
layout: document
redirect_from:
- /library/src/algorithm/argsort.hpp
- /library/src/algorithm/argsort.hpp.html
title: src/algorithm/argsort.hpp
---
