#include "../../../src/cp-template.hpp"
#include "../../../src/graph/tree/dp_on_tree.hpp"
#include "../../../src/utility/hash.hpp"
#include "../../../src/utility/random.hpp"

struct subtree_hashing {
    int n;
    dp_on_tree tree;
    subtree_hashing(int n) : n(n), tree(n) {}
    void add_edge(int u, int v) {
        static int i = 0;
        tree.add_edge(u, v, i++);
    }

    template < int num_of_mod >
    std::pair< int, std::vector<int> > solve(int root) {
        using hv = hash_vector< num_of_mod >;
        std::vector< hv > h(n);
        for(int i : rep(n)) h[i] = hv(randnum::gen_int<int>(0, hv::MODS[0]));

        using S = std::pair< hv, int >;
        vector< S > dp = tree.solve(
            root,
            [&](S a, S b) { return S{a.first * b.first, std::max(a.second, b.second + 1)}; },
            [&](S a, int i) { return a; },
            [&](S a, int i) { return S{a.first + h[a.second], a.second}; },
            S{hv(1), 0}
        );

        vector< S > key = dp;
        std::sort(key.begin(), key.end());
        key.erase(std::unique(key.begin(), key.end()), key.end());
        vector<int> id(n);
        for(int i : rep(n)) id[i] = std::lower_bound(key.begin(), key.end(), dp[i]) - key.begin();
        return {key.size(), id};
    }
};