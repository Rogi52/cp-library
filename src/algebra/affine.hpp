template < class T > class affine {
  public:
    T a, b;
    constexpr affine() = default;
    constexpr affine(const T &a, const T &b) : a(a), b(b) {}
    constexpr T eval(const T &x) const { return x * a + b; }
    constexpr affine composite(const affine &r) const {
        return affine(a * r.a, b * r.a + r.b);
    }
    static constexpr affine id() {
        return affine(T(1), T(0));
    }
};

template < class T > class affine_composite_monoid {
  public:
    using F = affine< T >;
    using set = F;
    static constexpr F op(const F &l, const F &r) { return l.composite(r); }
    static constexpr F id = F::id();
};
template < class T > constexpr affine< T > affine_composite_monoid< T >::id;
