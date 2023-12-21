#include <atcoder/maxflow>

// ICPC2023 Yokohama Regional H
// https://onlinejudge.u-aizu.ac.jp/beta/review.html#ICPCOOC2023/8680925
template < class Cost > class sm_min {
  public:
    using size_t = std::size_t;
    size_t n, s, t;
    atcoder::mf_graph<Cost> g;
    Cost c0;
    std::vector<std::array<Cost, 2>> c1;
    std::vector<std::vector<std::array<std::array<Cost, 2>, 2>>> c2;

    sm_min() = default;
    explicit sm_min(size_t n) : n(n), s(n), t(n + 1), g(1 + n + 1), c0(0), c1(n), c2(n, std::vector<std::array<std::array<Cost, 2>, 2>>(n)) {}

    void add_0(Cost cost) {
        c0 += cost;
    }

    void add_1(size_t i, bool f, Cost cost) {
        assert(i < n);
        c1[i][f] += cost;
    }

    void add_2(size_t i, bool f, size_t j, bool g, Cost cost) {
        assert(i < n);
        assert(j < n);
        c2[i][j][f][g] += cost;
    }

    Cost answer() {
        for(size_t i = 0; i < n; i++) {
            for(size_t j = 0; j < n; j++) {
                auto& c = c2[i][j];
                assert(c[0][1] + c[1][0] >= c[0][0] + c[1][1]);
                add_0(c[0][0]);
                add_1(i, 1, c[1][1] - c[0][1]);
                add_1(j, 1, c[0][1] - c[0][0]);
                g.add_edge(i, j, c[0][1] + c[1][0] - c[0][0] - c[1][1]);
            }
        }
        for(size_t i = 0; i < n; i++) {
            auto& c = c1[i];
            if(c[0] >= c[1]) {
                add_0(c[1]);
                g.add_edge(s, i, c[0] - c[1]);
            } else {
                add_0(c[0]);
                g.add_edge(i, t, c[1] - c[0]);
            }
        }
        return c0 + g.flow(s, t);
    }
};
