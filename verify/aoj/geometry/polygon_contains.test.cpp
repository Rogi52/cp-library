#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<i64> g = in(n);

    int q = in();
    for(int q_ : rep(q)) {
        point<i64> p = in();
        print(contains(g, p));
    }
}