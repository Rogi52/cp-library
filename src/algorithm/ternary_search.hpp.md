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
  bundledCode: "#line 1 \"src/algorithm/ternary_search.hpp\"\ntemplate < class K,\
    \ class V, class F >\nstd::pair< K, V > ternary_search(K L, K R, F f) {\n    while(R\
    \ - L >= K(3)) {\n        K kL = (L + L + R) / 3, kR = (L + R + R) / 3;\n    \
    \    V vL = f(kL), vR = f(kR);\n        if(vL < vR) R = kR; else L = kL;\n   \
    \ }\n    std::pair< K, V > res = {R, f(R)};\n    for(K k : rep(L, R)) {\n    \
    \    V v = f(k);\n        if(v < res.second) res = std::make_pair(k, v);\n   \
    \ }\n    return res;\n}\n\ntemplate < class K, class V, class F >\nstd::pair<\
    \ K, V > ternary_search_real(K L, K R, F f, int step = 80) {\n    while(step--)\
    \ {\n        K kL = (L + L + R) / 3, kR = (L + R + R) / 3;\n        V vL = f(kL),\
    \ vR = f(kR);\n        if(vL < vR) R = kR; else L = kL;\n    }\n    return std::make_pair(L,\
    \ f(L));\n}\n"
  code: "template < class K, class V, class F >\nstd::pair< K, V > ternary_search(K\
    \ L, K R, F f) {\n    while(R - L >= K(3)) {\n        K kL = (L + L + R) / 3,\
    \ kR = (L + R + R) / 3;\n        V vL = f(kL), vR = f(kR);\n        if(vL < vR)\
    \ R = kR; else L = kL;\n    }\n    std::pair< K, V > res = {R, f(R)};\n    for(K\
    \ k : rep(L, R)) {\n        V v = f(k);\n        if(v < res.second) res = std::make_pair(k,\
    \ v);\n    }\n    return res;\n}\n\ntemplate < class K, class V, class F >\nstd::pair<\
    \ K, V > ternary_search_real(K L, K R, F f, int step = 80) {\n    while(step--)\
    \ {\n        K kL = (L + L + R) / 3, kR = (L + R + R) / 3;\n        V vL = f(kL),\
    \ vR = f(kR);\n        if(vL < vR) R = kR; else L = kL;\n    }\n    return std::make_pair(L,\
    \ f(L));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/ternary_search.hpp
  requiredBy: []
  timestamp: '2023-10-21 06:29:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/ternary_search.hpp
layout: document
redirect_from:
- /library/src/algorithm/ternary_search.hpp
- /library/src/algorithm/ternary_search.hpp.html
title: src/algorithm/ternary_search.hpp
---
