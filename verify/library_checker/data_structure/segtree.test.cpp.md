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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/segtree.hpp\"\
    \n#include \"src/algebra/affine.hpp\"\n#include \"src/number/modint.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,Q;\
    \ cin >> N >> Q;\n    using F = affine<mint>;\n    vector< F > f(N);\n    for(int\
    \ i : rep(N)) {\n        mint a,b; cin >> a >> b;\n        f[i] = F(a, b);\n \
    \   }\n\n    segtree< affine_composite_monoid<mint> > seg(f);\n    for(int _ :\
    \ rep(Q)) {\n        int t; cin >> t;\n        if(t == 0) {\n            int p;\
    \ mint c,d; cin >> p >> c >> d;\n            seg.set(p, F(c, d));\n        }\n\
    \n        if(t == 1) {\n            int l,r; mint x; cin >> l >> r >> x;\n   \
    \         cout << seg.prod(l, r).eval(x) << \"\\n\";\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/segtree.test.cpp
- /verify/verify/library_checker/data_structure/segtree.test.cpp.html
title: verify/library_checker/data_structure/segtree.test.cpp
---
