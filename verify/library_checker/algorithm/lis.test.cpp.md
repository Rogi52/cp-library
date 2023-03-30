---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/lis.hpp
    title: Longest Increasing Subsequence
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ long;\n#line 1 \"src/algorithm/lis.hpp\"\ntemplate < class T, class Cmp >\n\
    tuple< vector< T >, vector<int>, vector<int> > l_s(const vector< T >& a, Cmp cmp)\
    \ {\n    int n = a.size();\n    vector< T > l_s;\n    vector<int> st(n, -1), nt(n,\
    \ -1), rank(n);\n    rep(i,n) {\n        int pos = lower_bound(l_s.begin(), l_s.end(),\
    \ a[i], cmp) - l_s.begin();\n        st[pos] = i;\n        if(pos >= 1) nt[i]\
    \ = st[pos - 1];\n        if(pos == int(l_s.size())) l_s.push_back(a[i]); else\
    \ l_s[pos] = a[i];\n        rank[i] = pos + 1;\n    }\n    int len = l_s.size();\n\
    \    vector<int> idx(len);\n    for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len]\
    \ = i;\n    return {l_s, idx, rank};\n}\n#line 5 \"verify/library_checker/algorithm/lis.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N; cin >> N;\n    vector<int> A(N);\n    rep(i,N) cin >> A[i];\n\n    auto [lis,\
    \ idx, rank] = l_s(A, [&](int a, int b) { return a < b; });\n    int K = idx.size();\n\
    \    cout << K << \"\\n\";\n    rep(i,K) cout << idx[i] << \" \\n\"[i == K - 1];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/algorithm/lis.hpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N; cin\
    \ >> N;\n    vector<int> A(N);\n    rep(i,N) cin >> A[i];\n\n    auto [lis, idx,\
    \ rank] = l_s(A, [&](int a, int b) { return a < b; });\n    int K = idx.size();\n\
    \    cout << K << \"\\n\";\n    rep(i,K) cout << idx[i] << \" \\n\"[i == K - 1];\n\
    }\n"
  dependsOn:
  - src/cp-template.hpp
  - src/algorithm/lis.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/lis.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 00:03:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/lis.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/lis.test.cpp
- /verify/verify/library_checker/algorithm/lis.test.cpp.html
title: verify/library_checker/algorithm/lis.test.cpp
---
