---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/algorithm/count_subseq.test.cpp
    title: verify/library_checker/algorithm/count_subseq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/count_subseq.hpp\"\ntemplate < class mint,\
    \ class T >\nmint count_subseq(const vector< T >& a) {\n    int n = a.size();\n\
    \    unordered_map< T, int > mp;\n    vector<mint> dp(n + 1);\n    dp[0] = 1;\n\
    \    rep(i,n) {\n        dp[i + 1] = dp[i] + dp[i];\n        if(mp.count(a[i]))\
    \ dp[i + 1] -= dp[mp[a[i]]];\n        mp[a[i]] = i;\n    }\n    return dp[n];\n\
    }\n"
  code: "template < class mint, class T >\nmint count_subseq(const vector< T >& a)\
    \ {\n    int n = a.size();\n    unordered_map< T, int > mp;\n    vector<mint>\
    \ dp(n + 1);\n    dp[0] = 1;\n    rep(i,n) {\n        dp[i + 1] = dp[i] + dp[i];\n\
    \        if(mp.count(a[i])) dp[i + 1] -= dp[mp[a[i]]];\n        mp[a[i]] = i;\n\
    \    }\n    return dp[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/count_subseq.hpp
  requiredBy: []
  timestamp: '2023-03-31 01:30:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/algorithm/count_subseq.test.cpp
documentation_of: src/algorithm/count_subseq.hpp
layout: document
redirect_from:
- /library/src/algorithm/count_subseq.hpp
- /library/src/algorithm/count_subseq.hpp.html
title: src/algorithm/count_subseq.hpp
---
