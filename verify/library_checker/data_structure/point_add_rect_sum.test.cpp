#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/point_add_rect_sum.hpp"
#include "../../../src/algebra/plus.hpp"

int main() {
    int N = in(), Q = in();
    rect_sum< tag::DYNAMIC, tag::POINT, int, PLUS<ll> > rs;
    for(int i : rep(N)) {
        int x = in(), y = in(), w = in();
        rs.add(x, y, w);
    }
    for(int i : rep(Q)) {
        int t = in();
        if(t == 0) {
            int x = in(), y = in(), w = in();
            rs.add(x, y, w);
        }
        if(t == 1) {
            int l = in(), d = in(), r = in(), u = in();
            rs.query(l, r, d, u);
        }
    }
    print(rs.solve(), '\n');
}
