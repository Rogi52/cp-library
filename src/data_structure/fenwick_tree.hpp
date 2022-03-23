template < class abel_group > class fenwick_tree {
  public:
    using T = typename abel_group::set;

  private:
    int n;
    vector< T > data;

  public:
    fenwick_tree() : n(0) {}
    fenwick_tree(int n) : n(n), data(n, abel_group::id) { assert(abel_group::commute); }
    FenwickTree(vector< T > a) : n(a.size()), data(a) {
        assert(AbelGroup::commute);
        for(int i = 1; i <= n; i++) {
            int p = i + (i & -i);
            if(p <= n) data[p - 1] = AbelGroup::op(data[i - 1], data[p - 1]);
        }
    }

    void add(int i, T x) {
        for(int p = i + 1; p <= n; p += p & -p) data[p - 1] = abel_group::op(data[p - 1], x);
    }

    // [0, r)
    T fold(int r) {
        T s = abel_group::id;
        for(int p = r; p > 0; p -= p & -p) s = abel_group::op(data[p - 1], s);
        return s;
    }

    // [l, r)
    T fold(int l, int r) {
        return abel_group::op(abel_group::inv(fold(l)), fold(r));
    }

    T get(int i) {
        return fold(i, i + 1);
    }

    void set(int i, T x) {
        add(i, abel_group::op(abel_group::inv(get(i)), x));
    }
};
