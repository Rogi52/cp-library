#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../../src/cp-template.hpp"
#include "../../../src/string/rolling_hash.hpp"

int main() {
    string s = in();
    int n = s.size();
    const int m = 2;
    rolling_hash< m > rh(s);
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
        return rolling_hash< m >::cmp(s, rh, i, n, s, rh, j, n) < 0;
    });
    print(I);
}
