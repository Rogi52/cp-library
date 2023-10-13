#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/static_rect_add_rect_sum.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/algebra/sum.hpp"

int main() {
    int N = in(), Q = in();
    using mint = mint998244353;
    rect_sum< tag::STATIC, tag::RECTANGLE, ll, sum_monoid<mint> > rs;
    for(int i : rep(N)) {
        int l = in(), d = in(), r = in(), u = in(), w = in();
        rs.add(l, r, d, u, w);
    }
    for(int i : rep(Q)) {
        int l = in(), d = in(), r = in(), u = in();
        rs.query(l, r, d, u);
    }
    print(rs.solve(), '\n');
}