---
title: Offline Level Ancestor
documentation_of: src/graph/tree/offline_level_ancestor.hpp
---

参考: https://noshi91.hatenablog.com/entry/2019/09/22/114149

## クエリ例
$\mathrm{LA}(v, d) \coloneqq v$ の祖先であって、深さが $d$ である頂点
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

$x$ は $y$ の祖先とし、距離を $d$ とする。 $x$ と $y$ を結ぶパス上の頂点を順に $x = v_0, v_1, \dots, v_d = y$ とするときの $v_1$

https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_g
```cpp
off_la::func get_ans = [&](int i, vector<int> &path, vector<int> &pos) {
    ans[i] = path[pos[x[i]] + 1];
};
```
