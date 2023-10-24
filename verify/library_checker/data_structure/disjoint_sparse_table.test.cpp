#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/disjoint_sparse_table.hpp"
#include "../../../src/algebra/minmax.hpp"

int main() {
    int N = in(), Q = in();
    std::vector<int> a = in(N);
    disjoint_sparse_table< min_monoid<int> > table(a);
    for(int _ : rep(Q)) {
        int l = in(), r = in();
        print(table.fold(l, r));
    }
}