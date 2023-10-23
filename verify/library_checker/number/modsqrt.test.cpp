#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/modfunc.hpp"

int main() {
    int T = in();
    for(int _ : rep(T)) {
        int Y = in(), P = in();
        print(modsqrt(Y, P));
    }
}
