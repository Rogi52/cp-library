#include "../../src/cp-template.hpp"
#include "../../src/algebra/minmax.hpp"
#include "../../src/algebra/set_monoid.hpp"

template < class T, T none = T(-1) > class range_update_range_min {
  public:
    using value_structure = min_monoid< T >;
    using operator_structure = set_monoid< T, none >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& x, const F& f) {
        return (f == none ? x : f);
    }
};

template < class T, T none = T(-1) > class range_update_range_max {
  public:
    using value_structure = max_monoid< T >;
    using operator_structure = set_monoid< T, none >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& x, const F& f) {
        return (f == none ? x : f);
    }
};