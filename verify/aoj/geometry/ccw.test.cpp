#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    using Int = i64;
    point<Int> p0 = in(), p1 = in();

    int q = in();
    for(int q_ : rep(q)) {
        point<Int> p2 = in();
        switch(ccw(p0, p1, p2)) {
            case +1: print("COUNTER_CLOCKWISE"); break;
            case -1: print("CLOCKWISE");         break;
            case +2: print("ONLINE_BACK");       break;
            case -2: print("ONLINE_FRONT");      break;
            case  0: print("ON_SEGMENT");        break;
        }
    }
}