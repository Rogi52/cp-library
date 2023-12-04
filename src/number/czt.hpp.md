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
  bundledCode: "#line 1 \"src/number/czt.hpp\"\nvector<mint> czt(vector<mint> x, mint\
    \ a, mint w, int m) {\n    int n = x.size();\n    if(w == mint(0)) {\n       \
    \ vector<mint> X(m, x[0]);\n        mint p = a;\n        for(int i : rep(1, n))\
    \ {\n            X[0] += x[i] * p;\n            p *= a;\n        }\n        return\
    \ X;\n    }\n\n    auto tri = [](mint b, int sz) {\n        vector<mint> res(sz);\n\
    \        res[0] = 1;\n        mint p = 1;\n        for(int i : rep(sz - 1)) {\n\
    \            res[i + 1] = res[i] * p;\n            p *= b;\n        }\n      \
    \  return res;\n    };\n    \n    vector<mint> iwt = tri(inv(w), n);\n    mint\
    \ p = 1;\n    for(int i : rep(n)) {\n        x[i] *= p * iwt[i];\n        p *=\
    \ a;\n    }\n    reverse(x.begin(), x.end());\n    vector<mint> X = ntt::mul(x,\
    \ tri(w, n + m - 1));\n    X = {X.begin() + n - 1, X.begin() + n - 1 + m};\n \
    \   iwt = tri(inv(w), m);\n    for(int k : rep(m)) X[k] *= iwt[k];\n    return\
    \ X;\n}\n"
  code: "vector<mint> czt(vector<mint> x, mint a, mint w, int m) {\n    int n = x.size();\n\
    \    if(w == mint(0)) {\n        vector<mint> X(m, x[0]);\n        mint p = a;\n\
    \        for(int i : rep(1, n)) {\n            X[0] += x[i] * p;\n           \
    \ p *= a;\n        }\n        return X;\n    }\n\n    auto tri = [](mint b, int\
    \ sz) {\n        vector<mint> res(sz);\n        res[0] = 1;\n        mint p =\
    \ 1;\n        for(int i : rep(sz - 1)) {\n            res[i + 1] = res[i] * p;\n\
    \            p *= b;\n        }\n        return res;\n    };\n    \n    vector<mint>\
    \ iwt = tri(inv(w), n);\n    mint p = 1;\n    for(int i : rep(n)) {\n        x[i]\
    \ *= p * iwt[i];\n        p *= a;\n    }\n    reverse(x.begin(), x.end());\n \
    \   vector<mint> X = ntt::mul(x, tri(w, n + m - 1));\n    X = {X.begin() + n -\
    \ 1, X.begin() + n - 1 + m};\n    iwt = tri(inv(w), m);\n    for(int k : rep(m))\
    \ X[k] *= iwt[k];\n    return X;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/czt.hpp
  requiredBy: []
  timestamp: '2023-05-06 10:05:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/czt.hpp
layout: document
redirect_from:
- /library/src/number/czt.hpp
- /library/src/number/czt.hpp.html
title: src/number/czt.hpp
---
