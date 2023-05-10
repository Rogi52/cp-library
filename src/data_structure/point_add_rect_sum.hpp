#include "../../src/cp-template.hpp"
#include "../../src/data_structure/static_point_add_rect_sum.hpp"

template < class T, class abel_group >
struct rect_sum < tag::DYNAMIC, tag::POINT, T, abel_group > {
    using A = abel_group;
    using W = typename A::set;
    using add_t = tuple< T, T, W >;
    using query_t = tuple< T, T, T, T >;
    vector< variant< add_t, query_t > > qs;

    void add(T x, T y, W w) {
        qs.push_back(add_t{x, y, w});
    }
    void query(T xL, T xR, T yL, T yR) {
        qs.push_back(query_t{xL, xR, yL, yR});
    }
    vector< W > solve() {
        int Q = qs.size();
        queue<pair<int,int>> que;
        que.emplace(0, Q);
        vector<int> q_id(Q);
        int id = 0;
        for(int i : rep(Q)) {
            if(holds_alternative< query_t >(qs[i])) {
                q_id[i] = id++;
            }
        }
        vector< W > ans(id);
        while(not que.empty()) {
            auto [L, R] = que.front(); que.pop();
            if(L + 1 >= R) continue;
            int M = (L + R) / 2;
            que.emplace(L, M);
            que.emplace(M, R);
            rect_sum< tag::STATIC, tag::POINT, T, A > rs;
            for(int i : rep(L, M)) {
                if(holds_alternative< add_t >(qs[i])) {
                    auto [x, y, w] = get< add_t >(qs[i]);
                    rs.add(x, y, w);
                }
            }
            for(int i : rep(M, R)) {
                if(holds_alternative< query_t >(qs[i])) {
                    auto [xL, xR, yL, yR] = get< query_t >(qs[i]);
                    rs.query(xL, xR, yL, yR);
                }
            }
            vector< W > res = rs.solve();
            int k = 0;
            for(int i : rep(M, R)) {
                if(holds_alternative< query_t >(qs[i])) {
                    ans[q_id[i]] += res[k++];
                }
            }
        }
        return ans;
    }
};