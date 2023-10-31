#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../../../src/cp-template.hpp"
#include "../../../src/number/stern-brocot_tree.hpp"
#include <iostream>

int main() {
    using sbt_n = stern_brocot_tree_node<int>;
    int T = in();
    for(int _ : rep(T)) {
        std::string problem = in();
        if(problem == "ENCODE_PATH") {
            int a = in(), b = in();
            vector<int> path = sbt_n(a, b).history;
            std::cout << path.size();
            for(int i : rep(path.size())) {
                std::cout << ' ' << (path[i] < 0 ? 'L' : 'R') << ' ' << std::abs(path[i]);
            }
            std::cout << '\n';
        }
        if(problem == "DECODE_PATH") {
            int k = in();
            vector<int> path(k);
            for(int i : rep(k)) {
                char c = in(); int n = in();
                path[i] = (c == 'L' ? -1 : +1) * n;
            }
            auto [a, b] = sbt_n(path).value();
            print(a, b);
        }
        if(problem == "LCA") {
            int a = in(), b = in(), c = in(), d = in();
            auto [f, g] = lca(sbt_n(a, b), sbt_n(c, d)).value();
            print(f, g);
        }
        if(problem == "ANCESTOR") {
            int k = in(), a = in(), b = in();
            sbt_n n(a, b);
            if(k <= n.depth) {
                n.up(n.depth - k);
                auto [f, g] = n.value();
                print(f, g);
            } else {
                print(-1);
            }
        }
        if(problem == "RANGE") {
            int a = in(), b = in();
            sbt_n x(a, b);
            auto [f, g] = x.lower_bound();
            auto [h, k] = x.upper_bound();
            print(f, g, h, k);
        }
    }
}
