#include "../../src/cp-template.hpp"

template < class M, class T >
struct with_index {
    struct VI {
        using V = typename M::set;
        mutable V value;
        T index;
    };
    using set = VI;
    static constexpr set op(const set& l, const set& r) {
        return M::op(l.value, r.value) == l.value ? l : r;
    }
    static constexpr set id() {
        return set{M::id(), T(1e9)};
    }
};