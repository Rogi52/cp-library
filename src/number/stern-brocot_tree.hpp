#include "../../src/cp-template.hpp"

template < class T >
T sgn(T x) {
    return (0 < x) - (x < 0);
}

template < class I >
class stern_brocot_tree_node {
    struct fraction {
        I upper, lower;
        fraction(I upper = 0, I lower = 1) : upper(upper), lower(lower) {}
        fraction& operator+=(const fraction& r) {
            this->upper += r.upper;
            this->lower += r.lower;
            return *this;
        }
        fraction& operator-=(const fraction& r) {
            this->upper -= r.upper;
            this->lower -= r.lower;
            return *this;
        }
        fraction& operator*=(I v) {
            this->upper *= v;
            this->lower *= v;
            return *this;
        }
        fraction operator+(const fraction& r) const { return fraction(*this) += r; }
        fraction operator-(const fraction& r) const { return fraction(*this) -= r; }
        fraction operator*(I v) { return fraction(*this) *= v; }
    };
    fraction L, M, R;

  public:
    std::vector< I > history;
    I depth;

    stern_brocot_tree_node() : L(0, 1), M(1, 1), R(1, 0), depth(0) {}
    stern_brocot_tree_node(I a, I b) : stern_brocot_tree_node() {
        assert(1 <= a);
        assert(1 <= b);
        I s = a < b ? -1 : +1;
        if(s == -1) std::swap(a, b);
        for(; b != 0; s *= -1) {
            auto [q, r] = std::div(a, b);
            down(s * (q - (r == 0)));
            a = b, b = r;
        }
    }
    stern_brocot_tree_node(std::vector< I > history) : stern_brocot_tree_node() {
        for(I k : history) down(k);
        assert(this->history == history);
    }
    using sbt_n = stern_brocot_tree_node< I >;

    std::pair< I, I > value()       { return std::make_pair(M.upper, M.lower); }
    std::pair< I, I > lower_bound() { return std::make_pair(L.upper, L.lower); }
    std::pair< I, I > upper_bound() { return std::make_pair(R.upper, R.lower); }

    void down_left(I k) {
        assert(1 <= k);
        std::tie(L, M, R)
            = std::make_tuple(L, L * k + M, L * (k - 1) + M);
        history.push_back(-k);
        depth += k;
    }
    void down_right(I k) {
        assert(1 <= k);
        std::tie(L, M, R)
            = std::make_tuple(R * (k - 1) + M, R * k + M, R);
        history.push_back(+k);
        depth += k;
    }
    void down(I k) {
        switch(sgn(k)) {
            case  0: return;
            case -1: return down_left (-k);
            case +1: return down_right(+k);
        }
    }
    void up(I k) {
        assert(0 <= k and k <= depth);
        while(k != 0) {
            I x = std::min(k, std::abs(history.back()));
            if(history.back() > 0) {
                std::tie(L, M, R)
                    = std::make_tuple(L - R * x, L - R * (x - 1), R);
                history.back() -= x;
            } else {
                std::tie(L, M, R)
                    = std::make_tuple(L, R - L * (x - 1), R - L * x);
                history.back() += x;
            }
            if(history.back() == 0) history.pop_back();
            k -= x;
            depth -= x;
        }
    }
    friend sbt_n lca(const sbt_n& L, const sbt_n& R) {
        sbt_n M;
        for(int i : rep(min(L.history.size(), R.history.size()))) {
            I Lx = L.history[i], Rx = R.history[i];
            if(sgn(Lx) == sgn(Rx)) {
                M.down(sgn(Lx) * std::min(abs(Lx), abs(Rx)));
                if(Lx != Rx) break;
            } else break;
        }
        return M;
    }
};

template < class I, class F >
std::pair< I, I > sbt_search(const I N, const F& f) {
    assert(1 <= N);
    if(f({0, 1})) return {0, 1};

    stern_brocot_tree_node< I > sbt_n;
    auto over = [&]() {
        auto [a, b] = sbt_n.value();
        return std::max(a, b) > N;
    };
    int sgn = f(sbt_n.value()) ? -1 : +1;
    auto ng = [&]() { return over() or f(sbt_n.value()) == (sgn > 0); };

    while(true) {
        I x = 1;
        while(true) {
            sbt_n.down(x * sgn);
            if(ng()) { sbt_n.up(x); break; }
            x *= 2;
        }
        x /= 2;
        while(x > 0) {
            sbt_n.down(x * sgn);
            if(ng()) sbt_n.up(x);
            x /= 2;
        }
        sbt_n.down(sgn);
        if(over()) return sbt_n.upper_bound();
        sgn *= -1;
    }
}