template < class comm_monoid > class fenwick_tree {
  public:
    using T = typename comm_monoid::set;

  private:
    int n, n2;
    vector< T > data;

    int ceil_pow2(int n) {
        int x = 1;
        while(x < n) x <<= 1;
        return x;
    }

  public:
    fenwick_tree() : fenwick_tree(0) {}
    fenwick_tree(int n) : n(n), n2(ceil_pow2(n)) data(n, comm_monoid::id) { assert(comm_monoid::comm); }
    fenwick_tree(const vector< T > &a) : n(a.size()), n2(ceil_pow2(n)), data(a) {
        assert(comm_monoid::comm);
        for(int i = 1; i <= n; i++) {
            int p = i + (i & -i);
            if(p <= n) data[p - 1] = comm_monoid::op(data[i - 1], data[p - 1]);
        }
    }

    void add(int i, T x) {
        for(int p = i + 1; p <= n; p += p & -p) data[p - 1] = comm_monoid::op(data[p - 1], x);
    }
    // [0, r)
    T fold(int r) {
        T s = comm_monoid::id;
        for(int p = r; p > 0; p -= p & -p) s = comm_monoid::op(data[p - 1], s);
        return s;
    }
    // [l, r)
    T fold(int l, int r) {
        return comm_monoid::op(comm_monoid::inv(fold(l)), fold(r));
    }
    T get(int i) {
        return fold(i, i + 1);
    }
    void set(int i, T x) {
        add(i, comm_monoid::op(comm_monoid::inv(get(i)), x));
    }
    int lower_bound(function<bool(T)> &f) {
        T s = comm_monoid::id;
        if(f(s)) return 0;
        int i = 0, k = n2;
        while(k >>= 1) {
            if((i | k) <= n && !f(comm_monoid::op(s, data[i | k])))
                s = comm_monoid::op(s, data[i |= k]);
        }
        return i + 1;
    }
};
