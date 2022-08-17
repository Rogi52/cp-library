#include "src/union_find.hpp"

template < class abel_monoid > class union_fold : union_find {
  public:
    union_fold(vector< T > &a) : union_find(a.size()), value(a) {}
    int unite(int x, int y) {
        if((x = union_find::unite(x, y)) != -1)
            value[x] = abel_monoid::op(value[x], value[y]);
        return x;
    }
    T fold(int x) { return value[root(x)]; }
    void add(int x, T v) {
        x = root(x);
        value[x] = abel_monoid::op(value[x], v);
    }

  private:
    using T = typename abel_monoid::set;
    vector< T > value;
};
