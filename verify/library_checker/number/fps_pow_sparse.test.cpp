#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/fps_sparse.hpp"

int main() {
    int N = in(), K = in(); ll M = in();
    using mint = mint998244353;
    fps_sparse<mint> f;
    for(int k : rep(K)) {
        int i = in(), a = in();
        f.push_back({i, a});
    }
    print(pow(f, M, N));
}
