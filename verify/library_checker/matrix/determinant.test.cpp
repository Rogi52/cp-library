#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../../src/cp-template.hpp"
#include "../../../src/matrix/base.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    square_matrix<mint> A(N);
    for(int i : rep(N)) A[i] = in(N);
    print(det(A));
}