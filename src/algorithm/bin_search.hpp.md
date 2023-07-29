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
  bundledCode: "#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate < class T, class\
    \ F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok - ng) > 1) {\n     \
    \   T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return\
    \ ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T ok, T ng, F& f,\
    \ int step = 80) {\n    while(step--) {\n        T mid = (ok + ng) / 2;\n    \
    \    (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n"
  code: "template < class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok\
    \ - ng) > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/bin_search.hpp
  requiredBy: []
  timestamp: '2023-07-29 19:05:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/bin_search.hpp
layout: document
redirect_from:
- /library/src/algorithm/bin_search.hpp
- /library/src/algorithm/bin_search.hpp.html
title: src/algorithm/bin_search.hpp
---
