#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include "src/cp-template.hpp"
#include "src/number/modint.hpp"
#include "src/algorithm/count_subseq.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    vector<int> A = in(N);
    cout << count_subseq<mint>(A) - 1 << endl;
}
