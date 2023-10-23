#include "../../src/cp-template.hpp"
#include "../../src/number/prime.hpp"
#include "../../src/utility/random.hpp"

u64 primitive_root(u64 p) {
    std::vector<std::pair<u64, i32>> pf = factor_pair(p - 1);
    while(true) {
        u64 g = randnum::gen_int<u64>(1, p);
        int ok = 1;
        for(auto [q, e] : pf) ok &= modpow64(g, (p - 1) / q, p) != 1;
        if(ok) return g;
    }
    return 0;
}