#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include "src/cp-template.hpp"
#include "src/number/modint.hpp"
#include "src/algorithm/count_subseq.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N = in();
    vector<int> A = in(N);
    print(count_subseq<mint>(A) - 1);
}
