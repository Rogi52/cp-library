---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data_structure/offline_multiset.hpp
    title: src/data_structure/offline_multiset.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/point_add_rect_sum.hpp
    title: src/data_structure/point_add_rect_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/static_point_add_rect_sum.hpp
    title: src/data_structure/static_point_add_rect_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/static_rect_add_rect_sum.hpp
    title: src/data_structure/static_rect_add_rect_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/fenwick_tree.test.cpp
    title: verify/library_checker/data_structure/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
    title: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \        }\n        return i;\n    }\n};\n"
  code: "template < class comm_monoid > class fenwick_tree {\n  public:\n    using\
    \ T = typename comm_monoid::set;\n\n  private:\n    int n, n2;\n    vector< T\
    \ > data;\n\n    int ceil_pow2(int n) {\n        int x = 1;\n        while(x <\
    \ n) x <<= 1;\n        return x;\n    }\n\n  public:\n    fenwick_tree() : fenwick_tree(0)\
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
    \        }\n        return i;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/fenwick_tree.hpp
  requiredBy:
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_rect_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/data_structure/offline_multiset.hpp
  timestamp: '2022-05-28 15:46:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
documentation_of: src/data_structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/src/data_structure/fenwick_tree.hpp
- /library/src/data_structure/fenwick_tree.hpp.html
title: src/data_structure/fenwick_tree.hpp
---
