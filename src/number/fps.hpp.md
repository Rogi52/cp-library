---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/number/fps.hpp\"\ntemplate < class mint > struct formal_power_series\
    \ : vector<mint> {\n    using vector<mint>::vector;\n    formal_power_series(const\
    \ vector<mint>& f) : vector<mint>(f) {}\n    using fps = formal_power_series<mint>;\n\
    \    int size() const { return vector<mint>::size(); }\n    void ups(int s) {\
    \ if(size() < s) this->resize(s, 0); }\n    fps low(int s) const {\n        return\
    \ fps(this->begin(), this->begin() + min(this->size(), s));\n    }\n    fps rev()\
    \ const {\n        fps res = *this;\n        reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n    fps operator-() const {\n        fps res = *this;\n\
    \        for(int i = 0; i < int(res.size()); i++) res[i] = -res[i];\n        return\
    \ res;\n    }\n    fps operator+(const mint& v) const { return fps(*this) += v;\
    \ }\n    fps operator+(const fps&  r) const { return fps(*this) += r; }\n    fps\
    \ operator-(const mint& v) const { return fps(*this) -= v; }\n    fps operator-(const\
    \ fps&  r) const { return fps(*this) -= r; }\n    fps operator*(const mint& v)\
    \ const { return fps(*this) *= v; }\n    fps operator*(const fps&  r) const {\
    \ return fps(*this) *= r; }\n    fps operator/(const mint& v) const { return fps(*this)\
    \ /= v; }\n    fps operator<<(int x) const { return fps(*this) <<= x; }\n    fps\
    \ operator>>(int x) const { return fps(*this) >>= x; }\n    fps& operator+=(const\
    \ fps&  r) { ups(r.size()); for(int i : rep(r.size())) (*this)[i] += r[i]; return\
    \ *this; }\n    fps& operator-=(const fps&  r) { ups(r.size()); for(int i : rep(r.size()))\
    \ (*this)[i] -= r[i]; return *this; }\n    fps& operator*=(const fps&  r) { return\
    \ *this = ntt::mul(*this, r); }\n    template < class T > fps& operator+=(T v)\
    \ { ups(1); (*this)[0] += v; return *this; }\n    template < class T > fps& operator-=(T\
    \ v) { ups(1); (*this)[0] -= v; return *this; }\n    template < class T > fps&\
    \ operator*=(T v) { for(auto &x : *this) x *= v; return *this; }\n    template\
    \ < class T > fps& operator/=(T v) { assert(v != T(0)); return *this *= modinv(v);\
    \ }\n    fps& operator<<=(int x) {\n        fps res(x, 0);\n        res.insert(res.end(),\
    \ this->begin(), this->end());\n        return *this = res;\n    }\n    fps& operator>>=(int\
    \ x) {\n        fps res;\n        res.insert(res.end(), this->begin() + x, this->end());\n\
    \        return *this = res;\n    }\n\n    friend fps diff(const fps& f) {\n \
    \       int n = f.size();\n        fps g(n - 1);\n        for(int i : rep(1, n))\
    \ g[i - 1] = f[i] * i;\n        return g;\n    }\n    friend fps integral(const\
    \ fps& f) {\n        int n = f.size();\n        fps g(n + 1, 0);\n        for(int\
    \ i : rep(0, n)) g[i + 1] = f[i] / (i + 1);\n        return g;\n    }\n    friend\
    \ fps inv(const fps& f, int deg) {\n        assert(f[0] != 0);\n        fps g({mint(1)\
    \ / f[0]});\n        for(int i = 1; i < deg; i <<= 1) {\n            g = (g +\
    \ g - g * g * f.low(i << 1)).low(i << 1);\n        }\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps log(const fps& f, int deg) {\n     \
    \   assert(f[0] == 1);\n        fps g = integral(diff(f) * inv(f, deg));\n   \
    \     g.resize(deg);\n        return g;\n    }\n    friend fps exp(const fps&\
    \ f, int deg) {\n        assert(f[0] == 0);\n        fps g(1, 1);\n        for(int\
    \ i = 1; i < deg; i <<= 1) {\n            g = g * (f.low(i << 1) - log(g, i <<\
    \ 1) + 1).low(i << 1);\n        }\n        g.resize(deg);\n        return g;\n\
    \    }\n    friend fps pow(const fps& f, ll n, int deg) {\n        if(n == 0)\
    \ { fps g(deg, 0); g[0] = 1; return g; }\n        int i = 0;\n        while(i\
    \ < f.size() && f[i] == 0) i++;\n        if(i == f.size() || __int128_t(i) * n\
    \ >= deg) return fps(deg, 0);\n        mint k = f[i];\n        fps g = exp(log((f\
    \ >> i) / k, deg) * n, deg) * modpow(k, n) << (i * n);\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps inner_sqrt(const fps& f, int deg) {\n\
    \        assert(f[0] == 1);\n        mint inv2 = mint(1) / 2;\n        fps g(1,\
    \ 1);\n        for(int i = 1; i < deg; i <<= 1) {\n            g = (g + f.low(i\
    \ << 1) * inv(g, i << 1)).low(i << 1);\n            for(mint& a : g) a *= inv2;\n\
    \        }\n        g.resize(deg);\n        return g;\n    }\n    friend fps sqrt(const\
    \ fps& f, int deg) {\n        int n = f.size(), d = n;\n        for(int i : revrep(0,\
    \ n)) if(f[i] != 0) d = i;\n        if(d == n) return f;\n        if(d % 2 ==\
    \ 1) return {};\n        mint y = f[d], x = modsqrt(y);\n        if(x * x != y)\
    \ return {};\n        mint c = mint(1) / y;\n        fps g(n - d);\n        for(int\
    \ i : rep(n - d)) g[i] = f[d + i] * c;\n        g = inner_sqrt(g, deg);\n    \
    \    for(int i : rep(g.size())) g[i] *= x;\n        for(int i : revrep(0, deg))\
    \ g[i] = (i >= d / 2 ? g[i - d / 2] : 0);\n        return g;\n    }\n\n    friend\
    \ fps inv(const fps& f) { return inv(f, f.size()); }\n    friend fps log(const\
    \ fps& f) { return log(f, f.size()); }\n    friend fps exp(const fps& f) { return\
    \ exp(f, f.size()); }\n    friend fps pow(const fps& f, ll n) { return pow(f,\
    \ n, f.size()); }\n    friend fps sqrt(const fps& f) { return sqrt(f, f.size());\
    \ }\n};\n\nusing fps = formal_power_series<mint>;\n"
  code: "template < class mint > struct formal_power_series : vector<mint> {\n   \
    \ using vector<mint>::vector;\n    formal_power_series(const vector<mint>& f)\
    \ : vector<mint>(f) {}\n    using fps = formal_power_series<mint>;\n    int size()\
    \ const { return vector<mint>::size(); }\n    void ups(int s) { if(size() < s)\
    \ this->resize(s, 0); }\n    fps low(int s) const {\n        return fps(this->begin(),\
    \ this->begin() + min(this->size(), s));\n    }\n    fps rev() const {\n     \
    \   fps res = *this;\n        reverse(res.begin(), res.end());\n        return\
    \ res;\n    }\n    fps operator-() const {\n        fps res = *this;\n       \
    \ for(int i = 0; i < int(res.size()); i++) res[i] = -res[i];\n        return res;\n\
    \    }\n    fps operator+(const mint& v) const { return fps(*this) += v; }\n \
    \   fps operator+(const fps&  r) const { return fps(*this) += r; }\n    fps operator-(const\
    \ mint& v) const { return fps(*this) -= v; }\n    fps operator-(const fps&  r)\
    \ const { return fps(*this) -= r; }\n    fps operator*(const mint& v) const {\
    \ return fps(*this) *= v; }\n    fps operator*(const fps&  r) const { return fps(*this)\
    \ *= r; }\n    fps operator/(const mint& v) const { return fps(*this) /= v; }\n\
    \    fps operator<<(int x) const { return fps(*this) <<= x; }\n    fps operator>>(int\
    \ x) const { return fps(*this) >>= x; }\n    fps& operator+=(const fps&  r) {\
    \ ups(r.size()); for(int i : rep(r.size())) (*this)[i] += r[i]; return *this;\
    \ }\n    fps& operator-=(const fps&  r) { ups(r.size()); for(int i : rep(r.size()))\
    \ (*this)[i] -= r[i]; return *this; }\n    fps& operator*=(const fps&  r) { return\
    \ *this = ntt::mul(*this, r); }\n    template < class T > fps& operator+=(T v)\
    \ { ups(1); (*this)[0] += v; return *this; }\n    template < class T > fps& operator-=(T\
    \ v) { ups(1); (*this)[0] -= v; return *this; }\n    template < class T > fps&\
    \ operator*=(T v) { for(auto &x : *this) x *= v; return *this; }\n    template\
    \ < class T > fps& operator/=(T v) { assert(v != T(0)); return *this *= modinv(v);\
    \ }\n    fps& operator<<=(int x) {\n        fps res(x, 0);\n        res.insert(res.end(),\
    \ this->begin(), this->end());\n        return *this = res;\n    }\n    fps& operator>>=(int\
    \ x) {\n        fps res;\n        res.insert(res.end(), this->begin() + x, this->end());\n\
    \        return *this = res;\n    }\n\n    friend fps diff(const fps& f) {\n \
    \       int n = f.size();\n        fps g(n - 1);\n        for(int i : rep(1, n))\
    \ g[i - 1] = f[i] * i;\n        return g;\n    }\n    friend fps integral(const\
    \ fps& f) {\n        int n = f.size();\n        fps g(n + 1, 0);\n        for(int\
    \ i : rep(0, n)) g[i + 1] = f[i] / (i + 1);\n        return g;\n    }\n    friend\
    \ fps inv(const fps& f, int deg) {\n        assert(f[0] != 0);\n        fps g({mint(1)\
    \ / f[0]});\n        for(int i = 1; i < deg; i <<= 1) {\n            g = (g +\
    \ g - g * g * f.low(i << 1)).low(i << 1);\n        }\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps log(const fps& f, int deg) {\n     \
    \   assert(f[0] == 1);\n        fps g = integral(diff(f) * inv(f, deg));\n   \
    \     g.resize(deg);\n        return g;\n    }\n    friend fps exp(const fps&\
    \ f, int deg) {\n        assert(f[0] == 0);\n        fps g(1, 1);\n        for(int\
    \ i = 1; i < deg; i <<= 1) {\n            g = g * (f.low(i << 1) - log(g, i <<\
    \ 1) + 1).low(i << 1);\n        }\n        g.resize(deg);\n        return g;\n\
    \    }\n    friend fps pow(const fps& f, ll n, int deg) {\n        if(n == 0)\
    \ { fps g(deg, 0); g[0] = 1; return g; }\n        int i = 0;\n        while(i\
    \ < f.size() && f[i] == 0) i++;\n        if(i == f.size() || __int128_t(i) * n\
    \ >= deg) return fps(deg, 0);\n        mint k = f[i];\n        fps g = exp(log((f\
    \ >> i) / k, deg) * n, deg) * modpow(k, n) << (i * n);\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps inner_sqrt(const fps& f, int deg) {\n\
    \        assert(f[0] == 1);\n        mint inv2 = mint(1) / 2;\n        fps g(1,\
    \ 1);\n        for(int i = 1; i < deg; i <<= 1) {\n            g = (g + f.low(i\
    \ << 1) * inv(g, i << 1)).low(i << 1);\n            for(mint& a : g) a *= inv2;\n\
    \        }\n        g.resize(deg);\n        return g;\n    }\n    friend fps sqrt(const\
    \ fps& f, int deg) {\n        int n = f.size(), d = n;\n        for(int i : revrep(0,\
    \ n)) if(f[i] != 0) d = i;\n        if(d == n) return f;\n        if(d % 2 ==\
    \ 1) return {};\n        mint y = f[d], x = modsqrt(y);\n        if(x * x != y)\
    \ return {};\n        mint c = mint(1) / y;\n        fps g(n - d);\n        for(int\
    \ i : rep(n - d)) g[i] = f[d + i] * c;\n        g = inner_sqrt(g, deg);\n    \
    \    for(int i : rep(g.size())) g[i] *= x;\n        for(int i : revrep(0, deg))\
    \ g[i] = (i >= d / 2 ? g[i - d / 2] : 0);\n        return g;\n    }\n\n    friend\
    \ fps inv(const fps& f) { return inv(f, f.size()); }\n    friend fps log(const\
    \ fps& f) { return log(f, f.size()); }\n    friend fps exp(const fps& f) { return\
    \ exp(f, f.size()); }\n    friend fps pow(const fps& f, ll n) { return pow(f,\
    \ n, f.size()); }\n    friend fps sqrt(const fps& f) { return sqrt(f, f.size());\
    \ }\n};\n\nusing fps = formal_power_series<mint>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/number/fps.hpp
  requiredBy: []
  timestamp: '2023-05-06 08:26:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/fps.hpp
layout: document
redirect_from:
- /library/src/number/fps.hpp
- /library/src/number/fps.hpp.html
title: src/number/fps.hpp
---
