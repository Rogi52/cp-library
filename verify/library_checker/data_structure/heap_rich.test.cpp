#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/heap_rich.hpp"

int main() {
    int N = in(), Q = in();
    vector<int> A = in(N);
    heap_minmax<int> q(A);

    for(int _ : rep(Q)) {
        int t = in();
        if(t == 0) {
            int x = in();
            q.push(x);
        }
        if(t == 1) {
            print(q.pop_min());
        }
        if(t == 2) {
            print(q.pop_max());
        }
    }
}
