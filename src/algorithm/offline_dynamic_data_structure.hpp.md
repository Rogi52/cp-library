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
  bundledCode: "#line 1 \"src/algorithm/offline_dynamic_data_structure.hpp\"\ntemplate\
    \ < class Value > class offline_dynamic_data_structure {\n  public:\n    using\
    \ size_t = std::size_t;\n    size_t Q, Q2;\n    std::vector<std::vector<Value>>\
    \ seg;\n    offline_dynamic_data_structure(const size_t Q) : Q(Q), Q2(1) {\n \
    \       while(Q2 < Q) Q2 *= 2;\n        seg.resize(2 * Q2 - 1);\n    }\n    void\
    \ add(const size_t a, const size_t b, const Value v) {\n        add(a, b, v, 0,\
    \ 0, Q2);\n    }\n    template < class Add, class Undo, class Query >\n    void\
    \ run(const Add add, const Undo undo, const Query query, const size_t k = 0) {\n\
    \        std::for_each(seg[k].begin(), seg[k].end(), [&](Value& v) { add(v); });\n\
    \        if(k < Q2 - 1) {\n            run(add, undo, query, 2 * k + 1);\n   \
    \         run(add, undo, query, 2 * k + 2);\n        } else if(k - (Q2 - 1) <\
    \ Q) {\n            query(k - (Q2 - 1));\n        }\n        std::for_each(seg[k].rbegin(),\
    \ seg[k].rend(), [&](Value& v) { undo(v); });\n    }\n\n  private:\n    void add(const\
    \ size_t a, const size_t b, const Value v, const size_t k, const size_t l, const\
    \ size_t r) {\n        if(r <= a or  b <= l) { return; }\n        if(a <= l and\
    \ r <= b) { seg[k].emplace_back(v); return; }\n        add(a, b, v, 2 * k + 1,\
    \ l, (l + r) / 2);\n        add(a, b, v, 2 * k + 2, (l + r) / 2, r);\n    }\n\
    };\n"
  code: "template < class Value > class offline_dynamic_data_structure {\n  public:\n\
    \    using size_t = std::size_t;\n    size_t Q, Q2;\n    std::vector<std::vector<Value>>\
    \ seg;\n    offline_dynamic_data_structure(const size_t Q) : Q(Q), Q2(1) {\n \
    \       while(Q2 < Q) Q2 *= 2;\n        seg.resize(2 * Q2 - 1);\n    }\n    void\
    \ add(const size_t a, const size_t b, const Value v) {\n        add(a, b, v, 0,\
    \ 0, Q2);\n    }\n    template < class Add, class Undo, class Query >\n    void\
    \ run(const Add add, const Undo undo, const Query query, const size_t k = 0) {\n\
    \        std::for_each(seg[k].begin(), seg[k].end(), [&](Value& v) { add(v); });\n\
    \        if(k < Q2 - 1) {\n            run(add, undo, query, 2 * k + 1);\n   \
    \         run(add, undo, query, 2 * k + 2);\n        } else if(k - (Q2 - 1) <\
    \ Q) {\n            query(k - (Q2 - 1));\n        }\n        std::for_each(seg[k].rbegin(),\
    \ seg[k].rend(), [&](Value& v) { undo(v); });\n    }\n\n  private:\n    void add(const\
    \ size_t a, const size_t b, const Value v, const size_t k, const size_t l, const\
    \ size_t r) {\n        if(r <= a or  b <= l) { return; }\n        if(a <= l and\
    \ r <= b) { seg[k].emplace_back(v); return; }\n        add(a, b, v, 2 * k + 1,\
    \ l, (l + r) / 2);\n        add(a, b, v, 2 * k + 2, (l + r) / 2, r);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/offline_dynamic_data_structure.hpp
  requiredBy: []
  timestamp: '2023-12-26 08:43:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/offline_dynamic_data_structure.hpp
layout: document
redirect_from:
- /library/src/algorithm/offline_dynamic_data_structure.hpp
- /library/src/algorithm/offline_dynamic_data_structure.hpp.html
title: src/algorithm/offline_dynamic_data_structure.hpp
---
