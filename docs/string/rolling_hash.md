---
title: Rolling Hash
documentation_of: src/string/rolling_hash.hpp
---

- $\mathrm{rolling}$ _ $\mathrm{hash}(s)$ : 文字列 $s$ のハッシュテーブルを構築する。 $O(\|S\|)$。
- $\mathrm{get}(l, r)$ : $s_{[l, r)}$ のハッシュ値を返す。 $O(1)$。  

長さが $O(N)$ の文字列 $s_1, s_2$ のハッシュテーブルをそれぞれ ${rh}_1, {rh}_2$ とする。
-  $\mathrm{lcp}({rh}_ 1, l_1, r_1, {rh}_ 2, l_2, r_2)$ : $s_{1[l_1, r_1)}$ と $s_{2[l_2, r_2)}$の最長共通接頭辞の長さを返す。 $O(\log N)$。
- $\mathrm{cmp}(s_1, {rh}_ 1, l_1, r_1, s_2, {rh}_ 2, l_2, r_2)$  :   文字列を辞書順比較し、次の値を返す。 $O(\log N)$。
	- $s_{1[l_1, r_1)} = s_{2[l_2, r_2)} \implies 0$
	- $s_{1[l_1, r_1)} < s_{2[l_2, r_2)} \implies +1$
	- $s_{1[l_1, r_1)} > s_{2[l_2, r_2)} \implies - 1$
