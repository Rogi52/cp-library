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
  bundledCode: "#line 1 \"src/number/quotient_range.hpp\"\nusing ll = long long;\n\
    vector< pair< pair< ll, ll >, ll > > quotient_range(ll N) {\n    vector< pair<\
    \ pair< ll, ll >, ll > > res;\n    for(ll L = 1; L <= N; L = N / (N / L) + 1)\
    \ {\n        ll X = N / L, R = N / X;\n        res.push_back({{L, R}, X});\n \
    \   }\n    return res;\n}\n"
  code: "using ll = long long;\nvector< pair< pair< ll, ll >, ll > > quotient_range(ll\
    \ N) {\n    vector< pair< pair< ll, ll >, ll > > res;\n    for(ll L = 1; L <=\
    \ N; L = N / (N / L) + 1) {\n        ll X = N / L, R = N / X;\n        res.push_back({{L,\
    \ R}, X});\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/quotient_range.hpp
  requiredBy: []
  timestamp: '2022-03-26 18:53:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/quotient_range.hpp
layout: document
redirect_from:
- /library/src/number/quotient_range.hpp
- /library/src/number/quotient_range.hpp.html
title: src/number/quotient_range.hpp
---
