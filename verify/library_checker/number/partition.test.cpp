#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/famous_number.hpp"

int main() {
    int N = in();
    print(partition<mint998244353>(N));
}
