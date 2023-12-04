#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int q = in();
    for(int q_ : rep(q)) {
        point<i64> p0 = in(), p1 = in(), p2 = in(), p3 = in();
        segment<i64> s1(p0, p1), s2(p2, p3);
        print(intersect_ss(s1, s2));
    }
}