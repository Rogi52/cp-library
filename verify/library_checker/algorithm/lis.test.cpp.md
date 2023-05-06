---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algorithm/lis.hpp
    title: Longest Increasing Subsequence
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"verify/library_checker/algorithm/lis.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long\
    \ long;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return\
    \ true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a <\
    \ b) { a = b; return true; } return false; }\n#line 1 \"src/algorithm/lis.hpp\"\
    \ntemplate < class T, class Cmp >\ntuple< vector< T >, vector<int>, vector<int>\
    \ > l_s(const vector< T >& a, Cmp cmp) {\n    int n = a.size();\n    vector< T\
    \ > l_s;\n    vector<int> st(n, -1), nt(n, -1), rank(n);\n    rep(i,n) {\n   \
    \     int pos = lower_bound(l_s.begin(), l_s.end(), a[i], cmp) - l_s.begin();\n\
    \        st[pos] = i;\n        if(pos >= 1) nt[i] = st[pos - 1];\n        if(pos\
    \ == int(l_s.size())) l_s.push_back(a[i]); else l_s[pos] = a[i];\n        rank[i]\
    \ = pos + 1;\n    }\n    int len = l_s.size();\n    vector<int> idx(len);\n  \
    \  for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len] = i;\n    return {l_s,\
    \ idx, rank};\n}\n#line 5 \"verify/library_checker/algorithm/lis.test.cpp\"\n\n\
    int main(){\n    int N = in();\n    vector<int> A = in(N);\n\n    auto [lis, idx,\
    \ rank] = l_s(A, [&](int a, int b) { return a < b; });\n    print(idx.size());\n\
    \    print(idx);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/algorithm/lis.hpp\"\n\nint\
    \ main(){\n    int N = in();\n    vector<int> A = in(N);\n\n    auto [lis, idx,\
    \ rank] = l_s(A, [&](int a, int b) { return a < b; });\n    print(idx.size());\n\
    \    print(idx);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/algorithm/lis.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/lis.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:20:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/lis.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/lis.test.cpp
- /verify/verify/library_checker/algorithm/lis.test.cpp.html
title: verify/library_checker/algorithm/lis.test.cpp
---
