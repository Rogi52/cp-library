---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  bundledCode: "#line 1 \"src/utility/zip.hpp\"\ntemplate < class T >\nstruct zipper\
    \ {\n  public:\n    zipper() {}\n    vector< T > data;\n    void insert(const\
    \ T x) {\n        built = 0;\n        data.push_back(x);\n    }\n    void insert(const\
    \ vector< T > v) {\n        built = 0;\n        data.insert(data.end(), v.begin(),\
    \ v.end());\n    }\n    template < class... args > zipper(args... a) { insert(a...);\
    \ }\n    template < class... args > void insert(const T x, args... a) { insert(x);\
    \ insert(a...); }\n    template < class... args > void insert(const vector< T\
    \ > x, args... a) { insert(x); insert(a...); }\n\n    void build() {\n       \
    \ sort(data.begin(), data.end());\n        data.erase(unique(data.begin(), data.end()),\
    \ data.end());\n        built = 1;\n    }\n\n    int id(const T x) {\n       \
    \ assert(built);\n        return lower_bound(data.begin(), data.end(), x) - data.begin();\n\
    \    }\n    vector<int> zip(const vector< T >& x) {\n        assert(built);\n\
    \        vector<int> idx(x.size());\n        for(int i : rep(x.size())) idx[i]\
    \ = id(x[i]);\n        return idx;\n    }\n    int size() {\n        assert(built);\n\
    \        return data.size();\n    }\n\n  private:\n    int built = 0;\n};\n"
  code: "template < class T >\nstruct zipper {\n  public:\n    zipper() {}\n    vector<\
    \ T > data;\n    void insert(const T x) {\n        built = 0;\n        data.push_back(x);\n\
    \    }\n    void insert(const vector< T > v) {\n        built = 0;\n        data.insert(data.end(),\
    \ v.begin(), v.end());\n    }\n    template < class... args > zipper(args... a)\
    \ { insert(a...); }\n    template < class... args > void insert(const T x, args...\
    \ a) { insert(x); insert(a...); }\n    template < class... args > void insert(const\
    \ vector< T > x, args... a) { insert(x); insert(a...); }\n\n    void build() {\n\
    \        sort(data.begin(), data.end());\n        data.erase(unique(data.begin(),\
    \ data.end()), data.end());\n        built = 1;\n    }\n\n    int id(const T x)\
    \ {\n        assert(built);\n        return lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n    }\n    vector<int> zip(const vector< T >& x) {\n   \
    \     assert(built);\n        vector<int> idx(x.size());\n        for(int i :\
    \ rep(x.size())) idx[i] = id(x[i]);\n        return idx;\n    }\n    int size()\
    \ {\n        assert(built);\n        return data.size();\n    }\n\n  private:\n\
    \    int built = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/zip.hpp
  requiredBy:
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/data_structure/static_rect_add_rect_sum.hpp
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rect_add_rect_sum.test.cpp
  - verify/library_checker/data_structure/rectangle_sum.test.cpp
  - verify/library_checker/data_structure/point_add_rect_sum.test.cpp
documentation_of: src/utility/zip.hpp
layout: document
redirect_from:
- /library/src/utility/zip.hpp
- /library/src/utility/zip.hpp.html
title: src/utility/zip.hpp
---
