---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest_path.hpp
    title: src/graph/shortest_path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i =\
    \ 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld = long\
    \ double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\ntemplate\
    \ < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return\
    \ false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return\
    \ true; } return false; }\n#line 1 \"src/graph/shortest_path.hpp\"\n// g <- pair\
    \ < v , cost > \ntemplate < class T >\nvector< T > dijkstra(vector<vector<pair<int,\
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
    }\n#line 5 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,M,s,t; cin >>\
    \ N >> M >> s >> t;\n    vector<vector<pair<int,ll>>> G(N);\n    rep(_,M) {\n\
    \        int a,b,c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n   \
    \ }\n\n    auto [dist, path] = shortest_path(G, s, t);\n    if(dist == numeric_limits<ll>::max())\
    \ {\n        cout << -1 << endl;\n    } else {\n        int n = path.size();\n\
    \        cout << dist << \" \" << n - 1 << endl;\n        rep(i,n-1) cout << path[i]\
    \ << \" \" << path[i + 1] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/graph/shortest_path.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,M,s,t; cin >>\
    \ N >> M >> s >> t;\n    vector<vector<pair<int,ll>>> G(N);\n    rep(_,M) {\n\
    \        int a,b,c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n   \
    \ }\n\n    auto [dist, path] = shortest_path(G, s, t);\n    if(dist == numeric_limits<ll>::max())\
    \ {\n        cout << -1 << endl;\n    } else {\n        int n = path.size();\n\
    \        cout << dist << \" \" << n - 1 << endl;\n        rep(i,n-1) cout << path[i]\
    \ << \" \" << path[i + 1] << '\\n';\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/graph/shortest_path.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
