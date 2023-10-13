#pragma once
#include "../../src/cp-template.hpp"
#include "../../src/algebra/minmax.hpp"
#include "../../src/algebra/sum.hpp"

template < class T > class range_add_range_min {
  public:
    using value_structure = min_monoid< T >;
    using operator_structure = sum_monoid< T >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& l, const F& r) {
        return S(l + r);
    }
};

template < class T > class range_add_range_max {
  public:
    using value_structure = max_monoid< T >;
    using operator_structure = sum_monoid< T >;
  private:
    using S = typename value_structure::set;
    using F = typename operator_structure::set;
  public:
    static constexpr S op(const S& l, const F& r) {
        return S(l + r);
    }
};
