#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/poly.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    vector< poly<mint> > fs(N);
    for(int i : rep(N)) {
        int d = in();
        fs[i] = poly<mint>(d + 1);
        for(int j : rep(d + 1)) fs[i][j] = in();
    }

    poly<mint> f = all_product(fs);
    print(f);
}
