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
  bundledCode: "#line 1 \"src/algorithm/lis.hpp\"\ntemplate < class T, class Cmp >\n\
    tuple< vector< T >, vector<int>, vector<int> > l_s(const vector< T >& a, Cmp cmp)\
    \ {\n    int n = a.size();\n    vector< T > lis;\n    vector<int> rank(n), st(n,\
    \ -1), nt(n, -1);\n    rep(i,n) {\n        int pos = lower_bound(lis.begin(),\
    \ lis.end(), a[i], cmp) - lis.begin();\n        st[pos] = i;\n        if(pos >=\
    \ 1) nt[i] = st[pos - 1];\n        if(pos == int(lis.size())) lis.push_back(a[i]);\
    \ else lis[pos] = a[i];\n        rank[i] = pos + 1;\n    }\n    int len = lis.size();\n\
    \    vector<int> idx(len);\n    for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len]\
    \ = i;\n    return {lis, idx, rank};\n}\n"
  code: "template < class T, class Cmp >\ntuple< vector< T >, vector<int>, vector<int>\
    \ > l_s(const vector< T >& a, Cmp cmp) {\n    int n = a.size();\n    vector< T\
    \ > lis;\n    vector<int> rank(n), st(n, -1), nt(n, -1);\n    rep(i,n) {\n   \
    \     int pos = lower_bound(lis.begin(), lis.end(), a[i], cmp) - lis.begin();\n\
    \        st[pos] = i;\n        if(pos >= 1) nt[i] = st[pos - 1];\n        if(pos\
    \ == int(lis.size())) lis.push_back(a[i]); else lis[pos] = a[i];\n        rank[i]\
    \ = pos + 1;\n    }\n    int len = lis.size();\n    vector<int> idx(len);\n  \
    \  for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len] = i;\n    return {lis,\
    \ idx, rank};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/lis.hpp
  requiredBy: []
  timestamp: '2023-03-30 23:29:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/lis.hpp
layout: document
redirect_from:
- /library/src/algorithm/lis.hpp
- /library/src/algorithm/lis.hpp.html
title: src/algorithm/lis.hpp
---
