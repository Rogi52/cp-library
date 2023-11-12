#include "../../src/cp-template.hpp"

template < class T >
std::vector< std::tuple< T, int, int > > manhattan_mst(std::vector< T > x, std::vector< T > y) {
    int n = x.size();
    std::vector<int> I(n);
    std::iota(I.begin(), I.end(), 0);
    std::vector< std::tuple< T, int, int > > edges;
    for(int a : {0, 1}) {
        for(int b : {0, 1}) {
            std::sort(I.begin(), I.end(), [&](int i, int j) { return x[i] + y[i] < x[j] + y[j]; });
            std::map< T, int > mp;
            for(int i : I) {
                for(auto it = mp.lower_bound(-y[i]); it != mp.end(); it = mp.erase(it)) {
                    int j = it->second;
                    T dx = x[i] - x[j], dy = y[i] - y[j];
                    if(dy <= dx) {
                        edges.emplace_back(std::abs(dx) + std::abs(dy), i, j);
                    } else break;
                }
                mp[-y[i]] = i;
            }
            std::swap(x, y);
        }
        for(T& xi : x) xi *= -1;
    }
    std::sort(edges.begin(), edges.end());
    return edges;
}