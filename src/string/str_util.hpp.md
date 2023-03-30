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
  bundledCode: "#line 1 \"src/string/str_util.hpp\"\nvector<int> str_to_vec(const\
    \ string& s, char base) {\n    int n = s.size();\n    vector<int> a(n);\n    rep(i,n)\
    \ a[i] = s[i] - base;\n    return a;\n}\n\nvector<vector<int>> next_pos(const\
    \ vector<int>& a, int k) {\n    int n = a.size();\n    vector<vector<int>> pos(n\
    \ + 1, vector<int>(k, -1));\n    for(int i = n - 1; i >= 0; i--) {\n        pos[i]\
    \ = pos[i + 1];\n        pos[i][a[i]] = i + 1;\n    }\n    return pos;\n}\n"
  code: "vector<int> str_to_vec(const string& s, char base) {\n    int n = s.size();\n\
    \    vector<int> a(n);\n    rep(i,n) a[i] = s[i] - base;\n    return a;\n}\n\n\
    vector<vector<int>> next_pos(const vector<int>& a, int k) {\n    int n = a.size();\n\
    \    vector<vector<int>> pos(n + 1, vector<int>(k, -1));\n    for(int i = n -\
    \ 1; i >= 0; i--) {\n        pos[i] = pos[i + 1];\n        pos[i][a[i]] = i +\
    \ 1;\n    }\n    return pos;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/str_util.hpp
  requiredBy: []
  timestamp: '2023-03-31 01:42:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/str_util.hpp
layout: document
redirect_from:
- /library/src/string/str_util.hpp
- /library/src/string/str_util.hpp.html
title: src/string/str_util.hpp
---
