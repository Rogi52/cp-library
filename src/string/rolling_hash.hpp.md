---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/rolling_hash.test.cpp
    title: verify/library_checker/string/rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/rolling_hash.hpp\"\ntemplate< int num_of_mod\
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
    \ string &s) {\n        int n = s.size();\n        hs.resize(n + 1); hs[0].fill(0);\n\
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
    \            return -1;\n        else\n            return +1;\n    }\n};\n"
  code: "template< int num_of_mod = 2 >\nstruct rolling_hash {\n    static constexpr\
    \ ll MODS[] = {999999937, 1000000007, 1000000009, 1000000021};\n    static constexpr\
    \ ll BASE = 9973;\n    \n    struct hash : array<ll, num_of_mod> {\n        using\
    \ array<ll, num_of_mod>::operator[];\n        static constexpr int n = num_of_mod;\n\
    \        hash() : array<ll,n>() {}\n        hash(ll x) : hash() { rep(i,n) (*this)[i]\
    \ = x % MODS[i]; }\n        hash& operator+=(const hash& rhs) { rep(i,n) if(((*this)[i]\
    \ += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n        hash&\
    \ operator-=(const hash& rhs) { rep(i,n) if(((*this)[i] += MODS[i] - rhs[i]) >=\
    \ MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n        hash& operator*=(const\
    \ hash& rhs) { rep(i,n) (*this)[i] = (*this)[i] * rhs[i] % MODS[i]; return *this;\
    \ }\n        hash& operator+=(const ll rhs) { rep(i,n) if(((*this)[i] += rhs %\
    \ MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n        hash& operator-=(const\
    \ ll rhs) { rep(i,n) if(((*this)[i] += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i]\
    \ -= MODS[i]; return *this; }\n        hash& operator*=(const ll rhs) { rep(i,n)\
    \ (*this)[i] = (*this)[i] * (rhs % MODS[i]) % MODS[i]; return *this; }\n     \
    \   hash operator+(const hash& rhs) const { return hash(*this) += rhs; }\n   \
    \     hash operator-(const hash& rhs) const { return hash(*this) -= rhs; }\n \
    \       hash operator*(const hash& rhs) const { return hash(*this) *= rhs; }\n\
    \        hash operator+(const ll rhs) const { return hash(*this) += rhs; }\n \
    \       hash operator-(const ll rhs) const { return hash(*this) -= rhs; }\n  \
    \      hash operator*(const ll rhs) const { return hash(*this) *= rhs; }\n   \
    \     hash operator-() const { return hash().fill(0) - *this; }\n        friend\
    \ hash operator+(ll x, const hash& y) { return hash(x) + y; }\n        friend\
    \ hash operator-(ll x, const hash& y) { return hash(x) + y; }\n        friend\
    \ hash operator*(ll x, const hash& y) { return hash(x) * y; }\n        bool operator==(const\
    \ hash& rhs) { rep(i,n) if((*this)[i] != rhs[i]) return false; return true ; }\n\
    \        bool operator!=(const hash& rhs) { rep(i,n) if((*this)[i] != rhs[i])\
    \ return true ; return false; }\n    };\n\n    vector< hash > pb, hs;\n    rolling_hash()\
    \ {}\n    rolling_hash(const string &s) {\n        int n = s.size();\n       \
    \ hs.resize(n + 1); hs[0].fill(0);\n        pb.resize(n + 1); pb[0].fill(1);\n\
    \        rep(i,n) {\n            hs[i + 1] = hs[i] * BASE + s[i];\n          \
    \  pb[i + 1] = pb[i] * BASE;\n        }\n    }\n\n    // [l, r)\n    hash get(int\
    \ l, int r) const {\n        return hs[r] - hs[l] * pb[r - l];\n    }\n\n    template\
    \ < int n >\n    static int lcp(const rolling_hash< n >& rh1, int l1, int r1,\
    \ const rolling_hash< n >& rh2, int l2, int r2) {\n        int lo = -1, hi = min(r1\
    \ - l1, r2 - l2) + 1;\n        while(hi - lo > 1) {\n            int mid = (lo\
    \ + hi) / 2;\n            (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo\
    \ : hi) = mid;\n        }\n        return lo;\n    }\n\n    template < int n >\n\
    \    static int cmp(const rolling_hash< n >& rh1, int l1, int r1, const rolling_hash<\
    \ n >& rh2, int l2, int r2) {\n        int len = lcp(rh1, l1, r1, rh2, l2, r2);\n\
    \        if(len == r1 - l1 && len == r2 - l2) return 0;\n        if(len == r1\
    \ - l1) return -1;\n        if(len == r2 - l2) return +1;\n        if((rh1.hs[l1\
    \ + len + 1] - rh1.hs[l1 + len] * rh1.BASE)[0] < (rh2.hs[l2 + len + 1] - rh2.hs[l2\
    \ + len] * rh2.BASE)[0])\n            return -1;\n        else\n            return\
    \ +1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-03-29 21:44:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/rolling_hash.test.cpp
documentation_of: src/string/rolling_hash.hpp
layout: document
title: Rolling Hash
---

- $\mathrm{rolling\_hash}(s)$ : 文字列 $s$ のハッシュテーブルを構築する。$O(|S|)$
- $\mathrm{get}(l, r)$ : $s_{[l, r)}$ のハッシュ値を返す。$O(1)$

長さが $O(N)$ の文字列 $s_1, s_2$ のハッシュテーブルをそれぞれ ${rh}_1, {rh}_2$ とする。
- $\mathrm{lcp}({rh}_1, l_1, r_1, {rh}_2, l_2, r_2)$ : $s_{1[l_1, r_1)}$ と $s_{2[l_2, r_2)}$の最長共通接頭辞の長さを返す。$O(\log N)$。
- $\mathrm{cmp}({rh}_1, l_1, r_1, {rh}_2, l_2, r_2)$ : 文字列を辞書順比較し、次の値を返す。 $O(\log N)$。ただし、アルファベットが対応する整数を $n$ とするとき $n < \mathrm{mod}$ を仮定している。
	- $s_{1[l_1, r_1)} = s_{2[l_2, r_2)} \implies  0$
	- $s_{1[l_1, r_1)} < s_{2[l_2, r_2)} \implies +1$
	- $s_{1[l_1, r_1)} > s_{2[l_2, r_2)} \implies -1$
