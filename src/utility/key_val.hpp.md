---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/algorithm/beam_search.hpp
    title: src/algorithm/beam_search.hpp
  - icon: ':warning:'
    path: src/algorithm/floor_sum.hpp
    title: src/algorithm/floor_sum.hpp
  - icon: ':warning:'
    path: src/algorithm/selection.hpp
    title: src/algorithm/selection.hpp
  - icon: ':question:'
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
  - icon: ':x:'
    path: src/number/fps.hpp
    title: src/number/fps.hpp
  - icon: ':x:'
    path: src/number/fps_sparse.hpp
    title: src/number/fps_sparse.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/nim_product.hpp
    title: src/number/nim_product.hpp
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
  - icon: ':x:'
    path: verify/library_checker/number/fps_inv_sparse.test.cpp
    title: verify/library_checker/number/fps_inv_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/nim_product.test.cpp
    title: verify/library_checker/number/nim_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/rolling_hash.test.cpp
    title: verify/library_checker/string/rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/key_val.hpp\"\ntemplate < class K, class V >\n\
    struct key_val {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val)\
    \ : key(key), val(val) {}\n};\n"
  code: "#pragma once\ntemplate < class K, class V >\nstruct key_val {\n    K key;\
    \ V val;\n    key_val() {}\n    key_val(K key, V val) : key(key), val(val) {}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/key_val.hpp
  requiredBy:
  - src/algorithm/selection.hpp
  - src/algorithm/floor_sum.hpp
  - src/algorithm/beam_search.hpp
  - src/cp-template.hpp
  - src/number/fps_sparse.hpp
  - src/number/nim_product.hpp
  - src/number/fps.hpp
  - src/graph/tree/rerooting.hpp
  - src/data_structure/static_rect_add_rect_sum.hpp
  - src/data_structure/binary_trie.hpp
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  timestamp: '2023-05-24 23:37:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/data_structure/min_cost_flow.test.cpp
  - verify/aoj/data_structure/binary_trie.test.cpp
  - verify/aoj/data_structure/max_flow.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
  - verify/library_checker/algorithm/lis.test.cpp
  - verify/library_checker/geometry/angle_sort.test.cpp
  - verify/library_checker/number/nim_product.test.cpp
  - verify/library_checker/number/bicoef.test.cpp
  - verify/library_checker/number/fps_inv_sparse.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - verify/library_checker/graph/tree/rerooting.test.cpp
  - verify/library_checker/string/rolling_hash.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - verify/library_checker/data_structure/binary_trie.test.cpp
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/union_find.test.cpp
  - verify/library_checker/data_structure/point_add_rect_sum.test.cpp
documentation_of: src/utility/key_val.hpp
layout: document
redirect_from:
- /library/src/utility/key_val.hpp
- /library/src/utility/key_val.hpp.html
title: src/utility/key_val.hpp
---