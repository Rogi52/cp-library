---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/geometry/angle_sort.hpp
    title: src/geometry/angle_sort.hpp
  - icon: ':x:'
    path: src/geometry/pointll.hpp
    title: src/geometry/pointll.hpp
  - icon: ':x:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':x:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"verify/library_checker/geometry/angle_sort.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n\
    #line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\ntemplate < class T > bool chmin(T& a, T b) { if(a\
    \ > b) { a = b; return true; } return false; }\ntemplate < class T > bool chmax(T&\
    \ a, T b) { if(a < b) { a = b; return true; } return false; }\n\n#line 1 \"src/utility/io.hpp\"\
    \nnamespace scanner {\n    static int sz = -1;\n    static int first = 1;\n  \
    \  struct input {\n        template < class T > operator T() const {\n       \
    \     if(first) {\n                first = 0;\n                cin.tie(0);\n \
    \               ios::sync_with_stdio(0);\n            }\n            if(sz ==\
    \ -1) {\n                T t; cin >> t; return t;\n            } else {\n    \
    \            T t(sz); sz = -1; cin >> t; return t;\n            }\n        }\n\
    \    };\n\n    template < class T > istream& operator>>(istream& is, vector< T\
    \ >& a) {\n        for(auto& x : a) cin >> x; return is;\n    }\n}\nscanner::input\
    \ input() { return scanner::input(); }\nscanner::input input(int sz) { scanner::sz\
    \ = sz; return scanner::input(); }\n\nnamespace printer {\n    void precision(int\
    \ d) {\n        cout << fixed << setprecision(d);\n    }\n}\nint print() { cout\
    \ << \"\\n\"; return 0; }\ntemplate < class head, class... tail >\nint print(head&&\
    \ h, tail&&... t) {\n    cout << h;\n    if(sizeof...(tail)) cout << \" \";\n\
    \    return print(forward<tail>(t)...);\n}\ntemplate < class T > int print(vector<\
    \ T >& a, char sep = ' ') {\n    int n = a.size();\n    rep(i,n) cout << a[i]\
    \ << (i < n - 1 ? sep : '\\n');\n    return 0;\n}\n#line 1 \"src/utility/rep_itr.hpp\"\
    \ntemplate < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept :\
    \ i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int\
    \ operator*() const noexcept { return i; }\n    constexpr bool operator!=(const\
    \ itr x) const noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n\
    };\n\ntemplate < class T > struct rep {\n    const itr< T > s, t;\n    constexpr\
    \ rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const\
    \ T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const\
    \ T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n\n\
    template < class T > struct revrep {\n    const itr < T > s, t;\n    constexpr\
    \ revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n#line 1 \"src/geometry/pointll.hpp\"\nstruct pointll {\n\
    \    ll x,y;\n    pointll(ll x = 0, ll y = 0) : x(x), y(y) {}\n    bool operator==(pointll\
    \ p) const { return x == p.x && y == p.y; }\n};\n\nll det(pointll p, pointll q)\
    \ { return p.x * q.y - p.y * q.x; }\nll dot(pointll p, pointll q) { return p.x\
    \ * q.x + p.y * q.y; }\n#line 1 \"src/geometry/angle_sort.hpp\"\nvector<int> angle_argsort(const\
    \ vector<pointll>& P) {\n    vector<int> lower, origin, upper;\n    pointll O(0,\
    \ 0);\n    rep(i,int(P.size())) {\n        if(P[i] == O)\n            origin.push_back(i);\n\
    \        else if(P[i].y < 0 || (P[i].y == 0 && P[i].x > 0))\n            lower\
    \ .push_back(i);\n        else\n            upper .push_back(i);\n    }\n    sort(lower.begin(),\
    \ lower.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    sort(upper.begin(),\
    \ upper.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });\n    vector<int>\
    \ I;\n    I.insert(I.end(), lower .begin(), lower .end());\n    I.insert(I.end(),\
    \ origin.begin(), origin.end());\n    I.insert(I.end(), upper .begin(), upper\
    \ .end());\n    return I;\n}\n\nvoid angle_sort(vector<pointll>& P) {\n    auto\
    \ I = angle_argsort(P);\n    vector<pointll> Q(P.size());\n    rep(i,int(P.size()))\
    \ Q[i] = P[I[i]];\n    swap(P, Q);\n}\n#line 6 \"verify/library_checker/geometry/angle_sort.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N; cin >> N;\n    vector<pointll> P(N);\n    for(int i : rep(N)) cin >> P[i].x\
    \ >> P[i].y;\n    auto I = angle_argsort(P);\n    for(int i : I) cout << P[i].x\
    \ << \" \" << P[i].y << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/geometry/pointll.hpp\"\n\
    #include \"src/geometry/angle_sort.hpp\"\n\nint main(){\n    cin.tie(0);\n   \
    \ ios::sync_with_stdio(0);\n    \n    int N; cin >> N;\n    vector<pointll> P(N);\n\
    \    for(int i : rep(N)) cin >> P[i].x >> P[i].y;\n    auto I = angle_argsort(P);\n\
    \    for(int i : I) cout << P[i].x << \" \" << P[i].y << \"\\n\";\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  - src/geometry/pointll.hpp
  - src/geometry/angle_sort.hpp
  isVerificationFile: true
  path: verify/library_checker/geometry/angle_sort.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/geometry/angle_sort.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/geometry/angle_sort.test.cpp
- /verify/verify/library_checker/geometry/angle_sort.test.cpp.html
title: verify/library_checker/geometry/angle_sort.test.cpp
---
