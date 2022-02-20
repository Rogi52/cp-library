namespace Algebra {

template < class T > class Plus {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return l + r; }
    static constexpr T id = T(0);
    static constexpr T inv(const T &x) { return -x; }
    static constexpr bool commute = true;
};

template < class T > class Plus {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return l ^ r; }
    static constexpr T id = T(0);
    static constexpr T inv(const T &x) { return x; }
    static constexpr bool commute = true;
};

}
