---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/utility/rep_itr.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/number/modint.hpp\"\n#include\
    \ \"src/data_structure/lazy_segtree.hpp\"\n#include \"src/algebra/range_affine_range_sum.hpp\"\
    \n\nint main(){\n    \n    int N,Q; cin >> N >> Q;\n    using S = range_affine_range_sum<mint>::value_structure::set;\n\
    \    vector< S > a(N);\n    for(int i : rep(N)) {\n        mint x; cin >> x;\n\
    \        a[i] = S{x, 1};\n    }\n\n    lazy_segtree< range_affine_range_sum<mint>\
    \ > lzst(a);\n    for(int _ : rep(Q)) {\n        int t; cin >> t;\n        if(t\
    \ == 0) {\n            int l,r; mint b,c; cin >> l >> r >> b >> c;\n         \
    \   lzst.apply(l, r, {b, c});\n        }\n\n        if(t == 1) {\n           \
    \ int l,r; cin >> l >> r;\n            cout << lzst.prod(l, r).first << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/lazy_segtree.test.cpp
- /verify/verify/library_checker/data_structure/lazy_segtree.test.cpp.html
title: verify/library_checker/data_structure/lazy_segtree.test.cpp
---
