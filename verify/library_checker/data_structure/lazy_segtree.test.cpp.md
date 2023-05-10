---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algebra/affine.hpp
    title: src/algebra/affine.hpp
  - icon: ':x:'
    path: src/algebra/cartesian_product_monoid.hpp
    title: src/algebra/cartesian_product_monoid.hpp
  - icon: ':question:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  - icon: ':x:'
    path: src/algebra/range_affine_range_sum.hpp
    title: src/algebra/range_affine_range_sum.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/data_structure/lazy_segtree.hpp
    title: src/data_structure/lazy_segtree.hpp
  - icon: ':question:'
    path: src/number/modint.hpp
    title: modint
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/lazy_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
    \ itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n\
    \    const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t)\
    \ {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
    \ < class T > operator T() {\n            T s; cin >> s; return s;\n        }\n\
    \    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n    \
    \    template < class T > operator vector< T >() {\n            vector< T > v(n);\n\
    \            for(T& x : v) cin >> x;\n            return v;\n        }\n    };\n\
    \    struct mat {\n        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n\
    \        template < class T > operator vector< vector< T > >() {\n           \
    \ vector m(h, vector< T >(w));\n            for(vector< T >& v : m) for(T& x :\
    \ v) cin >> x;\n            return m;\n        }\n    };\n    struct speedup {\n\
    \        speedup() {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n\
    \        }\n    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec\
    \ in(int n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return\
    \ scanner::mat(h, w); }\n\nnamespace printer {\n    void precision(int d) {\n\
    \        cout << fixed << setprecision(d);\n    }\n    void flush() {\n      \
    \  cout.flush();\n    }\n}\nint print() { cout << '\\n'; return 0; }\ntemplate\
    \ < class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 1 \"src/number/modint.hpp\"\nstruct modinfo\
    \ { uint mod, root, isprime; };\ntemplate < modinfo const &ref >\nstruct modint\
    \ {\n    static constexpr uint const &mod = ref.mod;\n    static constexpr uint\
    \ const &root = ref.root;\n    static constexpr uint const &isprime = ref.isprime;\n\
    \    uint v = 0;\n    constexpr modint& s(uint v) { this->v = v < mod ? v : v\
    \ - mod; return *this; }\n    constexpr modint(ll v = 0) { s(v % mod + mod); }\n\
    \    modint operator-() const { return modint() - *this; }\n    modint& operator+=(const\
    \ modint& rhs) { return s(v + rhs.v); }\n    modint& operator-=(const modint&\
    \ rhs) { return s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs)\
    \ { v = ull(v) * rhs.v % mod; return *this; }\n    modint& operator/=(const modint&\
    \ rhs) { return *this *= inv(rhs); }\n    modint operator+(const modint& rhs)\
    \ const { return modint(*this) += rhs; }\n    modint operator-(const modint& rhs)\
    \ const { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs)\
    \ const { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs)\
    \ const { return modint(*this) /= rhs; }\n    friend modint pow(modint x, ll n)\
    \ { modint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return\
    \ res; }\n    friend modint inv(modint v) {\n        if(isprime) {\n         \
    \   return pow(v, mod - 2);\n        } else {\n            ll a = v.v, b = modint::mod,\
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
    \ base1000000007 >;\n#line 1 \"src/data_structure/lazy_segtree.hpp\"\ntemplate\
    \ < class A > struct lazy_segtree {\n  public:\n    using V = typename A::value_structure;\n\
    \    using S = typename V::set;\n    using O = typename A::operator_structure;\n\
    \    using F = typename O::set;\n    int _n, size, log;\n    vector< S > d;\n\
    \    vector< F > lz;\n\n    void update(int k) { d[k] = V::op(d[2 * k], d[2 *\
    \ k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = A::op(d[k], f);\n\
    \        if(k < size) lz[k] = O::op(lz[k], f);\n    }\n    void push(int k) {\n\
    \        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n    \
    \    lz[k] = O::id;\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n \
    \       while((1U << x) < uint(n)) x++;\n        return x;\n    }\n\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    lazy_segtree(int n) : lazy_segtree(vector< S >(n,\
    \ S::id)) {}\n    lazy_segtree(const vector< S >& v) : _n(int(v.size())) {\n \
    \       log = ceil_pow2(_n);\n        size = 1 << log;\n        d = vector< S\
    \ >(2 * size, V::id);\n        lz = vector< F >(size, O::id);\n        for(int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >=\
    \ 1; i--) update(i);\n    }\n\n    void set(int i, S x) {\n        assert(0 <=\
    \ i && i < _n);\n        i += size;\n        for(int p = log; p >= 1; p--) push(i\
    \ >> p);\n        d[i] = x;\n        for(int p = 1; p <= log; p++) update(i >>\
    \ p);\n    }\n    S get(int i) {\n        assert(0 <= i && i < _n);\n        i\
    \ += size;\n        for(int p = log; p >= 1; p--) push(i >> p);\n        return\
    \ d[i];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if(l == r) return V::id;\n        l += size, r += size;\n\
    \        for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push(r >> i);\n        }\n\
    \        S sml = V::id, smr = V::id;\n        while(l < r) {\n            if(l\
    \ & 1) sml = V::op(sml, d[l++]);\n            if(r & 1) smr = V::op(d[--r], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return V::op(sml, smr);\n \
    \   }\n    S all_prod() { return d[1]; }\n    void apply(int i, F f) {\n     \
    \   assert(0 <= i && i < _n);\n        i += size;\n        for(int p = log; p\
    \ >= 1; p--) push(i >> p);\n        d[i] = O::op(d[i], f);\n        for(int p\
    \ = 1; p <= log; p++) update(i >> p);\n    }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n\
    \        l += size, r += size;\n        for(int i = log; i >= 1; i--) {\n    \
    \        if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while(l < r) {\n                if(l & 1) all_apply(l++, f);\n\
    \                if(r & 1) all_apply(--r, f);\n                l >>= 1, r >>=\
    \ 1;\n            }\n            l = l2, r = r2;\n        }\n        for(int i\
    \ = 1; i <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n\
    \            if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    template < class G > int max_right(int l, G g) {\n        assert(0 <= l &&\
    \ l <= _n);\n        assert(g(V::id));\n        if(l == _n) return _n;\n     \
    \   l += size;\n        for(int i = log; i >= 1; i--) push(l >> i);\n        S\
    \ sm = V::id();\n        do {\n            while(l % 2 == 0) l >>= 1;\n      \
    \      if(!g(V::op(sm, d[l]))) {\n                while(l < size) {\n        \
    \            push(l);\n                    l = 2 * l;\n                    if(g(V::op(sm,\
    \ d[l]))) {\n                        sm = V::op(sm, d[l]);\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = V::op(sm, d[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return _n;\n    }\n    template < class\
    \ G > int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n       \
    \ assert(g(V::id));\n        if(r == 0) return 0;\n        r += size;\n      \
    \  for(int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = V::id;\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!g(V::op(d[r], sm))) {\n                while(r < size) {\n  \
    \                  push(r);\n                    r = 2 * r + 1;\n            \
    \        if(g(V::op(d[r], sm))) {\n                        sm = V::op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = V::op(d[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n};\n#line 1\
    \ \"src/algebra/affine.hpp\"\ntemplate < class T > class affine {\n  public:\n\
    \    T a, b;\n    constexpr affine() = default;\n    constexpr affine(const T\
    \ &a, const T &b) : a(a), b(b) {}\n    constexpr T eval(const T &x) const { return\
    \ x * a + b; }\n    constexpr affine composite(const affine &r) const {\n    \
    \    return affine(a * r.a, b * r.a + r.b);\n    }\n    static constexpr affine\
    \ id() {\n        return affine(T(1), T(0));\n    }\n};\n\ntemplate < class T\
    \ > class affine_composite_monoid {\n  public:\n    using F = affine< T >;\n \
    \   using set = F;\n    static constexpr F op(const F &l, const F &r) { return\
    \ l.composite(r); }\n    static constexpr F id = F::id();\n};\ntemplate < class\
    \ T > constexpr affine< T > affine_composite_monoid< T >::id;\n#line 1 \"src/algebra/cartesian_product_monoid.hpp\"\
    \ntemplate < class M, class N > class cartesian_product_monoid {\n    using T\
    \ = pair< typename M::set, typename N::set >;\n  public:\n    using set = T;\n\
    \    static constexpr T op(const T &l, const T &r) {\n        return T(M::op(l.first,\
    \ r.first), N::op(l.second, r.second));\n    }\n    static constexpr T id{M::id,\
    \ N::id};\n};\n#line 1 \"src/algebra/plus.hpp\"\ntemplate < class T > class PLUS\
    \ {\n  public:\n    using set = T;\n    static constexpr T op(const T &l, const\
    \ T &r) { return l + r; }\n    static constexpr T id = T(0);\n    static constexpr\
    \ T inv(const T &x) { return -x; }\n    static constexpr T pow(const T &x, const\
    \ ll n) { return x * n; }\n    static constexpr bool comm = true;\n};\n#line 4\
    \ \"src/algebra/range_affine_range_sum.hpp\"\n\ntemplate < class T > class range_affine_range_sum\
    \ {\n  public:\n    using value_structure = cartesian_product_monoid< PLUS< T\
    \ >, PLUS< T > >;\n    using operator_structure = affine_composite_monoid< T >;\n\
    \  private:\n    using S = typename value_structure::set;\n    using F = typename\
    \ operator_structure::set;\n  public:\n    static constexpr S op(const S &l, const\
    \ F &r) {\n        return S(l.first * r.a + l.second * r.b, l.second);\n    }\n\
    };\n#line 7 \"verify/library_checker/data_structure/lazy_segtree.test.cpp\"\n\n\
    int main(){\n    \n    int N,Q; cin >> N >> Q;\n    using S = range_affine_range_sum<mint>::value_structure::set;\n\
    \    vector< S > a(N);\n    for(int i : rep(N)) {\n        mint x; cin >> x;\n\
    \        a[i] = S{x, 1};\n    }\n\n    lazy_segtree< range_affine_range_sum<mint>\
    \ > lzst(a);\n    for(int _ : rep(Q)) {\n        int t; cin >> t;\n        if(t\
    \ == 0) {\n            int l,r; mint b,c; cin >> l >> r >> b >> c;\n         \
    \   lzst.apply(l, r, {b, c});\n        }\n\n        if(t == 1) {\n           \
    \ int l,r; cin >> l >> r;\n            cout << lzst.prod(l, r).first << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/number/modint.hpp\"\n#include\
    \ \"src/data_structure/lazy_segtree.hpp\"\n#include \"src/algebra/range_affine_range_sum.hpp\"\
    \n\nint main(){\n    \n    int N,Q; cin >> N >> Q;\n    using S = range_affine_range_sum<mint>::value_structure::set;\n\
    \    vector< S > a(N);\n    for(int i : rep(N)) {\n        mint x; cin >> x;\n\
    \        a[i] = S{x, 1};\n    }\n\n    lazy_segtree< range_affine_range_sum<mint>\
    \ > lzst(a);\n    for(int _ : rep(Q)) {\n        int t; cin >> t;\n        if(t\
    \ == 0) {\n            int l,r; mint b,c; cin >> l >> r >> b >> c;\n         \
    \   lzst.apply(l, r, {b, c});\n        }\n\n        if(t == 1) {\n           \
    \ int l,r; cin >> l >> r;\n            cout << lzst.prod(l, r).first << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/number/modint.hpp
  - src/data_structure/lazy_segtree.hpp
  - src/algebra/range_affine_range_sum.hpp
  - src/algebra/affine.hpp
  - src/algebra/cartesian_product_monoid.hpp
  - src/algebra/plus.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/lazy_segtree.test.cpp
- /verify/verify/library_checker/data_structure/lazy_segtree.test.cpp.html
title: verify/library_checker/data_structure/lazy_segtree.test.cpp
---
