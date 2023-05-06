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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"src/cp-template.hpp\"\n#include \"src/data_structure/cht_offline_get_min.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N,Q; cin >> N >> Q;\n    vector<pair<ll,ll>> lines(N);\n    for(auto &[a, b]\
    \ : lines) cin >> a >> b;\n\n    vector<tuple<ll,ll,ll>> query(Q);\n    vector<ll>\
    \ xs;\n    for(int i : rep(Q)) {\n        int t; cin >> t;\n        if(t == 0)\
    \ {\n            ll a,b; cin >> a >> b;\n            query[i] = {t, a, b};\n \
    \       } else {\n            ll x; cin >> x;\n            query[i] = {t, x, 0};\n\
    \            xs.push_back(x);\n        }\n    }\n\n    CHT_offline_get_min<ll>\
    \ cht(xs);\n    for(auto [a, b] : lines) cht.add_line(a, b);\n    for(int i :\
    \ rep(Q)) {\n        auto [t, a, b] = query[i];\n        if(t == 0) {\n      \
    \      cht.add_line(a, b);\n        } else {\n            cout << cht.query(a)\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp
- /verify/verify/library_checker/data_structure/line_add_get_min.test.cpp.html
title: verify/library_checker/data_structure/line_add_get_min.test.cpp
---
