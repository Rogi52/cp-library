---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/max_flow.hpp
    title: src/graph/max_flow.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"verify/aoj/data_structure/max_flow.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n\n#line\
    \ 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
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
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 1 \"\
    src/graph/max_flow.hpp\"\ntemplate < class Cap > struct mf_graph {\n  public:\n\
    \    explicit mf_graph(int n) : n(n), g(n) {}\n  \n    int add_edge(int from,\
    \ int to, Cap cap) {\n        assert(0 <= from and from < n);\n        assert(0\
    \ <= to and to < n);\n        assert(0 <= cap);\n        int m = pos.size();\n\
    \        int from_id = g[from].size();\n        int to_id = g[to].size() + (from\
    \ == to);\n        g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to; Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int m = pos.size();\n\
    \        assert(0 <= i and i < m);\n        _edge e = g[pos[i].first][pos[i].second];\n\
    \        _edge r = g[e.to][e.rev];\n        return edge{pos[i].first, e.to, e.cap\
    \ + r.cap, r.cap};\n    }\n\n    vector<edge> edges() {\n        int m = pos.size();\n\
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
    \   };\n    vector<pair<int,int>> pos;\n    vector<vector<_edge>> g;\n};\n#line\
    \ 5 \"verify/aoj/data_structure/max_flow.test.cpp\"\n\nint main() {\n    int n\
    \ = in(), m = in();\n    mf_graph<int> g(n);\n    for(int i : rep(m)) {\n    \
    \    int u = in(), v = in(), c = in();\n        g.add_edge(u, v, c);\n    }\n\
    \    print(g.flow(0, n - 1));\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/graph/max_flow.hpp\"\
    \n\nint main() {\n    int n = in(), m = in();\n    mf_graph<int> g(n);\n    for(int\
    \ i : rep(m)) {\n        int u = in(), v = in(), c = in();\n        g.add_edge(u,\
    \ v, c);\n    }\n    print(g.flow(0, n - 1));\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/graph/max_flow.hpp
  isVerificationFile: true
  path: verify/aoj/data_structure/max_flow.test.cpp
  requiredBy: []
  timestamp: '2023-05-27 19:27:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/data_structure/max_flow.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/data_structure/max_flow.test.cpp
- /verify/verify/aoj/data_structure/max_flow.test.cpp.html
title: verify/aoj/data_structure/max_flow.test.cpp
---
