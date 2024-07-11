// ax + by = gcd(a,b)
// return (x, y, gcd(a,b)) [min(|x|+|y|), x<=y]
template < class Int > std::tuple<Int, Int, Int> ext_gcd(Int a, Int b) {
    if(b == 0) return {1, 0, a};
    auto [s, t, g] = ext_gcd(b, a % b); // bs + (a%b)t = g
    // ax + by = g
    // <=> ((a/b)b + (a%b))x + by = g
    // <=> b((a/b)x + y) + (a%b)x = g
    return {t, s - (a / b) * t, g};
}

// 0 <= x < m
template < class Int > Int safe_mod(Int x, Int m) {
    x %= m;
    if(x < 0) x += m;
    return x;
}

// x = r[i] (mod m[i])
template < class Int > std::pair<Int, Int> crt(std::vector<Int> r, std::vector<Int> m) {
    assert(r.size() == m.size());
    const int n = r.size();
    auto [r0, m0] = std::make_pair<Int, Int>(0, 1);
    for(int i = 0; i < n; i++) {
        auto [r1, m1] = std::make_pair(safe_mod(r[i], m[i]), m[i]);
        if(m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if(m0 % m1 == 0) {
            if(r0 % m1 != r1) return {0, 0};
            continue;
        }
        auto [im, _, g] = ext_gcd(m0, m1);
        if((r1 - r0) % g != 0) return {0, 0};
        Int u = m1 / g;
        r0 += (r1 - r0) / g % u * im % u * m0;
        m0 *= u;
        if(r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

template < class Int > Int mod_inv(Int a, Int m) {
    auto [ia, _, g] = ext_gcd(a, m);
    return safe_mod(ia, m);
}

// x = r[i] (mod m[i])
// return (x mod M, lcm(m) mod M)
template < class Int > std::pair<Int, Int> garner(std::vector<Int> r, std::vector<Int> m, Int M, bool coprime) {
    assert(r.size() == m.size());
    const int n = r.size();

    if(not coprime) {
        auto gcd = [&](auto self, Int a, Int b) -> Int {
            if(b == 0) return a;
            return self(self, b, a % b);
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                Int g = gcd(gcd, m[i], m[j]);
                if((r[i] - r[j]) % g != 0) return {0, 0};
                m[i] /= g, m[j] /= g;
                Int gi = gcd(gcd, m[i], g), gj = g / gi;
                do {
                    g = gcd(gcd, gi, gj);
                    gi *= g, gj /= g;
                } while(g != 1);
                m[i] *= gi, m[j] *= gj;
                r[i] %= m[i], r[j] %= m[j];
            }
        }
    }

    m.push_back(M);
    std::vector<Int> a(n + 1, 1), b(n + 1, 0);
    for(int k = 0; k < n; k++) {
        Int t = safe_mod((r[k] - b[k]) * mod_inv(a[k], m[k]), m[k]);
        for(int i = k + 1; i <= n; i++) {
            (b[i] += t * a[i]) %= m[i];
            (a[i] *= m[k]) %= m[i];
        }
    }
    return {b[n], a[n]};
}
