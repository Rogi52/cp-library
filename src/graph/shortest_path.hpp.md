---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/shortest_path.hpp\"\n// g <- pair < v , cost >\
    \ \ntemplate < class T >\nvector< T > dijkstra(vector<vector<pair<int, T>>> &graph,\
    \ int s) {\n    T INF = numeric_limits< T >::max();\n    vector<T> dist(graph.size(),\
    \ INF);\n    priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>>\
    \ q;\n    q.push({dist[s] = T(0), s});\n    while(!q.empty()){\n        auto [uc,\
    \ ui] = q.top(); q.pop();\n        if(uc != dist[ui]) continue;\n        for(auto\
    \ [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) \n            q.push({dist[vi]\
    \ = uc + vc, vi});\n    }\n    return dist;\n}\n\n// g <- pair < v , cost > \n\
    template < class T >\nvector< T > dijkstra(vector<vector<pair<int, T>>> &graph,\
    \ vector<int> &starts) {\n    T INF = numeric_limits< T >::max();\n    vector<T>\
    \ dist(graph.size(), INF);\n    priority_queue<pair<T,int>, vector<pair<T,int>>,\
    \ greater<pair<T,int>>> q;\n    for(int s : starts) q.push({dist[s] = T(0), s});\n\
    \    while(!q.empty()){\n        auto [uc, ui] = q.top(); q.pop();\n        if(uc\
    \ != dist[ui]) continue;\n        for(auto [vi, vc] : graph[ui]) if(dist[vi] >\
    \ uc + vc) \n            q.push({dist[vi] = uc + vc, vi});\n    }\n    return\
    \ dist;\n}\n\n// g <- pair < v , cost > \ntemplate < class T >\npair< T, vector<int>\
    \ > shortest_path(vector<vector<pair<int, T>>> &graph, int s, int t) {\n    T\
    \ INF = numeric_limits< T >::max();\n    vector<T> dist(graph.size(), INF);\n\
    \    vector<int> prev(graph.size(), -1);\n    priority_queue<pair<T,int>, vector<pair<T,int>>,\
    \ greater<pair<T,int>>> q;\n    q.push({dist[s] = T(0), s});\n    while(!q.empty()){\n\
    \        auto [uc, ui] = q.top(); q.pop();\n        if(uc != dist[ui]) continue;\n\
    \        for(auto [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) \n            q.push({dist[vi]\
    \ = uc + vc, vi}), prev[vi] = ui;\n    }\n\n    vector<int> path;\n    if(dist[t]\
    \ != INF) {\n        for(int v = t; v != -1; v = prev[v]) path.push_back(v);\n\
    \        reverse(path.begin(), path.end());\n    }\n    return {dist[t], path};\n\
    }\n"
  code: "// g <- pair < v , cost > \ntemplate < class T >\nvector< T > dijkstra(vector<vector<pair<int,\
    \ T>>> &graph, int s) {\n    T INF = numeric_limits< T >::max();\n    vector<T>\
    \ dist(graph.size(), INF);\n    priority_queue<pair<T,int>, vector<pair<T,int>>,\
    \ greater<pair<T,int>>> q;\n    q.push({dist[s] = T(0), s});\n    while(!q.empty()){\n\
    \        auto [uc, ui] = q.top(); q.pop();\n        if(uc != dist[ui]) continue;\n\
    \        for(auto [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) \n            q.push({dist[vi]\
    \ = uc + vc, vi});\n    }\n    return dist;\n}\n\n// g <- pair < v , cost > \n\
    template < class T >\nvector< T > dijkstra(vector<vector<pair<int, T>>> &graph,\
    \ vector<int> &starts) {\n    T INF = numeric_limits< T >::max();\n    vector<T>\
    \ dist(graph.size(), INF);\n    priority_queue<pair<T,int>, vector<pair<T,int>>,\
    \ greater<pair<T,int>>> q;\n    for(int s : starts) q.push({dist[s] = T(0), s});\n\
    \    while(!q.empty()){\n        auto [uc, ui] = q.top(); q.pop();\n        if(uc\
    \ != dist[ui]) continue;\n        for(auto [vi, vc] : graph[ui]) if(dist[vi] >\
    \ uc + vc) \n            q.push({dist[vi] = uc + vc, vi});\n    }\n    return\
    \ dist;\n}\n\n// g <- pair < v , cost > \ntemplate < class T >\npair< T, vector<int>\
    \ > shortest_path(vector<vector<pair<int, T>>> &graph, int s, int t) {\n    T\
    \ INF = numeric_limits< T >::max();\n    vector<T> dist(graph.size(), INF);\n\
    \    vector<int> prev(graph.size(), -1);\n    priority_queue<pair<T,int>, vector<pair<T,int>>,\
    \ greater<pair<T,int>>> q;\n    q.push({dist[s] = T(0), s});\n    while(!q.empty()){\n\
    \        auto [uc, ui] = q.top(); q.pop();\n        if(uc != dist[ui]) continue;\n\
    \        for(auto [vi, vc] : graph[ui]) if(dist[vi] > uc + vc) \n            q.push({dist[vi]\
    \ = uc + vc, vi}), prev[vi] = ui;\n    }\n\n    vector<int> path;\n    if(dist[t]\
    \ != INF) {\n        for(int v = t; v != -1; v = prev[v]) path.push_back(v);\n\
    \        reverse(path.begin(), path.end());\n    }\n    return {dist[t], path};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/shortest_path.hpp
  requiredBy: []
  timestamp: '2022-05-05 17:09:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: src/graph/shortest_path.hpp
layout: document
redirect_from:
- /library/src/graph/shortest_path.hpp
- /library/src/graph/shortest_path.hpp.html
title: src/graph/shortest_path.hpp
---
