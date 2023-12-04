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
  bundledCode: "#line 1 \"src/algorithm/find_local_min.hpp\"\n// f: [0, n) -> T\n\
    template < class T, class func > pair< int, T > find_local_min(func f, int n)\
    \ {\n    int a = 0, b = (n + 1) / 2, c = n + 1;\n    while(c - a > 2) {\n    \
    \    int l = (a + b) / 2, r = (b + c + 1) / 2;\n        if(f(l) < f(b))\n    \
    \        tie(a, b, c) = make_tuple(a, l, b);\n        else if(f(b) > f(r))\n \
    \           tie(a, b, c) = make_tuple(b, r, c);\n        else\n            tie(a,\
    \ b, c) = make_tuple(l, b, r);\n    }\n    return {b, f(b)};\n};\n\n// f: [0,\
    \ p) -> T, f(x) = f(x + p)\ntemplate < class T, class func > pair< int, T > find_min(func\
    \ f, int p) {\n    return find_local_min< T, func >(f, 2 * p - 1);\n}\n"
  code: "// f: [0, n) -> T\ntemplate < class T, class func > pair< int, T > find_local_min(func\
    \ f, int n) {\n    int a = 0, b = (n + 1) / 2, c = n + 1;\n    while(c - a > 2)\
    \ {\n        int l = (a + b) / 2, r = (b + c + 1) / 2;\n        if(f(l) < f(b))\n\
    \            tie(a, b, c) = make_tuple(a, l, b);\n        else if(f(b) > f(r))\n\
    \            tie(a, b, c) = make_tuple(b, r, c);\n        else\n            tie(a,\
    \ b, c) = make_tuple(l, b, r);\n    }\n    return {b, f(b)};\n};\n\n// f: [0,\
    \ p) -> T, f(x) = f(x + p)\ntemplate < class T, class func > pair< int, T > find_min(func\
    \ f, int p) {\n    return find_local_min< T, func >(f, 2 * p - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/find_local_min.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/find_local_min.hpp
layout: document
redirect_from:
- /library/src/algorithm/find_local_min.hpp
- /library/src/algorithm/find_local_min.hpp.html
title: src/algorithm/find_local_min.hpp
---
