---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/lis.test.cpp
    title: verify/library_checker/algorithm/lis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/lis.hpp\"\ntemplate < class T, class Cmp >\n\
    tuple< vector< T >, vector<int>, vector<int> > l_s(const vector< T >& a, Cmp cmp)\
    \ {\n    int n = a.size();\n    vector< T > lis;\n    vector<int> st(n, -1), nt(n,\
    \ -1), rank(n);\n    rep(i,n) {\n        int pos = lower_bound(lis.begin(), lis.end(),\
    \ a[i], cmp) - lis.begin();\n        st[pos] = i;\n        if(pos >= 1) nt[i]\
    \ = st[pos - 1];\n        if(pos == int(lis.size())) lis.push_back(a[i]); else\
    \ lis[pos] = a[i];\n        rank[i] = pos + 1;\n    }\n    int len = lis.size();\n\
    \    vector<int> idx(len);\n    for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len]\
    \ = i;\n    return {lis, idx, rank};\n}\n"
  code: "template < class T, class Cmp >\ntuple< vector< T >, vector<int>, vector<int>\
    \ > l_s(const vector< T >& a, Cmp cmp) {\n    int n = a.size();\n    vector< T\
    \ > lis;\n    vector<int> st(n, -1), nt(n, -1), rank(n);\n    rep(i,n) {\n   \
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
  timestamp: '2023-03-30 23:30:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/algorithm/lis.test.cpp
documentation_of: src/algorithm/lis.hpp
layout: document
title: Longest Increasing Subsequence
---

## 使い方
長さ $N$ の列 $A$ と比較関数 $\mathrm{cmp} : T \times T \to \lbrace	\mathrm{True}, \mathrm{False}\rbrace$ がある。 $A$ の部分列 $B$ が $\mathrm{Longest \  ? \  Subsequence} \ (\mathrm{L?S})$ であることを次のように定める。

> $B$ の長さを $M$ とする。任意の $i \ (1 \leq i < M)$ について $\mathrm{cmp}(B_i, B_{i+1}) = \mathrm{True}$ が成り立つ。

$O(N \log N)$ 時間の計算により、次の組を返す。
- $\mathrm{l?s}$ : $A$ の $\mathrm{cmp}$ における $\mathrm{L?S}$ 
- $\mathrm{idx}$ : $\mathrm{L?S}$ が $A$ において現れる位置 
- $\mathrm{rank}$ : $\mathrm{rank} \lbrack i \rbrack :=$ $A_i$ を最後の要素とする $\mathrm{L?S}$ の長さ 
