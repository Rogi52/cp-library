#include "../../src/cp-template.hpp"

template < class semi_group >
struct disjoint_sparse_table {
    using T = typename semi_group::set;
    std::vector<std::vector< T >> table;
    vector<int> msb;
    disjoint_sparse_table(const std::vector< T >& a) : table(1, a), msb(2) {
        int n = a.size();
        for(int i = 2; i < n; i <<= 1) {
            std::vector< T > v;
            for(int j = i; j < n; j += i << 1) {
                v.push_back(a[j - 1]);
                for(int k = 2; k <= i; k++)
                    v.push_back(semi_group::op(a[j - k], v.back()));
                v.push_back(a[j]);
                for(int k = 1; k < i and j + k < n; k++)
                    v.push_back(semi_group::op(v.back(), a[j + k]));
            }
            table.push_back(v);
        }
    }

    // [L, R)
    T fold(int L, int R) {
        if(L == --R) return table.front()[L];
        else {
            while(msb.size() <= (L ^ R)) msb.push_back(msb[msb.size() >> 1] + 1);
            int p = msb[L ^ R];
            return semi_group::op(table[p][L ^ (1 << p) - 1], table[p][R]);
        }
    }
};