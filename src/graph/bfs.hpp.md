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
  bundledCode: "#line 1 \"src/graph/bfs.hpp\"\nvector<int> bfs(vector<vector<int>>\
    \ &graph, int s) {\n    int INF = numeric_limits<int>::max();\n    vector<int>\
    \ dist(graph.size(), INF);\n    queue<int> q;\n    dist[s] = 0, q.push(s);\n \
    \   while(!q.empty()){\n        int u = q.front(); q.pop();\n        for(int v\
    \ : graph[u]) if(dist[v] == INF)\n            dist[v] = dist[u] + 1, q.push(v);\n\
    \    }\n    return dist;\n}\n"
  code: "vector<int> bfs(vector<vector<int>> &graph, int s) {\n    int INF = numeric_limits<int>::max();\n\
    \    vector<int> dist(graph.size(), INF);\n    queue<int> q;\n    dist[s] = 0,\
    \ q.push(s);\n    while(!q.empty()){\n        int u = q.front(); q.pop();\n  \
    \      for(int v : graph[u]) if(dist[v] == INF)\n            dist[v] = dist[u]\
    \ + 1, q.push(v);\n    }\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy: []
  timestamp: '2022-10-02 19:03:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---
