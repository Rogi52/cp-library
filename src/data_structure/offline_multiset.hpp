#inlcude "src/data_structure/fenwick_tree.hpp"
#include "src/algebra/plus.hpp"

template < class T, class U > class offline_multiset {
  private:
    int n;
    vector< T > v;
    fenwick_tree< algebra::PLUS< U > > ft;

  public:
    offline_multiset() {}
    offline_multiset(vector< T > x) : v(x) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        n = v.size();
        ft = fenwick_tree< algebra::PLUS< U > >(n);
    }

    void insert(T x, U cnt = 1) {
        int i = lower_bound(v.begin(), v.end(), x) - v.begin();
        assert(v[i] == x);
        ft.add(i, +cnt);
    }
    void erase(T x, U cnt = 1) {
        int i = lower_bound(v.begin(), v.end(), x) - v.begin();
        assert(v[i] == x);
        ft.add(i, -cnt);
    }
    T get_kth(U k) {
        return v[ft.search([k](U s){ return s >= k; })];
    }
};
