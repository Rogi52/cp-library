---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/beta/review.html#ICPCOOC2023/8680925
  bundledCode: "#line 1 \"src/graph/submodular_minimization.hpp\"\n#include <atcoder/maxflow>\n\
    \n// ICPC2023 Yokohama Regional H\n// https://onlinejudge.u-aizu.ac.jp/beta/review.html#ICPCOOC2023/8680925\n\
    template < class Cost > class sm_min {\n  public:\n    using size_t = std::size_t;\n\
    \    size_t n, s, t;\n    atcoder::mf_graph<Cost> g;\n    Cost c0;\n    std::vector<std::array<Cost,\
    \ 2>> c1;\n    std::vector<std::vector<std::array<std::array<Cost, 2>, 2>>> c2;\n\
    \n    sm_min() = default;\n    explicit sm_min(size_t n) : n(n), s(n), t(n + 1),\
    \ g(1 + n + 1), c0(0), c1(n), c2(n, std::vector<std::array<std::array<Cost, 2>,\
    \ 2>>(n)) {}\n\n    void add_0(Cost cost) {\n        c0 += cost;\n    }\n\n  \
    \  void add_1(size_t i, bool f, Cost cost) {\n        assert(i < n);\n       \
    \ c1[i][f] += cost;\n    }\n\n    void add_2(size_t i, bool f, size_t j, bool\
    \ g, Cost cost) {\n        assert(i < n);\n        assert(j < n);\n        c2[i][j][f][g]\
    \ += cost;\n    }\n\n    Cost answer() {\n        for(size_t i = 0; i < n; i++)\
    \ {\n            for(size_t j = 0; j < n; j++) {\n                auto& c = c2[i][j];\n\
    \                assert(c[0][1] + c[1][0] >= c[0][0] + c[1][1]);\n           \
    \     add_0(c[0][0]);\n                add_1(i, 1, c[1][1] - c[0][1]);\n     \
    \           add_1(j, 1, c[0][1] - c[0][0]);\n                g.add_edge(i, j,\
    \ c[0][1] + c[1][0] - c[0][0] - c[1][1]);\n            }\n        }\n        for(size_t\
    \ i = 0; i < n; i++) {\n            auto& c = c1[i];\n            if(c[0] >= c[1])\
    \ {\n                add_0(c[1]);\n                g.add_edge(s, i, c[0] - c[1]);\n\
    \            } else {\n                add_0(c[0]);\n                g.add_edge(i,\
    \ t, c[1] - c[0]);\n            }\n        }\n        return c0 + g.flow(s, t);\n\
    \    }\n};\n"
  code: "#include <atcoder/maxflow>\n\n// ICPC2023 Yokohama Regional H\n// https://onlinejudge.u-aizu.ac.jp/beta/review.html#ICPCOOC2023/8680925\n\
    template < class Cost > class sm_min {\n  public:\n    using size_t = std::size_t;\n\
    \    size_t n, s, t;\n    atcoder::mf_graph<Cost> g;\n    Cost c0;\n    std::vector<std::array<Cost,\
    \ 2>> c1;\n    std::vector<std::vector<std::array<std::array<Cost, 2>, 2>>> c2;\n\
    \n    sm_min() = default;\n    explicit sm_min(size_t n) : n(n), s(n), t(n + 1),\
    \ g(1 + n + 1), c0(0), c1(n), c2(n, std::vector<std::array<std::array<Cost, 2>,\
    \ 2>>(n)) {}\n\n    void add_0(Cost cost) {\n        c0 += cost;\n    }\n\n  \
    \  void add_1(size_t i, bool f, Cost cost) {\n        assert(i < n);\n       \
    \ c1[i][f] += cost;\n    }\n\n    void add_2(size_t i, bool f, size_t j, bool\
    \ g, Cost cost) {\n        assert(i < n);\n        assert(j < n);\n        c2[i][j][f][g]\
    \ += cost;\n    }\n\n    Cost answer() {\n        for(size_t i = 0; i < n; i++)\
    \ {\n            for(size_t j = 0; j < n; j++) {\n                auto& c = c2[i][j];\n\
    \                assert(c[0][1] + c[1][0] >= c[0][0] + c[1][1]);\n           \
    \     add_0(c[0][0]);\n                add_1(i, 1, c[1][1] - c[0][1]);\n     \
    \           add_1(j, 1, c[0][1] - c[0][0]);\n                g.add_edge(i, j,\
    \ c[0][1] + c[1][0] - c[0][0] - c[1][1]);\n            }\n        }\n        for(size_t\
    \ i = 0; i < n; i++) {\n            auto& c = c1[i];\n            if(c[0] >= c[1])\
    \ {\n                add_0(c[1]);\n                g.add_edge(s, i, c[0] - c[1]);\n\
    \            } else {\n                add_0(c[0]);\n                g.add_edge(i,\
    \ t, c[1] - c[0]);\n            }\n        }\n        return c0 + g.flow(s, t);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/submodular_minimization.hpp
  requiredBy: []
  timestamp: '2023-12-21 22:21:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/submodular_minimization.hpp
layout: document
redirect_from:
- /library/src/graph/submodular_minimization.hpp
- /library/src/graph/submodular_minimization.hpp.html
title: src/graph/submodular_minimization.hpp
---
