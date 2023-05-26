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
  bundledCode: "#line 1 \"src/graph/max_flow.hpp\"\ntemplate < class Cap > struct\
    \ mf_graph {\n  public:\n    explicit mf_graph(int n) : n(n), g(n) {}\n  \n  \
    \  int add_edge(int from, int to, Cap cap) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        assert(0 <= cap);\n    \
    \    int m = pos.size();\n        int from_id = g[from].size();\n        int to_id\
    \ = g[to].size() + (from == to);\n        g[from].push_back(_edge{to, to_id, cap});\n\
    \        g[to].push_back(_edge{from, from_id, 0});\n        return m;\n    }\n\
    \n    struct edge {\n        int from, to; Cap cap, flow;\n    };\n\n    edge\
    \ get_edge(int i) {\n        int m = pos.size();\n        assert(0 <= i and i\
    \ < m);\n        _edge e = g[pos[i].first][pos[i].second];\n        _edge r =\
    \ g[e.to][e.rev];\n        return edge{pos[i].first, e.to, e.cap + r.cap, r.cap};\n\
    \    }\n\n    vector<edge> edges() {\n        int m = pos.size();\n        vector<edge>\
    \ res(m);\n        for(int i : rep(m)) res[i] = get_edge(i);\n        return res;\n\
    \    }\n\n    void change_edge(int i, Cap cap, Cap flow) {\n        int m = pos.size();\n\
    \        assert(0 <= i and i < m);\n        assert(0 <= flow and flow <= cap);\n\
    \        _edge& e = g[pos[i].first][pos[i].second];\n        _edge& r = g[e.to][e.rev];\n\
    \        e.cap = cap - flow;\n        r.cap = flow;\n    }\n\n    Cap flow(int\
    \ s, int t, Cap flow_limit) {\n        assert(0 <= s and s < n);\n        assert(0\
    \ <= t and t < n);\n        assert(s != t);\n\n        vector<int> level(n), iter(n);\n\
    \        auto bfs = [&]() {\n            fill(level.begin(), level.end(), -1);\n\
    \            level[s] = 0;\n            queue<int> q;\n            q.push(s);\n\
    \            while(not q.empty()) {\n                int v = q.front(); q.pop();\n\
    \                for(_edge e : g[v]) {\n                    if(e.cap == 0 or level[e.to]\
    \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n         \
    \           if(e.to == t) return;\n                    q.push(e.to);\n       \
    \         }\n            }\n        };\n\n        auto dfs = [&](auto self, int\
    \ v, Cap up) {\n            if(v == s) return up;\n            Cap res = 0;\n\
    \            int level_v = level[v];\n            for(int& i = iter[v]; i < int(g[v].size());\
    \ i++) {\n                _edge& e = g[v][i];\n                if(level_v <= level[e.to]\
    \ or g[e.to][e.rev].cap == 0) continue;\n                Cap d = self(self, e.to,\
    \ min(up - res, g[e.to][e.rev].cap));\n                if(d <= 0) continue;\n\
    \                g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if(res == up) return res;\n      \
    \      }\n            level[v] = n;\n            return res;\n        };\n\n \
    \       Cap flow = 0;\n        while(flow < flow_limit) {\n            bfs();\n\
    \            if(level[t] == -1) break;\n            fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if(f ==\
    \ 0) break;\n            flow += f;\n        }\n        return flow;\n    }\n\n\
    \    Cap flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n\n    vector<int> min_cut(int s) {\n        vector<int> visited(n, 0);\n\
    \        queue<int> q;\n        q.push(s);\n        while(not q.empty()) {\n \
    \           int p = q.front(); q.pop();\n            visited[p] = 1;\n       \
    \     for(_edge e : g[p]) {\n                if(e.cap && not visited[e.to]) {\n\
    \                    visited[e.to] = 1;\n                    q.push(e.to);\n \
    \               }\n            }\n        }\n        return visited;\n    }\n\n\
    \  private:\n    int n;\n    struct _edge {\n        int to, rev; Cap cap;\n \
    \   };\n    vector<pair<int,int>> pos;\n    vector<vector<_edge>> g;\n};\n"
  code: "template < class Cap > struct mf_graph {\n  public:\n    explicit mf_graph(int\
    \ n) : n(n), g(n) {}\n  \n    int add_edge(int from, int to, Cap cap) {\n    \
    \    assert(0 <= from and from < n);\n        assert(0 <= to and to < n);\n  \
    \      assert(0 <= cap);\n        int m = pos.size();\n        int from_id = g[from].size();\n\
    \        int to_id = g[to].size() + (from == to);\n        g[from].push_back(_edge{to,\
    \ to_id, cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return\
    \ m;\n    }\n\n    struct edge {\n        int from, to; Cap cap, flow;\n    };\n\
    \n    edge get_edge(int i) {\n        int m = pos.size();\n        assert(0 <=\
    \ i and i < m);\n        _edge e = g[pos[i].first][pos[i].second];\n        _edge\
    \ r = g[e.to][e.rev];\n        return edge{pos[i].first, e.to, e.cap + r.cap,\
    \ r.cap};\n    }\n\n    vector<edge> edges() {\n        int m = pos.size();\n\
    \        vector<edge> res(m);\n        for(int i : rep(m)) res[i] = get_edge(i);\n\
    \        return res;\n    }\n\n    void change_edge(int i, Cap cap, Cap flow)\
    \ {\n        int m = pos.size();\n        assert(0 <= i and i < m);\n        assert(0\
    \ <= flow and flow <= cap);\n        _edge& e = g[pos[i].first][pos[i].second];\n\
    \        _edge& r = g[e.to][e.rev];\n        e.cap = cap - flow;\n        r.cap\
    \ = flow;\n    }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0\
    \ <= s and s < n);\n        assert(0 <= t and t < n);\n        assert(s != t);\n\
    \n        vector<int> level(n), iter(n);\n        auto bfs = [&]() {\n       \
    \     fill(level.begin(), level.end(), -1);\n            level[s] = 0;\n     \
    \       queue<int> q;\n            q.push(s);\n            while(not q.empty())\
    \ {\n                int v = q.front(); q.pop();\n                for(_edge e\
    \ : g[v]) {\n                    if(e.cap == 0 or level[e.to] >= 0) continue;\n\
    \                    level[e.to] = level[v] + 1;\n                    if(e.to\
    \ == t) return;\n                    q.push(e.to);\n                }\n      \
    \      }\n        };\n\n        auto dfs = [&](auto self, int v, Cap up) {\n \
    \           if(v == s) return up;\n            Cap res = 0;\n            int level_v\
    \ = level[v];\n            for(int& i = iter[v]; i < int(g[v].size()); i++) {\n\
    \                _edge& e = g[v][i];\n                if(level_v <= level[e.to]\
    \ or g[e.to][e.rev].cap == 0) continue;\n                Cap d = self(self, e.to,\
    \ min(up - res, g[e.to][e.rev].cap));\n                if(d <= 0) continue;\n\
    \                g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n\
    \                res += d;\n                if(res == up) return res;\n      \
    \      }\n            level[v] = n;\n            return res;\n        };\n\n \
    \       Cap flow = 0;\n        while(flow < flow_limit) {\n            bfs();\n\
    \            if(level[t] == -1) break;\n            fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if(f ==\
    \ 0) break;\n            flow += f;\n        }\n        return flow;\n    }\n\n\
    \    Cap flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n\n    vector<int> min_cut(int s) {\n        vector<int> visited(n, 0);\n\
    \        queue<int> q;\n        q.push(s);\n        while(not q.empty()) {\n \
    \           int p = q.front(); q.pop();\n            visited[p] = 1;\n       \
    \     for(_edge e : g[p]) {\n                if(e.cap && not visited[e.to]) {\n\
    \                    visited[e.to] = 1;\n                    q.push(e.to);\n \
    \               }\n            }\n        }\n        return visited;\n    }\n\n\
    \  private:\n    int n;\n    struct _edge {\n        int to, rev; Cap cap;\n \
    \   };\n    vector<pair<int,int>> pos;\n    vector<vector<_edge>> g;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/max_flow.hpp
  requiredBy: []
  timestamp: '2023-05-27 03:40:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/max_flow.hpp
layout: document
redirect_from:
- /library/src/graph/max_flow.hpp
- /library/src/graph/max_flow.hpp.html
title: src/graph/max_flow.hpp
---
