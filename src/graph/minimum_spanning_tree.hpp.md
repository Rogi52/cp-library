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
  bundledCode: "#line 1 \"src/graph/minimum_spanning_tree.hpp\"\nusing size_type =\
    \ int;\n\ntemplate < class weight_type >\npair<weight_type, vector<size_type>>\
    \ minimum_spanning_tree(const size_type n, const vector<tuple<size_type, size_type,\
    \ weight_type>>& edges) {\n    const size_type m = edges.size();\n    vector<size_type>\
    \ I(m);\n    iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(), [&](int\
    \ i, int j) { return get<2>(edges[i]) < get<2>(edges[j]); });\n    union_find\
    \ uf(n);\n    weight_type sum = 0;\n    vector<size_type> tree_edges;\n    tree_edges.reserve(n\
    \ - 1);\n    for(size_type i : I) {\n        auto [u, v, w] = edges[i];\n    \
    \    if(uf.unite(u, v) != -1) {\n            sum += w;\n            tree_edges.push_back(i);\n\
    \        }\n    }\n    return {sum, std::move(tree_edges)};\n}\n"
  code: "using size_type = int;\n\ntemplate < class weight_type >\npair<weight_type,\
    \ vector<size_type>> minimum_spanning_tree(const size_type n, const vector<tuple<size_type,\
    \ size_type, weight_type>>& edges) {\n    const size_type m = edges.size();\n\
    \    vector<size_type> I(m);\n    iota(I.begin(), I.end(), 0);\n    sort(I.begin(),\
    \ I.end(), [&](int i, int j) { return get<2>(edges[i]) < get<2>(edges[j]); });\n\
    \    union_find uf(n);\n    weight_type sum = 0;\n    vector<size_type> tree_edges;\n\
    \    tree_edges.reserve(n - 1);\n    for(size_type i : I) {\n        auto [u,\
    \ v, w] = edges[i];\n        if(uf.unite(u, v) != -1) {\n            sum += w;\n\
    \            tree_edges.push_back(i);\n        }\n    }\n    return {sum, std::move(tree_edges)};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2024-01-24 22:04:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/src/graph/minimum_spanning_tree.hpp
- /library/src/graph/minimum_spanning_tree.hpp.html
title: src/graph/minimum_spanning_tree.hpp
---
