#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"
#define ERROR 0.00000001

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    printer::precision(20);
    int q = in();
    for(int q_ : rep(q)) {
        point<ld> p0 = in(), p1 = in(), p2 = in(), p3 = in();
        segment<ld> s1(p0, p1), s2(p2, p3);
        print(distance_ss(s1, s2));
    }
}