---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: src/data_structure/fenwick_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    src/data_structure/fenwick_tree.hpp\"\ntemplate < class comm_monoid > class fenwick_tree\
    \ {\n  public:\n    using T = typename comm_monoid::set;\n\n  private:\n    int\
    \ n, n2;\n    vector< T > data;\n\n    int ceil_pow2(int n) {\n        int x =\
    \ 1;\n        while(x < n) x <<= 1;\n        return x;\n    }\n\n  public:\n \
    \   fenwick_tree() : fenwick_tree(0) {}\n    fenwick_tree(int n) : n(n), n2(ceil_pow2(n)),\
    \ data(n + 1, comm_monoid::id) { assert(comm_monoid::comm); }\n    fenwick_tree(const\
    \ vector< T > &a) : n(a.size()), n2(ceil_pow2(n)), data(a) {\n        assert(comm_monoid::comm);\n\
    \        data.insert(data.begin(), {comm_monoid::id});\n        for(int i = 1;\
    \ i <= n; i++) {\n            int p = i + (i & -i);\n            if(p <= n) data[p]\
    \ = comm_monoid::op(data[i], data[p]);\n        }\n    }\n\n    void add(int i,\
    \ T x) {\n        for(int p = i + 1; p <= n; p += p & -p) data[p] = comm_monoid::op(data[p],\
    \ x);\n    }\n    // [0, r)\n    T fold(int r) {\n        T s = comm_monoid::id;\n\
    \        for(int p = r; p > 0; p -= p & -p) s = comm_monoid::op(data[p], s);\n\
    \        return s;\n    }\n    // [l, r)\n    T fold(int l, int r) {\n       \
    \ return comm_monoid::op(comm_monoid::inv(fold(l)), fold(r));\n    }\n    T get(int\
    \ i) {\n        return fold(i, i + 1);\n    }\n    void set(int i, T x) {\n  \
    \      add(i, comm_monoid::op(comm_monoid::inv(get(i)), x));\n    }\n    template<\
    \ class func > int search(const func &f) {\n        T s = comm_monoid::id;\n \
    \       if(f(s)) return 0;\n        int i = 0, k = n2;\n        while(k >>= 1)\
    \ {\n            int p = i | k;\n            if(p <= n && !f(comm_monoid::op(s,\
    \ data[p]))) s = comm_monoid::op(s, data[i = p]);\n        }\n        return i;\n\
    \    }\n};\n#line 1 \"src/algebra/plus.hpp\"\ntemplate < class T > class PLUS\
    \ {\n  public:\n    using set = T;\n    static constexpr T op(const T &l, const\
    \ T &r) { return l + r; }\n    static constexpr T id = T(0);\n    static constexpr\
    \ T inv(const T &x) { return -x; }\n    static constexpr T pow(const T &x, const\
    \ ll n) { return x * n; }\n    static constexpr bool comm = true;\n};\n#line 6\
    \ \"verify/library_checker/data_structure/fenwick_tree.test.cpp\"\n\nint main(){\n\
    \    int N = in();\n    int Q = in();\n    vector<ll> a = in(N);\n    fenwick_tree<\
    \ PLUS< ll > > tree(a);\n\n    for(int _ : rep(Q)) {\n        int t = in();\n\
    \        switch(t) {\n            case 0: {\n                int p = in();\n \
    \               int x = in();\n                tree.add(p, x);\n            }\
    \ break;\n\n            case 1: {\n                int l = in();\n           \
    \     int r = in();\n                print(tree.fold(l, r));\n            }\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/fenwick_tree.hpp\"\
    \n#include \"src/algebra/plus.hpp\"\n\nint main(){\n    int N = in();\n    int\
    \ Q = in();\n    vector<ll> a = in(N);\n    fenwick_tree< PLUS< ll > > tree(a);\n\
    \n    for(int _ : rep(Q)) {\n        int t = in();\n        switch(t) {\n    \
    \        case 0: {\n                int p = in();\n                int x = in();\n\
    \                tree.add(p, x);\n            } break;\n\n            case 1:\
    \ {\n                int l = in();\n                int r = in();\n          \
    \      print(tree.fold(l, r));\n            }\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/data_structure/fenwick_tree.hpp
  - src/algebra/plus.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-24 23:48:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp.html
title: verify/library_checker/data_structure/fenwick_tree.test.cpp
---
