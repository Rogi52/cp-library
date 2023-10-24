#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/famous_number.hpp"

int main() {
    int N = in();
    print(bernoulli<mint998244353>(N));
}
