namespace Algebra {

template < class T > class Xor {
  public:
    using set = T;
    static T op(const T &l, const T &r) { return l ^ r; }
    static T id = T(0);
    static T inv(const T &x) { return x; }
};

}
