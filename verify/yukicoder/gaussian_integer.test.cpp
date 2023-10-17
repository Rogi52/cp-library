#define PROBLEM "https://yukicoder.me/problems/no/321"

#include "../../src/cp-template.hpp"
#include "../../src/number/gaussian_integer.hpp"

int main() {
    using gint = gaussian_integer;
    gint t; t.x = in(), t.y = in();
    gint g = gcd(t, conj(t));

    int N = in();
    int ans = 0;
    for(int _ : rep(N)) {
        gint v; v.x = in(), v.y = in();
        if(g == 0) {
            if(v == 0) ans++;
        } else {
            if(v % g == 0) ans++;
        }
    }
    print(ans);
}