#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/utility/hash.hpp"
#include "../../../../src/utility/random.hpp"
#include "../../../../src/graph/tree/tree_isomorphism.hpp"

int main() {
    int N = in();
    subtree_hashing g(N);
    for(int i : rep(1, N)) {
        int p = in();
        g.add_edge(p, i);
    }

    auto [K, ans] = g.solve< 2 >(0);
    print(K);
    print(ans);
}
