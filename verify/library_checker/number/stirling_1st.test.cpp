#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/famous_number.hpp"

int main() {
    int N = in();
    print(stirling_1st<mint998244353>(N));
}
