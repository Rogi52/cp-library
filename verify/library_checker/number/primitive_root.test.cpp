#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/primitive_root.hpp"

int main() {
    int Q = in();
    for(int _ : rep(Q)) {
        u64 p = in();
        print(primitive_root(p));
    }
}
