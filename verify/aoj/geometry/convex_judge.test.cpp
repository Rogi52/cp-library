#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<i64> p = in(n);
    print(is_convex(p));
}