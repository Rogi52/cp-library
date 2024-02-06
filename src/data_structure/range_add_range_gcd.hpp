template < class T > class gcd_monoid {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return std::gcd(l, r); }
    static constexpr T id() { return T(0); }
};

template < class T > struct range_add_range_gcd {
    using size_type = int;
    size_type n;
    segtree< sum_monoid< T > > seg_add;
    segtree< gcd_monoid< T > > seg_gcd;

    range_add_range_gcd(const std::vector< T >& a) : n(a.size()) {
        std::vector< T > d(n + 1, 0);
        d[0] = a[0];
        for(size_type i = 1; i < n; i++) d[i] = a[i] - a[i - 1];
        seg_add = segtree< sum_monoid< T > >(d);
        seg_gcd = segtree< gcd_monoid< T > >(d);
    }

    void apply(const size_type l, const size_type r, const T x) {
        seg_add.set(l, seg_add.get(l) + x);
        seg_add.set(r, seg_add.get(r) - x);
        seg_gcd.set(l, seg_gcd.get(l) + x);
        seg_gcd.set(r, seg_gcd.get(r) - x);
    }

    T prod(const size_type l, const size_type r) {
        return std::gcd(seg_add.prod(0, l + 1), seg_gcd.prod(l + 1, r));
    }
};
