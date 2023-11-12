#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "../../../src/cp-template.hpp"
#include "../../../src/geometry/manhattan_mst.hpp"
#include "../../../src/data_structure/union_find.hpp"

int main() {
    int N = in();
    std::vector<int> x(N), y(N);
    for(int i : rep(N)) x[i] = in(), y[i] = in();

    ll X = 0;
    union_find uf(N);
    std::vector<std::pair<int,int>> edges;
    for(auto [w, u, v] : manhattan_mst(x, y)) {
        if(uf.unite(u, v) != -1) {
            X += w;
            edges.push_back({u, v});
        }
    }

    print(X);
    for(auto [u, v] : edges) print(u, v);
}
