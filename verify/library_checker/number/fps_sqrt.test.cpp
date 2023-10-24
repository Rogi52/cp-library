#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/fps.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    fps<mint> f(in(N));
    try {
        print(sqrt(f));
    } catch(undefined error) {
        print(-1);
    }
}
