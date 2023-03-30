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
  bundledCode: "#line 1 \"src/algorithm/lis.hpp\"\ntemplate < class T >\npair< vector<\
    \ T >, vector<int> > lis(const vector< T >& a, bool strict) {\n    int n = a.size();\n\
    \    vector< T > lis;\n    vector<int> res(n);\n    rep(i,n) {\n        auto it\
    \ = (strict ? lower_bound(lis.begin(), lis.end(), a[i])\n                    \
    \      : upper_bound(lis.begin(), lis.end(), a[i]));\n        (lis.end() == it\
    \ ? lis.push_back(a[i]) : *it = a[i]);\n        res[i] = lis.size();\n    }\n\
    \    return {lis, res};\n}\n"
  code: "template < class T >\npair< vector< T >, vector<int> > lis(const vector<\
    \ T >& a, bool strict) {\n    int n = a.size();\n    vector< T > lis;\n    vector<int>\
    \ res(n);\n    rep(i,n) {\n        auto it = (strict ? lower_bound(lis.begin(),\
    \ lis.end(), a[i])\n                          : upper_bound(lis.begin(), lis.end(),\
    \ a[i]));\n        (lis.end() == it ? lis.push_back(a[i]) : *it = a[i]);\n   \
    \     res[i] = lis.size();\n    }\n    return {lis, res};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/lis.hpp
  requiredBy: []
  timestamp: '2023-03-30 22:35:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/lis.hpp
layout: document
redirect_from:
- /library/src/algorithm/lis.hpp
- /library/src/algorithm/lis.hpp.html
title: src/algorithm/lis.hpp
---
