#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../../../../src/cp-template.hpp"
#include "../../../../src/utility/hash.hpp"
#include "../../../../src/utility/random.hpp"
#include "../../../../src/graph/tree/tree.hpp"
#include "../../../../src/graph/tree/tree_isomorphism.hpp"

int main() {
    int N = in();
    tree_graph<int> g(N);
    for(int i : rep(1, N)) {
        int p = in();
        g.add_edge(p, i);
    }
    auto [K, ans] = subtree_hashing< 2 >(g, 0);
    print(K);
    print(ans);
}
