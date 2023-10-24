#include "../../src/cp-template.hpp"
#include "../../src/number/fps.hpp"
#include "../../src/number/binom_mod.hpp"

template < class mint >
std::vector<mint> sharp_p_subset_sum(std::vector<int> S, int T) {
    std::vector<mint> c(T + 1, 0);
    for(int s : S) c[s] += 1;
    fps<mint> logf(T + 1);
    for(int i : rep(1, T + 1)) for(int j : rep(1, T / i + 1))
        logf[i * j] += c[i] * inv<mint>(j) * (j % 2 == 1 ? +1 : -1);
    return exp(logf);
}