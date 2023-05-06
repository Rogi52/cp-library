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
    \n#line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long\
    \ long;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return\
    \ true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a <\
    \ b) { a = b; return true; } return false; }\n#line 1 \"src/number/modint.hpp\"\
    \nstruct modinfo { uint mod, root; };\ntemplate < modinfo const &ref >\nstruct\
    \ modint {\n    static constexpr uint const &mod = ref.mod;\n    static modint\
    \ root() { return modint(ref.root); }\n    uint v = 0;\n    constexpr modint&\
    \ s(uint v) { this->v = v < mod ? v : v - mod; return *this; }\n    constexpr\
    \ modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-() const { return\
    \ modint() - *this; }\n    modint& operator+=(const modint& rhs) { return s(v\
    \ + rhs.v); }\n    modint& operator-=(const modint& rhs) { return s(v + mod -\
    \ rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v %\
    \ mod; return *this; }\n    modint& operator/=(const modint& rhs) { return *this\
    \ *= rhs.inv(); }\n    modint operator+(const modint& rhs) const { return modint(*this)\
    \ += rhs; }\n    modint operator-(const modint& rhs) const { return modint(*this)\
    \ -= rhs; }\n    modint operator*(const modint& rhs) const { return modint(*this)\
    \ *= rhs; }\n    modint operator/(const modint& rhs) const { return modint(*this)\
    \ /= rhs; }\n    modint pow(ll n) const { modint res(1), x(*this); while(n > 0)\
    \ { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n    modint inv() const\
    \ { int a = v, b = mod, x = 1, y = 0, t; while(b > 0) { t = a / b; swap(a -= t\
    \ * b, b); swap(x -= t * y, y); } return modint(x); }\n    // modint inv() const\
    \ { return pow(mod - 2); }\n    friend modint operator+(int x, const modint& y)\
    \ { return modint(x) + y; }\n    friend modint operator-(int x, const modint&\
    \ y) { return modint(x) - y; }\n    friend modint operator*(int x, const modint&\
    \ y) { return modint(x) * y; }\n    friend modint operator/(int x, const modint&\
    \ y) { return modint(x) / y; }\n    friend istream& operator>>(istream& is, modint&\
    \ m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream& operator<<(ostream&\
    \ os, const modint& m) { return os << m.v; }\n    bool operator==(const modint&\
    \ r) const { return v == r.v; }\n    bool operator!=(const modint& r) const {\
    \ return v != r.v; }\n};\n\nconstexpr modinfo base { 998244353, 3 };\n//constexpr\
    \ modinfo base { 1000000007, 0 };\nusing mint = modint< base >;\n#line 1 \"src/algorithm/count_subseq.hpp\"\
    \ntemplate < class mint, class T >\nmint count_subseq(const vector< T >& a) {\n\
    \    int n = a.size();\n    unordered_map< T, int > mp;\n    vector<mint> dp(n\
    \ + 1);\n    dp[0] = 1;\n    rep(i,n) {\n        dp[i + 1] = dp[i] + dp[i];\n\
    \        if(mp.count(a[i])) dp[i + 1] -= dp[mp[a[i]]];\n        mp[a[i]] = i;\n\
    \    }\n    return dp[n];\n}\n#line 6 \"verify/library_checker/algorithm/count_subseq.test.cpp\"\
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
  - src/number/modint.hpp
  - src/algorithm/count_subseq.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/count_subseq.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:19:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/count_subseq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp.html
title: verify/library_checker/algorithm/count_subseq.test.cpp
---
