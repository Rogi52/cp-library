---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/rolling_hash_permutation.hpp\"\ntemplate < int\
    \ num_of_mod >\nstruct rolling_hash_perm {\n    int k;\n    vector< rolling_hash<\
    \ num_of_mod > > rhs;\n    rolling_hash_perm(const string& s, int k) : k(k), rhs(k)\
    \ {\n        int n = s.size();\n        rep(a,k) {\n            string t = \"\"\
    ;\n            rep(i,n) t += (s[i] - 'a' == a);\n            rhs[a] = rolling_hash<\
    \ num_of_mod >(t);\n        }\n    }\n\n    using hash = typename rolling_hash<\
    \ num_of_mod >::hash;\n    // [l, r)\n    vector< hash > get(int l, int r) const\
    \ {\n        vector< hash > res(k);\n        rep(a,k) res[a] = rhs[a].get(l, r);\n\
    \        sort(res.begin(), res.end());\n        return res;\n    }\n\n    template\
    \ < int n >\n    static int lcp(const rolling_hash_perm< n >& rh1, int l1, int\
    \ r1, const rolling_hash_perm< n >& rh2, int l2, int r2) {\n        int lo = -1,\
    \ hi = min(r1 - l1, r2 - l2) + 1;\n        while(hi - lo > 1) {\n            int\
    \ mid = (lo + hi) / 2;\n            (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 +\
    \ mid) ? lo : hi) = mid;\n        }\n        return lo;\n    }\n};\n"
  code: "template < int num_of_mod >\nstruct rolling_hash_perm {\n    int k;\n   \
    \ vector< rolling_hash< num_of_mod > > rhs;\n    rolling_hash_perm(const string&\
    \ s, int k) : k(k), rhs(k) {\n        int n = s.size();\n        rep(a,k) {\n\
    \            string t = \"\";\n            rep(i,n) t += (s[i] - 'a' == a);\n\
    \            rhs[a] = rolling_hash< num_of_mod >(t);\n        }\n    }\n\n   \
    \ using hash = typename rolling_hash< num_of_mod >::hash;\n    // [l, r)\n   \
    \ vector< hash > get(int l, int r) const {\n        vector< hash > res(k);\n \
    \       rep(a,k) res[a] = rhs[a].get(l, r);\n        sort(res.begin(), res.end());\n\
    \        return res;\n    }\n\n    template < int n >\n    static int lcp(const\
    \ rolling_hash_perm< n >& rh1, int l1, int r1, const rolling_hash_perm< n >& rh2,\
    \ int l2, int r2) {\n        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;\n  \
    \      while(hi - lo > 1) {\n            int mid = (lo + hi) / 2;\n          \
    \  (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;\n       \
    \ }\n        return lo;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash_permutation.hpp
  requiredBy: []
  timestamp: '2023-03-30 00:39:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash_permutation.hpp
layout: document
title: Rolling Hash for Alphabet Permutation
---

## 概要
2つの文字列 $s, t \in \Sigma ^{* } (\|\Sigma\| = k)$ が等しいことを次の2つの条件を満たすことと定める。
> [条件1] $|s| = |t|$ が成り立つ。長さを $N$ とおく。  
> [条件2] ある置換 $\sigma : \Sigma \to \Sigma$ が存在して、任意の $i \ (1 \leq i \leq N)$ について $s_i = \sigma(t_i)$ が成り立つ。

文字列の区間 $[l, r)$ が与えられたとき、この等しさを判定できるハッシュ値を計算する。
前処理が $O(k\|s\|)$ 時間、ハッシュ値の計算が $O(k \log k)$ 時間、判定に $O(k)$ 時間かかる。

### 前処理
各文字 $a \in \Sigma$ について、 $s^a_i = (s_i = a\  ?\  1\  :\  0)$ と定めた $s_a$ に対して $\mathrm{rolling} \ \mathrm{hash}$ を適用する: ${rh}(s_a)$ 。

### 判定
多重集合 $\lbrace {rh}(s_a).\mathrm{get}([l, r)) \mid a \in \Sigma \rbrace$ をハッシュ値とする。

これが等しいならば、文字列が等しいと判定する。なお実装ではハッシュ値を昇順に並べ、それを比較することで判定している。

## 使い方
文字種を $k$ とする。
- $\mathrm{rolling} \ \mathrm{hash}\ \mathrm{perm} (s)$ : 文字列 $s$ のハッシュテーブルを構築する。 $O(k\|S\|)$。
- $\mathrm{get}(l, r)$ : $s_{[l, r)}$ のハッシュ値を返す。 $O(k \log k)$。  

長さが $O(N)$ の文字列 $s_1, s_2$ のハッシュテーブルをそれぞれ ${rh}_1, {rh}_2$ とする。
-  $\mathrm{lcp}({rh}_ 1, l_1, r_1, {rh}_ 2, l_2, r_2)$ : $s_{1[l_1, r_1)}$ と $s_{2[l_2, r_2)}$の最長共通接頭辞の長さを返す。 $O(k \log k \log N)$。

## 参考
<details>
  <summary>ネタバレ注意</summary>
       <a href="https://atcoder.jp/contests/pakencamp-2022-day3/tasks/pakencamp_2022_day3_c">パ研合宿2022 第3日「teamwork」C - Permutation of Length 26</a>
</details>
