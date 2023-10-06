#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/poly.hpp"

int main() {
    using mint = mint998244353;
    int N = in(); mint c = in();
    poly<mint> f(N);
    for(int i : rep(N)) f[i] = in();
    print(f->*c);
}
