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
  bundledCode: "#line 1 \"src/number/bicoef_table.hpp\"\ntemplate < class T >\nvector<\
    \ vector< T > > bicoef_table(int N) {\n    vector< vector< T > > table(N + 1,\
    \ vector< T >(N + 1, T(1)));\n    for(int i = 1; i <= N; i++) for(int j = 1; j\
    \ <= N; j++)\n            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];\n\
    \    return table;\n}\n"
  code: "template < class T >\nvector< vector< T > > bicoef_table(int N) {\n    vector<\
    \ vector< T > > table(N + 1, vector< T >(N + 1, T(1)));\n    for(int i = 1; i\
    \ <= N; i++) for(int j = 1; j <= N; j++)\n            table[i][j] = table[i -\
    \ 1][j - 1] + table[i - 1][j];\n    return table;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/bicoef_table.hpp
  requiredBy: []
  timestamp: '2023-03-26 01:51:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/bicoef_table.hpp
layout: document
redirect_from:
- /library/src/number/bicoef_table.hpp
- /library/src/number/bicoef_table.hpp.html
title: src/number/bicoef_table.hpp
---
