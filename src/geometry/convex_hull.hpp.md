---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/heap.hpp
    title: src/utility/heap.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 269, in update\n    raise BundleErrorAt(path, -1, \"cycle found in inclusion\
    \ relations\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/algorithm/argsort.hpp:\
    \ line -1: cycle found in inclusion relations\n"
  code: "#include \"src/algorithm/argsort.hpp\"\n\ntemplate < class T >\npair< vector<\
    \ int >, vector< pair< T, T > > > convex_hull(vector< pair< T, T > > &points,\
    \ string mode = \"full\", bool inclusive = false) {\n    assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n    int n = points.size();\n  \
    \  if(n == 1) return {{0}, {points[0]}};\n    if(n == 2) return {{0, 1}, {points[0],\
    \ points[1]}};\n    vector<int> I = argsort(points);\n\n    auto check = [&](int\
    \ i, int j, int k) {\n        auto [xi, yi] = points[i];\n        auto [xj, yj]\
    \ = points[j];\n        auto [xk, yk] = points[k];\n        T det = (xj - xi)\
    \ * (yk - yj) - (yj - yi) * (xk - xj);\n        return inclusive ? det >= 0 :\
    \ det > 0;\n    };\n\n    auto calc = [&]() {\n        vector<int> J;\n      \
    \  for(int k : I) {\n            while(J.size() >= 2 && !check(J[J.size() - 2],\
    \ J.back(), k)) J.pop_back();\n            J.push_back(k);\n        }\n      \
    \  return J;\n    };\n\n    vector<int> ids;\n    if(mode == \"full\" || mode\
    \ == \"lower\") {\n        vector<int> J = calc();\n        ids.insert(ids.end(),\
    \ J.begin(), J.end());\n    }\n    if(mode == \"full\" || mode == \"upper\") {\n\
    \        if(!ids.empty()) ids.pop_back();\n        reverse(I.begin(), I.end());\n\
    \        vector<int> J = calc();\n        ids.insert(ids.end(), J.begin(), J.end());\n\
    \    }\n    if(mode == \"upper\") reverse(ids.begin(), ids.end());\n    if(ids.size()\
    \ >= 2 && ids[0] == ids.back()) ids.pop_back();\n    vector< pair< T, T > > ch;\n\
    \    for(int i : ids) ch.push_back(points[i]);\n    return {ids, ch};\n}\n"
  dependsOn:
  - src/algorithm/argsort.hpp
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/src/geometry/convex_hull.hpp
- /library/src/geometry/convex_hull.hpp.html
title: src/geometry/convex_hull.hpp
---
