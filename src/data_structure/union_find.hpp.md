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
  bundledCode: "#line 1 \"src/data_structure/union_find.hpp\"\nclass union_find {\n\
    \  public:\n    union_find(int n) : data(n, -1) {}\n    int unite(int x, int y)\
    \ {\n        x = root(x), y = root(y);\n        if(x != y) {\n            if(size(x)\
    \ < size(y)) swap(x, y);\n            data[x] += data[y];\n            return\
    \ data[y] = x;\n        }\n        return -1;\n    }\n    int root(int x) { return\
    \ data[x] < 0 ? x : data[x] = root(data[x]); }\n    int size(int x) { return -data[root(x)];\
    \ }\n    bool same(int x, int y) { return root(x) == root(y); }\n\n  private:\n\
    \    vector<int> data;\n};\n"
  code: "class union_find {\n  public:\n    union_find(int n) : data(n, -1) {}\n \
    \   int unite(int x, int y) {\n        x = root(x), y = root(y);\n        if(x\
    \ != y) {\n            if(size(x) < size(y)) swap(x, y);\n            data[x]\
    \ += data[y];\n            return data[y] = x;\n        }\n        return -1;\n\
    \    }\n    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]);\
    \ }\n    int size(int x) { return -data[root(x)]; }\n    bool same(int x, int\
    \ y) { return root(x) == root(y); }\n\n  private:\n    vector<int> data;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find.hpp
- /library/src/data_structure/union_find.hpp.html
title: src/data_structure/union_find.hpp
---
