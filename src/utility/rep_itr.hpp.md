---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr\
    \ {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n    constexpr\
    \ itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++() noexcept\
    \ { i += d; }\n    constexpr int operator*() const noexcept { return i; }\n  \
    \  constexpr bool operator!=(const itr x) const noexcept {\n        return d >\
    \ 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n   \
    \ const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n\
    \    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n"
  code: "#pragma once\ntemplate < class T > struct itr {\n    T i, d;\n    constexpr\
    \ itr(const T i) noexcept : i(i), d(1) {}\n    constexpr itr(const T i, const\
    \ T d) noexcept : i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n\
    \    constexpr int operator*() const noexcept { return i; }\n    constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return d > 0 ? i < x.i : i\
    \ > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n    const itr< T > s,\
    \ t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const\
    \ T s, const T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const\
    \ T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const\
    \ noexcept { return s; }\n    constexpr auto end() const noexcept { return t;\
    \ }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T > s, t;\n \
    \   constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr\
    \ revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr\
    \ revrep(const T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d)\
    \ {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr auto\
    \ end() const noexcept { return t; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/rep_itr.hpp
  requiredBy:
  - src/data_structure/binary_trie.hpp
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/data_structure/static_rect_add_rect_sum.hpp
  - src/cp-template.hpp
  - src/graph/tree/rerooting.hpp
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
documentation_of: src/utility/rep_itr.hpp
layout: document
redirect_from:
- /library/src/utility/rep_itr.hpp
- /library/src/utility/rep_itr.hpp.html
title: src/utility/rep_itr.hpp
---
