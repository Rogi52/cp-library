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
  bundledCode: "#line 1 \"src/algorithm/concave_max_plus_convolution.hpp\"\n// c[k]\
    \ = max_{i+j=k} a[i] + b[j]\n// b: concave\ntemplate < class T >\nstd::vector<\
    \ T > concave_max_plus_convolution(const std::vector< T >& a, const std::vector<\
    \ T >& b) {\n    const std::size_t n = a.size();\n    const std::size_t m = b.size();\n\
    \    const auto get = [&](const std::size_t k, const std::size_t i) {\n      \
    \  const std::size_t j = k - i;\n        return a[i] + b[j];\n    };\n    const\
    \ std::vector<int> amax\n      = smawk (n + m - 1, n,\n            [&](const std::size_t\
    \ i, const std::size_t j, const std::size_t k) {\n                if(i < k) return\
    \ false;\n                if(m <= i - j) return true;\n                return\
    \ get(i, j) <= get(i, k);\n            }\n        );\n    std::vector< T > c(n\
    \ + m - 1);\n    for(std::size_t i = 0; i < n + m - 1; i++) c[i] = get(i, amax[i]);\n\
    \    return c;\n}\n"
  code: "// c[k] = max_{i+j=k} a[i] + b[j]\n// b: concave\ntemplate < class T >\n\
    std::vector< T > concave_max_plus_convolution(const std::vector< T >& a, const\
    \ std::vector< T >& b) {\n    const std::size_t n = a.size();\n    const std::size_t\
    \ m = b.size();\n    const auto get = [&](const std::size_t k, const std::size_t\
    \ i) {\n        const std::size_t j = k - i;\n        return a[i] + b[j];\n  \
    \  };\n    const std::vector<int> amax\n      = smawk (n + m - 1, n,\n       \
    \     [&](const std::size_t i, const std::size_t j, const std::size_t k) {\n \
    \               if(i < k) return false;\n                if(m <= i - j) return\
    \ true;\n                return get(i, j) <= get(i, k);\n            }\n     \
    \   );\n    std::vector< T > c(n + m - 1);\n    for(std::size_t i = 0; i < n +\
    \ m - 1; i++) c[i] = get(i, amax[i]);\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/concave_max_plus_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-08 21:18:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/concave_max_plus_convolution.hpp
layout: document
redirect_from:
- /library/src/algorithm/concave_max_plus_convolution.hpp
- /library/src/algorithm/concave_max_plus_convolution.hpp.html
title: src/algorithm/concave_max_plus_convolution.hpp
---
