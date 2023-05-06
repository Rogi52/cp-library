---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algorithm/lis.hpp
    title: Longest Increasing Subsequence
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"verify/library_checker/algorithm/lis.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ { return t; }\n};\n#line 1 \"src/algorithm/lis.hpp\"\ntemplate < class T, class\
    \ Cmp >\ntuple< vector< T >, vector<int>, vector<int> > l_s(const vector< T >&\
    \ a, Cmp cmp) {\n    int n = a.size();\n    vector< T > l_s;\n    vector<int>\
    \ st(n, -1), nt(n, -1), rank(n);\n    rep(i,n) {\n        int pos = lower_bound(l_s.begin(),\
    \ l_s.end(), a[i], cmp) - l_s.begin();\n        st[pos] = i;\n        if(pos >=\
    \ 1) nt[i] = st[pos - 1];\n        if(pos == int(l_s.size())) l_s.push_back(a[i]);\
    \ else l_s[pos] = a[i];\n        rank[i] = pos + 1;\n    }\n    int len = l_s.size();\n\
    \    vector<int> idx(len);\n    for(int i = st[len - 1]; i >= 0; i = nt[i]) idx[--len]\
    \ = i;\n    return {l_s, idx, rank};\n}\n#line 5 \"verify/library_checker/algorithm/lis.test.cpp\"\
    \n\nint main(){\n    int N = in();\n    vector<int> A = in(N);\n\n    auto [lis,\
    \ idx, rank] = l_s(A, [&](int a, int b) { return a < b; });\n    print(idx.size());\n\
    \    print(idx);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/algorithm/lis.hpp\"\n\nint\
    \ main(){\n    int N = in();\n    vector<int> A = in(N);\n\n    auto [lis, idx,\
    \ rank] = l_s(A, [&](int a, int b) { return a < b; });\n    print(idx.size());\n\
    \    print(idx);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  - src/algorithm/lis.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/lis.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/lis.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/lis.test.cpp
- /verify/verify/library_checker/algorithm/lis.test.cpp.html
title: verify/library_checker/algorithm/lis.test.cpp
---
