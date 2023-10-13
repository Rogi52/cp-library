#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/eratosthenes.hpp"

int main() {
    int N = in();
    using mint = mint998244353;
    vector<mint> a = in(N), b = in(N);
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    vector<mint> c = Eratosthenes(N).gcd_convolution(a, b);
    c.erase(c.begin());
    print(c);
}