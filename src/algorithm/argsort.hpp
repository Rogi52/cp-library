#include "../../src/cp-template.hpp"

template < class T > std::vector< int > argsort(const std::vector< T > &a) {
    std::vector< int > ids((int)a.size());
    std::iota(ids.begin(), ids.end(), 0);
    std::sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] < a[j] || (a[i] == a[j] && i < j);
    });
    return ids;
}
