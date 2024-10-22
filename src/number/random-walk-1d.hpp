// (t, x) までの経路数
template < class mint > mint walk_1d(int t, int x) {
    return (t + x) % 2 == 0 ? comb<mint>(t, (t + x) / 2) : 0;
}

// 常に l 以上
template < class mint > mint walk_1d_lb(int t, int x, int l) {
    return l <= x ? walk_1d<mint>(t, x) - walk_1d<mint>(t, x - 2 * (l - 1)) : 0;
}

// 常に u 以下
template < class mint > mint walk_1d_ub(int t, int x, int u) {
    return walk_1d_lb<mint>(t, -x, -u);
}
