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
  bundledCode: "#line 1 \"src/algorithm/enumrate_quotient.hpp\"\n// x in [L, R), floor(N/x)\
    \ == Q\ntemplate < class T, class F >\nvoid for_each_quotient(T N, const F& f)\
    \ {\n    for(T L = 1; L <= N;) {\n        T Q = N / L, R = N / Q + 1;\n      \
    \  f(L, R, Q);\n        L = R;\n    }\n}\n"
  code: "// x in [L, R), floor(N/x) == Q\ntemplate < class T, class F >\nvoid for_each_quotient(T\
    \ N, const F& f) {\n    for(T L = 1; L <= N;) {\n        T Q = N / L, R = N /\
    \ Q + 1;\n        f(L, R, Q);\n        L = R;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/enumrate_quotient.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/enumrate_quotient.hpp
layout: document
redirect_from:
- /library/src/algorithm/enumrate_quotient.hpp
- /library/src/algorithm/enumrate_quotient.hpp.html
title: src/algorithm/enumrate_quotient.hpp
---
