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
  bundledCode: "#line 1 \"src/data_structure/rollback_array.hpp\"\ntemplate < class\
    \ Value > struct rollback_array {\n    std::vector<Value> a;\n    std::vector<std::pair<int,Value>>\
    \ history;\n    rollback_array() = default;\n    rollback_array(const int n) :\
    \ a(n) {}\n\n    void set(int i, Value v) {\n        history.emplace_back(i, a[i]);\n\
    \        a[i] = v;\n    }\n    Value get(int i) {\n        return a[i];\n    }\n\
    \    void undo() {\n        auto [i, v] = history.back(); history.pop_back();\n\
    \        a[i] = v;\n    }\n    int now() {\n        return history.size();\n \
    \   }\n    void rollback(int t) {\n        while(t < history.size()) undo();\n\
    \    }\n};\n"
  code: "template < class Value > struct rollback_array {\n    std::vector<Value>\
    \ a;\n    std::vector<std::pair<int,Value>> history;\n    rollback_array() = default;\n\
    \    rollback_array(const int n) : a(n) {}\n\n    void set(int i, Value v) {\n\
    \        history.emplace_back(i, a[i]);\n        a[i] = v;\n    }\n    Value get(int\
    \ i) {\n        return a[i];\n    }\n    void undo() {\n        auto [i, v] =\
    \ history.back(); history.pop_back();\n        a[i] = v;\n    }\n    int now()\
    \ {\n        return history.size();\n    }\n    void rollback(int t) {\n     \
    \   while(t < history.size()) undo();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/rollback_array.hpp
  requiredBy: []
  timestamp: '2023-12-26 17:55:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/rollback_array.hpp
layout: document
redirect_from:
- /library/src/data_structure/rollback_array.hpp
- /library/src/data_structure/rollback_array.hpp.html
title: src/data_structure/rollback_array.hpp
---
