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
  bundledCode: "#line 1 \"src/data_structure/potentialized_union_find.hpp\"\ntemplate\
    \ < class Group > class potentialized_union_find {\n  public:\n    using T = typename\
    \ Group::set;\n\n  private:\n    using size_t = std::size_t;\n    class node_type\
    \ {\n        friend potentialized_union_find;\n        T value;\n        size_t\
    \ parent;\n        size_t size;\n\n        node_type(const T value, const size_t\
    \ parent, const size_t size)\n            : value(value), parent(parent), size(size)\
    \ {}\n    };\n\n    std::vector<node_type> tree;\n    size_t size() const { return\
    \ tree.size(); }\n    void compress(const size_t x) {\n        const std::size_t\
    \ p = tree[x].parent;\n        if(p == x) return;\n        compress(p);\n    \
    \    tree[x].value = Group::op(tree[p].value, tree[x].value);\n        tree[x].parent\
    \ = tree[p].parent;\n    }\n\n  public:\n    potentialized_union_find() = default;\n\
    \    explicit potentialized_union_find(const size_t n)\n        : tree(n, node_type(Group::id(),\
    \ 0, 1)) {\n        for(size_t i = 0; i < n; i++) tree[i].parent = i;\n    }\n\
    \n    size_t find(const size_t x) {\n        assert(x < size());\n        compress(x);\n\
    \        return tree[x].parent;\n    }\n    T potential(const size_t x) {\n  \
    \      assert(x < size());\n        compress(x);\n        return tree[x].value;\n\
    \    }\n    bool same(const size_t x, const size_t y) {\n        assert(x < size());\n\
    \        compress(x);\n        return find(x) == find(y);\n    }\n    T distance(const\
    \ size_t x, const size_t y) {\n        assert(x < size());\n        assert(y <\
    \ size());\n        return Group::op(Group::inv(potential(x)), potential(y));\n\
    \    }\n    size_t size(const size_t x) {\n        assert(x < size());\n     \
    \   return tree[find(x)].size;\n    }\n    void unite(size_t x, size_t y, T d)\
    \ {\n        if(same(x, y)) return;\n        if(size(x) < size(y)) {\n       \
    \     d = Group::inv(d);\n            std::swap(x, y);\n        }\n        d =\
    \ Group::op(Group::op(potential(x), d), Group::inv(potential(y)));\n        x\
    \ = find(x), y = find(y);\n        tree[x].size += tree[y].size;\n        tree[y].parent\
    \ = x;\n        tree[y].value = d;\n    }\n};\n"
  code: "template < class Group > class potentialized_union_find {\n  public:\n  \
    \  using T = typename Group::set;\n\n  private:\n    using size_t = std::size_t;\n\
    \    class node_type {\n        friend potentialized_union_find;\n        T value;\n\
    \        size_t parent;\n        size_t size;\n\n        node_type(const T value,\
    \ const size_t parent, const size_t size)\n            : value(value), parent(parent),\
    \ size(size) {}\n    };\n\n    std::vector<node_type> tree;\n    size_t size()\
    \ const { return tree.size(); }\n    void compress(const size_t x) {\n       \
    \ const std::size_t p = tree[x].parent;\n        if(p == x) return;\n        compress(p);\n\
    \        tree[x].value = Group::op(tree[p].value, tree[x].value);\n        tree[x].parent\
    \ = tree[p].parent;\n    }\n\n  public:\n    potentialized_union_find() = default;\n\
    \    explicit potentialized_union_find(const size_t n)\n        : tree(n, node_type(Group::id(),\
    \ 0, 1)) {\n        for(size_t i = 0; i < n; i++) tree[i].parent = i;\n    }\n\
    \n    size_t find(const size_t x) {\n        assert(x < size());\n        compress(x);\n\
    \        return tree[x].parent;\n    }\n    T potential(const size_t x) {\n  \
    \      assert(x < size());\n        compress(x);\n        return tree[x].value;\n\
    \    }\n    bool same(const size_t x, const size_t y) {\n        assert(x < size());\n\
    \        compress(x);\n        return find(x) == find(y);\n    }\n    T distance(const\
    \ size_t x, const size_t y) {\n        assert(x < size());\n        assert(y <\
    \ size());\n        return Group::op(Group::inv(potential(x)), potential(y));\n\
    \    }\n    size_t size(const size_t x) {\n        assert(x < size());\n     \
    \   return tree[find(x)].size;\n    }\n    void unite(size_t x, size_t y, T d)\
    \ {\n        if(same(x, y)) return;\n        if(size(x) < size(y)) {\n       \
    \     d = Group::inv(d);\n            std::swap(x, y);\n        }\n        d =\
    \ Group::op(Group::op(potential(x), d), Group::inv(potential(y)));\n        x\
    \ = find(x), y = find(y);\n        tree[x].size += tree[y].size;\n        tree[y].parent\
    \ = x;\n        tree[y].value = d;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2023-12-20 04:49:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/potentialized_union_find.hpp
layout: document
redirect_from:
- /library/src/data_structure/potentialized_union_find.hpp
- /library/src/data_structure/potentialized_union_find.hpp.html
title: src/data_structure/potentialized_union_find.hpp
---
