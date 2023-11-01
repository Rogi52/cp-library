#include "../../src/cp-template.hpp"

template < class F >
void for_each_triangle(const std::vector<std::vector<int>>& g, const F& f) {
    int N = g.size();
    std::vector<std::vector<int>> h(N);
    for(int u : rep(N)) for(int v : g[u])
        if(std::make_pair(g[u].size(), u) > std::make_pair(g[v].size(), v))
            h[u].push_back(v);

    std::vector<int> used(N, 0);
    for(int x : rep(N)) {
        for(int z : h[x]) used[z] = 1;
        for(int y : h[x]) for(int z : h[y]) if(used[z]) f(x, y, z);
        for(int z : h[x]) used[z] = 0;
    }
}