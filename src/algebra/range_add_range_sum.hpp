#include "../../src/cp-template.hpp"
#include "../../src/algebra/sum.hpp"
#include "../../src/algebra/size.hpp"

template < class T > class range_add_range_sum {
  public:
    using value_structure = with_size< sum_monoid< T >, T >;
    using operator_structure = sum_monoid< T >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& x, const F& f) {
        return S{x.value + f * x.size, x.size};
    }
};