template < class T > struct fenwick_tree_2d {
    int H, W;
    vector<vector< T >> tree;
    fenwick_tree_2d(int H, int W) : H(H), W(W), tree(H + 1, vector(W + 1, T(0))) {}
    void add(int x, int y, T v) {
        assert(0 <= x and x < H);
        assert(0 <= y and y < W);
        for(int i = x + 1; i <= H; i += i & -i)
            for(int j = y + 1; j <= W; j += j & -j) tree[i][j] += v;
    }
    T prefix(int x, int y) {
        assert(0 <= x and x <= H);
        assert(0 <= y and y <= W);
        T s(0);
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j) s += tree[i][j];
        return s;
    }
    T sum(int xL, int xR, int yL, int yR) {
        return prefix(xR, yR) - prefix(xL, yR) - prefix(xR, yL) + prefix(xL, yL);
    }
};
