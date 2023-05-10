---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 2 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
    \ itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n\
    \    const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t)\
    \ {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
    \ < class T > operator T() {\n            T s; cin >> s; return s;\n        }\n\
    \    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n    \
    \    template < class T > operator vector< T >() {\n            vector< T > v(n);\n\
    \            for(T& x : v) cin >> x;\n            return v;\n        }\n    };\n\
    \    struct mat {\n        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n\
    \        template < class T > operator vector< vector< T > >() {\n           \
    \ vector m(h, vector< T >(w));\n            for(vector< T >& v : m) for(T& x :\
    \ v) cin >> x;\n            return m;\n        }\n    };\n    struct speedup {\n\
    \        speedup() {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n\
    \        }\n    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec\
    \ in(int n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return\
    \ scanner::mat(h, w); }\n\nnamespace printer {\n    void precision(int d) {\n\
    \        cout << fixed << setprecision(d);\n    }\n    void flush() {\n      \
    \  cout.flush();\n    }\n}\nint print() { cout << '\\n'; return 0; }\ntemplate\
    \ < class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 1 \"src/string/rolling_hash.hpp\"\ntemplate<\
    \ int num_of_mod = 2 >\nstruct rolling_hash {\n    static constexpr ll MODS[]\
    \ = {999999937, 1000000007, 1000000009, 1000000021};\n    static constexpr ll\
    \ BASE = 9973;\n    \n    struct hash : array<ll, num_of_mod> {\n        using\
    \ array<ll, num_of_mod>::operator[];\n        static constexpr int n = num_of_mod;\n\
    \        hash() : array<ll,n>() {}\n        hash(ll x) : hash() { for(int i :\
    \ rep(n)) (*this)[i] = x % MODS[i]; }\n        hash& operator+=(const hash& rhs)\
    \ { for(int i : rep(n)) if(((*this)[i] += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i];\
    \ return *this; }\n        hash& operator-=(const hash& rhs) { for(int i : rep(n))\
    \ if(((*this)[i] += MODS[i] - rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return\
    \ *this; }\n        hash& operator*=(const hash& rhs) { for(int i : rep(n)) (*this)[i]\
    \ = (*this)[i] * rhs[i] % MODS[i]; return *this; }\n        hash& operator+=(const\
    \ ll rhs) { for(int i : rep(n)) if(((*this)[i] += rhs % MODS[i]) >= MODS[i]) (*this)[i]\
    \ -= MODS[i]; return *this; }\n        hash& operator-=(const ll rhs) { for(int\
    \ i : rep(n)) if(((*this)[i] += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i]\
    \ -= MODS[i]; return *this; }\n        hash& operator*=(const ll rhs) { for(int\
    \ i : rep(n)) (*this)[i] = (*this)[i] * (rhs % MODS[i]) % MODS[i]; return *this;\
    \ }\n        hash operator+(const hash& rhs) const { return hash(*this) += rhs;\
    \ }\n        hash operator-(const hash& rhs) const { return hash(*this) -= rhs;\
    \ }\n        hash operator*(const hash& rhs) const { return hash(*this) *= rhs;\
    \ }\n        hash operator+(const ll rhs) const { return hash(*this) += rhs; }\n\
    \        hash operator-(const ll rhs) const { return hash(*this) -= rhs; }\n \
    \       hash operator*(const ll rhs) const { return hash(*this) *= rhs; }\n  \
    \      hash operator-() const { return hash().fill(0) - *this; }\n        friend\
    \ hash operator+(ll x, const hash& y) { return hash(x) + y; }\n        friend\
    \ hash operator-(ll x, const hash& y) { return hash(x) + y; }\n        friend\
    \ hash operator*(ll x, const hash& y) { return hash(x) * y; }\n        bool operator==(const\
    \ hash& rhs) { for(int i : rep(n)) if((*this)[i] != rhs[i]) return false; return\
    \ true ; }\n        bool operator!=(const hash& rhs) { for(int i : rep(n)) if((*this)[i]\
    \ != rhs[i]) return true ; return false; }\n    };\n\n    vector< hash > pb, hs;\n\
    \    rolling_hash() {}\n    rolling_hash(const string& s) {\n        int n = s.size();\n\
    \        hs.resize(n + 1); hs[0].fill(0);\n        pb.resize(n + 1); pb[0].fill(1);\n\
    \        for(int i : rep(n)) {\n            hs[i + 1] = hs[i] * BASE + s[i];\n\
    \            pb[i + 1] = pb[i] * BASE;\n        }\n    }\n\n    // [l, r)\n  \
    \  hash get(int l, int r) const {\n        return hs[r] - hs[l] * pb[r - l];\n\
    \    }\n\n    template < int n >\n    static int lcp(const rolling_hash< n >&\
    \ rh1, int l1, int r1, const rolling_hash< n >& rh2, int l2, int r2) {\n     \
    \   int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;\n        while(hi - lo > 1) {\n\
    \            int mid = (lo + hi) / 2;\n            (rh1.get(l1, l1 + mid) == rh2.get(l2,\
    \ l2 + mid) ? lo : hi) = mid;\n        }\n        return lo;\n    }\n\n    template\
    \ < int n >\n    static int cmp(const string& s1, const rolling_hash< n >& rh1,\
    \ int l1, int r1,\n                   const string& s2, const rolling_hash< n\
    \ >& rh2, int l2, int r2) {\n        int len = lcp(rh1, l1, r1, rh2, l2, r2);\n\
    \        if(len == r1 - l1 && len == r2 - l2) return 0;\n        if(len == r1\
    \ - l1) return -1;\n        if(len == r2 - l2) return +1;\n        return (s1[l1\
    \ + len] < s2[l2 + len] ? -1 : +1);\n    }\n};\n#line 5 \"verify/library_checker/string/rolling_hash.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    string s;\
    \ cin >> s;\n    int n = s.size();\n    rolling_hash< 1 > rh(s);\n    vector<int>\
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
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/library_checker/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/rolling_hash.test.cpp
- /verify/verify/library_checker/string/rolling_hash.test.cpp.html
title: verify/library_checker/string/rolling_hash.test.cpp
---
