#include "../../src/cp-template.hpp"

template < class T >
std::vector< std::vector< T > > binom_table(int N) {
    std::vector table(N + 1, std::vector(N + 1, T(1)));
    for(int i : rep(1, N + 1)) for(int j : rep(1, N + 1))
        table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
    return table;
}
