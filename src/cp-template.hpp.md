---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':x:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  - icon: ':x:'
    path: verify/library_checker/algorithm/lis.test.cpp
    title: verify/library_checker/algorithm/lis.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/fenwick_tree.test.cpp
    title: verify/library_checker/data_structure/fenwick_tree.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/line_add_get_min.test.cpp
    title: verify/library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/segment_add_get_min.test.cpp
    title: verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/union_find.test.cpp
    title: verify/library_checker/data_structure/union_find.test.cpp
  - icon: ':x:'
    path: verify/library_checker/geometry/angle_sort.test.cpp
    title: verify/library_checker/geometry/angle_sort.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/tree/cartesian_tree.test.cpp
    title: verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - icon: ':x:'
    path: verify/library_checker/string/rolling_hash.test.cpp
    title: verify/library_checker/string/rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\ntemplate < class T > bool chmin(T& a,\
    \ T b) { if(a > b) { a = b; return true; } return false; }\ntemplate < class T\
    \ > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }\n\
    \n#line 1 \"src/utility/io.hpp\"\nnamespace scanner {\n    static int sz = -1;\n\
    \    static int first = 1;\n    struct input {\n        template < class T > operator\
    \ T() const {\n            if(first) {\n                first = 0;\n         \
    \       cin.tie(0);\n                ios::sync_with_stdio(0);\n            }\n\
    \            if(sz == -1) {\n                T t; cin >> t; return t;\n      \
    \      } else {\n                T t(sz); sz = -1; cin >> t; return t;\n     \
    \       }\n        }\n    };\n\n    template < class T > istream& operator>>(istream&\
    \ is, vector< T >& a) {\n        for(auto& x : a) cin >> x; return is;\n    }\n\
    }\nscanner::input input() { return scanner::input(); }\nscanner::input input(int\
    \ sz) { scanner::sz = sz; return scanner::input(); }\n\nnamespace printer {\n\
    \    void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    }\nint print() { cout << \"\\n\"; return 0; }\ntemplate < class head, class...\
    \ tail >\nint print(head&& h, tail&&... t) {\n    cout << h;\n    if(sizeof...(tail))\
    \ cout << \" \";\n    return print(forward<tail>(t)...);\n}\ntemplate < class\
    \ T > int print(vector< T >& a, char sep = ' ') {\n    int n = a.size();\n   \
    \ rep(i,n) cout << a[i] << (i < n - 1 ? sep : '\\n');\n    return 0;\n}\n#line\
    \ 1 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr {\n    T i, d;\n\
    \    constexpr itr(const T i) noexcept : i(i), d(1) {}\n    constexpr itr(const\
    \ T i, const T d) noexcept : i(i), d(d) {}\n    void operator++() noexcept { i\
    \ += d; }\n    constexpr int operator*() const noexcept { return i; }\n    constexpr\
    \ bool operator!=(const itr x) const noexcept {\n        return d > 0 ? i < x.i\
    \ : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n    const itr< T\
    \ > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n    constexpr\
    \ rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr rep(const\
    \ T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto\
    \ begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 12 \"src/cp-template.hpp\"\n"
  code: '#include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using ld = long double;

    using uint = unsigned int;

    using ull  = unsigned long long;

    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }
    return false; }

    template < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; }
    return false; }


    #include "src/utility/io.hpp"

    #include "src/utility/rep_itr.hpp"

    '
  dependsOn:
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  isVerificationFile: false
  path: src/cp-template.hpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - verify/library_checker/geometry/angle_sort.test.cpp
  - verify/library_checker/string/rolling_hash.test.cpp
  - verify/library_checker/data_structure/union_find.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
  - verify/library_checker/algorithm/lis.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
documentation_of: src/cp-template.hpp
layout: document
redirect_from:
- /library/src/cp-template.hpp
- /library/src/cp-template.hpp.html
title: src/cp-template.hpp
---
