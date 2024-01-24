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
  bundledCode: "#line 1 \"src/graph/eulerian_trail.hpp\"\ntemplate < class edge_type\
    \ > struct eulerian_trail {};\nnamespace edge_type {\n    struct directed;\n \
    \   struct undirected;\n}\n\ntemplate <> struct eulerian_trail< edge_type::directed\
    \ >  {\n    int n, m;\n    vector<vector<pair<int,int>>> g;\n    vector<vector<int>>\
    \ self;\n    vector<int> in_deg, out_deg;\n    int s_, t_, o_;\n    eulerian_trail()\
    \ = default;\n    eulerian_trail(int n) : n(n), m(0), g(n), self(n), in_deg(n,\
    \ 0), out_deg(n, 0), s_(-1), t_(-1), o_(-1) {}\n    \n    void add_edge(int u,\
    \ int v, int i) {\n        if(u == v) {\n            self[u].push_back(i);\n \
    \       } else {\n            g[u].emplace_back(v, i);\n        }\n        out_deg[u]++,\
    \ in_deg[v]++, m++;\n    }\n\n    bool valid() {\n        bool deg_ok = [&] {\n\
    \            int s = 0, t = 0, o = 0;\n            for(int v = 0; v < n; v++)\
    \ {\n                if(in_deg[v] + 1 == out_deg[v]    ) s++, s_ = v;\n      \
    \          if(in_deg[v]     == out_deg[v] + 1) t++, t_ = v;\n                if(in_deg[v]\
    \     == out_deg[v]    ) o++;\n            }\n            return (s == 1 and t\
    \ == 1 and o == n - 2) or (s == 0 and t == 0 and o == n);\n        }();\n\n  \
    \      bool cc_ok = [&] {\n            if(m == 0) return true;\n            union_find\
    \ uf(n);\n            for(int u = 0; u < n; u++) for(auto [v, i] : g[u]) uf.unite(u,\
    \ v);\n            vector<int> ec(n, 0);\n            for(int u = 0; u < n; u++)\
    \ ec[uf.root(u)] += g[u].size() + self[u].size();\n            int cnt = 0;\n\
    \            for(int u = 0; u < n; u++) if(uf.root(u) == u and ec[u] >= 1) cnt++,\
    \ o_ = u;\n            return cnt == 1;\n        }();\n\n        return deg_ok\
    \ and cc_ok;\n    }\n\n    pair<vector<int>, vector<int>> get() {\n        if(m\
    \ == 0) return {{0}, {}};\n        vector<int> vs, es;\n        vs.reserve(m +\
    \ 1);\n        es.reserve(m);\n        auto dfs = [&](auto sf, int u, int e) ->\
    \ void {\n            while(not g[u].empty()) {\n                auto [v, i] =\
    \ g[u].back(); g[u].pop_back();\n                sf(sf, v, i);\n            }\n\
    \            while(not self[u].empty()) {\n                es.push_back(self[u].back());\
    \ self[u].pop_back();\n                vs.push_back(u);\n            }\n     \
    \       if(e != -1) es.push_back(e);\n            vs.push_back(u);\n        };\
    \ dfs(dfs, s_ != -1 ? s_ : o_, -1);\n        reverse(vs.begin(), vs.end());\n\
    \        reverse(es.begin(), es.end());\n        return {vs, es};\n    }\n};\n\
    \ntemplate <> struct eulerian_trail< edge_type::undirected >  {\n    int n, m;\n\
    \    vector<vector<pair<int,int>>> g;\n    vector<vector<int>> self;\n    vector<int>\
    \ deg;\n    int s_, t_, o_;\n    eulerian_trail() = default;\n    eulerian_trail(int\
    \ n) : n(n), m(0), g(n), self(n), deg(n, 0), s_(-1), t_(-1), o_(-1) {}\n    \n\
    \    void add_edge(int u, int v, int i) {\n        if(u == v) {\n            self[u].push_back(i);\n\
    \        } else {\n            g[u].emplace_back(v, i);\n            g[v].emplace_back(u,\
    \ i);\n        }\n        deg[u]++, deg[v]++, m++;\n    }\n\n    bool valid()\
    \ {\n        bool deg_ok = [&] {\n            int odd = 0;\n            for(int\
    \ v = 0; v < n; v++) {\n                if(deg[v] % 2 == 1) odd++, s_ = v;\n \
    \           }\n            return (odd == 0) or (odd == 2);\n        }();\n\n\
    \        bool cc_ok = [&] {\n            if(m == 0) return true;\n           \
    \ union_find uf(n);\n            for(int u = 0; u < n; u++) for(auto [v, i] :\
    \ g[u]) uf.unite(u, v);\n            vector<int> ec(n, 0);\n            for(int\
    \ u = 0; u < n; u++) ec[uf.root(u)] += g[u].size() + self[u].size();\n       \
    \     int cnt = 0;\n            for(int u = 0; u < n; u++) if(uf.root(u) == u\
    \ and ec[u] >= 1) cnt++, o_ = u;\n            return cnt == 1;\n        }();\n\
    \n        return deg_ok and cc_ok;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ get() {\n        if(m == 0) return {{0}, {}};\n        vector<int> vs, es;\n\
    \        vs.reserve(m + 1);\n        es.reserve(m);\n        vector<int> erased(m,\
    \ 0);\n        auto dfs = [&](auto sf, int u, int e) -> void {\n            while(not\
    \ g[u].empty()) {\n                auto [v, i] = g[u].back(); g[u].pop_back();\n\
    \                if(erased[i]) continue;\n                erased[i] = 1;\n   \
    \             sf(sf, v, i);\n            }\n            while(not self[u].empty())\
    \ {\n                es.push_back(self[u].back()); self[u].pop_back();\n     \
    \           vs.push_back(u);\n            }\n            if(e != -1) es.push_back(e);\n\
    \            vs.push_back(u);\n        }; dfs(dfs, s_ != -1 ? s_ : o_, -1);\n\
    \        return {vs, es};\n    }\n};\n"
  code: "template < class edge_type > struct eulerian_trail {};\nnamespace edge_type\
    \ {\n    struct directed;\n    struct undirected;\n}\n\ntemplate <> struct eulerian_trail<\
    \ edge_type::directed >  {\n    int n, m;\n    vector<vector<pair<int,int>>> g;\n\
    \    vector<vector<int>> self;\n    vector<int> in_deg, out_deg;\n    int s_,\
    \ t_, o_;\n    eulerian_trail() = default;\n    eulerian_trail(int n) : n(n),\
    \ m(0), g(n), self(n), in_deg(n, 0), out_deg(n, 0), s_(-1), t_(-1), o_(-1) {}\n\
    \    \n    void add_edge(int u, int v, int i) {\n        if(u == v) {\n      \
    \      self[u].push_back(i);\n        } else {\n            g[u].emplace_back(v,\
    \ i);\n        }\n        out_deg[u]++, in_deg[v]++, m++;\n    }\n\n    bool valid()\
    \ {\n        bool deg_ok = [&] {\n            int s = 0, t = 0, o = 0;\n     \
    \       for(int v = 0; v < n; v++) {\n                if(in_deg[v] + 1 == out_deg[v]\
    \    ) s++, s_ = v;\n                if(in_deg[v]     == out_deg[v] + 1) t++,\
    \ t_ = v;\n                if(in_deg[v]     == out_deg[v]    ) o++;\n        \
    \    }\n            return (s == 1 and t == 1 and o == n - 2) or (s == 0 and t\
    \ == 0 and o == n);\n        }();\n\n        bool cc_ok = [&] {\n            if(m\
    \ == 0) return true;\n            union_find uf(n);\n            for(int u = 0;\
    \ u < n; u++) for(auto [v, i] : g[u]) uf.unite(u, v);\n            vector<int>\
    \ ec(n, 0);\n            for(int u = 0; u < n; u++) ec[uf.root(u)] += g[u].size()\
    \ + self[u].size();\n            int cnt = 0;\n            for(int u = 0; u <\
    \ n; u++) if(uf.root(u) == u and ec[u] >= 1) cnt++, o_ = u;\n            return\
    \ cnt == 1;\n        }();\n\n        return deg_ok and cc_ok;\n    }\n\n    pair<vector<int>,\
    \ vector<int>> get() {\n        if(m == 0) return {{0}, {}};\n        vector<int>\
    \ vs, es;\n        vs.reserve(m + 1);\n        es.reserve(m);\n        auto dfs\
    \ = [&](auto sf, int u, int e) -> void {\n            while(not g[u].empty())\
    \ {\n                auto [v, i] = g[u].back(); g[u].pop_back();\n           \
    \     sf(sf, v, i);\n            }\n            while(not self[u].empty()) {\n\
    \                es.push_back(self[u].back()); self[u].pop_back();\n         \
    \       vs.push_back(u);\n            }\n            if(e != -1) es.push_back(e);\n\
    \            vs.push_back(u);\n        }; dfs(dfs, s_ != -1 ? s_ : o_, -1);\n\
    \        reverse(vs.begin(), vs.end());\n        reverse(es.begin(), es.end());\n\
    \        return {vs, es};\n    }\n};\n\ntemplate <> struct eulerian_trail< edge_type::undirected\
    \ >  {\n    int n, m;\n    vector<vector<pair<int,int>>> g;\n    vector<vector<int>>\
    \ self;\n    vector<int> deg;\n    int s_, t_, o_;\n    eulerian_trail() = default;\n\
    \    eulerian_trail(int n) : n(n), m(0), g(n), self(n), deg(n, 0), s_(-1), t_(-1),\
    \ o_(-1) {}\n    \n    void add_edge(int u, int v, int i) {\n        if(u == v)\
    \ {\n            self[u].push_back(i);\n        } else {\n            g[u].emplace_back(v,\
    \ i);\n            g[v].emplace_back(u, i);\n        }\n        deg[u]++, deg[v]++,\
    \ m++;\n    }\n\n    bool valid() {\n        bool deg_ok = [&] {\n           \
    \ int odd = 0;\n            for(int v = 0; v < n; v++) {\n                if(deg[v]\
    \ % 2 == 1) odd++, s_ = v;\n            }\n            return (odd == 0) or (odd\
    \ == 2);\n        }();\n\n        bool cc_ok = [&] {\n            if(m == 0) return\
    \ true;\n            union_find uf(n);\n            for(int u = 0; u < n; u++)\
    \ for(auto [v, i] : g[u]) uf.unite(u, v);\n            vector<int> ec(n, 0);\n\
    \            for(int u = 0; u < n; u++) ec[uf.root(u)] += g[u].size() + self[u].size();\n\
    \            int cnt = 0;\n            for(int u = 0; u < n; u++) if(uf.root(u)\
    \ == u and ec[u] >= 1) cnt++, o_ = u;\n            return cnt == 1;\n        }();\n\
    \n        return deg_ok and cc_ok;\n    }\n\n    pair<vector<int>, vector<int>>\
    \ get() {\n        if(m == 0) return {{0}, {}};\n        vector<int> vs, es;\n\
    \        vs.reserve(m + 1);\n        es.reserve(m);\n        vector<int> erased(m,\
    \ 0);\n        auto dfs = [&](auto sf, int u, int e) -> void {\n            while(not\
    \ g[u].empty()) {\n                auto [v, i] = g[u].back(); g[u].pop_back();\n\
    \                if(erased[i]) continue;\n                erased[i] = 1;\n   \
    \             sf(sf, v, i);\n            }\n            while(not self[u].empty())\
    \ {\n                es.push_back(self[u].back()); self[u].pop_back();\n     \
    \           vs.push_back(u);\n            }\n            if(e != -1) es.push_back(e);\n\
    \            vs.push_back(u);\n        }; dfs(dfs, s_ != -1 ? s_ : o_, -1);\n\
    \        return {vs, es};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/eulerian_trail.hpp
  requiredBy: []
  timestamp: '2024-01-24 20:20:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/eulerian_trail.hpp
layout: document
redirect_from:
- /library/src/graph/eulerian_trail.hpp
- /library/src/graph/eulerian_trail.hpp.html
title: src/graph/eulerian_trail.hpp
---
