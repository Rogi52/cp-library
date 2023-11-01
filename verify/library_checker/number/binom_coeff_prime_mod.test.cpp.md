---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':question:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':question:'
    path: src/number/binom_mod.hpp
    title: src/number/binom_mod.hpp
  - icon: ':question:'
    path: src/number/runtime_modint.hpp
    title: src/number/runtime_modint.hpp
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
    \ if(a < b) { a = b; return true; } return false; }\ntemplate < class T, class\
    \ U > T ceil (T x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y);\
    \ }\ntemplate < class T, class U > T floor(T x, U y) { return (x > 0 ?       \
    \    x / y : (x - y + 1) / y); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate\
    \ < class T > struct itr_rep {\n    T i, d;\n    constexpr itr_rep(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr_rep(const T i, const T d) noexcept\
    \ : i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int\
    \ operator*() const noexcept { return i; }\n    constexpr bool operator!=(const\
    \ itr_rep x) const noexcept { return d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate\
    \ < class T > struct rep {\n    const itr_rep< T > s, t;\n    constexpr rep(const\
    \ T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept\
    \ : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const T d) noexcept\
    \ : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept { return s;\
    \ }\n    constexpr auto end  () const noexcept { return t; }\n};\n\ntemplate <\
    \ class T > struct revrep {\n    const itr_rep < T > s, t;\n    constexpr revrep(const\
    \ T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s,\
    \ const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end  () const\
    \ noexcept { return t; }\n};\n#line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer\
    \ */\nistream& operator>>(istream& is, i128& x) {\n    std::string s; is >> s;\n\
    \    int pm = (s[0] == '-');\n    x = 0;\n    for(int i : rep(pm, int(s.size())))\
    \ x = x * 10 + (s[i] - '0');\n    if(pm) x *= -1;\n    return is;\n}\nostream&\
    \ operator<<(ostream& os, const i128& x) {\n    if(x == 0) return os << '0';\n\
    \    i128 y = x;\n    if(y < 0) {\n        os << '-';\n        y *= -1;\n    }\n\
    \    std::vector<int> ny;\n    while(y > 0) {\n        ny.push_back(y % 10);\n\
    \        y /= 10;\n    }\n    for(int i : revrep(ny.size())) os << ny[i];\n  \
    \  return os;\n}\n\nnamespace scanner {\n    struct sca {\n        template <\
    \ class T > operator T() {\n            T s; std::cin >> s; return s;\n      \
    \  }\n    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n\
    \        template < class T > operator std::vector< T >() {\n            std::vector<\
    \ T > v(n);\n            for(T& x : v) std::cin >> x;\n            return v;\n\
    \        }\n    };\n    struct mat {\n        int h, w;\n        mat(int h, int\
    \ w) : h(h), w(w) {}\n        template < class T > operator std::vector< std::vector<\
    \ T > >() {\n            std::vector m(h, std::vector< T >(w));\n            for(std::vector<\
    \ T >& v : m) for(T& x : v) std::cin >> x;\n            return m;\n        }\n\
    \    };\n    struct speedup {\n        speedup() {\n            std::cin.tie(0);\n\
    \            std::ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n\
    }\nscanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) { std::cout << std::fixed\
    \ << std::setprecision(d); }\n    void flush() { std::cout.flush(); }\n}\n\ntemplate\
    \ < class T >\nostream& operator<<(ostream& os, const std::vector< T > a) {\n\
    \    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os\
    \ << ' '; }\n    return os;\n}\n\nint print() { std::cout << '\\n'; return 0;\
    \ }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t) {\n\
    \    std::cout << h; if(sizeof...(tail)) std::cout << ' ';\n    return print(std::forward<tail>(t)...);\n\
    }\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n = a.size();\n\
    \    for(int i : rep(n)) std::cout << a[i] << \"\\n\";\n    return 0;\n}\n\n\n\
    #line 2 \"src/utility/key_val.hpp\"\n\ntemplate < class K, class V >\nstruct key_val\
    \ {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) : key(key),\
    \ val(val) {}\n    template < std::size_t Index >\n    std::tuple_element_t< Index,\
    \ key_val >& get() {\n        if constexpr (Index == 0) return key;\n        if\
    \ constexpr (Index == 1) return val;\n    }\n};\n\nnamespace std {\n\ntemplate\
    \ < class K, class V > struct tuple_size < key_val< K, V > > : integral_constant<\
    \ size_t, 2 > {};\ntemplate < class K, class V > struct tuple_element < 0, key_val<\
    \ K, V > > { using type = K; };\ntemplate < class K, class V > struct tuple_element\
    \ < 1, key_val< K, V > > { using type = V; };\n\n}\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T > key_val< int, T > max_of(const vector< T >& a) {\n    int\
    \ i = std::max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class T > key_val< int, T > min_of(const vector< T >& a) {\n   \
    \ int i = std::min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class S, class T > S sum_of(const vector< T >& a) {\n    S sum =\
    \ 0;\n    for(const T x : a) sum += x;\n    return sum;\n}\ntemplate < class S,\
    \ class T > vector< S > freq_of(const vector< T >& a, T L, T R) {\n    vector<\
    \ S > res(R - L, S(0));\n    for(const T x : a) res[x - L] += 1;\n    return res;\n\
    }\ntemplate < class S, class T > struct prefix_sum {\n    vector< S > s;\n   \
    \ prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), S(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    S sum(int L, int R) { return s[R] - s[L]; }\n};\n#line 3 \"src/utility/heap.hpp\"\
    \n\ntemplate < class T > using heap_min = std::priority_queue< T, std::vector<\
    \ T >, std::greater< T > >;\ntemplate < class T > using heap_max = std::priority_queue<\
    \ T, std::vector< T >, std::less< T > >;\n\n#line 23 \"src/cp-template.hpp\"\n\
    \n#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate < class T, class F >\nT bin_search(T\
    \ ok, T ng, F& f) {\n    while(abs(ok - ng) > 1) {\n        T mid = (ok + ng)\
    \ / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate\
    \ < class T, class F >\nT bin_search_real(T ok, T ng, F& f, int step = 80) {\n\
    \    while(step--) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ok;\n}\n#line 2 \"src/algorithm/argsort.hpp\"\n\n\
    template < class T > std::vector< int > argsort(const std::vector< T > &a) {\n\
    \    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(), ids.end(),\
    \ 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n        return\
    \ a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n}\n#line\
    \ 1 \"src/number/runtime_modint.hpp\"\nstruct runtime_modint {\n  public:\n  \
    \  ll v = 0;\n    runtime_modint(ll v = 0) { s(v % get_mod() + get_mod()); }\n\
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
  timestamp: '2023-11-01 09:21:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/binom_coeff_prime_mod.test.cpp
- /verify/verify/library_checker/number/binom_coeff_prime_mod.test.cpp.html
title: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
---
