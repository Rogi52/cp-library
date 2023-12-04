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
  bundledCode: "#line 1 \"src/graph/topological_sort.hpp\"\nvector<int> topo_sort(vector<vector<int>>\
    \ &G) {\n    int N = G.size();\n    vector<int> deg(N, 0), ord;\n    queue<int>\
    \ q;\n    rep(v,N) for(int to : G[v]) deg[to]++;\n    rep(v,N) if(deg[v] == 0)\
    \ q.push(v);\n    while(!q.empty()) {\n        int v = q.front(); q.pop(); ord.push_back(v);\n\
    \        for(int to : G[v]) if(--deg[to] == 0) q.push(to);\n    }\n    return\
    \ ord;\n}\n"
  code: "vector<int> topo_sort(vector<vector<int>> &G) {\n    int N = G.size();\n\
    \    vector<int> deg(N, 0), ord;\n    queue<int> q;\n    rep(v,N) for(int to :\
    \ G[v]) deg[to]++;\n    rep(v,N) if(deg[v] == 0) q.push(v);\n    while(!q.empty())\
    \ {\n        int v = q.front(); q.pop(); ord.push_back(v);\n        for(int to\
    \ : G[v]) if(--deg[to] == 0) q.push(to);\n    }\n    return ord;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: src/graph/topological_sort.hpp
---
