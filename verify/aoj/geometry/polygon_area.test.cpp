#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<i64> p = in(n);
    i64 s = area2(p);
    std::cout << s / 2 << "." << (s % 2 == 0 ? 0 : 5) << std::endl;
}