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
  bundledCode: "#line 2 \"src/graph/tree/cartesian_tree.hpp\"\n\ntemplate < class\
    \ T >\npair< vector<vector<int>>, int > cartesian_tree(vector< T > &a) {\n   \
    \ int n = a.size();\n    vector<vector<int>> tree(n);\n    vector<int> parent(n,\
    \ -1);\n    stack<int> st;\n    for(int i = 0; i < n; i++) {\n        int prev\
    \ = -1;\n        while(!st.empty() && a[i] < a[st.top()]) { prev = st.top(); st.pop();\
    \ }\n        if(prev != -1) parent[prev] = i;\n        if(!st.empty()) parent[i]\
    \ = st.top();\n        st.push(i);\n    }\n\n    int root = -1;\n    for(int i\
    \ = 0; i < n; i++) {\n        if(parent[i] == -1) root = i;\n        else tree[parent[i]].push_back(i);\n\
    \    }\n    return {tree, root};\n}\n"
  code: "#pragma once\n\ntemplate < class T >\npair< vector<vector<int>>, int > cartesian_tree(vector<\
    \ T > &a) {\n    int n = a.size();\n    vector<vector<int>> tree(n);\n    vector<int>\
    \ parent(n, -1);\n    stack<int> st;\n    for(int i = 0; i < n; i++) {\n     \
    \   int prev = -1;\n        while(!st.empty() && a[i] < a[st.top()]) { prev =\
    \ st.top(); st.pop(); }\n        if(prev != -1) parent[prev] = i;\n        if(!st.empty())\
    \ parent[i] = st.top();\n        st.push(i);\n    }\n\n    int root = -1;\n  \
    \  for(int i = 0; i < n; i++) {\n        if(parent[i] == -1) root = i;\n     \
    \   else tree[parent[i]].push_back(i);\n    }\n    return {tree, root};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2022-03-22 17:10:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/src/graph/tree/cartesian_tree.hpp
- /library/src/graph/tree/cartesian_tree.hpp.html
title: src/graph/tree/cartesian_tree.hpp
---
