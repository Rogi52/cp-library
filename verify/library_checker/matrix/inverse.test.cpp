#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../../src/cp-template.hpp"
#include "../../../src/matrix/base.hpp"
#include "../../../src/number/modint.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    square_matrix<mint> A(N);
    for(int i : rep(N)) A[i] = in(N);
    
    try {
        square_matrix<mint> A_inv = inv(A);
        for(int i : rep(N)) print(A_inv[i]);
    } catch(std::string e) {
        print(-1);
    }
}