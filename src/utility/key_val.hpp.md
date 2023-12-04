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
  bundledCode: "#line 2 \"src/utility/key_val.hpp\"\n\ntemplate < class K, class V\
    \ >\nstruct key_val {\n    K key; V val;\n    key_val() {}\n    key_val(K key,\
    \ V val) : key(key), val(val) {}\n    template < std::size_t Index >\n    std::tuple_element_t<\
    \ Index, key_val >& get() {\n        if constexpr (Index == 0) return key;\n \
    \       if constexpr (Index == 1) return val;\n    }\n};\n\nnamespace std {\n\n\
    template < class K, class V > struct tuple_size < key_val< K, V > > : integral_constant<\
    \ size_t, 2 > {};\ntemplate < class K, class V > struct tuple_element < 0, key_val<\
    \ K, V > > { using type = K; };\ntemplate < class K, class V > struct tuple_element\
    \ < 1, key_val< K, V > > { using type = V; };\n\n}\n"
  code: "#pragma once\n\ntemplate < class K, class V >\nstruct key_val {\n    K key;\
    \ V val;\n    key_val() {}\n    key_val(K key, V val) : key(key), val(val) {}\n\
    \    template < std::size_t Index >\n    std::tuple_element_t< Index, key_val\
    \ >& get() {\n        if constexpr (Index == 0) return key;\n        if constexpr\
    \ (Index == 1) return val;\n    }\n};\n\nnamespace std {\n\ntemplate < class K,\
    \ class V > struct tuple_size < key_val< K, V > > : integral_constant< size_t,\
    \ 2 > {};\ntemplate < class K, class V > struct tuple_element < 0, key_val< K,\
    \ V > > { using type = K; };\ntemplate < class K, class V > struct tuple_element\
    \ < 1, key_val< K, V > > { using type = V; };\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/key_val.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/key_val.hpp
layout: document
redirect_from:
- /library/src/utility/key_val.hpp
- /library/src/utility/key_val.hpp.html
title: src/utility/key_val.hpp
---
