namespace algebra {

template < class T > class XOR {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return l ^ r; }
    static constexpr T id = T(0);
    static constexpr T inv(const T &x) { return x; }
    static constexpr T pow(const T &x, const int n) { return n & 1 ? x : 0; }
    static constexpr bool commute = true;
};

}
