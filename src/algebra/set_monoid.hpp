template < class T, T none = T(-1) >
struct set_monoid {
  public:
    using set = T;
    static constexpr T op(const T& l, const T& r) { return (r == none ? l : r); }
    static constexpr T id() { return none; }
    static constexpr bool comm = false;
};
