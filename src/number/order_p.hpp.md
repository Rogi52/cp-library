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
  bundledCode: "#line 1 \"src/number/order_p.hpp\"\nstruct order_p {\n    u64 P;\n\
    \    std::size_t n;\n    std::vector<std::pair<u64, i32>> pf;\n    vector<u64>\
    \ prod;\n    order_p() = default;\n    order_p(u64 P) : order_p(P, factor_pair(P\
    \ - 1)) {}\n    order_p(u64 P, vector<pair<u64, i32>> pf) : P(P), pf(pf), n(pf.size()),\
    \ prod(n + 1) {\n        prod[0] = 1;\n        for(std::size_t i = 0; i < n; i++)\
    \ {\n            auto [p, e] = pf[i];\n            u64 pe = 1;\n            while(e--)\
    \ pe *= p;\n            prod[i + 1] = prod[i] * pe;\n        }\n    }\n\n    u64\
    \ get(u64 x) {\n        return n == 0 ? 1 : get(0, n, x);\n    }\n    u64 get(std::size_t\
    \ l, std::size_t r, u64 x) {\n        if(l + 1 == r) {\n            auto [p, e]\
    \ = pf[l];\n            std::size_t ei = [&] {\n                for(std::size_t\
    \ i = 0; i < e; i++) {\n                    if(x == 1) return i;\n           \
    \         x = modpow64(x, p, P);\n                }\n                return std::size_t(e);\n\
    \            }();\n            u64 ans = 1;\n            for(std::size_t _ = 0;\
    \ _ < ei; _++) ans *= p;\n            return ans;\n        }\n        std::size_t\
    \ m = (l + r) / 2;\n        return get(l, m, modpow64(x, prod[r] / prod[m], P))\n\
    \             * get(m, r, modpow64(x, prod[m] / prod[l], P));\n    }\n\n};\n"
  code: "struct order_p {\n    u64 P;\n    std::size_t n;\n    std::vector<std::pair<u64,\
    \ i32>> pf;\n    vector<u64> prod;\n    order_p() = default;\n    order_p(u64\
    \ P) : order_p(P, factor_pair(P - 1)) {}\n    order_p(u64 P, vector<pair<u64,\
    \ i32>> pf) : P(P), pf(pf), n(pf.size()), prod(n + 1) {\n        prod[0] = 1;\n\
    \        for(std::size_t i = 0; i < n; i++) {\n            auto [p, e] = pf[i];\n\
    \            u64 pe = 1;\n            while(e--) pe *= p;\n            prod[i\
    \ + 1] = prod[i] * pe;\n        }\n    }\n\n    u64 get(u64 x) {\n        return\
    \ n == 0 ? 1 : get(0, n, x);\n    }\n    u64 get(std::size_t l, std::size_t r,\
    \ u64 x) {\n        if(l + 1 == r) {\n            auto [p, e] = pf[l];\n     \
    \       std::size_t ei = [&] {\n                for(std::size_t i = 0; i < e;\
    \ i++) {\n                    if(x == 1) return i;\n                    x = modpow64(x,\
    \ p, P);\n                }\n                return std::size_t(e);\n        \
    \    }();\n            u64 ans = 1;\n            for(std::size_t _ = 0; _ < ei;\
    \ _++) ans *= p;\n            return ans;\n        }\n        std::size_t m =\
    \ (l + r) / 2;\n        return get(l, m, modpow64(x, prod[r] / prod[m], P))\n\
    \             * get(m, r, modpow64(x, prod[m] / prod[l], P));\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/order_p.hpp
  requiredBy: []
  timestamp: '2024-01-11 07:33:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/order_p.hpp
layout: document
redirect_from:
- /library/src/number/order_p.hpp
- /library/src/number/order_p.hpp.html
title: src/number/order_p.hpp
---
