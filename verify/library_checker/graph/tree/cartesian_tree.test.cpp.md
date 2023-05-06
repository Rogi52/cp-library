---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/graph/tree/cartesian_tree.hpp
    title: src/graph/tree/cartesian_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verify/library_checker/graph/tree/cartesian_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line\
    \ 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ { return t; }\n};\n#line 2 \"src/graph/tree/cartesian_tree.hpp\"\n\ntemplate\
    \ < class T >\npair< vector<vector<int>>, int > cartesian_tree(vector< T > &a)\
    \ {\n    int n = a.size();\n    vector<vector<int>> tree(n);\n    vector<int>\
    \ parent(n, -1);\n    stack<int> st;\n    for(int i = 0; i < n; i++) {\n     \
    \   int prev = -1;\n        while(!st.empty() && a[i] < a[st.top()]) { prev =\
    \ st.top(); st.pop(); }\n        if(prev != -1) parent[prev] = i;\n        if(!st.empty())\
    \ parent[i] = st.top();\n        st.push(i);\n    }\n\n    int root = -1;\n  \
    \  for(int i = 0; i < n; i++) {\n        if(parent[i] == -1) root = i;\n     \
    \   else tree[parent[i]].push_back(i);\n    }\n    return {tree, root};\n}\n#line\
    \ 5 \"verify/library_checker/graph/tree/cartesian_tree.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int n; cin >> n;\n \
    \   vector<int> a = in(n);\n    auto [G, r] = cartesian_tree<int>(a);\n    vector<int>\
    \ ans(n);\n    ans[r] = r;\n    for(int i : rep(n)) for(int v : G[i]) ans[v] =\
    \ i;\n    for(int p : ans) cout << p << \" \"; cout << endl;\n};\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/graph/tree/cartesian_tree.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int n; cin\
    \ >> n;\n    vector<int> a = in(n);\n    auto [G, r] = cartesian_tree<int>(a);\n\
    \    vector<int> ans(n);\n    ans[r] = r;\n    for(int i : rep(n)) for(int v :\
    \ G[i]) ans[v] = i;\n    for(int p : ans) cout << p << \" \"; cout << endl;\n\
    };\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  - src/graph/tree/cartesian_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/graph/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/tree/cartesian_tree.test.cpp
- /verify/verify/library_checker/graph/tree/cartesian_tree.test.cpp.html
title: verify/library_checker/graph/tree/cartesian_tree.test.cpp
---
