#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 0.00000001

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    using real = double;
    printer::precision(20);
    
    line<real> l = [&]() {
        point<real> p1 = in(), p2 = in();
        return line(p1, p2);
    }();

    int q = in();
    for(int q_ : rep(q)) {
        point<real> p = in();
        print(reflection(l, p));
    }
}