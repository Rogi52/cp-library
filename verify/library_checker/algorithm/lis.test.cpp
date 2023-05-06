#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "src/cp-template.hpp"
#include "src/algorithm/lis.hpp"

int main(){
    int N = in();
    vector<int> A = in(N);

    auto [lis, idx, rank] = l_s(A, [&](int a, int b) { return a < b; });
    print(idx.size());
    print(idx);
}
