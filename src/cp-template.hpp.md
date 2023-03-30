---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/lis.test.cpp
    title: verify/library_checker/algorithm/lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/fenwick_tree.test.cpp
    title: verify/library_checker/data_structure/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/line_add_get_min.test.cpp
    title: verify/library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segment_add_get_min.test.cpp
    title: verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/union_find.test.cpp
    title: verify/library_checker/data_structure/union_find.test.cpp
  - icon: ':x:'
    path: verify/library_checker/geometry/angle_sort.test.hpp
    title: verify/library_checker/geometry/angle_sort.test.hpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/tree/cartesian_tree.test.cpp
    title: verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/rolling_hash.test.cpp
    title: verify/library_checker/string/rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "src/cp-template.hpp"

    #include <bits/stdc++.h>

    #define rep(i,n) for(int i = 0; i < (n); i++)

    using namespace std;

    using ll = long long;

    using ld = long double;

    using uint = unsigned int;

    using ull  = unsigned long long;

    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }
    return false; }

    template < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; }
    return false; }

    '
  code: '#include <bits/stdc++.h>

    #define rep(i,n) for(int i = 0; i < (n); i++)

    using namespace std;

    using ll = long long;

    using ld = long double;

    using uint = unsigned int;

    using ull  = unsigned long long;

    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }
    return false; }

    template < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; }
    return false; }

    '
  dependsOn: []
  isVerificationFile: false
  path: src/cp-template.hpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/string/rolling_hash.test.cpp
  - verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/geometry/angle_sort.test.hpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
  - verify/library_checker/algorithm/lis.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/union_find.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
documentation_of: src/cp-template.hpp
layout: document
redirect_from:
- /library/src/cp-template.hpp
- /library/src/cp-template.hpp.html
title: src/cp-template.hpp
---
