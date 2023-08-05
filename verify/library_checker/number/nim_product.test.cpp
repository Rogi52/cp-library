#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/nim_product.hpp"

int main() {
    int T = in();
    for(int t : rep(T)) {
        ull A = in(), B = in();
        print(nim::prod(A, B));
    }
}