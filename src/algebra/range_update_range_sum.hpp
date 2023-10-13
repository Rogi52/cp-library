#include "../../src/cp-template.hpp"
#include "../../src/algebra/sum.hpp"
#include "../../src/algebra/set_monoid.hpp"
#include "../../src/algebra/size.hpp"

template < class T, T none = T(-1) > class range_update_range_sum {
  public:
    using value_structure = with_size< sum_monoid< T >, T >;
    using operator_structure = set_monoid< T, none >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& x, const F& f) {
        if(f != none) x.value = f * x.size;
        return x;
    }
};
