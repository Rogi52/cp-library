#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../../src/cp-template.hpp"
#include "../../../src/matrix/base.hpp"
#include "../../../src/matrix/linear_equation.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in(), M = in();
    using mint = mint998244353;
    matrix<mint> A(N, M);
    for(int i : rep(N)) A[i] = in(M);
    std::vector<mint> b = in(N);

    try {
        auto [rank, x, ker] = linear_equation(A, b);
        print(M - rank);
        print(x);
        for(int i : rep(M - rank)) print(ker[i]);
    } catch(std::string e) {
        print(-1);
    }
}