#include "../../src/cp-template.hpp"
#include "../../src/utility/zip.hpp"
#include "../../src/data_structure/fenwick_tree.hpp"

namespace tag {

struct STATIC;
struct DYNAMIC;

struct POINT;
struct RECTANGLE;

}

template < class SD, class ADD_TYPE, class T, class abel_group >
struct rect_sum {};

template < class T, class abel_group >
struct rect_sum < tag::STATIC, tag::POINT, T, abel_group > {
    using W = typename abel_group::set;
    vector<tuple< T, T, W >> P;
    vector<tuple< T, T, T, T >> R;
    zipper< T > X, Y;
    rect_sum() {}
    void add(T x, T y, W w) {
        P.emplace_back(x, y, w);
        X.insert(x); Y.insert(y);
    }
    void query(T xL, T xR, T yL, T yR) {
        R.emplace_back(xL, xR, yL, yR);
        X.insert(xL); X.insert(xR);
        Y.insert(yL); Y.insert(yR);
    }

    vector< W > solve() {
        X.build(); Y.build();
        vector< vector< pair< int, W > > > P2(X.size());
        vector< vector< tuple< int, int, int, int > > > R2(X.size());
        for(auto [x, y, w] : P) P2[X.id(x)].emplace_back(Y.id(y), w);
        for(int i : rep(R.size())) {
            auto [xL, xR, yL, yR] = R[i];
            int iyL = Y.id(yL), iyR = Y.id(yR);
            R2[X.id(xL)].emplace_back(iyL, iyR, i, 1);
            R2[X.id(xR)].emplace_back(iyL, iyR, i, 0);
        }

        vector< W > ans(R.size(), abel_group::id());
        fenwick_tree< abel_group > bit(Y.size());
        for(int x : rep(X.size())) {
            for(auto [yL, yR, i, inv] : R2[x]) {
                W w = bit.fold(yL, yR);
                if(inv) w = abel_group::inv(w);
                ans[i] = abel_group::op(ans[i], w);
            }
            for(auto [y, w] : P2[x]) bit.add(y, w);
        }
        return ans;
    }
};