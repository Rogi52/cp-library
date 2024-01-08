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
  bundledCode: "#line 1 \"src/algorithm/smawk.hpp\"\ntemplate < class Select >\nstd::vector<int>\
    \ smawk(const int row_size, const int col_size, const Select& select) {\n    const\
    \ std::function<std::vector<int>(const std::vector<int>&, const std::vector<int>&)>\
    \ dfs = \n        [&](const std::vector<int>& row, const std::vector<int>& col)\
    \ -> std::vector<int> {\n        const int n = row.size();\n        if(n == 0)\
    \ return {};\n\n        /* Reduce step */\n        std::vector<int> c2;\n    \
    \    for(const int i : col) {\n            while(not c2.empty() and select(row[c2.size()\
    \ - 1], c2.back(), i)) c2.pop_back();\n            if(c2.size() < n) c2.push_back(i);\n\
    \        }\n\n        /* Recurse step */\n        std::vector<int> r2;\n     \
    \   for(int i : rep(1, n, 2)) r2.push_back(row[i]);\n        const std::vector<int>\
    \ a2 = dfs(r2, c2);\n\n        /* Interpolate step */\n        std::vector<int>\
    \ ans(n);\n        for(int i : rep(a2.size())) ans[i * 2 + 1] = a2[i];\n     \
    \   int j = 0;\n        for(int i : rep(0, n, 2)) {\n            ans[i] = c2[j];\n\
    \            while(c2[j] != (i + 1 == n ? c2.back() : ans[i + 1])) {\n       \
    \         j += 1;\n                if(select(row[i], ans[i], c2[j])) ans[i] =\
    \ c2[j];\n            }\n        }\n        return ans;\n    };\n\n    std::vector<int>\
    \ row(row_size), col(col_size);\n    std::iota(row.begin(), row.end(), 0);\n \
    \   std::iota(col.begin(), col.end(), 0);\n    return dfs(row, col);\n}\n"
  code: "template < class Select >\nstd::vector<int> smawk(const int row_size, const\
    \ int col_size, const Select& select) {\n    const std::function<std::vector<int>(const\
    \ std::vector<int>&, const std::vector<int>&)> dfs = \n        [&](const std::vector<int>&\
    \ row, const std::vector<int>& col) -> std::vector<int> {\n        const int n\
    \ = row.size();\n        if(n == 0) return {};\n\n        /* Reduce step */\n\
    \        std::vector<int> c2;\n        for(const int i : col) {\n            while(not\
    \ c2.empty() and select(row[c2.size() - 1], c2.back(), i)) c2.pop_back();\n  \
    \          if(c2.size() < n) c2.push_back(i);\n        }\n\n        /* Recurse\
    \ step */\n        std::vector<int> r2;\n        for(int i : rep(1, n, 2)) r2.push_back(row[i]);\n\
    \        const std::vector<int> a2 = dfs(r2, c2);\n\n        /* Interpolate step\
    \ */\n        std::vector<int> ans(n);\n        for(int i : rep(a2.size())) ans[i\
    \ * 2 + 1] = a2[i];\n        int j = 0;\n        for(int i : rep(0, n, 2)) {\n\
    \            ans[i] = c2[j];\n            while(c2[j] != (i + 1 == n ? c2.back()\
    \ : ans[i + 1])) {\n                j += 1;\n                if(select(row[i],\
    \ ans[i], c2[j])) ans[i] = c2[j];\n            }\n        }\n        return ans;\n\
    \    };\n\n    std::vector<int> row(row_size), col(col_size);\n    std::iota(row.begin(),\
    \ row.end(), 0);\n    std::iota(col.begin(), col.end(), 0);\n    return dfs(row,\
    \ col);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/smawk.hpp
  requiredBy: []
  timestamp: '2024-01-08 21:17:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/smawk.hpp
layout: document
redirect_from:
- /library/src/algorithm/smawk.hpp
- /library/src/algorithm/smawk.hpp.html
title: src/algorithm/smawk.hpp
---
