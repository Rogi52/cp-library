#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../../src/cp-template.hpp"
#include "../../../src/matrix/base.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in(), M = in(), K = in();
    using mint = mint998244353;
    matrix<mint> A(N, M), B(M, K);
    for(int i : rep(N)) A[i] = in(M);
    for(int i : rep(M)) B[i] = in(K);
    matrix<mint> C = A * B;
    for(int i : rep(N)) print(C[i]);
}