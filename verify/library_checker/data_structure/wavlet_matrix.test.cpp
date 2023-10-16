#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../src/cp-template.hpp"
#include "../../../src/utility/zip.hpp"
#include "../../../src/data_structure/wavlet_matrix.hpp"

int main() {
    int N = in(), Q = in();
    using value_type = int;
    vector< value_type > a = in(N);
    zipper< value_type > z(a);
    wavlet_matrix< int > wm(z.zip(a));
    
    for(int _ : rep(Q)) {
        int L = in(), R = in(), k = in();
        print(z.data[wm.quantile(L, R, k)]);
    }
}