#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "src/cp-template.hpp"
#include "src/algorithm/lis.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    vector<int> A = in(N);

    auto [lis, idx, rank] = l_s(A, [&](int a, int b) { return a < b; });
    int K = idx.size();
    cout << K << "\n";
    print(idx);
}
