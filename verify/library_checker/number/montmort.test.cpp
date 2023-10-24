#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/runtime_modint.hpp"
#include "../../../src/number/famous_number.hpp"

int main() {
    int N = in(), M = in();
    using mint = runtime_modint;
    mint::set_mod(M);
    std::vector<mint> a = montmort<mint>(N);
    a.erase(a.begin());
    print(a);
}
