#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/sliding_window_aggregation.hpp"
#include "../../../src/number/modint.hpp"
#include "../../../src/algebra/affine.hpp"

int main() {
    using mint = mint998244353;
    swag_deque<affine_composite_monoid<mint>> que;

    int Q = in();
    for(int _ : rep(Q)) {
        int t = in();
        if(t == 0) {
            mint a = in(), b = in();
            que.push_front(affine<mint>(a, b));
        }
        if(t == 1) {
            mint a = in(), b = in();
            que.push_back(affine<mint>(a, b));
        }
        if(t == 2) {
            que.pop_front();
        }
        if(t == 3) {
            que.pop_back();
        }
        if(t == 4) {
            mint x = in();
            print(que.fold().eval(x));
        }
    }
}