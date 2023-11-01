---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':question:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/min_cost_flow.hpp
    title: src/graph/min_cost_flow.hpp
  - icon: ':question:'
    path: src/utility/heap.hpp
    title: src/utility/heap.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':question:'
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
    \  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\ntemplate\
    \ < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return\
    \ false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return\
    \ true; } return false; }\ntemplate < class T, class U > T ceil (T x, U y) { return\
    \ (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate < class T, class U\
    \ > T floor(T x, U y) { return (x > 0 ?           x / y : (x - y + 1) / y); }\n\
    \n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr_rep {\n\
    \    T i, d;\n    constexpr itr_rep(const T i) noexcept : i(i), d(1) {}\n    constexpr\
    \ itr_rep(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr_rep x) const noexcept { return\
    \ d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class T > struct rep {\n    const\
    \ itr_rep< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n\
    \    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end  () const\
    \ noexcept { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const\
    \ itr_rep < T > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1),\
    \ t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1,\
    \ -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d)\
    \ noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end  () const noexcept { return t; }\n};\n\
    #line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer */\nistream& operator>>(istream&\
    \ is, i128& x) {\n    std::string s; is >> s;\n    int pm = (s[0] == '-');\n \
    \   x = 0;\n    for(int i : rep(pm, int(s.size()))) x = x * 10 + (s[i] - '0');\n\
    \    if(pm) x *= -1;\n    return is;\n}\nostream& operator<<(ostream& os, const\
    \ i128& x) {\n    if(x == 0) return os << '0';\n    i128 y = x;\n    if(y < 0)\
    \ {\n        os << '-';\n        y *= -1;\n    }\n    std::vector<int> ny;\n \
    \   while(y > 0) {\n        ny.push_back(y % 10);\n        y /= 10;\n    }\n \
    \   for(int i : revrep(ny.size())) os << ny[i];\n    return os;\n}\n\nnamespace\
    \ scanner {\n    struct sca {\n        template < class T > operator T() {\n \
    \           T s; std::cin >> s; return s;\n        }\n    };\n    struct vec {\n\
    \        int n;\n        vec(int n) : n(n) {}\n        template < class T > operator\
    \ std::vector< T >() {\n            std::vector< T > v(n);\n            for(T&\
    \ x : v) std::cin >> x;\n            return v;\n        }\n    };\n    struct\
    \ mat {\n        int h, w;\n        mat(int h, int w) : h(h), w(w) {}\n      \
    \  template < class T > operator std::vector< std::vector< T > >() {\n       \
    \     std::vector m(h, std::vector< T >(w));\n            for(std::vector< T >&\
    \ v : m) for(T& x : v) std::cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            std::cin.tie(0);\n   \
    \         std::ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n\
    }\nscanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) { std::cout << std::fixed\
    \ << std::setprecision(d); }\n    void flush() { std::cout.flush(); }\n}\n\ntemplate\
    \ < class T >\nostream& operator<<(ostream& os, const std::vector< T > a) {\n\
    \    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os\
    \ << ' '; }\n    return os;\n}\n\nint print() { std::cout << '\\n'; return 0;\
    \ }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t) {\n\
    \    std::cout << h; if(sizeof...(tail)) std::cout << ' ';\n    return print(std::forward<tail>(t)...);\n\
    }\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n = a.size();\n\
    \    for(int i : rep(n)) std::cout << a[i] << \"\\n\";\n    return 0;\n}\n\n\n\
    #line 2 \"src/utility/key_val.hpp\"\n\ntemplate < class K, class V >\nstruct key_val\
    \ {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) : key(key),\
    \ val(val) {}\n    template < std::size_t Index >\n    std::tuple_element_t< Index,\
    \ key_val >& get() {\n        if constexpr (Index == 0) return key;\n        if\
    \ constexpr (Index == 1) return val;\n    }\n};\n\nnamespace std {\n\ntemplate\
    \ < class K, class V > struct tuple_size < key_val< K, V > > : integral_constant<\
    \ size_t, 2 > {};\ntemplate < class K, class V > struct tuple_element < 0, key_val<\
    \ K, V > > { using type = K; };\ntemplate < class K, class V > struct tuple_element\
    \ < 1, key_val< K, V > > { using type = V; };\n\n}\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T > key_val< int, T > max_of(const vector< T >& a) {\n    int\
    \ i = std::max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class T > key_val< int, T > min_of(const vector< T >& a) {\n   \
    \ int i = std::min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class S, class T > S sum_of(const vector< T >& a) {\n    S sum =\
    \ 0;\n    for(const T x : a) sum += x;\n    return sum;\n}\ntemplate < class S,\
    \ class T > vector< S > freq_of(const vector< T >& a, T L, T R) {\n    vector<\
    \ S > res(R - L, S(0));\n    for(const T x : a) res[x - L] += 1;\n    return res;\n\
    }\ntemplate < class S, class T > struct prefix_sum {\n    vector< S > s;\n   \
    \ prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), S(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    S sum(int L, int R) { return s[R] - s[L]; }\n};\n#line 3 \"src/utility/heap.hpp\"\
    \n\ntemplate < class T > using heap_min = std::priority_queue< T, std::vector<\
    \ T >, std::greater< T > >;\ntemplate < class T > using heap_max = std::priority_queue<\
    \ T, std::vector< T >, std::less< T > >;\n\n#line 23 \"src/cp-template.hpp\"\n\
    \n#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate < class T, class F >\nT bin_search(T\
    \ ok, T ng, F& f) {\n    while(abs(ok - ng) > 1) {\n        T mid = (ok + ng)\
    \ / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate\
    \ < class T, class F >\nT bin_search_real(T ok, T ng, F& f, int step = 80) {\n\
    \    while(step--) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ok;\n}\n#line 2 \"src/algorithm/argsort.hpp\"\n\n\
    template < class T > std::vector< int > argsort(const std::vector< T > &a) {\n\
    \    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(), ids.end(),\
    \ 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n        return\
    \ a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n}\n#line\
    \ 1 \"src/graph/min_cost_flow.hpp\"\ntemplate < class Cap, class Cost > struct\
    \ mcf_graph {\n  public:\n    explicit mcf_graph(int n) : n(n) {}\n\n    int add_edge(int\
    \ from, int to, Cap cap, Cost cost) {\n        assert(0 <= from and from < n);\n\
    \        assert(0 <= to and to < n);\n        assert(0 <= cap);\n        assert(0\
    \ <= cost);\n        int m = _edges.size();\n        _edges.push_back({from, to,\
    \ cap, 0, cost});\n        return m;\n    }\n\n    struct edge {\n        int\
    \ from, to;\n        Cap cap, flow;\n        Cost cost;\n    };\n\n    edge get_edge(int\
    \ i) {\n        int m = _edges.size();\n        assert(0 <= i and i < m);\n  \
    \      return _edges[i];\n    }\n\n    vector<edge> edges() { return _edges; }\n\
    \n    pair<Cap, Cost> flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
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
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/graph/min_cost_flow.hpp
  isVerificationFile: true
  path: verify/aoj/data_structure/min_cost_flow.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 09:21:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/data_structure/min_cost_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/data_structure/min_cost_flow.test.cpp
- /verify/verify/aoj/data_structure/min_cost_flow.test.cpp.html
title: verify/aoj/data_structure/min_cost_flow.test.cpp
---
