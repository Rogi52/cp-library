---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/number/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/number/fps.hpp
    title: src/number/fps.hpp
  - icon: ':x:'
    path: src/number/fps_sparse.hpp
    title: src/number/fps_sparse.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/number/fps_inv_sparse.test.cpp
    title: verify/library_checker/number/fps_inv_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root,\
    \ isprime; };\ntemplate < modinfo const &ref >\nstruct modint {\n    static constexpr\
    \ uint const &mod = ref.mod;\n    static constexpr uint const &root = ref.root;\n\
    \    static constexpr uint const &isprime = ref.isprime;\n    uint v = 0;\n  \
    \  constexpr modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this;\
    \ }\n    constexpr modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-()\
    \ const { return modint() - *this; }\n    modint& operator+=(const modint& rhs)\
    \ { return s(v + rhs.v); }\n    modint& operator-=(const modint& rhs) { return\
    \ s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v)\
    \ * rhs.v % mod; return *this; }\n    modint& operator/=(const modint& rhs) {\
    \ return *this *= inv(rhs); }\n    modint operator+(const modint& rhs) const {\
    \ return modint(*this) += rhs; }\n    modint operator-(const modint& rhs) const\
    \ { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs) const\
    \ { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs) const\
    \ { return modint(*this) /= rhs; }\n    friend modint pow(modint x, ll n) { modint\
    \ res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n\
    \    friend modint inv(modint v) {\n        if(isprime) {\n            return\
    \ pow(v, mod - 2);\n        } else {\n            ll a = v.v, b = modint::mod,\
    \ x = 1, y = 0, t;\n            while(b > 0) { t = a / b; swap(a -= t * b, b);\
    \ swap(x -= t * y, y); }\n            return modint(x);\n        }\n    }\n  \
    \  friend modint operator+(int x, const modint& y) { return modint(x) + y; }\n\
    \    friend modint operator-(int x, const modint& y) { return modint(x) - y; }\n\
    \    friend modint operator*(int x, const modint& y) { return modint(x) * y; }\n\
    \    friend modint operator/(int x, const modint& y) { return modint(x) / y; }\n\
    \    friend istream& operator>>(istream& is, modint& m) { ll x; is >> x; m = modint(x);\
    \ return is; }\n    friend ostream& operator<<(ostream& os, const modint& m) {\
    \ return os << m.v; }\n    bool operator==(const modint& r) const { return v ==\
    \ r.v; }\n    bool operator!=(const modint& r) const { return v != r.v; }\n  \
    \  static uint get_mod() { return mod; }\n};\nconstexpr modinfo base998244353\
    \ { 998244353, 3, 1 };\nconstexpr modinfo base1000000007 { 1000000007, 0, 1 };\n\
    using mint998244353 = modint< base998244353 >;\nusing mint1000000007 = modint<\
    \ base1000000007 >;\n#line 3 \"src/number/ntt.hpp\"\nnamespace ntt {\n\ntemplate\
    \ < class mint >\nvoid trans(vector<mint>& v, bool is_inv) {\n    if(v.empty())\
    \ return;\n    int n = v.size();\n    uint mod = mint::mod, root = mint::root;\n\
    \    static bool first = true;\n    static vector<ll> vbw(30), vibw(30);\n   \
    \ if(first) {\n        first = false;\n        for(int k : rep(30)) {\n      \
    \      vbw[k] = pow(mint(root), (mod - 1) >> (k + 1)).v;\n            vibw[k]\
    \ = inv(mint(vbw[k])).v;\n        }\n    }\n    for(int i = 0, j = 1; j < n -\
    \ 1; j++) {\n        for(int k = n >> 1; k > (i ^= k); k >>= 1);\n        if(i\
    \ > j) swap(v[i], v[j]);\n    }\n    for(int k = 0, t = 2; t <= n; ++k, t <<=\
    \ 1) {\n        mint bw = (is_inv ? vibw[k] : vbw[k]);\n        for (int i = 0;\
    \ i < n; i += t) {\n            mint w = 1;\n            for (int j = 0; j < t\
    \ / 2; ++j) {\n                int j1 = i + j, j2 = i + j + t/2;\n           \
    \     mint c1 = v[j1], c2 = v[j2] * w;\n                v[j1] = c1 + c2;\n   \
    \             v[j2] = c1 - c2;\n                w *= bw;\n            }\n    \
    \    }\n    }\n    if(is_inv) {\n        mint iv = inv(mint(n));\n        for(int\
    \ i : rep(n)) v[i] *= iv;\n    }\n}\ntemplate < class mint > void ntt(vector<mint>&\
    \ v) { trans(v, false); }\ntemplate < class mint > void intt(vector<mint>& v)\
    \ { trans(v, true); }\n\n// for garner\nconstexpr modinfo base0 { 754974721, 11,\
    \ 1};\nconstexpr modinfo base1 { 167772161,  3, 1};\nconstexpr modinfo base2 {\
    \ 469762049,  3, 1};\nusing mint0 = modint< base0 >;\nusing mint1 = modint< base1\
    \ >;\nusing mint2 = modint< base2 >;\nstatic const mint1 imod0  =  95869806; //\
    \ MOD0^-1 mod MOD1\nstatic const mint2 imod1  = 104391568; // MOD1^^1 mod MOD2\n\
    static const mint2 imod01 = 187290749; // imod1 / MOD0;\n\ntemplate < class T\
    \ >\nvector< T > naive(const vector< T >& a, const vector< T >& b) {\n    if(a.empty()\
    \ || b.empty()) return {};\n    int n = a.size(), m = b.size();\n    vector< T\
    \ > c(n + m - 1);\n    for(int i : rep(n)) for(int j : rep(m)) c[i + j] += a[i]\
    \ * b[j];\n    return c;\n}\n\ntemplate < class mint >\nvector<mint> mul(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    if(a.empty() || b.empty()) return\
    \ {};\n    int n = a.size(), m = b.size();\n    if(min(n, m) < 30) return naive(a,\
    \ b);\n    uint mod = mint::mod;\n\n    int sz = [&]() {\n        int n2 = 1,\
    \ m2 = 1;\n        while(n2 < n) n2 <<= 1;\n        while(m2 < m) m2 <<= 1;\n\
    \        return max(n2, m2) << 1;\n    }();\n\n    if(mod == 998244353) {\n  \
    \      vector<mint> a2(sz, 0), b2(sz, 0), c(sz, 0);\n        for(int i : rep(n))\
    \ a2[i] = a[i];\n        for(int i : rep(m)) b2[i] = b[i];\n        ntt(a2), ntt(b2);\n\
    \        for(int i : rep(sz)) c[i] = a2[i] * b2[i];\n        intt(c);\n      \
    \  c.resize(n + m - 1);\n        return c;\n    }\n\n    vector<mint0> a0(sz,\
    \ 0), b0(sz, 0), c0(sz, 0);\n    vector<mint1> a1(sz, 0), b1(sz, 0), c1(sz, 0);\n\
    \    vector<mint2> a2(sz, 0), b2(sz, 0), c2(sz, 0);\n    for(int i : rep(n)) a0[i].v\
    \ = a1[i].v = a2[i].v = a[i].v;\n    for(int i : rep(m)) b0[i].v = b1[i].v = b2[i].v\
    \ = b[i].v;\n    ntt(a0), ntt(b0), ntt(a1), ntt(b1), ntt(a2), ntt(b2);\n    for(int\
    \ i : rep(sz)) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] * b1[i];\n\
    \        c2[i] = a2[i] * b2[i];\n    }\n    intt(c0), intt(c1), intt(c2);\n  \
    \  \n    vector<mint> c(n + m - 1);\n    static const mint mod0 = mint0::mod,\
    \ mod01 = mod0 * mint1::mod;\n    for(int i : rep(n + m - 1)) {\n        ll y0\
    \ = c0[i].v;\n        ll y1 = (imod0 * (c1[i] - y0)).v;\n        ll y2 = (imod01\
    \ * (c2[i] - y0) - imod1 * y1).v;\n        c[i] = mod01 * y2 + mod0 * y1 + y0;\n\
    \    }\n    return c;\n}\n\n} // namespace ntt\n"
  code: "#pragma once\n#include \"../number/modint.hpp\"\nnamespace ntt {\n\ntemplate\
    \ < class mint >\nvoid trans(vector<mint>& v, bool is_inv) {\n    if(v.empty())\
    \ return;\n    int n = v.size();\n    uint mod = mint::mod, root = mint::root;\n\
    \    static bool first = true;\n    static vector<ll> vbw(30), vibw(30);\n   \
    \ if(first) {\n        first = false;\n        for(int k : rep(30)) {\n      \
    \      vbw[k] = pow(mint(root), (mod - 1) >> (k + 1)).v;\n            vibw[k]\
    \ = inv(mint(vbw[k])).v;\n        }\n    }\n    for(int i = 0, j = 1; j < n -\
    \ 1; j++) {\n        for(int k = n >> 1; k > (i ^= k); k >>= 1);\n        if(i\
    \ > j) swap(v[i], v[j]);\n    }\n    for(int k = 0, t = 2; t <= n; ++k, t <<=\
    \ 1) {\n        mint bw = (is_inv ? vibw[k] : vbw[k]);\n        for (int i = 0;\
    \ i < n; i += t) {\n            mint w = 1;\n            for (int j = 0; j < t\
    \ / 2; ++j) {\n                int j1 = i + j, j2 = i + j + t/2;\n           \
    \     mint c1 = v[j1], c2 = v[j2] * w;\n                v[j1] = c1 + c2;\n   \
    \             v[j2] = c1 - c2;\n                w *= bw;\n            }\n    \
    \    }\n    }\n    if(is_inv) {\n        mint iv = inv(mint(n));\n        for(int\
    \ i : rep(n)) v[i] *= iv;\n    }\n}\ntemplate < class mint > void ntt(vector<mint>&\
    \ v) { trans(v, false); }\ntemplate < class mint > void intt(vector<mint>& v)\
    \ { trans(v, true); }\n\n// for garner\nconstexpr modinfo base0 { 754974721, 11,\
    \ 1};\nconstexpr modinfo base1 { 167772161,  3, 1};\nconstexpr modinfo base2 {\
    \ 469762049,  3, 1};\nusing mint0 = modint< base0 >;\nusing mint1 = modint< base1\
    \ >;\nusing mint2 = modint< base2 >;\nstatic const mint1 imod0  =  95869806; //\
    \ MOD0^-1 mod MOD1\nstatic const mint2 imod1  = 104391568; // MOD1^^1 mod MOD2\n\
    static const mint2 imod01 = 187290749; // imod1 / MOD0;\n\ntemplate < class T\
    \ >\nvector< T > naive(const vector< T >& a, const vector< T >& b) {\n    if(a.empty()\
    \ || b.empty()) return {};\n    int n = a.size(), m = b.size();\n    vector< T\
    \ > c(n + m - 1);\n    for(int i : rep(n)) for(int j : rep(m)) c[i + j] += a[i]\
    \ * b[j];\n    return c;\n}\n\ntemplate < class mint >\nvector<mint> mul(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    if(a.empty() || b.empty()) return\
    \ {};\n    int n = a.size(), m = b.size();\n    if(min(n, m) < 30) return naive(a,\
    \ b);\n    uint mod = mint::mod;\n\n    int sz = [&]() {\n        int n2 = 1,\
    \ m2 = 1;\n        while(n2 < n) n2 <<= 1;\n        while(m2 < m) m2 <<= 1;\n\
    \        return max(n2, m2) << 1;\n    }();\n\n    if(mod == 998244353) {\n  \
    \      vector<mint> a2(sz, 0), b2(sz, 0), c(sz, 0);\n        for(int i : rep(n))\
    \ a2[i] = a[i];\n        for(int i : rep(m)) b2[i] = b[i];\n        ntt(a2), ntt(b2);\n\
    \        for(int i : rep(sz)) c[i] = a2[i] * b2[i];\n        intt(c);\n      \
    \  c.resize(n + m - 1);\n        return c;\n    }\n\n    vector<mint0> a0(sz,\
    \ 0), b0(sz, 0), c0(sz, 0);\n    vector<mint1> a1(sz, 0), b1(sz, 0), c1(sz, 0);\n\
    \    vector<mint2> a2(sz, 0), b2(sz, 0), c2(sz, 0);\n    for(int i : rep(n)) a0[i].v\
    \ = a1[i].v = a2[i].v = a[i].v;\n    for(int i : rep(m)) b0[i].v = b1[i].v = b2[i].v\
    \ = b[i].v;\n    ntt(a0), ntt(b0), ntt(a1), ntt(b1), ntt(a2), ntt(b2);\n    for(int\
    \ i : rep(sz)) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] * b1[i];\n\
    \        c2[i] = a2[i] * b2[i];\n    }\n    intt(c0), intt(c1), intt(c2);\n  \
    \  \n    vector<mint> c(n + m - 1);\n    static const mint mod0 = mint0::mod,\
    \ mod01 = mod0 * mint1::mod;\n    for(int i : rep(n + m - 1)) {\n        ll y0\
    \ = c0[i].v;\n        ll y1 = (imod0 * (c1[i] - y0)).v;\n        ll y2 = (imod01\
    \ * (c2[i] - y0) - imod1 * y1).v;\n        c[i] = mod01 * y2 + mod0 * y1 + y0;\n\
    \    }\n    return c;\n}\n\n} // namespace ntt\n"
  dependsOn:
  - src/number/modint.hpp
  isVerificationFile: false
  path: src/number/ntt.hpp
  requiredBy:
  - src/number/fps_sparse.hpp
  - src/number/fps.hpp
  timestamp: '2023-10-06 00:46:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/number/fps_inv_sparse.test.cpp
documentation_of: src/number/ntt.hpp
layout: document
redirect_from:
- /library/src/number/ntt.hpp
- /library/src/number/ntt.hpp.html
title: src/number/ntt.hpp
---
