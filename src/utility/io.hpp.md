---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
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
  bundledCode: "#line 1 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca\
    \ {\n        template < class T > operator T() {\n            T s; cin >> s; return\
    \ s;\n        }\n    };\n    struct vec {\n        int n;\n        vec(int n)\
    \ : n(n) {}\n        template < class T > operator vector< T >() {\n         \
    \   vector< T > v(n);\n            for(T& x : v) cin >> x;\n            return\
    \ v;\n        }\n    };\n    struct mat {\n        int h,w;\n        mat(int h,\
    \ int w) : h(h), w(w) {}\n        template < class T > operator vector< vector<\
    \ T > >() {\n            vector m(h, vector< T >(w));\n            for(vector<\
    \ T >& v : m) for(T& x : v) cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            cin.tie(0);\n        \
    \    ios::sync_with_stdio(0);\n        }\n    } su;\n}\nscanner::sca in() { return\
    \ scanner::sca(); }\nscanner::vec in(int n) { return scanner::vec(n); }\nscanner::mat\
    \ in(int h, int w) { return scanner::mat(h, w); }\n\nnamespace printer {\n   \
    \ void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    \    void flush() {\n        cout.flush();\n    }\n}\nint print() { cout << '\\\
    n'; return 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&...\
    \ t) {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T >& a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > >&\
    \ a) {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n\
    \    for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ?\
    \ ' ' : '\\n');\n    return 0;\n}\n"
  code: "namespace scanner {\n    struct sca {\n        template < class T > operator\
    \ T() {\n            T s; cin >> s; return s;\n        }\n    };\n    struct vec\
    \ {\n        int n;\n        vec(int n) : n(n) {}\n        template < class T\
    \ > operator vector< T >() {\n            vector< T > v(n);\n            for(T&\
    \ x : v) cin >> x;\n            return v;\n        }\n    };\n    struct mat {\n\
    \        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n        template\
    \ < class T > operator vector< vector< T > >() {\n            vector m(h, vector<\
    \ T >(w));\n            for(vector< T >& v : m) for(T& x : v) cin >> x;\n    \
    \        return m;\n        }\n    };\n    struct speedup {\n        speedup()\
    \ {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n        }\n\
    \    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec in(int\
    \ n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h,\
    \ w); }\n\nnamespace printer {\n    void precision(int d) {\n        cout << fixed\
    \ << setprecision(d);\n    }\n    void flush() {\n        cout.flush();\n    }\n\
    }\nint print() { cout << '\\n'; return 0; }\ntemplate < class head, class... tail\
    \ > int print(head&& h, tail&&... t) {\n    cout << h; if(sizeof...(tail)) cout\
    \ << ' ';\n    return print(forward<tail>(t)...);\n}\ntemplate < class T > int\
    \ print(vector< T >& a, char sep = ' ') {\n    int n = a.size();\n    for(int\
    \ i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\n');\n    return 0;\n}\n\
    template < class T > int print(vector< vector< T > >& a) {\n    if(a.empty())\
    \ return 0;\n    int h = a.size(), w = a[0].size();\n    for(int i : rep(h)) for(int\
    \ j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' ' : '\\n');\n    return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/io.hpp
  requiredBy:
  - src/cp-template.hpp
  timestamp: '2023-05-06 07:15:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/tree/cartesian_tree.test.cpp
  - verify/library_checker/geometry/angle_sort.test.cpp
  - verify/library_checker/number/bicoef.test.cpp
  - verify/library_checker/string/rolling_hash.test.cpp
  - verify/library_checker/data_structure/union_find.test.cpp
  - verify/library_checker/data_structure/fenwick_tree.test.cpp
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
  - verify/library_checker/data_structure/segment_add_get_min.test.cpp
  - verify/library_checker/data_structure/segtree.test.cpp
  - verify/library_checker/data_structure/line_add_get_min.test.cpp
  - verify/library_checker/algorithm/lis.test.cpp
  - verify/library_checker/algorithm/count_subseq.test.cpp
documentation_of: src/utility/io.hpp
layout: document
redirect_from:
- /library/src/utility/io.hpp
- /library/src/utility/io.hpp.html
title: src/utility/io.hpp
---
