#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/base.hpp"

int main() {
    int n = in();
    polygon<i64> g = in(n);
    g = convex_hull(g);
    n = g.size();

    int s = 0;
    for(int i = 1; i < n; i++)
        if(g[s].y > g[i].y or (g[s].y == g[i].y and g[s].x > g[i].x)) s = i;
    
    print(n);
    for(int i : rep(n)) print(g[(s + i) % n]);
}