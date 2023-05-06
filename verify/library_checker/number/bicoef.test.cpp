#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "src/cp-template.hpp"
#include "src/number/runtime_modint.hpp"
#include "src/number/bicoef.hpp"

int main() {
    int T = in();
    int m = in();
    mint::set_mod(m);
    bicoef<mint> c(min(m, 10'000'000));
    for(int i : rep(T)) {
        int n = in();
        int k = in();
        print(c.comb(n, k));
    }
}