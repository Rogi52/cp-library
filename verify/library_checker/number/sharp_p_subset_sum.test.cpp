#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/sharp_p_subset_sum.hpp"

int main() {
    int N = in(), T = in();
    std::vector<int> s = in(N);
    using mint = mint998244353;
    std::vector<mint> p = sharp_p_subset_sum<mint>(s, T);
    p.erase(p.begin());
    print(p);
}
