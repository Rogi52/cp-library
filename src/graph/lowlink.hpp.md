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
  bundledCode: "#line 1 \"src/graph/lowlink.hpp\"\nstruct lowlink {\n    using size_t\
    \ = std::size_t;\n    std::vector<std::vector<std::pair<size_t, size_t>>> graph;\n\
    \    std::vector<size_t> ord, low, articulation;\n    std::vector<std::pair<size_t,\
    \ size_t>> bridge;\n\n    explicit lowlink(const size_t n) : graph(n), ord(n,\
    \ 0), low(n, 0) {}\n\n    void add_edge(const size_t u, const size_t v, const\
    \ size_t i) {\n        assert(u < graph.size());\n        assert(v < graph.size());\n\
    \        graph[u].push_back({v, i});\n        graph[v].push_back({u, i});\n  \
    \  }\n\n    virtual void build() {\n        size_t t = 0;\n        std::vector<bool>\
    \ used(graph.size(), false);\n        std::function<void(size_t,size_t)> dfs =\
    \ [&](size_t v, size_t p) -> void {\n            used[v] = true;\n           \
    \ ord[v] = low[v] = t++;\n\n            bool is_articulation = false, parent_checked\
    \ = false;\n            size_t child_cnt = 0;\n            for(auto [to, _] :\
    \ graph[v]) {\n                if(to == p and not std::exchange(parent_checked,\
    \ true)) continue;\n                if(not used[to]) {\n                    child_cnt++;\n\
    \                    dfs(to, v);\n                    low[v] = std::min(low[v],\
    \ low[to]);\n                    is_articulation |= p != -1 and ord[v] <= low[to];\n\
    \                    if(ord[v] < low[to]) bridge.push_back(std::minmax({v, to}));\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n            }\n\n            is_articulation |= p == -1 and\
    \ child_cnt >= 2;\n            if(is_articulation) articulation.push_back(v);\n\
    \        };\n        for(size_t v = 0; v < graph.size(); v++) if(not used[v])\
    \ dfs(v, -1);\n    }\n};\n\nstruct two_edge_connected_components : lowlink {\n\
    \    using lowlink::lowlink;\n    using lowlink::graph;\n    using lowlink::ord;\n\
    \    using lowlink::low;\n    using lowlink::bridge;\n\n    using size_t = std::size_t;\n\
    \    std::vector<size_t> id;\n    std::vector<std::vector<size_t>> group, tree;\n\
    \n    explicit two_edge_connected_components(const size_t n) : lowlink(n), id(n,\
    \ -1) {}\n\n    void build() override {\n        lowlink::build();\n\n       \
    \ size_t c = 0;\n        function<void(size_t,size_t)> dfs = [&](size_t v, size_t\
    \ p) -> void {\n            id[v] = (p != -1 and low[v] <= ord[p] ? id[p] : c++);\n\
    \            for(auto [to, _] : graph[v]) if(id[to] == -1) dfs(to, v);\n     \
    \   };\n        for(size_t i = 0; i < graph.size(); i++) if(id[i] == -1) dfs(i,\
    \ -1);\n\n        group.resize(c);\n        for(size_t i = 0; i < graph.size();\
    \ i++) group[id[i]].push_back(i);\n\n        tree.resize(c);\n        for(auto\
    \ [u, v] : bridge) {\n            u = id[u], v = id[v];\n            tree[u].push_back(v);\n\
    \            tree[v].push_back(u);\n        }\n    }\n};\n\nstruct biconnected_components\
    \ : lowlink {\n    using lowlink::lowlink;\n    using lowlink::graph;\n    using\
    \ lowlink::ord;\n    using lowlink::low;\n    using size_t = std::size_t;\n  \
    \  std::vector<std::vector<std::tuple<size_t, size_t, size_t>>> bc;\n\n    void\
    \ build() override {\n        lowlink::build();\n        std::vector<bool> used(graph.size(),\
    \ false);\n        std::vector<std::tuple<size_t, size_t, size_t>> tmp;\n\n  \
    \      function<void(size_t,size_t)> dfs = [&](size_t v, size_t p) -> void {\n\
    \            used[v] = true;\n            bool parent_checked = false;\n     \
    \       for(auto [to, i] : graph[v]) {\n                if(to == p and not exchange(parent_checked,\
    \ true)) continue;\n                if(not used[to] or ord[to] < ord[v]) tmp.emplace_back(v,\
    \ to, i);\n                if(not used[to]) {\n                    dfs(to, v);\n\
    \                    if(ord[v] <= low[to]) {\n                        std::vector<std::tuple<size_t,\
    \ size_t, size_t>> c;\n                        while(true) {\n               \
    \             auto e = tmp.back(); tmp.pop_back();\n                         \
    \   c.emplace_back(e);\n                            if(get<2>(e) == i) break;\n\
    \                        }\n                        bc.emplace_back(std::move(c));\n\
    \                    }\n                }\n            }\n        };\n\n     \
    \   for(size_t i = 0; i < graph.size(); i++) if(not used[i]) dfs(i, -1);\n   \
    \ }\n};\n\nstruct block_cut_tree : biconnected_components {\n    using biconnected_components::biconnected_components;\n\
    \    using biconnected_components::graph;\n    using biconnected_components::articulation;\n\
    \    using biconnected_components::bc;\n\n    using size_t = std::size_t;\n  \
    \  std::vector<int> rev;\n    std::vector<std::vector<size_t>> group, tree;\n\n\
    \    explicit block_cut_tree(const size_t n) : biconnected_components(n), rev(n,\
    \ -1) {}\n\n    void build() override {\n        biconnected_components::build();\n\
    \n        size_t c = bc.size();\n        for(size_t v : articulation) rev[v] =\
    \ c++;\n        std::vector<size_t> last(c, -1);\n        tree.resize(c);\n  \
    \      for(size_t i = 0; i < bc.size(); i++) {\n            for(auto [u, v, _]\
    \ : bc[i]) {\n                for(size_t x : {u, v}) {\n                    if(rev[x]\
    \ != -1 and bc.size() <= rev[x]) {\n                        if(std::exchange(last[rev[x]],\
    \ i) != i) {\n                            tree[rev[x]].push_back(i);\n       \
    \                     tree[i].push_back(rev[x]);\n                        }\n\
    \                    } else {\n                        rev[x] = i;\n         \
    \           }\n                }\n            }\n        }\n        group.resize(c);\n\
    \        for(size_t i = 0; i < graph.size(); i++) group[rev[i]].push_back(i);\n\
    \    }\n};\n"
  code: "struct lowlink {\n    using size_t = std::size_t;\n    std::vector<std::vector<std::pair<size_t,\
    \ size_t>>> graph;\n    std::vector<size_t> ord, low, articulation;\n    std::vector<std::pair<size_t,\
    \ size_t>> bridge;\n\n    explicit lowlink(const size_t n) : graph(n), ord(n,\
    \ 0), low(n, 0) {}\n\n    void add_edge(const size_t u, const size_t v, const\
    \ size_t i) {\n        assert(u < graph.size());\n        assert(v < graph.size());\n\
    \        graph[u].push_back({v, i});\n        graph[v].push_back({u, i});\n  \
    \  }\n\n    virtual void build() {\n        size_t t = 0;\n        std::vector<bool>\
    \ used(graph.size(), false);\n        std::function<void(size_t,size_t)> dfs =\
    \ [&](size_t v, size_t p) -> void {\n            used[v] = true;\n           \
    \ ord[v] = low[v] = t++;\n\n            bool is_articulation = false, parent_checked\
    \ = false;\n            size_t child_cnt = 0;\n            for(auto [to, _] :\
    \ graph[v]) {\n                if(to == p and not std::exchange(parent_checked,\
    \ true)) continue;\n                if(not used[to]) {\n                    child_cnt++;\n\
    \                    dfs(to, v);\n                    low[v] = std::min(low[v],\
    \ low[to]);\n                    is_articulation |= p != -1 and ord[v] <= low[to];\n\
    \                    if(ord[v] < low[to]) bridge.push_back(std::minmax({v, to}));\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n            }\n\n            is_articulation |= p == -1 and\
    \ child_cnt >= 2;\n            if(is_articulation) articulation.push_back(v);\n\
    \        };\n        for(size_t v = 0; v < graph.size(); v++) if(not used[v])\
    \ dfs(v, -1);\n    }\n};\n\nstruct two_edge_connected_components : lowlink {\n\
    \    using lowlink::lowlink;\n    using lowlink::graph;\n    using lowlink::ord;\n\
    \    using lowlink::low;\n    using lowlink::bridge;\n\n    using size_t = std::size_t;\n\
    \    std::vector<size_t> id;\n    std::vector<std::vector<size_t>> group, tree;\n\
    \n    explicit two_edge_connected_components(const size_t n) : lowlink(n), id(n,\
    \ -1) {}\n\n    void build() override {\n        lowlink::build();\n\n       \
    \ size_t c = 0;\n        function<void(size_t,size_t)> dfs = [&](size_t v, size_t\
    \ p) -> void {\n            id[v] = (p != -1 and low[v] <= ord[p] ? id[p] : c++);\n\
    \            for(auto [to, _] : graph[v]) if(id[to] == -1) dfs(to, v);\n     \
    \   };\n        for(size_t i = 0; i < graph.size(); i++) if(id[i] == -1) dfs(i,\
    \ -1);\n\n        group.resize(c);\n        for(size_t i = 0; i < graph.size();\
    \ i++) group[id[i]].push_back(i);\n\n        tree.resize(c);\n        for(auto\
    \ [u, v] : bridge) {\n            u = id[u], v = id[v];\n            tree[u].push_back(v);\n\
    \            tree[v].push_back(u);\n        }\n    }\n};\n\nstruct biconnected_components\
    \ : lowlink {\n    using lowlink::lowlink;\n    using lowlink::graph;\n    using\
    \ lowlink::ord;\n    using lowlink::low;\n    using size_t = std::size_t;\n  \
    \  std::vector<std::vector<std::tuple<size_t, size_t, size_t>>> bc;\n\n    void\
    \ build() override {\n        lowlink::build();\n        std::vector<bool> used(graph.size(),\
    \ false);\n        std::vector<std::tuple<size_t, size_t, size_t>> tmp;\n\n  \
    \      function<void(size_t,size_t)> dfs = [&](size_t v, size_t p) -> void {\n\
    \            used[v] = true;\n            bool parent_checked = false;\n     \
    \       for(auto [to, i] : graph[v]) {\n                if(to == p and not exchange(parent_checked,\
    \ true)) continue;\n                if(not used[to] or ord[to] < ord[v]) tmp.emplace_back(v,\
    \ to, i);\n                if(not used[to]) {\n                    dfs(to, v);\n\
    \                    if(ord[v] <= low[to]) {\n                        std::vector<std::tuple<size_t,\
    \ size_t, size_t>> c;\n                        while(true) {\n               \
    \             auto e = tmp.back(); tmp.pop_back();\n                         \
    \   c.emplace_back(e);\n                            if(get<2>(e) == i) break;\n\
    \                        }\n                        bc.emplace_back(std::move(c));\n\
    \                    }\n                }\n            }\n        };\n\n     \
    \   for(size_t i = 0; i < graph.size(); i++) if(not used[i]) dfs(i, -1);\n   \
    \ }\n};\n\nstruct block_cut_tree : biconnected_components {\n    using biconnected_components::biconnected_components;\n\
    \    using biconnected_components::graph;\n    using biconnected_components::articulation;\n\
    \    using biconnected_components::bc;\n\n    using size_t = std::size_t;\n  \
    \  std::vector<int> rev;\n    std::vector<std::vector<size_t>> group, tree;\n\n\
    \    explicit block_cut_tree(const size_t n) : biconnected_components(n), rev(n,\
    \ -1) {}\n\n    void build() override {\n        biconnected_components::build();\n\
    \n        size_t c = bc.size();\n        for(size_t v : articulation) rev[v] =\
    \ c++;\n        std::vector<size_t> last(c, -1);\n        tree.resize(c);\n  \
    \      for(size_t i = 0; i < bc.size(); i++) {\n            for(auto [u, v, _]\
    \ : bc[i]) {\n                for(size_t x : {u, v}) {\n                    if(rev[x]\
    \ != -1 and bc.size() <= rev[x]) {\n                        if(std::exchange(last[rev[x]],\
    \ i) != i) {\n                            tree[rev[x]].push_back(i);\n       \
    \                     tree[i].push_back(rev[x]);\n                        }\n\
    \                    } else {\n                        rev[x] = i;\n         \
    \           }\n                }\n            }\n        }\n        group.resize(c);\n\
    \        for(size_t i = 0; i < graph.size(); i++) group[rev[i]].push_back(i);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2023-12-26 12:00:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/lowlink.hpp
layout: document
redirect_from:
- /library/src/graph/lowlink.hpp
- /library/src/graph/lowlink.hpp.html
title: src/graph/lowlink.hpp
---
