---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: src/data_structure/fenwick_tree.hpp
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
    #line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\n#line 1 \"src/data_structure/fenwick_tree.hpp\"\
    \ntemplate < class comm_monoid > class fenwick_tree {\n  public:\n    using T\
    \ = typename comm_monoid::set;\n\n  private:\n    int n, n2;\n    vector< T >\
    \ data;\n\n    int ceil_pow2(int n) {\n        int x = 1;\n        while(x < n)\
    \ x <<= 1;\n        return x;\n    }\n\n  public:\n    fenwick_tree() : fenwick_tree(0)\
    \ {}\n    fenwick_tree(int n) : n(n), n2(ceil_pow2(n)), data(n + 1, comm_monoid::id)\
    \ { assert(comm_monoid::comm); }\n    fenwick_tree(const vector< T > &a) : n(a.size()),\
    \ n2(ceil_pow2(n)), data(a) {\n        assert(comm_monoid::comm);\n        data.insert(data.begin(),\
    \ {comm_monoid::id});\n        for(int i = 1; i <= n; i++) {\n            int\
    \ p = i + (i & -i);\n            if(p <= n) data[p] = comm_monoid::op(data[i],\
    \ data[p]);\n        }\n    }\n\n    void add(int i, T x) {\n        for(int p\
    \ = i + 1; p <= n; p += p & -p) data[p] = comm_monoid::op(data[p], x);\n    }\n\
    \    // [0, r)\n    T fold(int r) {\n        T s = comm_monoid::id;\n        for(int\
    \ p = r; p > 0; p -= p & -p) s = comm_monoid::op(data[p], s);\n        return\
    \ s;\n    }\n    // [l, r)\n    T fold(int l, int r) {\n        return comm_monoid::op(comm_monoid::inv(fold(l)),\
    \ fold(r));\n    }\n    T get(int i) {\n        return fold(i, i + 1);\n    }\n\
    \    void set(int i, T x) {\n        add(i, comm_monoid::op(comm_monoid::inv(get(i)),\
    \ x));\n    }\n    template< class func > int search(const func &f) {\n      \
    \  T s = comm_monoid::id;\n        if(f(s)) return 0;\n        int i = 0, k =\
    \ n2;\n        while(k >>= 1) {\n            int p = i | k;\n            if(p\
    \ <= n && !f(comm_monoid::op(s, data[p]))) s = comm_monoid::op(s, data[i = p]);\n\
    \        }\n        return i;\n    }\n};\n#line 1 \"src/algebra/plus.hpp\"\ntemplate\
    \ < class T > class PLUS {\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T &l, const T &r) { return l + r; }\n    static constexpr T id =\
    \ T(0);\n    static constexpr T inv(const T &x) { return -x; }\n    static constexpr\
    \ T pow(const T &x, const int n) { return x * n; }\n    static constexpr bool\
    \ comm = true;\n};\n#line 6 \"verify/library_checker/data_structure/fenwick_tree.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N,Q; cin >> N >> Q;\n    vector<ll> a(N);\n    rep(i,N) cin >> a[i];\n    fenwick_tree<\
    \ PLUS< ll > > tree(a);\n\n    rep(_,Q) {\n        int t; cin >> t;\n        switch(t)\
    \ {\n            case 0: {\n                int p,x; cin >> p >> x;\n        \
    \        tree.add(p, x);\n            } break;\n\n            case 1: {\n    \
    \            int l,r; cin >> l >> r;\n                cout << tree.fold(l, r)\
    \ << '\\n';\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/fenwick_tree.hpp\"\
    \n#include \"src/algebra/plus.hpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    \n    int N,Q; cin >> N >> Q;\n    vector<ll> a(N);\n    rep(i,N) cin >>\
    \ a[i];\n    fenwick_tree< PLUS< ll > > tree(a);\n\n    rep(_,Q) {\n        int\
    \ t; cin >> t;\n        switch(t) {\n            case 0: {\n                int\
    \ p,x; cin >> p >> x;\n                tree.add(p, x);\n            } break;\n\
    \n            case 1: {\n                int l,r; cin >> l >> r;\n           \
    \     cout << tree.fold(l, r) << '\\n';\n            }\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/data_structure/fenwick_tree.hpp
  - src/algebra/plus.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp.html
title: verify/library_checker/data_structure/fenwick_tree.test.cpp
---
