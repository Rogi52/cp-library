#pragma once
#include "../../src/cp-template.hpp"

template < class T > class min_monoid {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return std::min(l, r); }
    static constexpr T id() { return std::numeric_limits< T >::max(); }
    static constexpr bool comm = true;
};

template < class T > class max_monoid {
  public:
    using set = T;
    static constexpr T op(const T &l, const T &r) { return std::max(l, r); }
    static constexpr T id() { return std::numeric_limits< T >::min(); }
    static constexpr bool comm = true;
};
