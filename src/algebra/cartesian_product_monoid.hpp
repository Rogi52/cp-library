template < class M, class N > class cartesian_product_monoid {
    using T = pair< typename M::set, typename N::set >;
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) {
        return T(M::op(l.first, r.first), N::op(l.second, r.second));
    }
    static constexpr T id() { return T(M::id(), N::id()); }
};
