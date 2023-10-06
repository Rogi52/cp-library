#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/number/poly.hpp"

int main() {
    int N = in(), M = in();
    using mint = mint998244353;
    poly<mint> f(N), g(M);
    for(int i : rep(N)) f[i] = in();
    for(int i : rep(M)) g[i] = in();

    poly<mint> q = f / g, r = f % g;
    while(q.size() >= 1 and q.back() == 0) q.pop_back();
    while(r.size() >= 1 and r.back() == 0) r.pop_back();
    print(q.size(), r.size());
    print(q);
    print(r);
}
