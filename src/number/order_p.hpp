struct order_p {
    u64 P;
    std::size_t n;
    std::vector<std::pair<u64, i32>> pf;
    vector<u64> prod;
    order_p() = default;
    order_p(u64 P) : order_p(P, factor_pair(P - 1)) {}
    order_p(u64 P, vector<pair<u64, i32>> pf) : P(P), pf(pf), n(pf.size()), prod(n + 1) {
        prod[0] = 1;
        for(std::size_t i = 0; i < n; i++) {
            auto [p, e] = pf[i];
            u64 pe = 1;
            while(e--) pe *= p;
            prod[i + 1] = prod[i] * pe;
        }
    }

    u64 get(u64 x) {
        return n == 0 ? 1 : get(0, n, x);
    }
    u64 get(std::size_t l, std::size_t r, u64 x) {
        if(l + 1 == r) {
            auto [p, e] = pf[l];
            std::size_t ei = [&] {
                for(std::size_t i = 0; i < e; i++) {
                    if(x == 1) return i;
                    x = modpow64(x, p, P);
                }
                return std::size_t(e);
            }();
            u64 ans = 1;
            for(std::size_t _ = 0; _ < ei; _++) ans *= p;
            return ans;
        }
        std::size_t m = (l + r) / 2;
        return get(l, m, modpow64(x, prod[r] / prod[m], P))
             * get(m, r, modpow64(x, prod[m] / prod[l], P));
    }

};
