---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/tree/rerooting.test.cpp
    title: verify/library_checker/graph/tree/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate <\
    \ class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false;\
    \ }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true;\
    \ } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T\
    \ > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1)\
    \ {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n\
    \        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T >\
    \ struct rep {\n    const itr< T > s, t;\n    constexpr rep(const T t) noexcept\
    \ : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t)\
    \ {}\n    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t,\
    \ d) {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr\
    \ auto end() const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr < T > s, t;\n    constexpr revrep(const T t) noexcept : s(t\
    \ - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end() const noexcept { return\
    \ t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca\
    \ {\n        template < class T > operator T() {\n            T s; cin >> s; return\
    \ s;\n        }\n    };\n    struct vec {\n        int n;\n        vec(int n)\
    \ : n(n) {}\n        template < class T > operator vector< T >() {\n         \
    \   vector< T > v(n);\n            for(T& x : v) cin >> x;\n            return\
    \ v;\n        }\n    };\n    struct mat {\n        int h,w;\n        mat(int h,\
    \ int w) : h(h), w(w) {}\n        template < class T > operator vector< vector<\
    \ T > >() {\n            vector m(h, vector< T >(w));\n            for(vector<\
    \ T >& v : m) for(T& x : v) cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            cin.tie(0);\n        \
    \    ios::sync_with_stdio(0);\n        }\n    } su;\n}\nscanner::sca in() { return\
    \ scanner::sca(); }\nscanner::vec in(int n) { return scanner::vec(n); }\nscanner::mat\
    \ in(int h, int w) { return scanner::mat(h, w); }\n\nnamespace printer {\n   \
    \ void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    \    void flush() {\n        cout.flush();\n    }\n}\nint print() { cout << '\\\
    n'; return 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&...\
    \ t) {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/graph/tree/rerooting.hpp\"\n\nstruct\
    \ rerooting {\n    int N;\n    vector<vector<pair<int,int>>> G;\n    rerooting(int\
    \ N) : N(N), G(N) {}\n    void add_edge(int u, int v, int i) {\n        G[u].push_back({v,\
    \ i});\n        G[v].push_back({u, i});\n    }\n\n    template < class S, class\
    \ M, class E, class V >\n    vector< S > solve(const M& merge, const E& fe, const\
    \ V& fv, const S unit) {\n        vector<vector< S >> dp(N);\n        for(int\
    \ i : rep(N)) dp[i].resize(G[i].size());\n\n        function<S(int,int)> dfs1\
    \ = [&](int v, int p) -> S {\n            S res = unit;\n            for(int i\
    \ : rep(G[v].size())) {\n                auto [to, id] = G[v][i];\n          \
    \      if(to != p) {\n                    dp[v][i] = dfs1(to, v);\n          \
    \          res = merge(res, fe(dp[v][i], id));\n                }\n          \
    \  }\n            return fv(res, v);\n        }; dfs1(0, -1);\n\n        function<void(int,int,S)>\
    \ dfs2 = [&](int v, int p, S dp_par) {\n            for(int i : rep(G[v].size()))\
    \ {\n                auto [to, id] = G[v][i];\n                if(to == p) {\n\
    \                    dp[v][i] = dp_par;\n                }\n            }\n\n\
    \            vector< S > R(G[v].size() + 1U);\n            R[G[v].size()] = unit;\n\
    \            for(int i : revrep(G[v].size())) {\n                auto [to, id]\
    \ = G[v][i];\n                R[i] = merge(R[i + 1], fe(dp[v][i], id));\n    \
    \        }\n            S L = unit;\n            for(int i : rep(G[v].size()))\
    \ {\n                auto [to, id] = G[v][i];\n                if(to != p) {\n\
    \                    S val = merge(L, R[i + 1]);\n                    dfs2(to,\
    \ v, fv(val, v));\n                }\n                L = merge(L, fe(dp[v][i],\
    \ id));\n            }\n        }; dfs2(0, -1, unit);\n\n        vector< S > res(N,\
    \ unit);\n        for(int v : rep(N)) {\n            for(int i : rep(G[v].size()))\
    \ {\n                auto [to, id] = G[v][i];\n                res[v] = merge(res[v],\
    \ fe(dp[v][i], id));\n            }\n            res[v] = fv(res[v], v);\n   \
    \     }\n        return res;\n    }\n};\n"
  code: "#include \"../../../src/cp-template.hpp\"\n\nstruct rerooting {\n    int\
    \ N;\n    vector<vector<pair<int,int>>> G;\n    rerooting(int N) : N(N), G(N)\
    \ {}\n    void add_edge(int u, int v, int i) {\n        G[u].push_back({v, i});\n\
    \        G[v].push_back({u, i});\n    }\n\n    template < class S, class M, class\
    \ E, class V >\n    vector< S > solve(const M& merge, const E& fe, const V& fv,\
    \ const S unit) {\n        vector<vector< S >> dp(N);\n        for(int i : rep(N))\
    \ dp[i].resize(G[i].size());\n\n        function<S(int,int)> dfs1 = [&](int v,\
    \ int p) -> S {\n            S res = unit;\n            for(int i : rep(G[v].size()))\
    \ {\n                auto [to, id] = G[v][i];\n                if(to != p) {\n\
    \                    dp[v][i] = dfs1(to, v);\n                    res = merge(res,\
    \ fe(dp[v][i], id));\n                }\n            }\n            return fv(res,\
    \ v);\n        }; dfs1(0, -1);\n\n        function<void(int,int,S)> dfs2 = [&](int\
    \ v, int p, S dp_par) {\n            for(int i : rep(G[v].size())) {\n       \
    \         auto [to, id] = G[v][i];\n                if(to == p) {\n          \
    \          dp[v][i] = dp_par;\n                }\n            }\n\n          \
    \  vector< S > R(G[v].size() + 1U);\n            R[G[v].size()] = unit;\n    \
    \        for(int i : revrep(G[v].size())) {\n                auto [to, id] = G[v][i];\n\
    \                R[i] = merge(R[i + 1], fe(dp[v][i], id));\n            }\n  \
    \          S L = unit;\n            for(int i : rep(G[v].size())) {\n        \
    \        auto [to, id] = G[v][i];\n                if(to != p) {\n           \
    \         S val = merge(L, R[i + 1]);\n                    dfs2(to, v, fv(val,\
    \ v));\n                }\n                L = merge(L, fe(dp[v][i], id));\n \
    \           }\n        }; dfs2(0, -1, unit);\n\n        vector< S > res(N, unit);\n\
    \        for(int v : rep(N)) {\n            for(int i : rep(G[v].size())) {\n\
    \                auto [to, id] = G[v][i];\n                res[v] = merge(res[v],\
    \ fe(dp[v][i], id));\n            }\n            res[v] = fv(res[v], v);\n   \
    \     }\n        return res;\n    }\n};"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  isVerificationFile: false
  path: src/graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2023-05-10 15:04:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/tree/rerooting.test.cpp
documentation_of: src/graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/src/graph/tree/rerooting.hpp
- /library/src/graph/tree/rerooting.hpp.html
title: src/graph/tree/rerooting.hpp
---
