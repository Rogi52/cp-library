---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/geometry/angle_sort.hpp
    title: src/geometry/angle_sort.hpp
  - icon: ':x:'
    path: src/geometry/pointll.hpp
    title: src/geometry/pointll.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"verify/library_checker/geometry/angle_sort.test.hpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n\
    #line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int\
    \ i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld\
    \ = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\n#line 1 \"src/geometry/pointll.hpp\"\n\
    struct pointll {\n    ll x,y;\n    pointll(ll x = 0, ll y = 0) : x(x), y(y) {}\n\
    \    bool operator==(pointll p) const { return x == p.x && y == p.y; }\n};\n\n\
    ll det(pointll p, pointll q) { return p.x * q.y - p.y * q.x; }\nll dot(pointll\
    \ p, pointll q) { return p.x * q.x + p.y * q.y; }\n#line 1 \"src/geometry/angle_sort.hpp\"\
    \nvector<int> angle_argsort(vector<pointll>& P) {\n    vector<int> lower, origin,\
    \ upper;\n    pointll O(0, 0);\n    rep(i,int(P.size())) {\n        if(P[i] ==\
    \ O)\n            origin.push_back(i);\n        else if(P[i].y < 0 || (P[i].y\
    \ == 0 && P[i].x > 0))\n            lower .push_back(i);\n        else\n     \
    \       upper .push_back(i);\n    }\n    sort(lower.begin(), lower.end(), [&](int\
    \ i, int j) { return det(P[i], P[j]) > 0; });\n    sort(upper.begin(), upper.end(),\
    \ [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    vector<int> I;\n  \
    \  I.insert(I.end(), lower .begin(), lower .end());\n    I.insert(I.end(), origin.begin(),\
    \ origin.end());\n    I.insert(I.end(), upper .begin(), upper .end());\n    return\
    \ I;\n}\n#line 6 \"verify/library_checker/geometry/angle_sort.test.hpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N; cin\
    \ >> N;\n    vector<pointll> P(N);\n    rep(i,N) cin >> P[i].x >> P[i].y;\n  \
    \  auto I = angle_argsort(P);\n    for(int i : I) cout << P[i].x << \" \" << P[i].y\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/geometry/pointll.hpp\"\n\
    #include \"src/geometry/angle_sort.hpp\"\n\nint main(){\n    cin.tie(0);\n   \
    \ ios::sync_with_stdio(0);\n    \n    int N; cin >> N;\n    vector<pointll> P(N);\n\
    \    rep(i,N) cin >> P[i].x >> P[i].y;\n    auto I = angle_argsort(P);\n    for(int\
    \ i : I) cout << P[i].x << \" \" << P[i].y << \"\\n\";\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/geometry/pointll.hpp
  - src/geometry/angle_sort.hpp
  isVerificationFile: true
  path: verify/library_checker/geometry/angle_sort.test.hpp
  requiredBy: []
  timestamp: '2023-03-31 03:20:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/geometry/angle_sort.test.hpp
layout: document
redirect_from:
- /verify/verify/library_checker/geometry/angle_sort.test.hpp
- /verify/verify/library_checker/geometry/angle_sort.test.hpp.html
title: verify/library_checker/geometry/angle_sort.test.hpp
---
