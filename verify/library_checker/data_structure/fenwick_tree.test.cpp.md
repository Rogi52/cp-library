---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/fenwick_tree.hpp\"\
    \n#include \"src/algebra/plus.hpp\"\n\nint main(){\n    int N = in();\n    int\
    \ Q = in();\n    vector<ll> a = in(N);\n    fenwick_tree< PLUS< ll > > tree(a);\n\
    \n    for(int _ : rep(Q)) {\n        int t = in();\n        switch(t) {\n    \
    \        case 0: {\n                int p = in();\n                int x = in();\n\
    \                tree.add(p, x);\n            } break;\n\n            case 1:\
    \ {\n                int l = in();\n                int r = in();\n          \
    \      print(tree.fold(l, r));\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp
- /verify/verify/library_checker/data_structure/fenwick_tree.test.cpp.html
title: verify/library_checker/data_structure/fenwick_tree.test.cpp
---
