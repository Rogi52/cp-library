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
    - https://noshi91.hatenablog.com/entry/2023/12/06/002723
  bundledCode: "#line 1 \"src/data_structure/suffix_xor_base.hpp\"\n// https://noshi91.hatenablog.com/entry/2023/12/06/002723\n\
    template < class T > class suffix_xor_base {\n    int sz;\n    std::vector<std::pair<int,\
    \ T>> b;\n\n  public:\n    suffix_xor_base() : sz(0), b{{-1, 0}} {}\n    void\
    \ push_back(T x) {\n        assert(0 <= x);\n        std::pair<int, T> q = {sz++,\
    \ x};\n        for(auto it = b.begin(); it != b.end(); it++) {\n            if((q.second\
    \ & ~it->second) > it->second) {\n                b.insert(it, q);\n         \
    \       break;\n            }\n            if(q.second <= (q.second ^ it->second))\
    \ continue;\n            if(q.first > it->first) std::swap(q, *it);\n        \
    \    q.second ^= it->second;\n        }\n    }\n    std::vector< T > get(int l)\
    \ const {\n        assert(0 <= l);\n        std::vector< T > res;\n        for(const\
    \ auto& [i, x] : b) if(l <= i) res.push_back(x);\n        return res;\n    }\n\
    };\n"
  code: "// https://noshi91.hatenablog.com/entry/2023/12/06/002723\ntemplate < class\
    \ T > class suffix_xor_base {\n    int sz;\n    std::vector<std::pair<int, T>>\
    \ b;\n\n  public:\n    suffix_xor_base() : sz(0), b{{-1, 0}} {}\n    void push_back(T\
    \ x) {\n        assert(0 <= x);\n        std::pair<int, T> q = {sz++, x};\n  \
    \      for(auto it = b.begin(); it != b.end(); it++) {\n            if((q.second\
    \ & ~it->second) > it->second) {\n                b.insert(it, q);\n         \
    \       break;\n            }\n            if(q.second <= (q.second ^ it->second))\
    \ continue;\n            if(q.first > it->first) std::swap(q, *it);\n        \
    \    q.second ^= it->second;\n        }\n    }\n    std::vector< T > get(int l)\
    \ const {\n        assert(0 <= l);\n        std::vector< T > res;\n        for(const\
    \ auto& [i, x] : b) if(l <= i) res.push_back(x);\n        return res;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/suffix_xor_base.hpp
  requiredBy: []
  timestamp: '2023-12-06 20:31:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/suffix_xor_base.hpp
layout: document
redirect_from:
- /library/src/data_structure/suffix_xor_base.hpp
- /library/src/data_structure/suffix_xor_base.hpp.html
title: src/data_structure/suffix_xor_base.hpp
---
