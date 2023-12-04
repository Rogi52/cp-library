#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 0.000001

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<ld> g = in(n);
    printer::precision(20);
    print(diameter(g));
}