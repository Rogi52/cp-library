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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/cht_offline_get_min.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    int N,Q;\
    \ cin >> N >> Q;\n    using Line = tuple<ll,ll,ll,ll>;\n    vector< Line > lines(N);\n\
    \    for(auto &[l, r, a, b] : lines) cin >> l >> r >> a >> b;\n\n    vector< pair<\
    \ int, Line > > query(Q);\n    vector< ll > xs;\n    for(int i : rep(Q)) {\n \
    \       int t; cin >> t;\n        if(t == 0) {\n            ll l, r, a, b; cin\
    \ >> l >> r >> a >> b;\n            query[i] = {t, {l, r, a, b}};\n        } else\
    \ {\n            ll x; cin >> x;\n            query[i] = {t, {x, 0, 0, 0}};\n\
    \            xs.push_back(x);\n        }\n    }\n\n    CHT_offline_get_min<ll>\
    \ cht(xs);\n    for(auto [l, r, a, b] : lines) cht.add_segment(a, b, l, r);\n\
    \    for(int i : rep(Q)) {\n        int t = query[i].first;\n        if(t == 0)\
    \ {\n            auto [l, r, a, b] = query[i].second;\n            cht.add_segment(a,\
    \ b, l, r);\n        } else {\n            auto [x, _, __, ___] = query[i].second;\n\
    \            ll ans = cht.query(x);\n            if(ans == cht.inf) {\n      \
    \          cout << \"INFINITY\" << '\\n';\n            } else {\n            \
    \    cout << ans << '\\n';\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/data_structure/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/segment_add_get_min.test.cpp
- /verify/verify/library_checker/data_structure/segment_add_get_min.test.cpp.html
title: verify/library_checker/data_structure/segment_add_get_min.test.cpp
---
