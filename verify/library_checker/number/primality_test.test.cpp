#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/prime.hpp"

int main() {
    int Q = in();
    for(int _ : rep(Q)) {
        u64 N = in();
        print(prime_test(N) ? "Yes" : "No");
    }
}
