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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/algebra/plus.hpp:\
    \ line -1: no such header\n"
  code: "#include \"src/data_structure/fenwick_tree.hpp\"\n#include \"src/algebra/plus.hpp\"\
    \n\ntemplate < class T, class U > class offline_multiset {\n  private:\n    int\
    \ n;\n    vector< T > v;\n    fenwick_tree< algebra::PLUS< U > > ft;\n\n  public:\n\
    \    offline_multiset() {}\n    offline_multiset(const vector< T > &x) : v(x)\
    \ {\n        sort(v.begin(), v.end());\n        v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n        n = v.size();\n        ft = fenwick_tree< algebra::PLUS<\
    \ U > >(n);\n    }\n\n    void insert(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, +cnt);\n\
    \    }\n    void erase(T x, U cnt = 1) {\n        int i = lower_bound(v.begin(),\
    \ v.end(), x) - v.begin();\n        assert(v[i] == x);\n        ft.add(i, -cnt);\n\
    \    }\n    T get_kth(U k) {\n        return v[ft.search([k](U s){ return s >=\
    \ k; })];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/offline_multiset.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/offline_multiset.hpp
layout: document
redirect_from:
- /library/src/data_structure/offline_multiset.hpp
- /library/src/data_structure/offline_multiset.hpp.html
title: src/data_structure/offline_multiset.hpp
---
