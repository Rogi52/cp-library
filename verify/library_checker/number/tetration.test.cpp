#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/tetration.hpp"

int main() {
    int T = in();
    for(int _ : rep(T)) {
        int A = in(), B = in(), M = in();
        print(tetration(A, B, M));
    }
}
