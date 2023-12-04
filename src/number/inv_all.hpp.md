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
  bundledCode: "#line 1 \"src/number/inv_all.hpp\"\nvector<mint> inv_all(const vector<mint>&\
    \ a) {\n    int n = a.size();\n    vector<mint> L(n + 1, 1), R(n + 1, 1);\n  \
    \  for(int i : rep(n)) L[i + 1] = L[i] * a[i];\n    for(int i : revrep(n)) R[i]\
    \ = R[i + 1] * a[i];\n    mint P = inv(L[n]);\n    vector<mint> inva(n);\n   \
    \ for(int i : rep(n)) inva[i] = L[i] * P * R[i + 1];\n    return inva;\n}\n"
  code: "vector<mint> inv_all(const vector<mint>& a) {\n    int n = a.size();\n  \
    \  vector<mint> L(n + 1, 1), R(n + 1, 1);\n    for(int i : rep(n)) L[i + 1] =\
    \ L[i] * a[i];\n    for(int i : revrep(n)) R[i] = R[i + 1] * a[i];\n    mint P\
    \ = inv(L[n]);\n    vector<mint> inva(n);\n    for(int i : rep(n)) inva[i] = L[i]\
    \ * P * R[i + 1];\n    return inva;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/inv_all.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/inv_all.hpp
layout: document
redirect_from:
- /library/src/number/inv_all.hpp
- /library/src/number/inv_all.hpp.html
title: src/number/inv_all.hpp
---
