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
  bundledCode: "#line 2 \"src/utility/vec_op.hpp\"\ntemplate < class T > key_val<\
    \ int, T > max_of(const vector< T >& a) {\n    int i = std::max_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\ntemplate < class T > key_val<\
    \ int, T > min_of(const vector< T >& a) {\n    int i = std::min_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\ntemplate < class S, class T\
    \ > S sum_of(const vector< T >& a) {\n    S sum = 0;\n    for(const T x : a) sum\
    \ += x;\n    return sum;\n}\ntemplate < class S, class T > vector< S > freq_of(const\
    \ vector< T >& a, T L, T R) {\n    vector< S > res(R - L, S(0));\n    for(const\
    \ T x : a) res[x - L] += 1;\n    return res;\n}\ntemplate < class S, class T >\
    \ struct prefix_sum {\n    vector< S > s;\n    prefix_sum(const vector< T >& a)\
    \ : s(a) {\n        s.insert(s.begin(), S(0));\n        for(int i : rep(a.size()))\
    \ s[i + 1] += s[i];\n    }\n    // [L, R)\n    S sum(int L, int R) { return s[R]\
    \ - s[L]; }\n};\n"
  code: "#pragma once\ntemplate < class T > key_val< int, T > max_of(const vector<\
    \ T >& a) {\n    int i = std::max_element(a.begin(), a.end()) - a.begin();\n \
    \   return {i, a[i]};\n}\ntemplate < class T > key_val< int, T > min_of(const\
    \ vector< T >& a) {\n    int i = std::min_element(a.begin(), a.end()) - a.begin();\n\
    \    return {i, a[i]};\n}\ntemplate < class S, class T > S sum_of(const vector<\
    \ T >& a) {\n    S sum = 0;\n    for(const T x : a) sum += x;\n    return sum;\n\
    }\ntemplate < class S, class T > vector< S > freq_of(const vector< T >& a, T L,\
    \ T R) {\n    vector< S > res(R - L, S(0));\n    for(const T x : a) res[x - L]\
    \ += 1;\n    return res;\n}\ntemplate < class S, class T > struct prefix_sum {\n\
    \    vector< S > s;\n    prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(),\
    \ S(0));\n        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    //\
    \ [L, R)\n    S sum(int L, int R) { return s[R] - s[L]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/vec_op.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/vec_op.hpp
layout: document
redirect_from:
- /library/src/utility/vec_op.hpp
- /library/src/utility/vec_op.hpp.html
title: src/utility/vec_op.hpp
---
