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
  bundledCode: "#line 2 \"src/number/extgcd.hpp\"\ntemplate < class T >\nT extgcd(T\
    \ a, T b, T& x, T& y) {\n    T g = a;\n    if(b != 0) {\n        g = extgcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n   \
    \     y = 0;\n    }\n    return g;\n}\n"
  code: "#pragma once\ntemplate < class T >\nT extgcd(T a, T b, T& x, T& y) {\n  \
    \  T g = a;\n    if(b != 0) {\n        g = extgcd(b, a % b, y, x);\n        y\
    \ -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return\
    \ g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/number/extgcd.hpp
  requiredBy: []
  timestamp: '2023-10-28 05:38:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/extgcd.hpp
layout: document
redirect_from:
- /library/src/number/extgcd.hpp
- /library/src/number/extgcd.hpp.html
title: src/number/extgcd.hpp
---
