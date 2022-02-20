template < class CMonoid > class FenwickTree {
  public:
    using T = typename CMonoid::set;

  private:
    int n;
    vector<T> data;

  public:
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), data(n, CMonoid::id) {}

    void add(int i, T x) {
        for(int p = i + 1; p <= n; p += p & -p) data[p - 1] = CMonoid::op(data[p - 1], x);
    }

    // [0, r)
    T fold(int r) {
        T s = CMonoid::id;
        for(int p = r; p > 0; p -= p & -p) s = CMonoid::op(data[p - 1], s);
        return s;
    }
  
    // [l, r)
    T fold(int l, int r) {
        return CMonoid::op(CMonoid::inv(fold(l)), fold(r));
    }

    T get(int i) {
        return fold(i, i + 1);
    }

    void set(int i, T x) {
        add(i, CMonoid::op(CMonoid::inv(get(i)), x));
    }
};
