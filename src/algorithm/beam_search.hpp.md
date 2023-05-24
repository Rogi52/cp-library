---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/algorithm/selection.hpp
    title: src/algorithm/selection.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/algorithm/selection.hpp\"\n\ntemplate\
    \ < class T >\nT kth(const vector< T >& a, int k) {\n    int n = a.size();\n \
    \   T INF = numeric_limits< T >::max();\n    vector< T > c;\n    for(int i : rep(0,\
    \ n, 5)) {\n        vector< T > b;\n        for(int d : rep(5)) {\n          \
    \  b.push_back(i + d < n ? a[i + d] : INF);\n        }\n        sort(b.begin(),\
    \ b.end());\n        c.push_back(b[2]);\n    }\n\n    T m = kth(c, n / 10);\n\
    \    vector< T > s1, s2, s3;\n    for(T& x : a) {\n        if(x <  m) s1.push_back(x);\n\
    \        if(x == m) s2.push_back(x);\n        if(x >  m) s3.push_back(x);\n  \
    \  }\n\n    if(k <= int(s1.size())) return kth(s1, k);\n    if(k <= int(s1.size()\
    \ + s2.size())) return m;\n    return kth(s1, k - int(s1.size() + s2.size()));\n\
    }\n\ntemplate < class T >\nvector< T > topk(const vector< T >& a, int k, bool\
    \ sorted = false) {\n    T v = kth(a, k);\n    vector< T > s1, s2;\n    for(T&\
    \ x : a) {\n        if(x <  v) s1.push_back(x);\n        if(x == v) s2.push_back(x);\n\
    \    }\n    while(int(s1.size()) < k) s1.push_back(s2);\n    if(sorted) sort(s1.begin(),\
    \ s1.end());\n    return s1;\n}\n#line 3 \"src/algorithm/beam_search.hpp\"\n\n\
    template < class state, class F >\nstate beam_search(state first, int turn, int\
    \ width, const F& trans) {\n    vector<state> list = {first};\n    for(int t :\
    \ rep(turn)) {\n        vector<state> next;\n        for(state& s : list) {\n\
    \            vector<state> ns = trans(s);\n            next.insert(next.end(),\
    \ ns.begin(), ns.end());\n        }\n        list = topk(next, width);\n    }\n\
    \    return kth(list, 1);\n}\n"
  code: "#include \"../../src/cp-template.hpp\"\n#include \"../../src/algorithm/selection.hpp\"\
    \n\ntemplate < class state, class F >\nstate beam_search(state first, int turn,\
    \ int width, const F& trans) {\n    vector<state> list = {first};\n    for(int\
    \ t : rep(turn)) {\n        vector<state> next;\n        for(state& s : list)\
    \ {\n            vector<state> ns = trans(s);\n            next.insert(next.end(),\
    \ ns.begin(), ns.end());\n        }\n        list = topk(next, width);\n    }\n\
    \    return kth(list, 1);\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/algorithm/selection.hpp
  isVerificationFile: false
  path: src/algorithm/beam_search.hpp
  requiredBy: []
  timestamp: '2023-05-24 19:19:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/beam_search.hpp
layout: document
redirect_from:
- /library/src/algorithm/beam_search.hpp
- /library/src/algorithm/beam_search.hpp.html
title: src/algorithm/beam_search.hpp
---
