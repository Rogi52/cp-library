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
  bundledCode: "#line 1 \"src/algorithm/mo.hpp\"\nnamespace mo {\n \nusing func =\
    \ function<void(int)>;\nvoid sol(int N, vector<pair<int,int>> &query, func &add_left,\
    \ func &del_left, func &add_right, func &del_right, func &ans, int block_size\
    \ = -1) {\n    if(block_size == -1) block_size = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(query.size() * 2.0 / 3.0)));\n    vector<int> I(query.size());\n    iota(I.begin(),\
    \ I.end(), 0);\n    sort(I.begin(), I.end(), [&](int i, int j) {\n        auto\
    \ [Li, Ri] = query[i];\n        auto [Lj, Rj] = query[j];\n        if(Li / block_size\
    \ != Lj / block_size) return Li < Lj;\n        if(Li / block_size & 1) return\
    \ Ri < Rj;\n        return Ri > Rj;\n    });\n    int nL = 0, nR = 0;\n    for(int\
    \ i : I) {\n        auto [L, R] = query[i];\n        while(nL > L) add_left (--nL);\n\
    \        while(nR < R) add_right(nR++);\n        while(nL < L) del_left (nL++);\n\
    \        while(nR > R) del_right(--nR);\n        ans(i);\n    }\n}\n \n} // namespace\
    \ mo\n"
  code: "namespace mo {\n \nusing func = function<void(int)>;\nvoid sol(int N, vector<pair<int,int>>\
    \ &query, func &add_left, func &del_left, func &add_right, func &del_right, func\
    \ &ans, int block_size = -1) {\n    if(block_size == -1) block_size = max<int>(1,\
    \ 1.0 * N / max<double>(1.0, sqrt(query.size() * 2.0 / 3.0)));\n    vector<int>\
    \ I(query.size());\n    iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(),\
    \ [&](int i, int j) {\n        auto [Li, Ri] = query[i];\n        auto [Lj, Rj]\
    \ = query[j];\n        if(Li / block_size != Lj / block_size) return Li < Lj;\n\
    \        if(Li / block_size & 1) return Ri < Rj;\n        return Ri > Rj;\n  \
    \  });\n    int nL = 0, nR = 0;\n    for(int i : I) {\n        auto [L, R] = query[i];\n\
    \        while(nL > L) add_left (--nL);\n        while(nR < R) add_right(nR++);\n\
    \        while(nL < L) del_left (nL++);\n        while(nR > R) del_right(--nR);\n\
    \        ans(i);\n    }\n}\n \n} // namespace mo\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/mo.hpp
  requiredBy: []
  timestamp: '2023-03-26 02:20:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/mo.hpp
layout: document
redirect_from:
- /library/src/algorithm/mo.hpp
- /library/src/algorithm/mo.hpp.html
title: src/algorithm/mo.hpp
---
