#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#define ERROR 0.00001

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<ld> g = in(n);

    int q = in();
    printer::precision(20);
    for(int q_ : rep(q)) {
        line<ld> l = [&]() {
            point<ld> a = in(), b = in();
            return line(a, b);
        }();
        print(area(convex_cut(g, l)));
    }
}