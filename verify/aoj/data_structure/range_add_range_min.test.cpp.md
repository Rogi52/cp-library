---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/minmax.hpp
    title: src/algebra/minmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/range_add_range_minmax.hpp
    title: src/algebra/range_add_range_minmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/sum.hpp
    title: src/algebra/sum.hpp
  - icon: ':question:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':question:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/lazy_segtree.hpp
    title: src/data_structure/lazy_segtree.hpp
  - icon: ':question:'
    path: src/utility/heap.hpp
    title: src/utility/heap.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':question:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
  bundledCode: "#line 1 \"verify/aoj/data_structure/range_add_range_min.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H\"\n\n#line\
    \ 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\n\
    template < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept\
    \ : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d)\
    \ {}\n    void operator++() noexcept { i += d; }\n    constexpr int operator*()\
    \ const noexcept { return i; }\n    constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate\
    \ < class T > struct rep {\n    const itr< T > s, t;\n    constexpr rep(const\
    \ T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept\
    \ : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const T d) noexcept\
    \ : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept { return s;\
    \ }\n    constexpr auto end() const noexcept { return t; }\n};\n\ntemplate < class\
    \ T > struct revrep {\n    const itr < T > s, t;\n    constexpr revrep(const T\
    \ t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const\
    \ T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T\
    \ s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n   \
    \ struct sca {\n        template < class T > operator T() {\n            T s;\
    \ cin >> s; return s;\n        }\n    };\n    struct vec {\n        int n;\n \
    \       vec(int n) : n(n) {}\n        template < class T > operator vector< T\
    \ >() {\n            vector< T > v(n);\n            for(T& x : v) cin >> x;\n\
    \            return v;\n        }\n    };\n    struct mat {\n        int h,w;\n\
    \        mat(int h, int w) : h(h), w(w) {}\n        template < class T > operator\
    \ vector< vector< T > >() {\n            vector m(h, vector< T >(w));\n      \
    \      for(vector< T >& v : m) for(T& x : v) cin >> x;\n            return m;\n\
    \        }\n    };\n    struct speedup {\n        speedup() {\n            cin.tie(0);\n\
    \            ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n}\n\
    scanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) {\n        cout << fixed\
    \ << setprecision(d);\n    }\n    void flush() {\n        cout.flush();\n    }\n\
    }\n\ntemplate < class T >\nostream& operator<<(ostream& os, const std::vector<\
    \ T > a) {\n    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i\
    \ != n - 1) os << ' '; }\n    return os;\n}\n\nint print() { cout << '\\n'; return\
    \ 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t)\
    \ {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\n\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n =\
    \ a.size();\n    for(int i : rep(n)) cout << a[i] << \"\\n\";\n    return 0;\n\
    }\n#line 2 \"src/utility/key_val.hpp\"\ntemplate < class K, class V >\nstruct\
    \ key_val {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) :\
    \ key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\ntemplate < class\
    \ T >\nkey_val< int, T > max_of(const vector< T >& a) {\n    int i = max_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nkey_val<\
    \ int, T > min_of(const vector< T >& a) {\n    int i = min_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nT sum_of(const\
    \ vector< T >& a) {\n    T sum = 0;\n    for(const T x : a) sum += x;\n    return\
    \ sum;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector< T >& a, T\
    \ L, T R) {\n    vector<int> res(R - L);\n    for(const T x : a) res[x - L]++;\n\
    \    return res;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector<\
    \ T >& a, T R) {\n    return freq_of(a, T(0), R);\n}\n\ntemplate < class T >\n\
    struct prefix_sum {\n    vector< T > s;\n    prefix_sum(const vector< T >& a)\
    \ : s(a) {\n        s.insert(s.begin(), T(0));\n        for(int i : rep(a.size()))\
    \ s[i + 1] += s[i];\n    }\n    // [L, R)\n    T sum(int L, int R) {\n       \
    \ return s[R] - s[L];\n    }\n};\n#line 3 \"src/utility/heap.hpp\"\n\ntemplate\
    \ < class T > using heap_min = std::priority_queue< T, std::vector< T >, std::greater<\
    \ T > >;\ntemplate < class T > using heap_max = std::priority_queue< T, std::vector<\
    \ T >, std::less< T > >;\n\n#line 21 \"src/cp-template.hpp\"\n\n#line 1 \"src/algorithm/bin_search.hpp\"\
    \ntemplate < class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok\
    \ - ng) > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line\
    \ 2 \"src/algorithm/argsort.hpp\"\n\ntemplate < class T > std::vector< int > argsort(const\
    \ std::vector< T > &a) {\n    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n\
    \        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n\
    }\n#line 1 \"src/data_structure/lazy_segtree.hpp\"\ntemplate < class A > struct\
    \ lazy_segtree {\n  public:\n    using V = typename A::value_structure;\n    using\
    \ S = typename V::set;\n    using O = typename A::operator_structure;\n    using\
    \ F = typename O::set;\n    int _n, size, log;\n    vector< S > d;\n    vector<\
    \ F > lz;\n\n    void update(int k) { d[k] = V::op(d[2 * k], d[2 * k + 1]); }\n\
    \    void all_apply(int k, F f) {\n        d[k] = A::op(d[k], f);\n        if(k\
    \ < size) lz[k] = O::op(lz[k], f);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = O::id();\n\
    \    }\n    int ceil_pow2(int n) {\n        int x = 0;\n        while((1U << x)\
    \ < uint(n)) x++;\n        return x;\n    }\n\n    lazy_segtree() : lazy_segtree(0)\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(vector< S >(n, S::id())) {}\n   \
    \ lazy_segtree(int n, S s) : lazy_segtree(vector< S >(n, s)) {}\n    lazy_segtree(const\
    \ vector< S >& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n      \
    \  size = 1 << log;\n        d = vector< S >(2 * size, V::id());\n        lz =\
    \ vector< F >(size, O::id());\n        for(int i = 0; i < _n; i++) d[size + i]\
    \ = v[i];\n        for(int i = size - 1; i >= 1; i--) update(i);\n    }\n\n  \
    \  void set(int i, S x) {\n        assert(0 <= i && i < _n);\n        i += size;\n\
    \        for(int p = log; p >= 1; p--) push(i >> p);\n        d[i] = x;\n    \
    \    for(int p = 1; p <= log; p++) update(i >> p);\n    }\n    S get(int i) {\n\
    \        assert(0 <= i && i < _n);\n        i += size;\n        for(int p = log;\
    \ p >= 1; p--) push(i >> p);\n        return d[i];\n    }\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return\
    \ V::id();\n        l += size, r += size;\n        for(int i = log; i >= 1; i--)\
    \ {\n            if(((l >> i) << i) != l) push(l >> i);\n            if(((r >>\
    \ i) << i) != r) push(r >> i);\n        }\n        S sml = V::id(), smr = V::id();\n\
    \        while(l < r) {\n            if(l & 1) sml = V::op(sml, d[l++]);\n   \
    \         if(r & 1) smr = V::op(d[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n        return V::op(sml, smr);\n    }\n    S all_prod() { return\
    \ d[1]; }\n    void apply(int i, F f) {\n        assert(0 <= i && i < _n);\n \
    \       i += size;\n        for(int p = log; p >= 1; p--) push(i >> p);\n    \
    \    d[i] = O::op(d[i], f);\n        for(int p = 1; p <= log; p++) update(i >>\
    \ p);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        if(l == r) return;\n        l += size, r += size;\n\
    \        for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1) >> i);\n  \
    \      }\n        {\n            int l2 = l, r2 = r;\n            while(l < r)\
    \ {\n                if(l & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r,\
    \ f);\n                l >>= 1, r >>= 1;\n            }\n            l = l2, r\
    \ = r2;\n        }\n        for(int i = 1; i <= log; i++) {\n            if(((l\
    \ >> i) << i) != l) update(l >> i);\n            if(((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n    template < class G > int max_right(int l,\
    \ G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(V::id()));\n  \
    \      if(l == _n) return _n;\n        l += size;\n        for(int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = V::id()();\n        do {\n        \
    \    while(l % 2 == 0) l >>= 1;\n            if(!g(V::op(sm, d[l]))) {\n     \
    \           while(l < size) {\n                    push(l);\n                \
    \    l = 2 * l;\n                    if(g(V::op(sm, d[l]))) {\n              \
    \          sm = V::op(sm, d[l]);\n                        l++;\n             \
    \       }\n                }\n                return l - size;\n            }\n\
    \            sm = V::op(sm, d[l]);\n            l++;\n        } while((l & -l)\
    \ != l);\n        return _n;\n    }\n    template < class G > int min_left(int\
    \ r, G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(V::id()));\n\
    \        if(r == 0) return 0;\n        r += size;\n        for(int i = log; i\
    \ >= 1; i--) push((r - 1) >> i);\n        S sm = V::id();\n        do {\n    \
    \        r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n            if(!g(V::op(d[r],\
    \ sm))) {\n                while(r < size) {\n                    push(r);\n \
    \                   r = 2 * r + 1;\n                    if(g(V::op(d[r], sm)))\
    \ {\n                        sm = V::op(d[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = V::op(d[r], sm);\n        } while((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n#line 3 \"src/algebra/minmax.hpp\"\n\ntemplate\
    \ < class T > class min_monoid {\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T &l, const T &r) { return std::min(l, r); }\n    static constexpr\
    \ T id() { return std::numeric_limits< T >::max(); }\n    static constexpr bool\
    \ comm = true;\n};\n\ntemplate < class T > class max_monoid {\n  public:\n   \
    \ using set = T;\n    static constexpr T op(const T &l, const T &r) { return std::max(l,\
    \ r); }\n    static constexpr T id() { return std::numeric_limits< T >::min();\
    \ }\n    static constexpr bool comm = true;\n};\n#line 1 \"src/algebra/sum.hpp\"\
    \ntemplate < class T > class sum_monoid {\n  public:\n    using set = T;\n   \
    \ static constexpr T op(const T &l, const T &r) { return l + r; }\n    static\
    \ constexpr T id() { return T(0); }\n    static constexpr T inv(const T &x) {\
    \ return -x; }\n    static constexpr T pow(const T &x, const ll n) { return x\
    \ * n; }\n    static constexpr bool comm = true;\n};\n#line 5 \"src/algebra/range_add_range_minmax.hpp\"\
    \n\ntemplate < class T > class range_add_range_min {\n  public:\n    using value_structure\
    \ = min_monoid< T >;\n    using operator_structure = sum_monoid< T >;\n  private:\n\
    \    using S = typename value_structure::set;\n    using F = typename operator_structure::set;\n\
    \  public:\n    static constexpr S op(const S& l, const F& r) {\n        return\
    \ S(l + r);\n    }\n};\n\ntemplate < class T > class range_add_range_max {\n \
    \ public:\n    using value_structure = max_monoid< T >;\n    using operator_structure\
    \ = sum_monoid< T >;\n  private:\n    using S = typename value_structure::set;\n\
    \    using F = typename operator_structure::set;\n  public:\n    static constexpr\
    \ S op(const S& l, const F& r) {\n        return S(l + r);\n    }\n};\n#line 6\
    \ \"verify/aoj/data_structure/range_add_range_min.test.cpp\"\n\nint main() {\n\
    \    int n = in(), q = in();\n    lazy_segtree<range_add_range_min<int>> st(n,\
    \ 0);\n    for(int _q : rep(q)) {\n        int type = in();\n        if(type ==\
    \ 0) {\n            int s = in(), t = in(), x = in(); t++;\n            st.apply(s,\
    \ t, x);\n        }\n        if(type == 1) {\n            int s = in(), t = in();\
    \ t++;\n            print(st.prod(s, t));\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H\"\n\n\
    #include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/lazy_segtree.hpp\"\
    \n#include \"../../../src/algebra/range_add_range_minmax.hpp\"\n\nint main() {\n\
    \    int n = in(), q = in();\n    lazy_segtree<range_add_range_min<int>> st(n,\
    \ 0);\n    for(int _q : rep(q)) {\n        int type = in();\n        if(type ==\
    \ 0) {\n            int s = in(), t = in(), x = in(); t++;\n            st.apply(s,\
    \ t, x);\n        }\n        if(type == 1) {\n            int s = in(), t = in();\
    \ t++;\n            print(st.prod(s, t));\n        }\n    }\n\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/lazy_segtree.hpp
  - src/algebra/range_add_range_minmax.hpp
  - src/algebra/minmax.hpp
  - src/algebra/sum.hpp
  isVerificationFile: true
  path: verify/aoj/data_structure/range_add_range_min.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/data_structure/range_add_range_min.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/data_structure/range_add_range_min.test.cpp
- /verify/verify/aoj/data_structure/range_add_range_min.test.cpp.html
title: verify/aoj/data_structure/range_add_range_min.test.cpp
---
