---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/binom_mod.hpp
    title: src/number/binom_mod.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/runtime_modint.hpp
    title: src/number/runtime_modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/heap.hpp
    title: src/utility/heap.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"verify/library_checker/number/binom_coeff_prime_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\
    \ntemplate < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept :\
    \ i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int\
    \ operator*() const noexcept { return i; }\n    constexpr bool operator!=(const\
    \ itr x) const noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n\
    };\n\ntemplate < class T > struct rep {\n    const itr< T > s, t;\n    constexpr\
    \ rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const\
    \ T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const\
    \ T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n\n\
    template < class T > struct revrep {\n    const itr < T > s, t;\n    constexpr\
    \ revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
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
    }\n#line 1 \"src/number/runtime_modint.hpp\"\nstruct runtime_modint {\n  public:\n\
    \    ll v = 0;\n    runtime_modint(ll v = 0) { s(v % get_mod() + get_mod()); }\n\
    \    static void set_mod(ll m) { mod() = m; }\n    static void set_mod(ll m, int\
    \ isp) { mod() = m; prime() = isp; }\n    static ll get_mod() { return mod();\
    \ }\n    static int is_prime() { return prime(); }\n    using rtmint = runtime_modint;\n\
    \    rtmint& s(ll v) { this->v = v < get_mod() ? v : v - get_mod(); return *this;\
    \ }\n    rtmint operator-() const { return rtmint() - *this; }\n    rtmint& operator+=(const\
    \ rtmint& rhs) { return s(v + rhs.v); }\n    rtmint& operator-=(const rtmint&\
    \ rhs) { return s(v + get_mod() - rhs.v); }\n    rtmint& operator*=(const rtmint&\
    \ rhs) { v = ull(v) * rhs.v % get_mod(); return *this; }\n    rtmint& operator/=(const\
    \ rtmint& rhs) { return *this *= inv(rhs); }\n    rtmint operator+(const rtmint&\
    \ rhs) const { return rtmint(*this) += rhs; }\n    rtmint operator-(const rtmint&\
    \ rhs) const { return rtmint(*this) -= rhs; }\n    rtmint operator*(const rtmint&\
    \ rhs) const { return rtmint(*this) *= rhs; }\n    rtmint operator/(const rtmint&\
    \ rhs) const { return rtmint(*this) /= rhs; }\n    friend rtmint pow(rtmint x,\
    \ ll n) { rtmint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; }\
    \ return res; }\n    friend rtmint inv(rtmint v) {\n        if(prime()) {\n  \
    \          return pow(v, get_mod() - 2);\n        } else {\n            ll a =\
    \ v.v, b = get_mod(), x = 1, y = 0, t;\n            while(b > 0) { t = a / b;\
    \ swap(a -= t * b, b); swap(x -= t * y, y); }\n            return rtmint(x);\n\
    \        }\n    }\n    friend rtmint operator+(int x, const rtmint& y) { return\
    \ rtmint(x) + y; }\n    friend rtmint operator-(int x, const rtmint& y) { return\
    \ rtmint(x) - y; }\n    friend rtmint operator*(int x, const rtmint& y) { return\
    \ rtmint(x) * y; }\n    friend rtmint operator/(int x, const rtmint& y) { return\
    \ rtmint(x) / y; }\n    friend istream& operator>>(istream& is, rtmint& m) { ll\
    \ x; is >> x; m = rtmint(x); return is; }\n    friend ostream& operator<<(ostream&\
    \ os, const rtmint& m) { return os << m.v; }\n    bool operator==(const rtmint&\
    \ r) const { return v == r.v; }\n    bool operator!=(const rtmint& r) const {\
    \ return v != r.v; }\n  private:\n    static ll &mod() {\n        static ll mod_\
    \ = 0;\n        return mod_;\n    }\n    static int &prime() {\n        static\
    \ int prime_ = 0;\n        return prime_;\n    }\n};\n#line 2 \"src/number/binom_mod.hpp\"\
    \n\ntemplate < class mint >\nmint fact(int n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n\
    \    static const uint mod = mint::get_mod();\n    static std::vector<mint> data\
    \ = {1, 1};\n    while(int(data.size()) <= n) {\n        int i = data.size();\n\
    \        data.push_back(data.back() * i);\n    }\n    return data[n];\n}\n\ntemplate\
    \ < class mint >\nmint inv(int n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n\
    \    static const uint mod = mint::get_mod();\n    static std::vector<mint> data\
    \ = {1, 1};\n    while(int(data.size()) <= n) {\n        int i = data.size();\n\
    \        data.push_back(- data[mod % i] * (mod / i));\n    }\n    return data[n];\n\
    }\n\ntemplate < class mint >\nmint fact_inv(int n) {\n    assert(0 <= n);\n  \
    \  assert(mint::is_prime());\n    static const uint mod = mint::get_mod();\n \
    \   static std::vector<mint> data = {1, 1};\n    while(int(data.size()) <= n)\
    \ {\n        int i = data.size();\n        data.push_back(data.back() * inv<mint>(i));\n\
    \    }\n    return data[n];\n}\n\ntemplate < class mint >\nmint comb(int n, int\
    \ k) {\n    if(k < 0 or n < k) return 0;\n    return fact<mint>(n) * fact_inv<mint>(k)\
    \ * fact_inv<mint>(n - k);\n}\n\ntemplate < class mint >\nmint perm(int n, int\
    \ k) {\n    return fact<mint>(n) * fact_inv<mint>(n - k);\n}\n\ntemplate < class\
    \ mint >\nmint homo(int n, int k) {\n    return comb<mint>(n + k - 1, k);\n}\n\
    #line 6 \"verify/library_checker/number/binom_coeff_prime_mod.test.cpp\"\n\nint\
    \ main() {\n    int T = in(), m = in();\n    using mint = runtime_modint;\n  \
    \  mint::set_mod(m, 1);\n    for(int i : rep(T)) {\n        int n = in(), k =\
    \ in();\n        print(comb<mint>(n, k));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/number/runtime_modint.hpp\"\
    \n#include \"../../../src/number/binom_mod.hpp\"\n\nint main() {\n    int T =\
    \ in(), m = in();\n    using mint = runtime_modint;\n    mint::set_mod(m, 1);\n\
    \    for(int i : rep(T)) {\n        int n = in(), k = in();\n        print(comb<mint>(n,\
    \ k));\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/number/runtime_modint.hpp
  - src/number/binom_mod.hpp
  isVerificationFile: true
  path: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 23:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/binom_coeff_prime_mod.test.cpp
- /verify/verify/library_checker/number/binom_coeff_prime_mod.test.cpp.html
title: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
---
