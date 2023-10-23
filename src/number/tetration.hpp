#pragma once
#include "../../src/cp-template.hpp"
#include "../../src/number/prime.hpp"
#include "../../src/number/modfunc.hpp"

u32 tetration(std::vector<u32> a, u32 mod) {
    for(u32 x : a) assert(x > 0);
    std::vector<u32> m = {mod};
    while(m.back() != 1) m.push_back(euler_phi(m.back()));
    u64 n = 1;
    for(int i : revrep(min(a.size(), m.size()))) {
        u64 x = 1, v = a[i];
        while(n > 0) {
            if(n % 2 == 1) {
                x *= v;
                if(x >= m[i]) x = x % m[i] + m[i];
            }
            v *= v;
            if(v >= m[i]) v = v % m[i] + m[i];
            n /= 2;
        }
        n = x;
    }
    return n % mod;
}

u32 tetration(u32 a, u32 b, u32 mod) {
    if(a == 0) return (b % 2 == 0) % mod;
    return tetration(std::vector<u32>(std::min<u32>(b, 64), a), mod);
}