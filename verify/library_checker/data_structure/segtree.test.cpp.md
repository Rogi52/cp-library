---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/affine.hpp
    title: src/algebra/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/segtree.hpp
    title: src/data_structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/library_checker/data_structure/segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#line 1 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,n)\
    \ for(int i = 0; i < (n); i++)\nusing namespace std;\nusing ll = long long;\n\
    using ld = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long\
    \ long;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return\
    \ true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a <\
    \ b) { a = b; return true; } return false; }\n#line 1 \"src/data_structure/segtree.hpp\"\
    \ntemplate < class monoid > struct segtree {\n    using S = typename monoid::set;\n\
    \n    segtree() : segtree(0) {}\n    segtree(int n) : segtree(vector< S >(n, monoid::id))\
    \ {}\n    segtree(const vector< S >& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = vector< S >(2 * size, monoid::id);\n  \
    \      for(int i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size\
    \ - 1; i >= 1; i--) update(i);\n    }\n    // a[i] <- x\n    void set(int i, S\
    \ x) {\n        assert(0 <= i && i < _n);\n        i += size;\n        d[i] =\
    \ x;\n        for(int p = 1; p <= log; p++) update(i >> p);\n    }\n    // a[i]\n\
    \    S get(int i) {\n        assert(0 <= i && i < _n);\n        return d[i + size];\n\
    \    }\n    // [l, r)\n    S prod(int l, int r) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        S sml = monoid::id, smr = monoid::id;\n        l\
    \ += size, r += size;\n        while(l < r) {\n            if(l & 1) sml = monoid::op(sml,\
    \ d[l++]);\n            if(r & 1) smr = monoid::op(d[--r], smr);\n           \
    \ l >>= 1, r >>= 1;\n        }\n        return monoid::op(sml, smr);\n    }\n\
    \    S all_prod() { return d[1]; }\n    template < class func > int max_right(int\
    \ l, func f) {\n        assert(0 <= l && l <= _n);\n        assert(f(monoid::id));\n\
    \        if(l == _n) return _n;\n        l += size;\n        S sm = monoid::id;\n\
    \        do {\n            while(l % 2 == 0) l >>= 1;\n            if(!f(monoid::op(sm,\
    \ d[l]))) {\n                while(l < size) {\n                    l = 2 * l;\n\
    \                    if(f(monoid::op(sm, d[l]))) {\n                        sm\
    \ = monoid::op(sm, d[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - size;\n            }\n        \
    \    sm = monoid::op(sm, d[l]);\n            l++;\n        } while((l & -l) !=\
    \ l);\n        return _n;\n    }\n    template < class func > int min_left(int\
    \ r, func f) {\n        assert(0 <= r && r <= _n);\n        assert(f(monoid::id));\n\
    \        if(r == 0) return 0;\n        r += size;\n        S sm = monoid::id;\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!f(monoid::op(d[r], sm))) {\n                while(r < size) {\n\
    \                    r = 2 * r + 1;\n                    if(f(monoid::op(d[r],\
    \ sm))) {\n                        sm = monoid::op(d[r], sm);\n              \
    \          r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = monoid::op(d[r], sm);\n     \
    \   } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n,\
    \ size, log;\n    vector< S > d;\n    int ceil_pow2(int n) { int x = 0; while((1U\
    \ << x) < uint(n)) x++; return x; }\n    void update(int k) { d[k] = monoid::op(d[2\
    \ * k], d[2 * k + 1]); }\n};\n#line 1 \"src/algebra/affine.hpp\"\ntemplate < class\
    \ T > class affine {\n  public:\n    T a, b;\n    constexpr affine() = default;\n\
    \    constexpr affine(const T &a, const T &b) : a(a), b(b) {}\n    constexpr T\
    \ eval(const T &x) const { return x * a + b; }\n    constexpr affine composite(const\
    \ affine &r) const {\n        return affine(a * r.a, b * r.a + r.b);\n    }\n\
    \    static constexpr affine id() {\n        return affine(T(1), T(0));\n    }\n\
    };\n\ntemplate < class T > class affine_composite_monoid {\n  public:\n    using\
    \ F = affine< T >;\n    using set = F;\n    static constexpr F op(const F &l,\
    \ const F &r) { return l.composite(r); }\n    static constexpr F id = F::id();\n\
    };\ntemplate < class T > constexpr affine< T > affine_composite_monoid< T >::id;\n\
    #line 1 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root; };\ntemplate\
    \ < modinfo const &ref >\nstruct modint {\n    static constexpr uint const &mod\
    \ = ref.mod;\n    static modint root() { return modint(ref.root); }\n    uint\
    \ v = 0;\n    constexpr modint& s(uint v) { this->v = v < mod ? v : v - mod; return\
    \ *this; }\n    constexpr modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-()\
    \ const { return modint() - *this; }\n    modint& operator+=(const modint& rhs)\
    \ { return s(v + rhs.v); }\n    modint& operator-=(const modint& rhs) { return\
    \ s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v)\
    \ * rhs.v % mod; return *this; }\n    modint& operator/=(const modint& rhs) {\
    \ return *this *= rhs.inv(); }\n    modint operator+(const modint& rhs) const\
    \ { return modint(*this) += rhs; }\n    modint operator-(const modint& rhs) const\
    \ { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs) const\
    \ { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs) const\
    \ { return modint(*this) /= rhs; }\n    modint pow(ll n) const { modint res(1),\
    \ x(*this); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res;\
    \ }\n    modint inv() const { int a = v, b = mod, x = 1, y = 0, t; while(b > 0)\
    \ { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y); } return modint(x); }\n\
    \    // modint inv() const { return pow(mod - 2); }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n};\n\nconstexpr modinfo base { 998244353, 3 };\n\
    //constexpr modinfo base { 1000000007, 0 };\nusing mint = modint< base >;\n#line\
    \ 7 \"verify/library_checker/data_structure/segtree.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,Q; cin >> N >>\
    \ Q;\n    using F = affine<mint>;\n    vector< F > f(N);\n    rep(i,N) {\n   \
    \     mint a,b; cin >> a >> b;\n        f[i] = F(a, b);\n    }\n\n    segtree<\
    \ affine_composite_monoid<mint> > seg(f);\n    rep(_,Q) {\n        int t; cin\
    \ >> t;\n        if(t == 0) {\n            int p; mint c,d; cin >> p >> c >> d;\n\
    \            seg.set(p, F(c, d));\n        }\n\n        if(t == 1) {\n       \
    \     int l,r; mint x; cin >> l >> r >> x;\n            cout << seg.prod(l, r).eval(x)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/data_structure/segtree.hpp\"\
    \n#include \"src/algebra/affine.hpp\"\n#include \"src/number/modint.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int N,Q;\
    \ cin >> N >> Q;\n    using F = affine<mint>;\n    vector< F > f(N);\n    rep(i,N)\
    \ {\n        mint a,b; cin >> a >> b;\n        f[i] = F(a, b);\n    }\n\n    segtree<\
    \ affine_composite_monoid<mint> > seg(f);\n    rep(_,Q) {\n        int t; cin\
    \ >> t;\n        if(t == 0) {\n            int p; mint c,d; cin >> p >> c >> d;\n\
    \            seg.set(p, F(c, d));\n        }\n\n        if(t == 1) {\n       \
    \     int l,r; mint x; cin >> l >> r >> x;\n            cout << seg.prod(l, r).eval(x)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/data_structure/segtree.hpp
  - src/algebra/affine.hpp
  - src/number/modint.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/segtree.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 01:57:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/segtree.test.cpp
- /verify/verify/library_checker/data_structure/segtree.test.cpp.html
title: verify/library_checker/data_structure/segtree.test.cpp
---
