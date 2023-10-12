---
title: 行列木定理
documentation_of: src/matrix/matrix-tree.hpp
---

## 参考
- [https://www2.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf](https://www2.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf)
- [https://mizuwater0.hatenablog.com/entry/2018/11/25/233547](https://mizuwater0.hatenablog.com/entry/2018/11/25/233547)

## 行列木定理

$n$ 頂点の多重無向グラフ $G$ がある。$G$ のラプラシアン $X$ は次のように定義される。
$$
X_{ij} = \left\{
\begin{array}{lc}
({\small頂点 {\normalsize \,i\,} と頂点 {\normalsize \,j\,} を結ぶ辺の数}) \times (-1) & (i \neq j) \\
({\small 頂点 {\normalsize \,i\,} の次数}) & (\mathrm{otherwise})
\end{array} \right.
$$

$G$ の全域木の個数は、ラプラシアン $X$ の任意の余因子に等しい。

## 証明の概略
ある辺 $e$ に注目したとき、$G$ の全域木の個数は、$e$ を縮約したグラフ $G / e$ の全域木の個数と、$e$ を削除したグラフ $G \setminus e$ の全域木の個数の和に等しい:
$$ T(G) = T(G / e) + T(G \setminus e) $$
これを用いて帰納法で示す。