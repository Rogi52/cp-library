#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/static_point_add_rect_sum.hpp"
#innclde "../../../src/algebra/plus.hpp"

int main() {
    int N = in(), Q = in();
    rect_sum< tag::STATIC, tag::POINT, int, PLUS<ll> > rs;
    for(int i : rep(N)) {
        int x = in(), y = in(), w = in();
        rs.add(x, y, w);
    }
    for(int i : rep(Q)) {
        int l = in(), d = in(), r = in(), u = in();
        rs.query(l, r, d, u);
    }
    print(rs.solve(), '\n');
}
