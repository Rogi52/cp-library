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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../src/algebra/plus.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/point_add_rect_sum.hpp\"\
    \n#include \"../../../src/algebra/plus.hpp\"\n\nint main() {\n    int N = in(),\
    \ Q = in();\n    rect_sum< tag::DYNAMIC, tag::POINT, int, PLUS<ll> > rs;\n   \
    \ for(int i : rep(N)) {\n        int x = in(), y = in(), w = in();\n        rs.add(x,\
    \ y, w);\n    }\n    for(int i : rep(Q)) {\n        int t = in();\n        if(t\
    \ == 0) {\n            int x = in(), y = in(), w = in();\n            rs.add(x,\
    \ y, w);\n        }\n        if(t == 1) {\n            int l = in(), d = in(),\
    \ r = in(), u = in();\n            rs.query(l, r, d, u);\n        }\n    }\n \
    \   print(rs.solve(), '\\n');\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_rect_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_rect_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
---
