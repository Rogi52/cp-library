---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
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
    #define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 1 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n) for(int i =\
    \ 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\nusing ld = long\
    \ double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n#line\
    \ 1 \"src/string/rolling_hash.hpp\"\ntemplate< int num_of_mod = 2 >\nstruct rolling_hash\
    \ {\n    static constexpr ll MODS[] = {999999937, 1000000007, 1000000009, 1000000021};\n\
    \    static constexpr ll BASE = 9973;\n    \n    struct hash : array<ll, num_of_mod>\
    \ {\n        using array<ll, num_of_mod>::operator[];\n        static constexpr\
    \ int n = num_of_mod;\n        hash() : array<ll,n>() {}\n        hash(ll x) :\
    \ hash() { rep(i,n) (*this)[i] = x % MODS[i]; }\n        hash& operator+=(const\
    \ hash& rhs) { rep(i,n) if(((*this)[i] += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i];\
    \ return *this; }\n        hash& operator-=(const hash& rhs) { rep(i,n) if(((*this)[i]\
    \ += MODS[i] - rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n  \
    \      hash& operator*=(const hash& rhs) { rep(i,n) (*this)[i] = (*this)[i] *\
    \ rhs[i] % MODS[i]; return *this; }\n        hash& operator+=(const ll rhs) {\
    \ rep(i,n) if(((*this)[i] += rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i];\
    \ return *this; }\n        hash& operator-=(const ll rhs) { rep(i,n) if(((*this)[i]\
    \ += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this;\
    \ }\n        hash& operator*=(const ll rhs) { rep(i,n) (*this)[i] = (*this)[i]\
    \ * (rhs % MODS[i]) % MODS[i]; return *this; }\n        hash operator+(const hash&\
    \ rhs) const { return hash(*this) += rhs; }\n        hash operator-(const hash&\
    \ rhs) const { return hash(*this) -= rhs; }\n        hash operator*(const hash&\
    \ rhs) const { return hash(*this) *= rhs; }\n        hash operator+(const ll rhs)\
    \ const { return hash(*this) += rhs; }\n        hash operator-(const ll rhs) const\
    \ { return hash(*this) -= rhs; }\n        hash operator*(const ll rhs) const {\
    \ return hash(*this) *= rhs; }\n        hash operator-() const { return hash().fill(0)\
    \ - *this; }\n        friend hash operator+(ll x, const hash& y) { return hash(x)\
    \ + y; }\n        friend hash operator-(ll x, const hash& y) { return hash(x)\
    \ + y; }\n        friend hash operator*(ll x, const hash& y) { return hash(x)\
    \ * y; }\n        bool operator==(const hash& rhs) { rep(i,n) if((*this)[i] !=\
    \ rhs[i]) return false; return true ; }\n        bool operator!=(const hash& rhs)\
    \ { rep(i,n) if((*this)[i] != rhs[i]) return true ; return false; }\n    };\n\n\
    \    vector< hash > pb, hs;\n    rolling_hash() {}\n    rolling_hash(const string\
    \ &s) {\n        int n = s.size();\n        hs.resize(n + 1); hs[0].fill(0);\n\
    \        pb.resize(n + 1); pb[0].fill(1);\n        rep(i,n) {\n            hs[i\
    \ + 1] = hs[i] * BASE + s[i];\n            pb[i + 1] = pb[i] * BASE;\n       \
    \ }\n    }\n\n    // [l, r)\n    hash get(int l, int r) const {\n        return\
    \ hs[r] - hs[l] * pb[r - l];\n    }\n\n    template < int n >\n    static int\
    \ lcp(const rolling_hash< n >& rh1, int l1, int r1, const rolling_hash< n >& rh2,\
    \ int l2, int r2) {\n        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;\n  \
    \      while(hi - lo > 1) {\n            int mid = (lo + hi) / 2;\n          \
    \  (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;\n       \
    \ }\n        return lo;\n    }\n\n    template < int n >\n    static int cmp(const\
    \ rolling_hash< n >& rh1, int l1, int r1, const rolling_hash< n >& rh2, int l2,\
    \ int r2) {\n        int len = lcp(rh1, l1, r1, rh2, l2, r2);\n        if(len\
    \ == r1 - l1 && len == r2 - l2) return 0;\n        if(len == r1 - l1) return -1;\n\
    \        if(len == r2 - l2) return +1;\n        if((rh1.hs[l1 + len + 1] - rh1.hs[l1\
    \ + len] * rh1.BASE)[0] < (rh2.hs[l2 + len + 1] - rh2.hs[l2 + len] * rh2.BASE)[0])\n\
    \            return -1;\n        else\n            return +1;\n    }\n};\n#line\
    \ 5 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\nint main(){\n \
    \   cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    string s; cin >> s;\n   \
    \ int n = s.size();\n    rolling_hash< 1 > rh(s);\n    vector<int> I(n);\n   \
    \ iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(), [&](int i, int j)\
    \ {\n        return rolling_hash< 1 >::cmp(rh, i, n, rh, j, n) < 0;\n    });\n\
    \    rep(i,n) cout << I[i] << \" \\n\"[i == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"src/cp-template.hpp\"\n#include \"src/string/rolling_hash.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n\n    string s; cin >> s;\n  \
    \  int n = s.size();\n    rolling_hash< 1 > rh(s);\n    vector<int> I(n);\n  \
    \  iota(I.begin(), I.end(), 0);\n    sort(I.begin(), I.end(), [&](int i, int j)\
    \ {\n        return rolling_hash< 1 >::cmp(rh, i, n, rh, j, n) < 0;\n    });\n\
    \    rep(i,n) cout << I[i] << \" \\n\"[i == n - 1];\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/library_checker/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-03-29 21:46:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/rolling_hash.test.cpp
- /verify/verify/library_checker/string/rolling_hash.test.cpp.html
title: verify/library_checker/string/rolling_hash.test.cpp
---
