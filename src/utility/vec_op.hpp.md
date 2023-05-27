---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/algorithm/beam_search.hpp
    title: src/algorithm/beam_search.hpp
  - icon: ':warning:'
    path: src/algorithm/selection.hpp
    title: src/algorithm/selection.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/binary_trie.hpp
    title: src/data_structure/binary_trie.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/point_add_rect_sum.hpp
    title: src/data_structure/point_add_rect_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/static_point_add_rect_sum.hpp
    title: src/data_structure/static_point_add_rect_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/static_rect_add_rect_sum.hpp
    title: src/data_structure/static_rect_add_rect_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/rerooting.hpp
    title: src/graph/tree/rerooting.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/binary_trie.test.cpp
    title: verify/aoj/data_structure/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/max_flow.test.cpp
    title: verify/aoj/data_structure/max_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/min_cost_flow.test.cpp
    title: verify/aoj/data_structure/min_cost_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/lis.test.cpp
    title: verify/library_checker/algorithm/lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/binary_trie.test.cpp
    title: verify/library_checker/data_structure/binary_trie.test.cpp
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
    path: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segment_add_get_min.test.cpp
    title: verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
    title: verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/union_find.test.cpp
    title: verify/library_checker/data_structure/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/geometry/angle_sort.test.cpp
    title: verify/library_checker/geometry/angle_sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/tree/cartesian_tree.test.cpp
    title: verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/tree/rerooting.test.cpp
    title: verify/library_checker/graph/tree/rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/bicoef.test.cpp
    title: verify/library_checker/number/bicoef.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/rolling_hash.test.cpp
    title: verify/library_checker/string/rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/vec_op.hpp\"\ntemplate < class T >\nkey_val<\
    \ int, T > max_of(const vector< T >& a) {\n    int i = max_element(a.begin(),\
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
    \ return s[R] - s[L];\n    }\n};\n"
  code: "#pragma once\ntemplate < class T >\nkey_val< int, T > max_of(const vector<\
    \ T >& a) {\n    int i = max_element(a.begin(), a.end()) - a.begin();\n    return\
    \ {i, a[i]};\n}\n\ntemplate < class T >\nkey_val< int, T > min_of(const vector<\
    \ T >& a) {\n    int i = min_element(a.begin(), a.end()) - a.begin();\n    return\
    \ {i, a[i]};\n}\n\ntemplate < class T >\nT sum_of(const vector< T >& a) {\n  \
    \  T sum = 0;\n    for(const T x : a) sum += x;\n    return sum;\n}\n\ntemplate\
    \ < class T >\nvector<int> freq_of(const vector< T >& a, T L, T R) {\n    vector<int>\
    \ res(R - L);\n    for(const T x : a) res[x - L]++;\n    return res;\n}\n\ntemplate\
    \ < class T >\nvector<int> freq_of(const vector< T >& a, T R) {\n    return freq_of(a,\
    \ T(0), R);\n}\n\ntemplate < class T >\nstruct prefix_sum {\n    vector< T > s;\n\
    \    prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), T(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/vec_op.hpp
  requiredBy:
  - src/data_structure/binary_trie.hpp
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/data_structure/static_rect_add_rect_sum.hpp
  - src/cp-template.hpp
  - src/graph/tree/rerooting.hpp
  - src/algorithm/selection.hpp
  - src/algorithm/beam_search.hpp
  timestamp: '2023-05-24 23:48:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/data_structure/min_cost_flow.test.cpp
  - verify/aoj/data_structure/max_flow.test.cpp
  - verify/aoj/data_structure/binary_trie.test.cpp
  - verify/library_checker/geometry/angle_sort.test.cpp
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/union_find.test.cpp
  - verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - verify/library_checker/data_structure/binary_trie.test.cpp
  - verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - verify/library_checker/graph/tree/rerooting.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/algorithm/lis.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
  - verify/library_checker/string/rolling_hash.test.cpp
  - verify/library_checker/number/bicoef.test.cpp
documentation_of: src/utility/vec_op.hpp
layout: document
redirect_from:
- /library/src/utility/vec_op.hpp
- /library/src/utility/vec_op.hpp.html
title: src/utility/vec_op.hpp
---
