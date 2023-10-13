#include "../../src/algebra/affine.hpp"
#include "../../src/algebra/sum.hpp"
#include "../../src/algebra/cartesian_product_monoid.hpp"

template < class T > class range_affine_range_sum {
  public:
    using value_structure = cartesian_product_monoid< sum_monoid< T >, sum_monoid< T > >;
    using operator_structure = affine_composite_monoid< T >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S &l, const F &r) {
        return S(l.first * r.a + l.second * r.b, l.second);
    }
};
