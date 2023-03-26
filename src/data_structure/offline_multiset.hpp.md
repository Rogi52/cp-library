---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: src/data_structure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structure/fenwick_tree.hpp\"\ntemplate < class\
    \ comm_monoid > class fenwick_tree {\n  public:\n    using T = typename comm_monoid::set;\n\
    \n  private:\n    int n, n2;\n    vector< T > data;\n\n    int ceil_pow2(int n)\
    \ {\n        int x = 1;\n        while(x < n) x <<= 1;\n        return x;\n  \
    \  }\n\n  public:\n    fenwick_tree() : fenwick_tree(0) {}\n    fenwick_tree(int\
    \ n) : n(n), n2(ceil_pow2(n)), data(n + 1, comm_monoid::id) { assert(comm_monoid::comm);\
    \ }\n    fenwick_tree(const vector< T > &a) : n(a.size()), n2(ceil_pow2(n)), data(a)\
    \ {\n        assert(comm_monoid::comm);\n        data.insert(data.begin(), {comm_monoid::id});\n\
    \        for(int i = 1; i <= n; i++) {\n            int p = i + (i & -i);\n  \
    \          if(p <= n) data[p] = comm_monoid::op(data[i], data[p]);\n        }\n\
    \    }\n\n    void add(int i, T x) {\n        for(int p = i + 1; p <= n; p +=\
    \ p & -p) data[p] = comm_monoid::op(data[p], x);\n    }\n    // [0, r)\n    T\
    \ fold(int r) {\n        T s = comm_monoid::id;\n        for(int p = r; p > 0;\
    \ p -= p & -p) s = comm_monoid::op(data[p], s);\n        return s;\n    }\n  \
    \  // [l, r)\n    T fold(int l, int r) {\n        return comm_monoid::op(comm_monoid::inv(fold(l)),\
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
    \ comm = true;\n};\n#line 3 \"src/data_structure/offline_multiset.hpp\"\n\ntemplate\
    \ < class T, class U > class offline_multiset {\n  private:\n    int n;\n    vector<\
    \ T > v;\n    fenwick_tree< algebra::PLUS< U > > ft;\n\n  public:\n    offline_multiset()\
    \ {}\n    offline_multiset(const vector< T > &x) : v(x) {\n        sort(v.begin(),\
    \ v.end());\n        v.erase(unique(v.begin(), v.end()), v.end());\n        n\
    \ = v.size();\n        ft = fenwick_tree< algebra::PLUS< U > >(n);\n    }\n\n\
    \    void insert(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(), v.end(),\
    \ x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, +cnt);\n    }\n\
    \    void erase(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(), v.end(),\
    \ x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, -cnt);\n    }\n\
    \    T get_kth(U k) {\n        return v[ft.search([k](U s){ return s >= k; })];\n\
    \    }\n};\n"
  code: "#include \"src/data_structure/fenwick_tree.hpp\"\n#include \"src/algebra/plus.hpp\"\
    \n\ntemplate < class T, class U > class offline_multiset {\n  private:\n    int\
    \ n;\n    vector< T > v;\n    fenwick_tree< algebra::PLUS< U > > ft;\n\n  public:\n\
    \    offline_multiset() {}\n    offline_multiset(const vector< T > &x) : v(x)\
    \ {\n        sort(v.begin(), v.end());\n        v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n        n = v.size();\n        ft = fenwick_tree< algebra::PLUS<\
    \ U > >(n);\n    }\n\n    void insert(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, +cnt);\n\
    \    }\n    void erase(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, -cnt);\n\
    \    }\n    T get_kth(U k) {\n        return v[ft.search([k](U s){ return s >=\
    \ k; })];\n    }\n};\n"
  dependsOn:
  - src/data_structure/fenwick_tree.hpp
  - src/algebra/plus.hpp
  isVerificationFile: false
  path: src/data_structure/offline_multiset.hpp
  requiredBy: []
  timestamp: '2023-03-26 22:09:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/offline_multiset.hpp
layout: document
redirect_from:
- /library/src/data_structure/offline_multiset.hpp
- /library/src/data_structure/offline_multiset.hpp.html
title: src/data_structure/offline_multiset.hpp
---
