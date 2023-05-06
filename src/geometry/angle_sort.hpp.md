---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/geometry/angle_sort.test.cpp
    title: verify/library_checker/geometry/angle_sort.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/geometry/angle_sort.hpp\"\nvector<int> angle_argsort(const\
    \ vector<pointll>& P) {\n    vector<int> lower, origin, upper;\n    pointll O(0,\
    \ 0);\n    rep(i,int(P.size())) {\n        if(P[i] == O)\n            origin.push_back(i);\n\
    \        else if(P[i].y < 0 || (P[i].y == 0 && P[i].x > 0))\n            lower\
    \ .push_back(i);\n        else\n            upper .push_back(i);\n    }\n    sort(lower.begin(),\
    \ lower.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    sort(upper.begin(),\
    \ upper.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    vector<int>\
    \ I;\n    I.insert(I.end(), lower .begin(), lower .end());\n    I.insert(I.end(),\
    \ origin.begin(), origin.end());\n    I.insert(I.end(), upper .begin(), upper\
    \ .end());\n    return I;\n}\n\nvoid angle_sort(vector<pointll>& P) {\n    auto\
    \ I = angle_argsort(P);\n    vector<pointll> Q(P.size());\n    rep(i,int(P.size()))\
    \ Q[i] = P[I[i]];\n    swap(P, Q);\n}\n"
  code: "vector<int> angle_argsort(const vector<pointll>& P) {\n    vector<int> lower,\
    \ origin, upper;\n    pointll O(0, 0);\n    rep(i,int(P.size())) {\n        if(P[i]\
    \ == O)\n            origin.push_back(i);\n        else if(P[i].y < 0 || (P[i].y\
    \ == 0 && P[i].x > 0))\n            lower .push_back(i);\n        else\n     \
    \       upper .push_back(i);\n    }\n    sort(lower.begin(), lower.end(), [&](int\
    \ i, int j) { return det(P[i], P[j]) > 0; });\n    sort(upper.begin(), upper.end(),\
    \ [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    vector<int> I;\n  \
    \  I.insert(I.end(), lower .begin(), lower .end());\n    I.insert(I.end(), origin.begin(),\
    \ origin.end());\n    I.insert(I.end(), upper .begin(), upper .end());\n    return\
    \ I;\n}\n\nvoid angle_sort(vector<pointll>& P) {\n    auto I = angle_argsort(P);\n\
    \    vector<pointll> Q(P.size());\n    rep(i,int(P.size())) Q[i] = P[I[i]];\n\
    \    swap(P, Q);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/angle_sort.hpp
  requiredBy: []
  timestamp: '2023-03-31 04:57:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/geometry/angle_sort.test.cpp
documentation_of: src/geometry/angle_sort.hpp
layout: document
redirect_from:
- /library/src/geometry/angle_sort.hpp
- /library/src/geometry/angle_sort.hpp.html
title: src/geometry/angle_sort.hpp
---
