#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/runtime_modint.hpp"
#include "../../../src/number/binom_mod.hpp"

int main() {
    int T = in(), m = in();
    using mint = runtime_modint;
    mint::set_mod(m, 1);
    for(int i : rep(T)) {
        int n = in(), k = in();
        print(comb<mint>(n, k));
    }
}