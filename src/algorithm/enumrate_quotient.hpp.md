---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/stern-brocot_tree_search.test.cpp
    title: verify/yukicoder/stern-brocot_tree_search.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  timestamp: '2023-10-31 17:44:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yukicoder/stern-brocot_tree_search.test.cpp
documentation_of: src/algorithm/enumrate_quotient.hpp
layout: document
redirect_from:
- /library/src/algorithm/enumrate_quotient.hpp
- /library/src/algorithm/enumrate_quotient.hpp.html
title: src/algorithm/enumrate_quotient.hpp
---
