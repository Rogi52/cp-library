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
  bundledCode: "#line 1 \"src/data_structure/rollback_union_find.hpp\"\nclass rollback_union_find\
    \ {\n  private:\n    using size_t = std::size_t;\n    class node_type {\n    \
    \    friend rollback_union_find;\n        size_t parent;\n        size_t size;\n\
    \        node_type(const size_t parent, const size_t size) : parent(parent), size(size)\
    \ {}\n    };\n\n    std::vector<node_type> tree;\n    std::vector<std::pair<size_t,\
    \ node_type>> history;\n\n  public:\n    rollback_union_find() = default;\n  \
    \  explicit rollback_union_find(const size_t n) : tree(n, node_type(n, 1)) {}\n\
    \    size_t size() const { return tree.size(); }\n    size_t find(const size_t\
    \ x) {\n        assert(x < size());\n        if(tree[x].parent == size())\n  \
    \          return x;\n        else\n            return find(tree[x].parent);\n\
    \    }\n    bool same(const size_t x, const size_t y) {\n        assert(x < size());\n\
    \        assert(y < size());\n        return find(x) == find(y);\n    }\n    size_t\
    \ size(const size_t x) {\n        assert(x < size());\n        return tree[find(x)].size;\n\
    \    }\n    void unite(size_t x, size_t y) {\n        assert(x < size());\n  \
    \      assert(y < size());\n        x = find(x);\n        y = find(y);\n     \
    \   history.emplace_back(x, tree[x]);\n        history.emplace_back(y, tree[y]);\n\
    \        if(x != y) {\n            if(tree[x].size < tree[y].size) std::swap(x,\
    \ y);\n            tree[x].size += tree[y].size;\n            tree[y].parent =\
    \ x;\n        }\n    }\n    void undo() {\n        for(int _ = 0; _ < 2; _++)\
    \ {\n            auto [x, state] = history.back(); history.pop_back();\n     \
    \       tree[x] = state;\n        }\n    }\n    size_t inner_snap = 0;\n    void\
    \ snapshot() {\n        inner_snap = history.size() / 2;\n    }\n    size_t now()\
    \ {\n        return history.size() / 2;\n    }\n    void rollback(size_t t = -1)\
    \ {\n        if(t == -1) t = inner_snap;\n        t *= 2;\n        while(t < history.size())\
    \ undo();\n    }\n};\n"
  code: "class rollback_union_find {\n  private:\n    using size_t = std::size_t;\n\
    \    class node_type {\n        friend rollback_union_find;\n        size_t parent;\n\
    \        size_t size;\n        node_type(const size_t parent, const size_t size)\
    \ : parent(parent), size(size) {}\n    };\n\n    std::vector<node_type> tree;\n\
    \    std::vector<std::pair<size_t, node_type>> history;\n\n  public:\n    rollback_union_find()\
    \ = default;\n    explicit rollback_union_find(const size_t n) : tree(n, node_type(n,\
    \ 1)) {}\n    size_t size() const { return tree.size(); }\n    size_t find(const\
    \ size_t x) {\n        assert(x < size());\n        if(tree[x].parent == size())\n\
    \            return x;\n        else\n            return find(tree[x].parent);\n\
    \    }\n    bool same(const size_t x, const size_t y) {\n        assert(x < size());\n\
    \        assert(y < size());\n        return find(x) == find(y);\n    }\n    size_t\
    \ size(const size_t x) {\n        assert(x < size());\n        return tree[find(x)].size;\n\
    \    }\n    void unite(size_t x, size_t y) {\n        assert(x < size());\n  \
    \      assert(y < size());\n        x = find(x);\n        y = find(y);\n     \
    \   history.emplace_back(x, tree[x]);\n        history.emplace_back(y, tree[y]);\n\
    \        if(x != y) {\n            if(tree[x].size < tree[y].size) std::swap(x,\
    \ y);\n            tree[x].size += tree[y].size;\n            tree[y].parent =\
    \ x;\n        }\n    }\n    void undo() {\n        for(int _ = 0; _ < 2; _++)\
    \ {\n            auto [x, state] = history.back(); history.pop_back();\n     \
    \       tree[x] = state;\n        }\n    }\n    size_t inner_snap = 0;\n    void\
    \ snapshot() {\n        inner_snap = history.size() / 2;\n    }\n    size_t now()\
    \ {\n        return history.size() / 2;\n    }\n    void rollback(size_t t = -1)\
    \ {\n        if(t == -1) t = inner_snap;\n        t *= 2;\n        while(t < history.size())\
    \ undo();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/rollback_union_find.hpp
  requiredBy: []
  timestamp: '2023-12-24 07:38:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/rollback_union_find.hpp
layout: document
redirect_from:
- /library/src/data_structure/rollback_union_find.hpp
- /library/src/data_structure/rollback_union_find.hpp.html
title: src/data_structure/rollback_union_find.hpp
---
