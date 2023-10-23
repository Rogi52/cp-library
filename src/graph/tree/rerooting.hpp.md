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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/graph/tree/rerooting.test.cpp
    title: verify/library_checker/graph/tree/rerooting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\
    \ntemplate < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept :\
    \ i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int\
    \ operator*() const noexcept { return i; }\n    constexpr bool operator!=(const\
    \ itr x) const noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n\
    };\n\ntemplate < class T > struct rep {\n    const itr< T > s, t;\n    constexpr\
    \ rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const\
    \ T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const\
    \ T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n\n\
    template < class T > struct revrep {\n    const itr < T > s, t;\n    constexpr\
    \ revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n   \
    \ struct sca {\n        template < class T > operator T() {\n            T s;\
    \ cin >> s; return s;\n        }\n    };\n    struct vec {\n        int n;\n \
    \       vec(int n) : n(n) {}\n        template < class T > operator vector< T\
    \ >() {\n            vector< T > v(n);\n            for(T& x : v) cin >> x;\n\
    \            return v;\n        }\n    };\n    struct mat {\n        int h,w;\n\
    \        mat(int h, int w) : h(h), w(w) {}\n        template < class T > operator\
    \ vector< vector< T > >() {\n            vector m(h, vector< T >(w));\n      \
    \      for(vector< T >& v : m) for(T& x : v) cin >> x;\n            return m;\n\
    \        }\n    };\n    struct speedup {\n        speedup() {\n            cin.tie(0);\n\
    \            ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n}\n\
    scanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) {\n        cout << fixed\
    \ << setprecision(d);\n    }\n    void flush() {\n        cout.flush();\n    }\n\
    }\n\ntemplate < class T >\nostream& operator<<(ostream& os, const std::vector<\
    \ T > a) {\n    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i\
    \ != n - 1) os << ' '; }\n    return os;\n}\n\nint print() { cout << '\\n'; return\
    \ 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t)\
    \ {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\n\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n =\
    \ a.size();\n    for(int i : rep(n)) cout << a[i] << \"\\n\";\n    return 0;\n\
    }\n#line 2 \"src/utility/key_val.hpp\"\ntemplate < class K, class V >\nstruct\
    \ key_val {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) :\
    \ key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\ntemplate < class\
    \ T >\nkey_val< int, T > max_of(const vector< T >& a) {\n    int i = max_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nkey_val<\
    \ int, T > min_of(const vector< T >& a) {\n    int i = min_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nT sum_of(const\
    \ vector< T >& a) {\n    T sum = 0;\n    for(const T x : a) sum += x;\n    return\
    \ sum;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector< T >& a, T\
    \ L, T R) {\n    vector<int> res(R - L);\n    for(const T x : a) res[x - L]++;\n\
    \    return res;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector<\
    \ T >& a, T R) {\n    return freq_of(a, T(0), R);\n}\n\ntemplate < class T >\n\
    struct prefix_sum {\n    vector< T > s;\n    prefix_sum(const vector< T >& a)\
    \ : s(a) {\n        s.insert(s.begin(), T(0));\n        for(int i : rep(a.size()))\
    \ s[i + 1] += s[i];\n    }\n    // [L, R)\n    T sum(int L, int R) {\n       \
    \ return s[R] - s[L];\n    }\n};\n#line 3 \"src/utility/heap.hpp\"\n\ntemplate\
    \ < class T > using heap_min = std::priority_queue< T, std::vector< T >, std::greater<\
    \ T > >;\ntemplate < class T > using heap_max = std::priority_queue< T, std::vector<\
    \ T >, std::less< T > >;\n\n#line 21 \"src/cp-template.hpp\"\n\n#line 1 \"src/algorithm/bin_search.hpp\"\
    \ntemplate < class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok\
    \ - ng) > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line\
    \ 2 \"src/algorithm/argsort.hpp\"\n\ntemplate < class T > std::vector< int > argsort(const\
    \ std::vector< T > &a) {\n    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n\
    \        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n\
    }\n#line 2 \"src/graph/tree/rerooting.hpp\"\n\nstruct rerooting {\n    int N;\n\
    \    vector<vector<pair<int,int>>> G;\n    rerooting(int N) : N(N), G(N) {}\n\
    \    void add_edge(int u, int v, int i) {\n        G[u].push_back({v, i});\n \
    \       G[v].push_back({u, i});\n    }\n\n    template < class S, class M, class\
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
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/graph/tree/rerooting.test.cpp
documentation_of: src/graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/src/graph/tree/rerooting.hpp
- /library/src/graph/tree/rerooting.hpp.html
title: src/graph/tree/rerooting.hpp
---