---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algorithm/count_subseq.hpp
    title: src/algorithm/count_subseq.hpp
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/number/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"verify/library_checker/algorithm/count_subseq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\
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
    \ { return t; }\n};\n#line 1 \"src/number/modint.hpp\"\nstruct modinfo { uint\
    \ mod, root; };\ntemplate < modinfo const &ref >\nstruct modint {\n    static\
    \ constexpr uint const &mod = ref.mod;\n    static modint root() { return modint(ref.root);\
    \ }\n    uint v = 0;\n    constexpr modint& s(uint v) { this->v = v < mod ? v\
    \ : v - mod; return *this; }\n    constexpr modint(ll v = 0) { s(v % mod + mod);\
    \ }\n    modint operator-() const { return modint() - *this; }\n    modint& operator+=(const\
    \ modint& rhs) { return s(v + rhs.v); }\n    modint& operator-=(const modint&\
    \ rhs) { return s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs)\
    \ { v = ull(v) * rhs.v % mod; return *this; }\n    modint& operator/=(const modint&\
    \ rhs) { return *this *= rhs.inv(); }\n    modint operator+(const modint& rhs)\
    \ const { return modint(*this) += rhs; }\n    modint operator-(const modint& rhs)\
    \ const { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs)\
    \ const { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs)\
    \ const { return modint(*this) /= rhs; }\n    modint pow(ll n) const { modint\
    \ res(1), x(*this); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return\
    \ res; }\n    modint inv() const { int a = v, b = mod, x = 1, y = 0, t; while(b\
    \ > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); } return modint(x);\
    \ }\n    // modint inv() const { return pow(mod - 2); }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n};\n\nconstexpr modinfo base { 998244353, 3 };\n\
    //constexpr modinfo base { 1000000007, 0 };\nusing mint = modint< base >;\n#line\
    \ 1 \"src/algorithm/count_subseq.hpp\"\ntemplate < class mint, class T >\nmint\
    \ count_subseq(const vector< T >& a) {\n    int n = a.size();\n    unordered_map<\
    \ T, int > mp;\n    vector<mint> dp(n + 1);\n    dp[0] = 1;\n    rep(i,n) {\n\
    \        dp[i + 1] = dp[i] + dp[i];\n        if(mp.count(a[i])) dp[i + 1] -= dp[mp[a[i]]];\n\
    \        mp[a[i]] = i;\n    }\n    return dp[n];\n}\n#line 6 \"verify/library_checker/algorithm/count_subseq.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N = in();\n    vector<int> A = in(N);\n    print(count_subseq<mint>(A) - 1);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/number/modint.hpp\"\n#include\
    \ \"src/algorithm/count_subseq.hpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    \n    int N = in();\n    vector<int> A = in(N);\n    print(count_subseq<mint>(A)\
    \ - 1);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  - src/number/modint.hpp
  - src/algorithm/count_subseq.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/count_subseq.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/count_subseq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp.html
title: verify/library_checker/algorithm/count_subseq.test.cpp
---
