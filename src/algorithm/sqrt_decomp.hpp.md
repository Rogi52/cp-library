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
  bundledCode: '#line 1 "src/algorithm/sqrt_decomp.hpp"

    int B = sqrt(N); // bucket size

    int NB = (N + B - 1) / B; // num of bucket


    // [L, R) query

    int i = L;

    for(; i < R && i % B != 0; i++) { /* data[i] */ }

    for(; i + B <= R; i += B) { /* bucket[i / B] */ }

    for(; i < R; i++) { /* data[i] */ }

    '
  code: 'int B = sqrt(N); // bucket size

    int NB = (N + B - 1) / B; // num of bucket


    // [L, R) query

    int i = L;

    for(; i < R && i % B != 0; i++) { /* data[i] */ }

    for(; i + B <= R; i += B) { /* bucket[i / B] */ }

    for(; i < R; i++) { /* data[i] */ }

    '
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/sqrt_decomp.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/sqrt_decomp.hpp
layout: document
redirect_from:
- /library/src/algorithm/sqrt_decomp.hpp
- /library/src/algorithm/sqrt_decomp.hpp.html
title: src/algorithm/sqrt_decomp.hpp
---
