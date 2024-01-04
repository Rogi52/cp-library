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
  bundledCode: "#line 1 \"src/data_structure/radix_heap.hpp\"\nusing u64 = unsigned\
    \ long long;\n\n// \u5927\u5C0F\u95A2\u4FC2\u3092\u4FDD\u3061\u306A\u304C\u3089\
    \ cast \u3059\u308B\nnamespace float_to_uint_cast {\n    using f64 = double;\n\
    \    using u64 = unsigned long long;\n    constexpr int digits = 64;\n    u64\
    \ float_to_uint(f64 f) {\n        u64 u = std::bit_cast<u64>(f);\n        return\
    \ u ^ ((-(u >> (digits - 1))) | 1ULL << (digits - 1));\n    }\n    f64 uint_to_float(u64\
    \ u) {\n        u = u ^ (((u >> (digits - 1)) - 1) | 1ULL << (digits - 1));\n\
    \        return std::bit_cast<f64>(u);\n    }\n\n} // namespace my_cast\n\ntemplate\
    \ < class Key, class Value > class radix_heap {\n    std::size_t size_;\n    Key\
    \ last;\n    std::vector<std::pair<Key, Value>> container[64 + 1];\n\n    std::size_t\
    \ pos(Key x) {\n        return x == 0 ? 0 : 64 - __builtin_clzll(x);\n    }\n\n\
    \  public:\n    radix_heap() : size_(0), last(0) {\n        static_assert(std::is_same<Key,\
    \ u64>::value, \"Key must be u64.\");\n    }\n    std::size_t size() const { return\
    \ size_; }\n    bool empty() const { return size_ == 0; }\n    void push(const\
    \ Key key, const Value value) {\n        container[pos(key ^ last)].emplace_back(key,\
    \ value);\n        size_++;\n    }\n    std::pair<Key, Value> pop() {\n      \
    \  if(container[0].empty()) {\n            std::size_t i = 1; while(container[i].empty())\
    \ i++;\n            last = std::min_element(container[i].begin(), container[i].end())->first;\n\
    \            for(std::pair<Key, Value>& p : container[i]) container[pos(p.first\
    \ ^ last)].emplace_back(p);\n            container[i].clear();\n        }\n  \
    \      std::pair<Key, Value> p = container[0].back(); container[0].pop_back();\n\
    \        size_--;\n        return p;\n    }\n};\n"
  code: "using u64 = unsigned long long;\n\n// \u5927\u5C0F\u95A2\u4FC2\u3092\u4FDD\
    \u3061\u306A\u304C\u3089 cast \u3059\u308B\nnamespace float_to_uint_cast {\n \
    \   using f64 = double;\n    using u64 = unsigned long long;\n    constexpr int\
    \ digits = 64;\n    u64 float_to_uint(f64 f) {\n        u64 u = std::bit_cast<u64>(f);\n\
    \        return u ^ ((-(u >> (digits - 1))) | 1ULL << (digits - 1));\n    }\n\
    \    f64 uint_to_float(u64 u) {\n        u = u ^ (((u >> (digits - 1)) - 1) |\
    \ 1ULL << (digits - 1));\n        return std::bit_cast<f64>(u);\n    }\n\n} //\
    \ namespace my_cast\n\ntemplate < class Key, class Value > class radix_heap {\n\
    \    std::size_t size_;\n    Key last;\n    std::vector<std::pair<Key, Value>>\
    \ container[64 + 1];\n\n    std::size_t pos(Key x) {\n        return x == 0 ?\
    \ 0 : 64 - __builtin_clzll(x);\n    }\n\n  public:\n    radix_heap() : size_(0),\
    \ last(0) {\n        static_assert(std::is_same<Key, u64>::value, \"Key must be\
    \ u64.\");\n    }\n    std::size_t size() const { return size_; }\n    bool empty()\
    \ const { return size_ == 0; }\n    void push(const Key key, const Value value)\
    \ {\n        container[pos(key ^ last)].emplace_back(key, value);\n        size_++;\n\
    \    }\n    std::pair<Key, Value> pop() {\n        if(container[0].empty()) {\n\
    \            std::size_t i = 1; while(container[i].empty()) i++;\n           \
    \ last = std::min_element(container[i].begin(), container[i].end())->first;\n\
    \            for(std::pair<Key, Value>& p : container[i]) container[pos(p.first\
    \ ^ last)].emplace_back(p);\n            container[i].clear();\n        }\n  \
    \      std::pair<Key, Value> p = container[0].back(); container[0].pop_back();\n\
    \        size_--;\n        return p;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/radix_heap.hpp
  requiredBy: []
  timestamp: '2024-01-04 09:09:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/radix_heap.hpp
layout: document
redirect_from:
- /library/src/data_structure/radix_heap.hpp
- /library/src/data_structure/radix_heap.hpp.html
title: src/data_structure/radix_heap.hpp
---
