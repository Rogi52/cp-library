---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/cartesian_tree.hpp
    title: src/graph/tree/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verify/library_checker/graph/tree/cartesian_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line\
    \ 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\n#line 2 \"src/graph/tree/cartesian_tree.hpp\"\
    \n\ntemplate < class T >\npair< vector<vector<int>>, int > cartesian_tree(vector<\
    \ T > &a) {\n    int n = a.size();\n    vector<vector<int>> tree(n);\n    vector<int>\
    \ parent(n, -1);\n    stack<int> st;\n    for(int i = 0; i < n; i++) {\n     \
    \   int prev = -1;\n        while(!st.empty() && a[i] < a[st.top()]) { prev =\
    \ st.top(); st.pop(); }\n        if(prev != -1) parent[prev] = i;\n        if(!st.empty())\
    \ parent[i] = st.top();\n        st.push(i);\n    }\n\n    int root = -1;\n  \
    \  for(int i = 0; i < n; i++) {\n        if(parent[i] == -1) root = i;\n     \
    \   else tree[parent[i]].push_back(i);\n    }\n    return {tree, root};\n}\n#line\
    \ 5 \"verify/library_checker/graph/tree/cartesian_tree.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int n; cin >> n;\n \
    \   vector<int> a(n);\n    rep(i,n) cin >> a[i];\n    auto [G, r] = cartesian_tree<int>(a);\n\
    \    vector<int> ans(n);\n    ans[r] = r;\n    rep(i,n) for(int v : G[i]) ans[v]\
    \ = i;\n    for(int p : ans) cout << p << \" \"; cout << endl;\n};\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/graph/tree/cartesian_tree.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int n; cin\
    \ >> n;\n    vector<int> a(n);\n    rep(i,n) cin >> a[i];\n    auto [G, r] = cartesian_tree<int>(a);\n\
    \    vector<int> ans(n);\n    ans[r] = r;\n    rep(i,n) for(int v : G[i]) ans[v]\
    \ = i;\n    for(int p : ans) cout << p << \" \"; cout << endl;\n};\n"
  dependsOn:
  - src/cp-template.hpp
  - src/graph/tree/cartesian_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/tree/cartesian_tree.test.cpp
- /verify/verify/library_checker/graph/tree/cartesian_tree.test.cpp.html
title: verify/library_checker/graph/tree/cartesian_tree.test.cpp
---
