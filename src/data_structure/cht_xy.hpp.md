---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structure/cht_xy.hpp\"\ntemplate < class T > class\
    \ CHT_xy {\n  private:\n    using Point = pair< T, T >;\n    vector< Point > ps;\n\
    \    bool is_prepared = false;\n\n    T eval(int i, T x, T y) {\n        i %=\
    \ size(); if(i < 0) i += size();\n        auto [a, b] = ps[i];\n        return\
    \ a * x + b * y;\n    }\n\n    struct rets {\n        Point p; T v;\n    };\n\n\
    \  public:\n    CHT_xy() {}\n    CHT_xy(vector< Point > &ps) : ps(ps) {}\n\n \
    \   int size() { return ps.size(); }\n\n    void clear() { ps.clear(); is_prepared\
    \ = false; }\n\n    void add(T a, T b) {\n        assert(!is_prepared);\n    \
    \    ps.push_back(Point(a, b));\n    }\n\n    void build() {\n        assert(!is_prepared);\n\
    \        is_prepared = true;\n        ps = convex_hull< T >(ps).second;\n    }\n\
    \n    rets get_min(T x, T y) {\n        assert(is_prepared);\n        auto f =\
    \ [&](int i) -> T { return +eval(i, x, y); };\n        auto [i, minimum] = find_min<\
    \ T >(f, size());\n        return {ps[i], +minimum};\n    }\n\n    rets get_max(T\
    \ x, T y) {\n        assert(is_prepared);\n        auto f = [&](int i) -> T {\
    \ return -eval(i, x, y); };\n        auto [i, minimum] = find_min< T >(f, size());\n\
    \        return {ps[i], -minimum};\n    }\n};\n"
  code: "template < class T > class CHT_xy {\n  private:\n    using Point = pair<\
    \ T, T >;\n    vector< Point > ps;\n    bool is_prepared = false;\n\n    T eval(int\
    \ i, T x, T y) {\n        i %= size(); if(i < 0) i += size();\n        auto [a,\
    \ b] = ps[i];\n        return a * x + b * y;\n    }\n\n    struct rets {\n   \
    \     Point p; T v;\n    };\n\n  public:\n    CHT_xy() {}\n    CHT_xy(vector<\
    \ Point > &ps) : ps(ps) {}\n\n    int size() { return ps.size(); }\n\n    void\
    \ clear() { ps.clear(); is_prepared = false; }\n\n    void add(T a, T b) {\n \
    \       assert(!is_prepared);\n        ps.push_back(Point(a, b));\n    }\n\n \
    \   void build() {\n        assert(!is_prepared);\n        is_prepared = true;\n\
    \        ps = convex_hull< T >(ps).second;\n    }\n\n    rets get_min(T x, T y)\
    \ {\n        assert(is_prepared);\n        auto f = [&](int i) -> T { return +eval(i,\
    \ x, y); };\n        auto [i, minimum] = find_min< T >(f, size());\n        return\
    \ {ps[i], +minimum};\n    }\n\n    rets get_max(T x, T y) {\n        assert(is_prepared);\n\
    \        auto f = [&](int i) -> T { return -eval(i, x, y); };\n        auto [i,\
    \ minimum] = find_min< T >(f, size());\n        return {ps[i], -minimum};\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht_xy.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/cht_xy.hpp
layout: document
redirect_from:
- /library/src/data_structure/cht_xy.hpp
- /library/src/data_structure/cht_xy.hpp.html
title: src/data_structure/cht_xy.hpp
---
