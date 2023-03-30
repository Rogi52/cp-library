---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find.hpp
    title: src/data_structure/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/union_find.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i =\
    \ 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld = long\
    \ double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\ntemplate\
    \ < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return\
    \ false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return\
    \ true; } return false; }\n#line 1 \"src/data_structure/union_find.hpp\"\nclass\
    \ union_find {\n  public:\n    union_find(int n) : data(n, -1) {}\n    int unite(int\
    \ x, int y) {\n        x = root(x), y = root(y);\n        if(x != y) {\n     \
    \       if(size(x) < size(y)) swap(x, y);\n            data[x] += data[y];\n \
    \           return data[y] = x;\n        }\n        return -1;\n    }\n    int\
    \ root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }\n    int size(int\
    \ x) { return -data[root(x)]; }\n    bool same(int x, int y) { return root(x)\
    \ == root(y); }\n\n  private:\n    vector<int> data;\n};\n#line 5 \"verify/library_checker/data_structure/union_find.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N,Q; cin >> N >> Q;\n    union_find uf(N);\n\n    rep(_,Q) {\n        int t,\
    \ u, v; cin >> t >> u >> v;\n        switch(t) {\n            case 0: {\n    \
    \            uf.unite(u, v);\n            } break;\n\n            case 1: {\n\
    \                cout << uf.same(u, v) << '\\n';\n            } break;\n     \
    \   }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/data_structure/union_find.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,Q;\
    \ cin >> N >> Q;\n    union_find uf(N);\n\n    rep(_,Q) {\n        int t, u, v;\
    \ cin >> t >> u >> v;\n        switch(t) {\n            case 0: {\n          \
    \      uf.unite(u, v);\n            } break;\n\n            case 1: {\n      \
    \          cout << uf.same(u, v) << '\\n';\n            } break;\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/union_find.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/union_find.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/union_find.test.cpp
- /verify/verify/library_checker/data_structure/union_find.test.cpp.html
title: verify/library_checker/data_structure/union_find.test.cpp
---
