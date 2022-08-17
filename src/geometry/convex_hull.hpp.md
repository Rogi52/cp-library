---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  _extendedRequiredBy: []
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
    \    return ids;\n}\n#line 2 \"src/geometry/convex_hull.hpp\"\n\ntemplate < class\
    \ T >\npair< vector< int >, vector< pair< T, T > > > convex_hull(vector< pair<\
    \ T, T > > &points, string mode = \"full\", bool inclusive = false) {\n    assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\n    int n = points.size();\n\
    \    if(n == 1) return {{0}, {points[0]}};\n    if(n == 2) return {{0, 1}, {points[0],\
    \ points[1]}};\n    vector<int> I = argsort(points);\n\n    auto check = [&](int\
    \ i, int j, int k) {\n        auto [xi, yi] = points[i];\n        auto [xj, yj]\
    \ = points[j];\n        auto [xk, yk] = points[k];\n        T det = (xj - xi)\
    \ * (yk - yj) - (yj - yi) * (xk - xj);\n        return inclusive ? det >= 0 :\
    \ det > 0;\n    };\n\n    auto calc = [&]() {\n        vector<int> J;\n      \
    \  for(int k : I) {\n            while(J.size() >= 2 && !check(J[J.size() - 2],\
    \ J.back(), k)) J.pop_back();\n            J.push_back(k);\n        }\n      \
    \  return J;\n    };\n\n    vector<int> ids;\n    if(mode == \"full\" || mode\
    \ == \"lower\") {\n        vector<int> J = calc();\n        ids.insert(ids.end(),\
    \ J.begin(), J.end());\n    }\n    if(mode == \"full\" || mode == \"upper\") {\n\
    \        if(!ids.empty()) ids.pop_back();\n        reverse(I.begin(), I.end());\n\
    \        vector<int> J = calc();\n        ids.insert(ids.end(), J.begin(), J.end());\n\
    \    }\n    if(mode == \"upper\") reverse(ids.begin(), ids.end());\n    if(ids.size()\
    \ >= 2 && ids[0] == ids.back()) ids.pop_back();\n    vector< pair< T, T > > ch;\n\
    \    for(int i : ids) ch.push_back(points[i]);\n    return {ids, ch};\n}\n"
  code: "#include \"src/algorithm/argsort.hpp\"\n\ntemplate < class T >\npair< vector<\
    \ int >, vector< pair< T, T > > > convex_hull(vector< pair< T, T > > &points,\
    \ string mode = \"full\", bool inclusive = false) {\n    assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n    int n = points.size();\n  \
    \  if(n == 1) return {{0}, {points[0]}};\n    if(n == 2) return {{0, 1}, {points[0],\
    \ points[1]}};\n    vector<int> I = argsort(points);\n\n    auto check = [&](int\
    \ i, int j, int k) {\n        auto [xi, yi] = points[i];\n        auto [xj, yj]\
    \ = points[j];\n        auto [xk, yk] = points[k];\n        T det = (xj - xi)\
    \ * (yk - yj) - (yj - yi) * (xk - xj);\n        return inclusive ? det >= 0 :\
    \ det > 0;\n    };\n\n    auto calc = [&]() {\n        vector<int> J;\n      \
    \  for(int k : I) {\n            while(J.size() >= 2 && !check(J[J.size() - 2],\
    \ J.back(), k)) J.pop_back();\n            J.push_back(k);\n        }\n      \
    \  return J;\n    };\n\n    vector<int> ids;\n    if(mode == \"full\" || mode\
    \ == \"lower\") {\n        vector<int> J = calc();\n        ids.insert(ids.end(),\
    \ J.begin(), J.end());\n    }\n    if(mode == \"full\" || mode == \"upper\") {\n\
    \        if(!ids.empty()) ids.pop_back();\n        reverse(I.begin(), I.end());\n\
    \        vector<int> J = calc();\n        ids.insert(ids.end(), J.begin(), J.end());\n\
    \    }\n    if(mode == \"upper\") reverse(ids.begin(), ids.end());\n    if(ids.size()\
    \ >= 2 && ids[0] == ids.back()) ids.pop_back();\n    vector< pair< T, T > > ch;\n\
    \    for(int i : ids) ch.push_back(points[i]);\n    return {ids, ch};\n}\n"
  dependsOn:
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2022-03-21 11:29:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/src/geometry/convex_hull.hpp
- /library/src/geometry/convex_hull.hpp.html
title: src/geometry/convex_hull.hpp
---
