---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest_path.hpp
    title: src/graph/shortest_path.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
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
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 1 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
    \ itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n\
    \    const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t)\
    \ {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 1 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
    \ < class T > operator T() {\n            T s; cin >> s; return s;\n        }\n\
    \    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n    \
    \    template < class T > operator vector< T >() {\n            vector< T > v(n);\n\
    \            for(T& x : v) cin >> x;\n            return v;\n        }\n    };\n\
    \    struct mat {\n        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n\
    \        template < class T > operator vector< vector< T > >() {\n           \
    \ vector m(h, vector< T >(w));\n            for(vector< T >& v : m) for(T& x :\
    \ v) cin >> x;\n            return m;\n        }\n    };\n    struct speedup {\n\
    \        speedup() {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n\
    \        }\n    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec\
    \ in(int n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return\
    \ scanner::mat(h, w); }\n\nnamespace printer {\n    void precision(int d) {\n\
    \        cout << fixed << setprecision(d);\n    }\n    void flush() {\n      \
    \  cout.flush();\n    }\n}\nint print() { cout << '\\n'; return 0; }\ntemplate\
    \ < class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T >& a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > >&\
    \ a) {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n\
    \    for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ?\
    \ ' ' : '\\n');\n    return 0;\n}\n#line 1 \"src/graph/shortest_path.hpp\"\n//\
    \ g <- pair < v , cost > \ntemplate < class T >\nvector< T > dijkstra(vector<vector<pair<int,\
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
    \ N >> M >> s >> t;\n    vector<vector<pair<int,ll>>> G(N);\n    for(int _ : rep(M))\
    \ {\n        int a,b,c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n\
    \    }\n\n    auto [dist, path] = shortest_path(G, s, t);\n    if(dist == numeric_limits<ll>::max())\
    \ {\n        cout << -1 << endl;\n    } else {\n        int n = path.size();\n\
    \        cout << dist << \" \" << n - 1 << endl;\n        for(int i : rep(n-1))\
    \ cout << path[i] << \" \" << path[i + 1] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/graph/shortest_path.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,M,s,t; cin >>\
    \ N >> M >> s >> t;\n    vector<vector<pair<int,ll>>> G(N);\n    for(int _ : rep(M))\
    \ {\n        int a,b,c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n\
    \    }\n\n    auto [dist, path] = shortest_path(G, s, t);\n    if(dist == numeric_limits<ll>::max())\
    \ {\n        cout << -1 << endl;\n    } else {\n        int n = path.size();\n\
    \        cout << dist << \" \" << n - 1 << endl;\n        for(int i : rep(n-1))\
    \ cout << path[i] << \" \" << path[i + 1] << '\\n';\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/graph/shortest_path.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:51:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
