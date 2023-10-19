---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/min_cost_flow.hpp
    title: src/graph/min_cost_flow.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
  bundledCode: "#line 1 \"verify/aoj/data_structure/min_cost_flow.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\n\n#line 2 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
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
    \ 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
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
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/utility/key_val.hpp\"\ntemplate <\
    \ class K, class V >\nstruct key_val {\n    K key; V val;\n    key_val() {}\n\
    \    key_val(K key, V val) : key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T >\nkey_val< int, T > max_of(const vector< T >& a) {\n   \
    \ int i = max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nkey_val< int, T > min_of(const vector< T >& a) {\n\
    \    int i = min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nT sum_of(const vector< T >& a) {\n    T sum = 0;\n\
    \    for(const T x : a) sum += x;\n    return sum;\n}\n\ntemplate < class T >\n\
    vector<int> freq_of(const vector< T >& a, T L, T R) {\n    vector<int> res(R -\
    \ L);\n    for(const T x : a) res[x - L]++;\n    return res;\n}\n\ntemplate <\
    \ class T >\nvector<int> freq_of(const vector< T >& a, T R) {\n    return freq_of(a,\
    \ T(0), R);\n}\n\ntemplate < class T >\nstruct prefix_sum {\n    vector< T > s;\n\
    \    prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), T(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 16 \"\
    src/cp-template.hpp\"\n\n#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate <\
    \ class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok - ng)\
    \ > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line\
    \ 2 \"src/algorithm/argsort.hpp\"\n\ntemplate < class T > std::vector< int > argsort(const\
    \ std::vector< T > &a) {\n    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n\
    \        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n\
    }\n#line 1 \"src/graph/min_cost_flow.hpp\"\ntemplate < class Cap, class Cost >\
    \ struct mcf_graph {\n  public:\n    explicit mcf_graph(int n) : n(n) {}\n\n \
    \   int add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(0 <=\
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
    \ = d;\n        }\n        return result;\n    }\n};\n#line 5 \"verify/aoj/data_structure/min_cost_flow.test.cpp\"\
    \n\nint main() {\n    int n = in(), m = in(), f = in();\n    mcf_graph<int,int>\
    \ g(n);\n    for(int i : rep(m)) {\n        int u = in(), v = in(), c = in(),\
    \ d = in();\n        g.add_edge(u, v, c, d);\n    }\n    auto [flow, cost] = g.flow(0,\
    \ n - 1, f);\n    print(flow == f ? cost : -1);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\n\n\
    #include \"../../../src/cp-template.hpp\"\n#include \"../../../src/graph/min_cost_flow.hpp\"\
    \n\nint main() {\n    int n = in(), m = in(), f = in();\n    mcf_graph<int,int>\
    \ g(n);\n    for(int i : rep(m)) {\n        int u = in(), v = in(), c = in(),\
    \ d = in();\n        g.add_edge(u, v, c, d);\n    }\n    auto [flow, cost] = g.flow(0,\
    \ n - 1, f);\n    print(flow == f ? cost : -1);\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/graph/min_cost_flow.hpp
  isVerificationFile: true
  path: verify/aoj/data_structure/min_cost_flow.test.cpp
  requiredBy: []
  timestamp: '2023-10-18 21:43:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/data_structure/min_cost_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/data_structure/min_cost_flow.test.cpp
- /verify/verify/aoj/data_structure/min_cost_flow.test.cpp.html
title: verify/aoj/data_structure/min_cost_flow.test.cpp
---
