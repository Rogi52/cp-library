#pragma once
#include "../../src/cp-template.hpp"
#include "../../src/utility/random.hpp"

u64 modpow64(u64 a, u64 n, u64 mod) {
    a %= mod;
    u64 res = 1;
    while(n > 0) {
        if(n % 2 == 1) res = i128(res) * a % mod;
        a = i128(a) * a % mod;
        n /= 2;
    }
    return res;
}

u64 modpow(u64 a, u64 n, u64 mod) {
    a %= mod;
    u64 res = 1;
    while(n > 0) {
        if(n % 2 == 1) res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return res;
}

// solve x^2 = a (mod p)
// return x
// or No Solution (-1)
i32 modsqrt(i32 a, i32 p) {
    if(p == 2) return a;
    a %= p;
    if(a == 0) return 0;
    if(modpow(a, (p - 1) / 2, p) != 1) return -1;
    i32 q = p - 1, m = 0; while(q % 2 == 0) q /= 2, m++;
    i32 z; do { z = randnum::gen_int<i32>(1, p); } while(modpow(z, (p - 1) / 2, p) != p - 1);
    i64 c = modpow(z, q, p), t = modpow(a, q, p), r = modpow(a, (q + 1) / 2, p);
    while(m > 1) {
        if(modpow(t, 1 << (m - 2), p) != 1) r = r * c % p, t = t * (c * c % p) % p;
        c = c * c % p;
        m -= 1;
    }
    return r;
}
