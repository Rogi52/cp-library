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
  bundledCode: "#line 1 \"src/number/bicoef.hpp\"\ntemplate < class mint >\nclass\
    \ bicoef {\n    int N;\n    vector<mint> fact_, inv_, finv_;\n  public:\n    bicoef(int\
    \ N) : N(N), fact_(N+1, 1), inv_(N+1, 1), finv_(N+1, 1) {\n        uint mod =\
    \ mint::mod;\n        for(int i = 2; i <= N; i++) {\n            fact_[i] = fact_[i\
    \ - 1] * i;\n            inv_ [i] = - inv_[mod % i] * (mod / i);\n           \
    \ finv_[i] = finv_[i - 1] * inv_[i];\n        }\n    }\n    mint fact(int n) {\
    \ assert(0 <= n && n <= N); return fact_[n]; }\n    mint inv (int n) { assert(0\
    \ <= n && n <= N); return inv_ [n]; }\n    mint finv(int n) { assert(0 <= n &&\
    \ n <= N); return finv_[n]; }\n    mint comb(int n, int k) { return fact(n) *\
    \ finv(k) * finv(n - k); }\n    mint perm(int n, int k) { return fact(n) * finv(n\
    \ - k); }\n    mint homo(int n, int k) { return comb(n + k - 1, k); }\n};\n"
  code: "template < class mint >\nclass bicoef {\n    int N;\n    vector<mint> fact_,\
    \ inv_, finv_;\n  public:\n    bicoef(int N) : N(N), fact_(N+1, 1), inv_(N+1,\
    \ 1), finv_(N+1, 1) {\n        uint mod = mint::mod;\n        for(int i = 2; i\
    \ <= N; i++) {\n            fact_[i] = fact_[i - 1] * i;\n            inv_ [i]\
    \ = - inv_[mod % i] * (mod / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n\
    \        }\n    }\n    mint fact(int n) { assert(0 <= n && n <= N); return fact_[n];\
    \ }\n    mint inv (int n) { assert(0 <= n && n <= N); return inv_ [n]; }\n   \
    \ mint finv(int n) { assert(0 <= n && n <= N); return finv_[n]; }\n    mint comb(int\
    \ n, int k) { return fact(n) * finv(k) * finv(n - k); }\n    mint perm(int n,\
    \ int k) { return fact(n) * finv(n - k); }\n    mint homo(int n, int k) { return\
    \ comb(n + k - 1, k); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/bicoef.hpp
  requiredBy: []
  timestamp: '2023-03-26 01:52:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/bicoef.hpp
layout: document
redirect_from:
- /library/src/number/bicoef.hpp
- /library/src/number/bicoef.hpp.html
title: src/number/bicoef.hpp
---
