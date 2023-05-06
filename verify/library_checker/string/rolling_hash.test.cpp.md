---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
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
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 1 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\ntemplate < class T > bool chmin(T& a, T b) { if(a >\
    \ b) { a = b; return true; } return false; }\ntemplate < class T > bool chmax(T&\
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
    \ { return t; }\n};\n#line 1 \"src/string/rolling_hash.hpp\"\ntemplate< int num_of_mod\
    \ = 2 >\nstruct rolling_hash {\n    static constexpr ll MODS[] = {999999937, 1000000007,\
    \ 1000000009, 1000000021};\n    static constexpr ll BASE = 9973;\n    \n    struct\
    \ hash : array<ll, num_of_mod> {\n        using array<ll, num_of_mod>::operator[];\n\
    \        static constexpr int n = num_of_mod;\n        hash() : array<ll,n>()\
    \ {}\n        hash(ll x) : hash() { rep(i,n) (*this)[i] = x % MODS[i]; }\n   \
    \     hash& operator+=(const hash& rhs) { rep(i,n) if(((*this)[i] += rhs[i]) >=\
    \ MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n        hash& operator-=(const\
    \ hash& rhs) { rep(i,n) if(((*this)[i] += MODS[i] - rhs[i]) >= MODS[i]) (*this)[i]\
    \ -= MODS[i]; return *this; }\n        hash& operator*=(const hash& rhs) { rep(i,n)\
    \ (*this)[i] = (*this)[i] * rhs[i] % MODS[i]; return *this; }\n        hash& operator+=(const\
    \ ll rhs) { rep(i,n) if(((*this)[i] += rhs % MODS[i]) >= MODS[i]) (*this)[i] -=\
    \ MODS[i]; return *this; }\n        hash& operator-=(const ll rhs) { rep(i,n)\
    \ if(((*this)[i] += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i];\
    \ return *this; }\n        hash& operator*=(const ll rhs) { rep(i,n) (*this)[i]\
    \ = (*this)[i] * (rhs % MODS[i]) % MODS[i]; return *this; }\n        hash operator+(const\
    \ hash& rhs) const { return hash(*this) += rhs; }\n        hash operator-(const\
    \ hash& rhs) const { return hash(*this) -= rhs; }\n        hash operator*(const\
    \ hash& rhs) const { return hash(*this) *= rhs; }\n        hash operator+(const\
    \ ll rhs) const { return hash(*this) += rhs; }\n        hash operator-(const ll\
    \ rhs) const { return hash(*this) -= rhs; }\n        hash operator*(const ll rhs)\
    \ const { return hash(*this) *= rhs; }\n        hash operator-() const { return\
    \ hash().fill(0) - *this; }\n        friend hash operator+(ll x, const hash& y)\
    \ { return hash(x) + y; }\n        friend hash operator-(ll x, const hash& y)\
    \ { return hash(x) + y; }\n        friend hash operator*(ll x, const hash& y)\
    \ { return hash(x) * y; }\n        bool operator==(const hash& rhs) { rep(i,n)\
    \ if((*this)[i] != rhs[i]) return false; return true ; }\n        bool operator!=(const\
    \ hash& rhs) { rep(i,n) if((*this)[i] != rhs[i]) return true ; return false; }\n\
    \    };\n\n    vector< hash > pb, hs;\n    rolling_hash() {}\n    rolling_hash(const\
    \ string& s) {\n        int n = s.size();\n        hs.resize(n + 1); hs[0].fill(0);\n\
    \        pb.resize(n + 1); pb[0].fill(1);\n        rep(i,n) {\n            hs[i\
    \ + 1] = hs[i] * BASE + s[i];\n            pb[i + 1] = pb[i] * BASE;\n       \
    \ }\n    }\n\n    // [l, r)\n    hash get(int l, int r) const {\n        return\
    \ hs[r] - hs[l] * pb[r - l];\n    }\n\n    template < int n >\n    static int\
    \ lcp(const rolling_hash< n >& rh1, int l1, int r1, const rolling_hash< n >& rh2,\
    \ int l2, int r2) {\n        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;\n  \
    \      while(hi - lo > 1) {\n            int mid = (lo + hi) / 2;\n          \
    \  (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;\n       \
    \ }\n        return lo;\n    }\n\n    template < int n >\n    static int cmp(const\
    \ string& s1, const rolling_hash< n >& rh1, int l1, int r1,\n                \
    \   const string& s2, const rolling_hash< n >& rh2, int l2, int r2) {\n      \
    \  int len = lcp(rh1, l1, r1, rh2, l2, r2);\n        if(len == r1 - l1 && len\
    \ == r2 - l2) return 0;\n        if(len == r1 - l1) return -1;\n        if(len\
    \ == r2 - l2) return +1;\n        return (s1[l1 + len] < s2[l2 + len] ? -1 : +1);\n\
    \    }\n};\n#line 5 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    string s; cin\
    \ >> s;\n    int n = s.size();\n    rolling_hash< 1 > rh(s);\n    vector<int>\
    \ I(n);\n    iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(), [&](int\
    \ i, int j) {\n        return rolling_hash< 1 >::cmp(s, rh, i, n, s, rh, j, n)\
    \ < 0;\n    });\n    print(I);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/string/rolling_hash.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    string s; cin >> s;\n  \
    \  int n = s.size();\n    rolling_hash< 1 > rh(s);\n    vector<int> I(n);\n  \
    \  iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(), [&](int i, int j)\
    \ {\n        return rolling_hash< 1 >::cmp(s, rh, i, n, s, rh, j, n) < 0;\n  \
    \  });\n    print(I);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/io.hpp
  - src/utility/rep_itr.hpp
  - src/string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/library_checker/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-05-06 10:33:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/rolling_hash.test.cpp
- /verify/verify/library_checker/string/rolling_hash.test.cpp.html
title: verify/library_checker/string/rolling_hash.test.cpp
---
