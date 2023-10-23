#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/prime.hpp"

int main() {
    int Q = in();
    for(int _ : rep(Q)) {
        u64 a = in();
        std::vector<u64> pf = factor(a);
        print(pf.size(), pf);
    }
}
