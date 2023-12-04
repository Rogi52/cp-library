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
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\ntemplate < class T > class min_plus\
    \ {\n  public:\n    using set = T;\n    static constexpr T add(const T& l, const\
    \ T& r) { return std::min(l, r); }\n    static constexpr T id0 = numeric_limits<\
    \ T >::max();\n    static constexpr T mul(const T& l, const T& r) { return l +\
    \ r; }\n    static constexpr T id1 = T(0);\n};\n\ntemplate < class T > class max_min\
    \ {\n  public:\n    using set = T;\n    static constexpr T add(const T& l, const\
    \ T& r) { return std::max(l, r); }\n    static constexpr T id0 = -numeric_limits<\
    \ T >::max();\n    static constexpr T mul(const T& l, const T& r) { return std::min(l,\
    \ r); }\n    static constexpr T id1 = +numeric_limits< T >::max();\n};\n\ntemplate\
    \ < class closed_semiring, class F >\nvector< typename closed_semiring::set >\
    \ dijkstra(vector<vector<tuple<int, typename closed_semiring::set, int>>>& graph,\
    \ int s, const F& f) {\n    using CS = closed_semiring;\n    using T = typename\
    \ CS::set;\n    vector< T > dist(graph.size(), CS::id0);\n    using P = pair<\
    \ T, int >;\n    auto cmp = [&](const P& a, const P& b) {\n        if(a.first\
    \ != b.first) return CS::add(a.first, b.first) == b.first;\n        return a.second\
    \ < b.second;\n    };\n    priority_queue< P, vector< P >, decltype(cmp)> q(cmp);\n\
    \    q.push({dist[s] = CS::id1, s});\n    while(!q.empty()) {\n        auto [uc,\
    \ ui] = q.top(); q.pop();\n        if(uc != dist[ui]) continue;\n        for(auto\
    \ [vi, vc, id] : graph[ui]) {\n            T nd = CS::add(dist[vi], CS::mul(f(uc,\
    \ id), vc));\n            if(dist[vi] != nd) q.push({dist[vi] = nd, vi});\n  \
    \      }\n    }\n    return dist;\n}\n"
  code: "template < class T > class min_plus {\n  public:\n    using set = T;\n  \
    \  static constexpr T add(const T& l, const T& r) { return std::min(l, r); }\n\
    \    static constexpr T id0 = numeric_limits< T >::max();\n    static constexpr\
    \ T mul(const T& l, const T& r) { return l + r; }\n    static constexpr T id1\
    \ = T(0);\n};\n\ntemplate < class T > class max_min {\n  public:\n    using set\
    \ = T;\n    static constexpr T add(const T& l, const T& r) { return std::max(l,\
    \ r); }\n    static constexpr T id0 = -numeric_limits< T >::max();\n    static\
    \ constexpr T mul(const T& l, const T& r) { return std::min(l, r); }\n    static\
    \ constexpr T id1 = +numeric_limits< T >::max();\n};\n\ntemplate < class closed_semiring,\
    \ class F >\nvector< typename closed_semiring::set > dijkstra(vector<vector<tuple<int,\
    \ typename closed_semiring::set, int>>>& graph, int s, const F& f) {\n    using\
    \ CS = closed_semiring;\n    using T = typename CS::set;\n    vector< T > dist(graph.size(),\
    \ CS::id0);\n    using P = pair< T, int >;\n    auto cmp = [&](const P& a, const\
    \ P& b) {\n        if(a.first != b.first) return CS::add(a.first, b.first) ==\
    \ b.first;\n        return a.second < b.second;\n    };\n    priority_queue< P,\
    \ vector< P >, decltype(cmp)> q(cmp);\n    q.push({dist[s] = CS::id1, s});\n \
    \   while(!q.empty()) {\n        auto [uc, ui] = q.top(); q.pop();\n        if(uc\
    \ != dist[ui]) continue;\n        for(auto [vi, vc, id] : graph[ui]) {\n     \
    \       T nd = CS::add(dist[vi], CS::mul(f(uc, id), vc));\n            if(dist[vi]\
    \ != nd) q.push({dist[vi] = nd, vi});\n        }\n    }\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-04-14 04:12:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
