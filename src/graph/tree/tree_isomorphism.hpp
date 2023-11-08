#include "../../../src/cp-template.hpp"
#include "../../../src/graph/tree/rerooting.hpp"
#include "../../../src/utility/hash.hpp"
#include "../../../src/utility/random.hpp"

template < int num_of_mod, class TREE >
std::pair< int, std::vector<int> > subtree_hashing(TREE& tree, int root = 0) {
    using hv = hash_vector< num_of_mod >;
    std::vector< hv > h(n);
    for(int i : rep(n)) h[i] = hv(randnum::gen_int<int>(0, hv::MODS[0]));

    using S = std::pair< hv, int >;
    dp_on_tree< S > x(
        tree,
        [&](S a, S b) { return S{a.first * b.first, std::max(a.second, b.second + 1)}; },
        [&](S a, int i) { return a; },
        [&](S a, int i) { return S{a.first + h[a.second], a.second}; },
        [&]() { return S{hv(1), 0}}
    );
    x.solve()

    vector< S > key = x.dp;
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    vector<int> id(n);
    for(int i : rep(n)) id[i] = std::lower_bound(key.begin(), key.end(), dp[i]) - key.begin();
    return {key.size(), id};
};