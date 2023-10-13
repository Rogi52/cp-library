#include "../../src/cp-template.hpp"
#include "./static_point_add_rect_sum.hpp"

template < class T, class abel_group >
struct rect_sum < tag::STATIC, tag::RECTANGLE, T, abel_group > {
    using A = abel_group;
    using W = typename A::set;

    struct A4 {
        using set = array< W, 4 >;
        static set op(const set& x, const set& y) {
            set z;
            for(int i : rep(4)) z[i] = A::op(x[i], y[i]);
            return z;
        }
        static set inv(const set& x) {
            set z;
            for(int i : rep(4)) z[i] = A::inv(x[i]);
            return z;
        }
        static set pow(const set& x, ll n) {
            set z;
            for(int i : rep(4)) z[i] = A::pow(x, n);
            return z;
        }
        static constexpr set id() {
            return set{A::id(), A::id(), A::id(), A::id()};
        }
        static constexpr bool comm = true;
    };

    rect_sum< tag::STATIC, tag::POINT, T, A4 > M;
    vector<tuple< T, T, T, T >> R;
    void add(T xL, T xR, T yL, T yR, W w) {
        M.add(xL, yL, {        w, A::pow(w, -yL), A::pow(w, -xL), A::pow(w, +xL * yL)});
        M.add(xL, yR, {A::inv(w), A::pow(w, +yR), A::pow(w, +xL), A::pow(w, -xL * yR)});
        M.add(xR, yL, {A::inv(w), A::pow(w, +yL), A::pow(w, +xR), A::pow(w, -xR * yL)});
        M.add(xR, yR, {        w, A::pow(w, -yR), A::pow(w, -xR), A::pow(w, +xR * yR)});
    }
    void query(T xL, T xR, T yL, T yR) {
        R.emplace_back(xL, xR, yL, yR);
        M.query(0, xL, 0, yL);
        M.query(0, xL, 0, yR);
        M.query(0, xR, 0, yL);
        M.query(0, xR, 0, yR);
    }
    vector< W > solve() {
        vector< W > ans(R.size());
        vector< array< W, 4 > > res = M.solve();

        int k = 0;
        for(int i : rep(R.size())) {
            auto [xL, xR, yL, yR] = R[i];
            W p = A::id(), m = A::id();
            for(T x : {xL, xR}) {
                for(T y : {yL, yR}) {
                    p = A::op(p, A::pow(res[k][0], x * y));
                    p = A::op(p, A::pow(res[k][1], x * 1));
                    p = A::op(p, A::pow(res[k][2], 1 * y));
                    p = A::op(p, A::pow(res[k][3], 1 * 1));
                    swap(p, m); k++;
                }
                swap(p, m);
            }
            ans[i] = A::op(p, A::inv(m));
        }
        return ans;
    }
};