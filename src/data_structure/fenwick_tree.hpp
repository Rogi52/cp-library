template < class AbelGroup > class FenwickTree {
  public:
    using T = typename AbelGroup::set;

  private:
    int n;
    vector< T > data;

  public:
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), data(n, AbelGroup::id) { assert(AbelGroup::commute); }
    FenwickTree(vector< T > a) : n(a.size()), data(a) {
        assert(AbelGroup::commute);
        for(int i = 1; i <= n; i++) {
            int p = i + (i & -i);
            if(p <= n) data[p - 1] = AbelGroup::op(data[i - 1], data[p - 1]);
        }
    }

    void add(int i, T x) {
        for(int p = i + 1; p <= n; p += p & -p) data[p - 1] = AbelGroup::op(data[p - 1], x);
    }

    // [0, r)
    T fold(int r) {
        T s = AbelGroup::id;
        for(int p = r; p > 0; p -= p & -p) s = AbelGroup::op(data[p - 1], s);
        return s;
    }

    // [l, r)
    T fold(int l, int r) {
        return AbelGroup::op(AbelGroup::inv(fold(l)), fold(r));
    }

    T get(int i) {
        return fold(i, i + 1);
    }

    void set(int i, T x) {
        add(i, AbelGroup::op(AbelGroup::inv(get(i)), x));
    }
};
