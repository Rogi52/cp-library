---
title: Offline Level Ancestor
documentation_of: src/graph/tree/offline_level_ancestor.hpp
---

参考: [Offline Level Ancestor Θ(N+Q) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/09/22/114149)

## クエリ例
$\mathrm{LA}(v, d) := v$ の祖先であって、深さが $d$ である頂点
```cpp
off_la::func la = [&](int i, vector<int> &path, vector<int> &pos) {
    ans[i] = path[d[i]];
};
```

$v$ から根の方向に $k$ 回親を辿った頂点
```cpp
off_la::func up = [&](int i, vector<int> &path, vector<int> &pos) {
    ans[i] = path[int(path.size()) - 1 - k[i]];
};
```

$u$ は $v$ の祖先とし、距離を $d$ とする。 $u$ と $v$ を結ぶパス上の頂点を順に $u = x_0, x_1, \dots, x_d = v$ とするときの $x_k$  

```cpp
off_la::func get_ans = [&](int i, vector<int> &path, vector<int> &pos) {
  ans[i] = path[pos[u[i]] + k[i]];
};
```

## 参考
<details>
  <summary>ネタバレ注意</summary>
  <a href="https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_g">パ研合宿2022 第1日「Jikka」G - Ancestor Query</a>
</details>
