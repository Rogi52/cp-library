#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "../../../src/cp-template.hpp"

int main() {
    int T = in();
    for(int _ : rep(T)) {
        i128 A = in(), B = in();
        print(A + B);
    }
}