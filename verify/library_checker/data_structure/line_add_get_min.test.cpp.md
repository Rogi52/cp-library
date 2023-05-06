---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/cht_offline_get_min.hpp
    title: src/data_structure/cht_offline_get_min.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line\
    \ 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 1 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
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
    \ 1 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
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
    }\ntemplate < class T > int print(vector< T >& a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > >&\
    \ a) {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n\
    \    for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ?\
    \ ' ' : '\\n');\n    return 0;\n}\n#line 1 \"src/data_structure/cht_offline_get_min.hpp\"\
    \ntemplate < class T > class CHT_offline_get_min {\n  private:\n    struct Line\
    \ {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T eval(T\
    \ x) { return a * x + b; }\n    };\n\n    T sgn;\n    int n;\n    vector< Line\
    \ > ls;\n    vector< T > xs;\n\n  public:\n    T inf = numeric_limits< T >::max();\n\
    \n    CHT_offline_get_min(vector< T > &x, bool is_min = true) : xs(x) {\n    \
    \    sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = xs.size();\n        ls.assign(n << 1, Line(0, inf));\n\
    \        sgn = is_min ? +1 : -1;\n    }\n\n    void add_line(T a, T b) { update(a,\
    \ b, 0, n); }\n\n    void add_segment(T a, T b, T l, T r) {\n        int xl =\
    \ distance(xs.begin(), lower_bound(xs.begin(), xs.end(), l));\n        int xr\
    \ = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), r));\n        update(a,\
    \ b, xl, xr);\n    }\n\n    T query(T x) {\n        int i = distance(xs.begin(),\
    \ lower_bound(xs.begin(), xs.end(), x));\n        assert(i != n && x == xs[i]);\n\
    \        T v = inf;\n        for(i += n; i > 0; i >>= 1) v = min(v, ls[i].eval(x));\n\
    \        return sgn * v;\n    }\n\n  private:\n    void update(T a, T b, int l,\
    \ int r) {\n        a *= sgn, b *= sgn;\n        Line f(a, b);\n        for(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) descend(f, l++);\n\
    \            if(r & 1) descend(f, --r);\n        }\n    }\n\n    void descend(Line\
    \ g, int i) {\n        int l = i, r = i + 1;\n        while(l < n) l <<= 1, r\
    \ <<= 1;\n        while(l < r) {\n            int m = (l + r) >> 1;\n        \
    \    T xl = xs[l - n], xm = xs[m - n], xr = xs[r - 1 - n];\n            Line &f\
    \ = ls[i];\n            if(f.eval(xl) <= g.eval(xl) && f.eval(xr) <= g.eval(xr))\
    \ return;\n            if(f.eval(xl) >= g.eval(xl) && f.eval(xr) >= g.eval(xr))\
    \ { f = g; return; }\n            if(f.eval(xm) >  g.eval(xm)) swap(f, g);\n \
    \           if(f.eval(xl) >  g.eval(xl)) i = i << 1 | 0, r = m; else i = i <<\
    \ 1 | 1, l = m;\n        }\n    }\n};\n#line 5 \"verify/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N,Q; cin >> N >> Q;\n    vector<pair<ll,ll>> lines(N);\n    for(auto &[a, b]\
    \ : lines) cin >> a >> b;\n\n    vector<tuple<ll,ll,ll>> query(Q);\n    vector<ll>\
    \ xs;\n    for(int i : rep(Q)) {\n        int t; cin >> t;\n        if(t == 0)\
    \ {\n            ll a,b; cin >> a >> b;\n            query[i] = {t, a, b};\n \
    \       } else {\n            ll x; cin >> x;\n            query[i] = {t, x, 0};\n\
    \            xs.push_back(x);\n        }\n    }\n\n    CHT_offline_get_min<ll>\
    \ cht(xs);\n    for(auto [a, b] : lines) cht.add_line(a, b);\n    for(int i :\
    \ rep(Q)) {\n        auto [t, a, b] = query[i];\n        if(t == 0) {\n      \
    \      cht.add_line(a, b);\n        } else {\n            cout << cht.query(a)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"src/cp-template.hpp\"\n#include \"src/data_structure/cht_offline_get_min.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N,Q; cin >> N >> Q;\n    vector<pair<ll,ll>> lines(N);\n    for(auto &[a, b]\
    \ : lines) cin >> a >> b;\n\n    vector<tuple<ll,ll,ll>> query(Q);\n    vector<ll>\
    \ xs;\n    for(int i : rep(Q)) {\n        int t; cin >> t;\n        if(t == 0)\
    \ {\n            ll a,b; cin >> a >> b;\n            query[i] = {t, a, b};\n \
    \       } else {\n            ll x; cin >> x;\n            query[i] = {t, x, 0};\n\
    \            xs.push_back(x);\n        }\n    }\n\n    CHT_offline_get_min<ll>\
    \ cht(xs);\n    for(auto [a, b] : lines) cht.add_line(a, b);\n    for(int i :\
    \ rep(Q)) {\n        auto [t, a, b] = query[i];\n        if(t == 0) {\n      \
    \      cht.add_line(a, b);\n        } else {\n            cout << cht.query(a)\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/data_structure/cht_offline_get_min.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:51:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp.html
title: verify/library_checker/data_structure/line_add_get_min.test.cpp
---
