#include "../cp-template.hpp"

namespace nim {
    constexpr ull SMALL_BIT = 1 << 3;
    constexpr ull SMALL = 1 << SMALL_BIT;
    ull _prod(ull a, ull b, ull n_bit) {
        static ull memo[SMALL][SMALL], vis[SMALL][SMALL];
        if(n_bit == 1) return a & b;
        if(n_bit <= SMALL_BIT and vis[a][b]) return memo[a][b];
        ull n = n_bit >> 1, m = 1ULL << n;
        auto [au, al] = make_pair(a / m, a % m);
        auto [bu, bl] = make_pair(b / m, b % m);
        ull ans = 0;
        ans ^= (_prod(au, bu, n) ^ _prod(al, bu, n) ^ _prod(au, bl, n)) * m;
        ans ^= _prod(_prod(au, bu, n), m >> 1, n_bit / 2);
        ans ^= _prod(al, bl, n);
        if(n_bit <= SMALL_BIT) vis[a][b] = 1ULL, memo[a][b] = ans;
        return ans;
    }

    ull prod(ull a, ull b) {
        return _prod(a, b, 64);
    }
}