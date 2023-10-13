#include "../../src/cp-template.hpp"

template < class M, class T >
struct with_size {
  public:
    struct VS {
        using V = typename M::set;
        mutable V value;
        T size;
    };
    using set = VS;
    static constexpr set op(const set& l, const set& r) {
        return set{M::op(l.value, r.value), l.size + r.size};
    }
    static constexpr set id() {
        return set{M::id(), 0};
    }
};