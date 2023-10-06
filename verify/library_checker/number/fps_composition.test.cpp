#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/fps.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    fps<mint> f(N), g(N);
    for(int i : rep(N)) f[i] = in();
    for(int i : rep(N)) g[i] = in();

    fps<mint> h = f(g);
    print(h);
}
