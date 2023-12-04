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
  bundledCode: "#line 1 \"src/graph/min_cost_flow.hpp\"\ntemplate < class Cap, class\
    \ Cost > struct mcf_graph {\n  public:\n    explicit mcf_graph(int n) : n(n) {}\n\
    \n    int add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(0 <=\
    \ from and from < n);\n        assert(0 <= to and to < n);\n        assert(0 <=\
    \ cap);\n        assert(0 <= cost);\n        int m = _edges.size();\n        _edges.push_back({from,\
    \ to, cap, 0, cost});\n        return m;\n    }\n\n    struct edge {\n       \
    \ int from, to;\n        Cap cap, flow;\n        Cost cost;\n    };\n\n    edge\
    \ get_edge(int i) {\n        int m = _edges.size();\n        assert(0 <= i and\
    \ i < m);\n        return _edges[i];\n    }\n\n    vector<edge> edges() { return\
    \ _edges; }\n\n    pair<Cap, Cost> flow(int s, int t) {\n        return flow(s,\
    \ t, numeric_limits<Cap>::max());\n    }\n    pair<Cap, Cost> flow(int s, int\
    \ t, Cap flow_limit) {\n        return slope(s, t, flow_limit).back();\n    }\n\
    \    vector<pair<Cap, Cost>> slope(int s, int t) {\n        return slope(s, t,\
    \ numeric_limits<Cap>::max());\n    }\n    vector<pair<Cap, Cost>> slope(int s,\
    \ int t, Cap flow_limit) {\n        assert(0 <= s and s < n);\n        assert(0\
    \ <= t and t < n);\n        assert(s != t);\n\n        int m = _edges.size();\n\
    \        vector<int> e_id(m);\n        auto g = [&]() {\n            vector<int>\
    \ degree(n), r_id(m);\n            vector<pair<int, _edge>> elist;\n         \
    \   elist.reserve(m + m);\n            for(int i : rep(m)) {\n               \
    \ edge e = _edges[i];\n                e_id[i] = degree[e.from]++;\n         \
    \       r_id[i] = degree[e.to]++;\n                elist.push_back({e.from, {e.to,\
    \ -1, e.cap - e.flow, e.cost}});\n                elist.push_back({e.to, {e.from,\
    \ -1, e.flow, -e.cost}});\n            }\n            csr<_edge> _g(n, elist);\n\
    \            for(int i : rep(m)) {\n                edge e = _edges[i];\n    \
    \            e_id[i] += _g.start[e.from];\n                r_id[i] += _g.start[e.to];\n\
    \                _g.elist[e_id[i]].rev = r_id[i];\n                _g.elist[r_id[i]].rev\
    \ = e_id[i];\n            }\n            return _g;\n        }();\n\n        auto\
    \ result = slope(g, s, t, flow_limit);\n        for(int i : rep(m)) {\n      \
    \      _edge e = g.elist[e_id[i]];\n            _edges[i].flow = _edges[i].cap\
    \ - e.cap;\n        }\n        return result;\n    }\n\n  private:\n    int n;\n\
    \    struct _edge {\n        int to, rev;\n        Cap cap;\n        Cost cost;\n\
    \    };\n    vector<edge> _edges;\n\n    template < class E > struct csr {\n \
    \       vector<int> start;\n        vector< E > elist;\n        explicit csr(int\
    \ n, const vector<pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {\n\
    \            for(auto e : edges) start[e.first + 1]++;\n            for(int i\
    \ = 1; i <= n; i++) start[i] += start[i - 1];\n            vector<int> counter\
    \ = start;\n            for(auto e : edges) elist[counter[e.first]++] = e.second;\n\
    \        }\n    };\n\n    vector<pair<Cap, Cost>> slope(csr<_edge>& g, int s,\
    \ int t, Cap flow_limit) {\n        // variants (C = maxcost):\n        // -(n-1)C\
    \ <= dual[s] <= dual[i] <= dual[t] = 0\n        // reduced cost (= e.cost + dual[e.from]\
    \ - dual[e.to]) >= 0 for all edge\n\n        // dual_dist[i] = (dual[i], dist[i])\n\
    \        vector<pair<Cost, Cost>> dual_dist(n);\n        vector<int> prev_e(n);\n\
    \        vector<bool> vis(n);\n        struct Q {\n            Cost key;\n   \
    \         int to;\n            bool operator<(Q r) const { return key > r.key;\
    \ }\n        };\n        vector<int> que_min;\n        vector< Q > que;\n    \
    \    auto dual_ref = [&]() {\n            for (int i : rep(n)) dual_dist[i].second\
    \ = numeric_limits<Cost>::max();\n            fill(vis.begin(), vis.end(), false);\n\
    \            que_min.clear();\n            que.clear();\n            size_t heap_r\
    \ = 0;\n            dual_dist[s].second = 0;\n            que_min.push_back(s);\n\
    \            while (not que_min.empty() or not que.empty()) {\n              \
    \  int v;\n                if (not que_min.empty()) {\n                    v =\
    \ que_min.back();\n                    que_min.pop_back();\n                }\
    \ else {\n                    while (heap_r < que.size()) {\n                \
    \        heap_r++;\n                        push_heap(que.begin(), que.begin()\
    \ + heap_r);\n                    }\n                    v = que.front().to;\n\
    \                    pop_heap(que.begin(), que.end());\n                    que.pop_back();\n\
    \                    heap_r--;\n                }\n                if (vis[v])\
    \ continue;\n                vis[v] = true;\n                if (v == t) break;\n\
    \                // dist[v] = shortest(s, v) + dual[s] - dual[v]\n           \
    \     // dist[v] >= 0 (all reduced cost are positive)\n                // dist[v]\
    \ <= (n-1)C\n                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             _edge e = g.elist[i];\n                    if (!e.cap) continue;\n\
    \                    // |-dual[e.to] + dual[v]| <= (n-1)C\n                  \
    \  // cost <= C - -(n-1)C + 0 = nC\n                    Cost cost = e.cost - dual_dist[e.to].first\
    \ + dual_v;\n                    if (dual_dist[e.to].second - dist_v > cost) {\n\
    \                        Cost dist_to = dist_v + cost;\n                     \
    \   dual_dist[e.to].second = dist_to;\n                        prev_e[e.to] =\
    \ e.rev;\n                        if (dist_to == dist_v) {\n                 \
    \           que_min.push_back(e.to);\n                        } else {\n     \
    \                       que.push_back(Q{dist_to, e.to});\n                   \
    \     }\n                    }\n                }\n            }\n           \
    \ if (!vis[t]) {\n                return false;\n            }\n\n           \
    \ for (int v = 0; v < n; v++) {\n                if (!vis[v]) continue;\n    \
    \            // dual[v] = dual[v] - dist[t] + dist[v]\n                //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n                // \
    \        (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,\n              \
    \  //         t) + dual[t] + shortest(s, v) = shortest(s, v) -\n             \
    \   //         shortest(s, t) >= 0 - (n-1)C\n                dual_dist[v].first\
    \ -= dual_dist[t].second - dual_dist[v].second;\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n     \
    \   while (flow < flow_limit) {\n            if (!dual_ref()) break;\n       \
    \     Cap c = flow_limit - flow;\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n                c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      \
    \      }\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n \
    \               auto& e = g.elist[prev_e[v]];\n                e.cap += c;\n \
    \               g.elist[e.rev].cap -= c;\n            }\n            Cost d =\
    \ -dual_dist[s].first;\n            flow += c;\n            cost += c * d;\n \
    \           if (prev_cost_per_flow == d) {\n                result.pop_back();\n\
    \            }\n            result.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return result;\n    }\n};\n"
  code: "template < class Cap, class Cost > struct mcf_graph {\n  public:\n    explicit\
    \ mcf_graph(int n) : n(n) {}\n\n    int add_edge(int from, int to, Cap cap, Cost\
    \ cost) {\n        assert(0 <= from and from < n);\n        assert(0 <= to and\
    \ to < n);\n        assert(0 <= cap);\n        assert(0 <= cost);\n        int\
    \ m = _edges.size();\n        _edges.push_back({from, to, cap, 0, cost});\n  \
    \      return m;\n    }\n\n    struct edge {\n        int from, to;\n        Cap\
    \ cap, flow;\n        Cost cost;\n    };\n\n    edge get_edge(int i) {\n     \
    \   int m = _edges.size();\n        assert(0 <= i and i < m);\n        return\
    \ _edges[i];\n    }\n\n    vector<edge> edges() { return _edges; }\n\n    pair<Cap,\
    \ Cost> flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n    pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n        return\
    \ slope(s, t, flow_limit).back();\n    }\n    vector<pair<Cap, Cost>> slope(int\
    \ s, int t) {\n        return slope(s, t, numeric_limits<Cap>::max());\n    }\n\
    \    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {\n        assert(0\
    \ <= s and s < n);\n        assert(0 <= t and t < n);\n        assert(s != t);\n\
    \n        int m = _edges.size();\n        vector<int> e_id(m);\n        auto g\
    \ = [&]() {\n            vector<int> degree(n), r_id(m);\n            vector<pair<int,\
    \ _edge>> elist;\n            elist.reserve(m + m);\n            for(int i : rep(m))\
    \ {\n                edge e = _edges[i];\n                e_id[i] = degree[e.from]++;\n\
    \                r_id[i] = degree[e.to]++;\n                elist.push_back({e.from,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n                elist.push_back({e.to,\
    \ {e.from, -1, e.flow, -e.cost}});\n            }\n            csr<_edge> _g(n,\
    \ elist);\n            for(int i : rep(m)) {\n                edge e = _edges[i];\n\
    \                e_id[i] += _g.start[e.from];\n                r_id[i] += _g.start[e.to];\n\
    \                _g.elist[e_id[i]].rev = r_id[i];\n                _g.elist[r_id[i]].rev\
    \ = e_id[i];\n            }\n            return _g;\n        }();\n\n        auto\
    \ result = slope(g, s, t, flow_limit);\n        for(int i : rep(m)) {\n      \
    \      _edge e = g.elist[e_id[i]];\n            _edges[i].flow = _edges[i].cap\
    \ - e.cap;\n        }\n        return result;\n    }\n\n  private:\n    int n;\n\
    \    struct _edge {\n        int to, rev;\n        Cap cap;\n        Cost cost;\n\
    \    };\n    vector<edge> _edges;\n\n    template < class E > struct csr {\n \
    \       vector<int> start;\n        vector< E > elist;\n        explicit csr(int\
    \ n, const vector<pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {\n\
    \            for(auto e : edges) start[e.first + 1]++;\n            for(int i\
    \ = 1; i <= n; i++) start[i] += start[i - 1];\n            vector<int> counter\
    \ = start;\n            for(auto e : edges) elist[counter[e.first]++] = e.second;\n\
    \        }\n    };\n\n    vector<pair<Cap, Cost>> slope(csr<_edge>& g, int s,\
    \ int t, Cap flow_limit) {\n        // variants (C = maxcost):\n        // -(n-1)C\
    \ <= dual[s] <= dual[i] <= dual[t] = 0\n        // reduced cost (= e.cost + dual[e.from]\
    \ - dual[e.to]) >= 0 for all edge\n\n        // dual_dist[i] = (dual[i], dist[i])\n\
    \        vector<pair<Cost, Cost>> dual_dist(n);\n        vector<int> prev_e(n);\n\
    \        vector<bool> vis(n);\n        struct Q {\n            Cost key;\n   \
    \         int to;\n            bool operator<(Q r) const { return key > r.key;\
    \ }\n        };\n        vector<int> que_min;\n        vector< Q > que;\n    \
    \    auto dual_ref = [&]() {\n            for (int i : rep(n)) dual_dist[i].second\
    \ = numeric_limits<Cost>::max();\n            fill(vis.begin(), vis.end(), false);\n\
    \            que_min.clear();\n            que.clear();\n            size_t heap_r\
    \ = 0;\n            dual_dist[s].second = 0;\n            que_min.push_back(s);\n\
    \            while (not que_min.empty() or not que.empty()) {\n              \
    \  int v;\n                if (not que_min.empty()) {\n                    v =\
    \ que_min.back();\n                    que_min.pop_back();\n                }\
    \ else {\n                    while (heap_r < que.size()) {\n                \
    \        heap_r++;\n                        push_heap(que.begin(), que.begin()\
    \ + heap_r);\n                    }\n                    v = que.front().to;\n\
    \                    pop_heap(que.begin(), que.end());\n                    que.pop_back();\n\
    \                    heap_r--;\n                }\n                if (vis[v])\
    \ continue;\n                vis[v] = true;\n                if (v == t) break;\n\
    \                // dist[v] = shortest(s, v) + dual[s] - dual[v]\n           \
    \     // dist[v] >= 0 (all reduced cost are positive)\n                // dist[v]\
    \ <= (n-1)C\n                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n\
    \                for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n       \
    \             _edge e = g.elist[i];\n                    if (!e.cap) continue;\n\
    \                    // |-dual[e.to] + dual[v]| <= (n-1)C\n                  \
    \  // cost <= C - -(n-1)C + 0 = nC\n                    Cost cost = e.cost - dual_dist[e.to].first\
    \ + dual_v;\n                    if (dual_dist[e.to].second - dist_v > cost) {\n\
    \                        Cost dist_to = dist_v + cost;\n                     \
    \   dual_dist[e.to].second = dist_to;\n                        prev_e[e.to] =\
    \ e.rev;\n                        if (dist_to == dist_v) {\n                 \
    \           que_min.push_back(e.to);\n                        } else {\n     \
    \                       que.push_back(Q{dist_to, e.to});\n                   \
    \     }\n                    }\n                }\n            }\n           \
    \ if (!vis[t]) {\n                return false;\n            }\n\n           \
    \ for (int v = 0; v < n; v++) {\n                if (!vis[v]) continue;\n    \
    \            // dual[v] = dual[v] - dist[t] + dist[v]\n                //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n                // \
    \        (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,\n              \
    \  //         t) + dual[t] + shortest(s, v) = shortest(s, v) -\n             \
    \   //         shortest(s, t) >= 0 - (n-1)C\n                dual_dist[v].first\
    \ -= dual_dist[t].second - dual_dist[v].second;\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n     \
    \   while (flow < flow_limit) {\n            if (!dual_ref()) break;\n       \
    \     Cap c = flow_limit - flow;\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n                c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      \
    \      }\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n \
    \               auto& e = g.elist[prev_e[v]];\n                e.cap += c;\n \
    \               g.elist[e.rev].cap -= c;\n            }\n            Cost d =\
    \ -dual_dist[s].first;\n            flow += c;\n            cost += c * d;\n \
    \           if (prev_cost_per_flow == d) {\n                result.pop_back();\n\
    \            }\n            result.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return result;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/min_cost_flow.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/min_cost_flow.hpp
layout: document
redirect_from:
- /library/src/graph/min_cost_flow.hpp
- /library/src/graph/min_cost_flow.hpp.html
title: src/graph/min_cost_flow.hpp
---
