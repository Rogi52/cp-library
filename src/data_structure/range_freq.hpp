#include "../../src/cp-template.hpp"

template < class T >
struct range_freq {
    int n;
    std::vector< std::vector< T > > data;
    range_freq(const std::vector< T >& a) {
        n = 1;
        while(n < a.size()) n <<= 1;
        data.resize(2 * n - 1);
        for(int i : rep(a.size())) data[i + n - 1].push_back(a[i]);
        for(int i : revrep(n - 1)) {
            int L = i * 2 + 1, R = i * 2 + 2;
            data[i].resize(data[L].size() + data[R].size());
            std::merge(data[L].begin(), data[L].end(), data[R].begin(), data[R].end(), data[i].begin());
        }
    }

    // [L, R) and [-inf, RV)
    int query(int L, int R, T RV) {
        return query(L, R, RV, 0, 0, n);
    }

    // [LI, RI) and [LV, RV)
    int query(int LI, int RI, T LV, T RV) {
        return query(LI, RI, RV) - query(LI, RI, LV);
    }

  private:
    int query(int LI, int RI, T x, int k, int l, int r) {
        if(RI <= l or r <= LI)
            return 0;
        else if(LI <= l and r <= RI)
            return lower_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
        else
            return query(LI, RI, x, k * 2 + 1, l, (l + r) / 2) + query(LI, RI, x, k * 2 + 2, (l + r) / 2, r);
    }
};
