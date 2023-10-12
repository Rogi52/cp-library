---
title: LGV 公式
documentation_of: src/matrix/lgv.hpp
src/graph/tree/offline_level_ancestor.hpp
---

## 参考
- [https://www2.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf](https://www2.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf)
- [https://twitter.com/kotatsugame_t/status/1411648290546851840](https://twitter.com/kotatsugame_t/status/1411648290546851840)
- [https://atcoder.jp/contests/abc216/editorial/2561](https://atcoder.jp/contests/abc216/editorial/2561)


## LGV 公式
DAG があり、そのうち $n$ 個の頂点 $a_1, a_2, \dots, a_n$ が始点として、$n$ 個の頂点 $b_1, b_2, \dots, b_n$ が終点としてマークされている。

「$i < j$ かつ $k < l$ ならば $a_i$ から $b_l$ に向かうパスと $a_j$ から $b_k$ に向かうパスは頂点を共有する」($\star$) とき、

パスの $n$ 個組であって、$i$ 番目のパスの始点は $a_i$ 、終点は $b_i$ であり、かつどの $2$ つのパスも頂点を共有しないものの数は

$n \times n$ 行列 $X$ ($X_{ij} = $ $a_i$ から $b_j$ に向かうパスの個数) の行列式 $\mathrm{det}(X)$ に等しい。

### 証明の概略
行列式の各項 $\mathrm{sgn} (\sigma) X_{1 \sigma(1)} X_{2 \sigma(2)} \dots X_{n \sigma(n)}$ は、$a_1 \to b_{\sigma(1)}, a_2 \to b_{\sigma(2)}, \dots a_n \to b_{\sigma(n)}$ へのパスの組の個数の $\mathrm{sgn} (\sigma)$ 倍である。

このパスの組がどの $2$ つのパスも頂点を共有しない場合、($\star$) より $\sigma(1) = 1, \sigma(2) = 2, \dots, \sigma(n) = n$ であり、これが数えたい場合の数である。

このパスの組がある頂点 $v$ を共有する場合、$a_i \to v \to b_k, a_j \to v \to b_l$ を $a_i \to v \to b_l, a_j \to v \to b_k$ に置き換えると、置換の符号が異なることから行列式の計算で相殺される。
