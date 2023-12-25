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
  bundledCode: "#line 1 \"src/algorithm/event_segment.hpp\"\ntemplate < class Value,\
    \ bool monotone > struct event_segment {\n    using size_t = std::size_t;\n  \
    \  std::map< Value, std::vector<size_t> > adds, removes;\n\n    void add(const\
    \ size_t time, const Value value) {\n        adds[value].emplace_back(time);\n\
    \    }\n    void remove(const size_t time, const Value value) {\n        removes[value].emplace_back(time);\n\
    \    }\n    std::vector<std::tuple<size_t, size_t, Value>> trans(const size_t\
    \ inf) {\n        std::vector<std::tuple<size_t, size_t, Value>> res;\n      \
    \  for(auto& [value, L] : adds) {\n            std::vector<size_t>& R = removes[value];\n\
    \            if(R.size() < L.size()) R.emplace_back(inf);\n            assert(L.size()\
    \ == R.size());\n            if(not monotone) {\n                std::sort(L.begin(),\
    \ L.end());\n                std::sort(R.begin(), R.end());\n            }\n \
    \           for(size_t i = 0; i < L.size(); i++) {\n                assert(L[i]\
    \ <= R[i]);\n                if(L[i] < R[i]) res.emplace_back(L[i], R[i], value);\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "template < class Value, bool monotone > struct event_segment {\n    using\
    \ size_t = std::size_t;\n    std::map< Value, std::vector<size_t> > adds, removes;\n\
    \n    void add(const size_t time, const Value value) {\n        adds[value].emplace_back(time);\n\
    \    }\n    void remove(const size_t time, const Value value) {\n        removes[value].emplace_back(time);\n\
    \    }\n    std::vector<std::tuple<size_t, size_t, Value>> trans(const size_t\
    \ inf) {\n        std::vector<std::tuple<size_t, size_t, Value>> res;\n      \
    \  for(auto& [value, L] : adds) {\n            std::vector<size_t>& R = removes[value];\n\
    \            if(R.size() < L.size()) R.emplace_back(inf);\n            assert(L.size()\
    \ == R.size());\n            if(not monotone) {\n                std::sort(L.begin(),\
    \ L.end());\n                std::sort(R.begin(), R.end());\n            }\n \
    \           for(size_t i = 0; i < L.size(); i++) {\n                assert(L[i]\
    \ <= R[i]);\n                if(L[i] < R[i]) res.emplace_back(L[i], R[i], value);\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/event_segment.hpp
  requiredBy: []
  timestamp: '2023-12-26 08:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/event_segment.hpp
layout: document
redirect_from:
- /library/src/algorithm/event_segment.hpp
- /library/src/algorithm/event_segment.hpp.html
title: src/algorithm/event_segment.hpp
---
