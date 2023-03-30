---
title: Longest Increasing Subsequence
documentation_of: src/algorithm/lis.hpp
---

## 使い方
長さ $N$ の列 $A$ と比較関数 $\mathrm{cmp} : T \times T \to \lbrace	\mathrm{True}, \mathrm{False}\rbrace$ がある。 $A$ の部分列 $B$ が $\mathrm{Longest \  ? \  Subsequence} \ (\mathrm{L?S})$ であることを次のように定める。

> $B$ の長さを $M$ とする。任意の $i \ (1 \leq i < M)$ について $\mathrm{cmp}(B_i, B_{i+1}) = \mathrm{True}$ が成り立つ。

$O(N \log N)$ 時間の計算により、次の組を返す。
- $\mathrm{l?s}$ : $A$ の $\mathrm{cmp}$ における $\mathrm{L?S}$ 
- $\mathrm{idx}$ : $\mathrm{L?S}$ が $A$ において現れる位置 
- $\mathrm{rank}$ : $\mathrm{rank} \lbrack i \rbrack :=$ $A_i$ を最後の要素とする $\mathrm{L?S}$ の長さ 
