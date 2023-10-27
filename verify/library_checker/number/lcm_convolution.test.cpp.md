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
  - icon: ':x:'
    path: src/number/eratosthenes.hpp
    title: src/number/eratosthenes.hpp
  - icon: ':question:'
    path: src/number/modint.hpp
    title: modint
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"verify/library_checker/number/lcm_convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#line\
    \ 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\ntemplate < class T, class U > T ceil (T\
    \ x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate <\
    \ class T, class U > T floor(T x, U y) { return (x > 0 ?           x / y : (x\
    \ - y + 1) / y); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T\
    \ > struct itr_rep {\n    T i, d;\n    constexpr itr_rep(const T i) noexcept :\
    \ i(i), d(1) {}\n    constexpr itr_rep(const T i, const T d) noexcept : i(i),\
    \ d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int operator*()\
    \ const noexcept { return i; }\n    constexpr bool operator!=(const itr_rep x)\
    \ const noexcept { return d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class\
    \ T > struct rep {\n    const itr_rep< T > s, t;\n    constexpr rep(const T t)\
    \ noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept :\
    \ s(s), t(t) {}\n    constexpr rep(const T s, const T t, const T d) noexcept :\
    \ s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept { return s; }\n\
    \    constexpr auto end  () const noexcept { return t; }\n};\n\ntemplate < class\
    \ T > struct revrep {\n    const itr_rep < T > s, t;\n    constexpr revrep(const\
    \ T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s,\
    \ const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end  () const\
    \ noexcept { return t; }\n};\n#line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer\
    \ */\nistream& operator>>(istream& is, i128& x) {\n    std::string s; is >> s;\n\
    \    int pm = (s[0] == '-');\n    x = 0;\n    for(int i : rep(pm, int(s.size())))\
    \ x = x * 10 + (s[i] - '0');\n    if(pm) x *= -1;\n    return is;\n}\nostream&\
    \ operator<<(ostream& os, const i128& x) {\n    if(x == 0) return os << x;\n \
    \   i128 y = x;\n    if(y < 0) {\n        os << '-';\n        y *= -1;\n    }\n\
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
    \ 2 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root, isprime; };\n\
    template < modinfo const &ref >\nstruct modint {\n    static constexpr uint const\
    \ &mod = ref.mod;\n    static constexpr uint const &root = ref.root;\n    static\
    \ constexpr uint const &isprime = ref.isprime;\n    uint v = 0;\n    constexpr\
    \ modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this; }\n    constexpr\
    \ modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-() const { return\
    \ modint() - *this; }\n    modint& operator+=(const modint& rhs) { return s(v\
    \ + rhs.v); }\n    modint& operator-=(const modint& rhs) { return s(v + mod -\
    \ rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v %\
    \ mod; return *this; }\n    modint& operator/=(const modint& rhs) { return *this\
    \ *= inv(rhs); }\n    modint operator+(const modint& rhs) const { return modint(*this)\
    \ += rhs; }\n    modint operator-(const modint& rhs) const { return modint(*this)\
    \ -= rhs; }\n    modint operator*(const modint& rhs) const { return modint(*this)\
    \ *= rhs; }\n    modint operator/(const modint& rhs) const { return modint(*this)\
    \ /= rhs; }\n    friend modint pow(modint x, ll n) { modint res(1); while(n >\
    \ 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n    friend modint\
    \ inv(modint v) {\n        if(isprime) {\n            return pow(v, mod - 2);\n\
    \        } else {\n            ll a = v.v, b = modint::mod, x = 1, y = 0, t;\n\
    \            while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y);\
    \ }\n            return modint(x);\n        }\n    }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n    static uint get_mod() { return mod; }\n    static\
    \ int is_prime() { return isprime; }\n};\nconstexpr modinfo base998244353 { 998244353,\
    \ 3, 1 };\nconstexpr modinfo base1000000007 { 1000000007, 0, 1 };\nusing mint998244353\
    \ = modint< base998244353 >;\nusing mint1000000007 = modint< base1000000007 >;\n\
    #line 2 \"src/number/eratosthenes.hpp\"\n\nstruct Eratosthenes {\n    int N;\n\
    \    vector<int> isprime, primes, spf, mobius;\n    Eratosthenes(int N) : N(N),\
    \ isprime(N + 1, 1), spf(N + 1, -1), mobius(N + 1, 1) {\n        isprime[1] =\
    \ 0;\n        spf[1] = 1;\n        for(int n = 2; n <= N; n++) if(isprime[n])\
    \ {\n            primes.push_back(n);\n            spf[n] = n;\n            mobius[n]\
    \ = -1;\n            for(int m = n + n; m <= N; m += n) {\n                isprime[m]\
    \ = 0;\n                if(spf[m] == -1) spf[m] = n;\n                mobius[m]\
    \ = ((m / n) % n == 0 ? 0 : - mobius[m]);\n            }\n        }\n    }\n \
    \   vector<pair<int,int>> factorize(int n) {\n        assert(1 <= n and n <= N);\n\
    \        vector<pair<int,int>> res;\n        while(n > 1) {\n            int p\
    \ = spf[n], e = 0;\n            while(spf[n] == p) n /= p, e++;\n            res.push_back({p,\
    \ e});\n        }\n        return res;\n    }\n    vector<int> divisors(int n)\
    \ {\n        vector<int> res = {1};\n        auto pf = factorize(n);\n       \
    \ for(auto [p, e] : pf) {\n            for(int i : rep(res.size())) {\n      \
    \          int v = 1;\n                for(int j : rep(e)) {\n               \
    \     v *= p;\n                    res.push_back(res[i] * v);\n              \
    \  }\n            }\n        }\n        return res;\n    }\n    int euler_phi(int\
    \ n) {\n        assert(1 <= n and n <= N);\n        int res = n;\n        for(auto\
    \ [p, e] : factorize(n)) {\n            res /= p;\n            res *= p - 1;\n\
    \        }\n        return res;\n    }\n\n    template < class T >\n    void multiple_zeta(vector<\
    \ T >& a) {\n        int n = a.size() - 1;\n        assert(1 <= n and n <= N);\n\
    \        for(int p : primes) {\n            if(p <= n)\n                for(int\
    \ k = n / p; k > 0; k--) a[k] += a[k * p];\n            else\n               \
    \ break;\n        }\n    }\n    template < class T >\n    void multiple_mobius(vector<\
    \ T >& a) {\n        int n = a.size() - 1;\n        assert(1 <= n and n <= N);\n\
    \        for(int p : primes) {\n            if(p <= n)\n                for(int\
    \ k = 1; k * p <= n; k++) a[k] -= a[k * p];\n            else\n              \
    \  break;\n        }\n    }\n    template < class T >\n    void divisor_zeta(vector<\
    \ T >& a) {\n        int n = a.size() - 1;\n        assert(1 <= n and n <= N);\n\
    \        for(int p : primes) {\n            if(p <= n)\n                for(int\
    \ k = 1; k * p <= n; k++) a[k * p] += a[k];\n            else\n              \
    \  break;\n        }\n    }\n    template < class T >\n    void divisor_mobius(vector<\
    \ T >& a) {\n        int n = a.size() - 1;\n        assert(1 <= n and n <= N);\n\
    \        for(int p : primes) {\n            if(p <= n)\n                for(int\
    \ k = n / p; k > 0; k--) a[k * p] -= a[k];\n            else\n               \
    \ break;\n        }\n    }\n    template < class T >\n    vector< T > gcd_convolution(vector<\
    \ T > a, vector< T > b) {\n        int n = max(a.size(), b.size());\n        a.resize(n,\
    \ 0);\n        b.resize(n, 0);\n        multiple_zeta(a);\n        multiple_zeta(b);\n\
    \        vector< T > c(n);\n        for(int i : rep(n)) c[i] = a[i] * b[i];\n\
    \        multiple_mobius(c);\n        return c;\n    }\n    template < class T\
    \ >\n    vector< T > lcm_convolution(vector< T > a, vector< T > b) {\n       \
    \ int n = max(a.size(), b.size());\n        a.resize(n, 0);\n        b.resize(n,\
    \ 0);\n        divisor_zeta(a);\n        divisor_zeta(b);\n        vector< T >\
    \ c(n);\n        for(int i : rep(n)) c[i] = a[i] * b[i];\n        divisor_mobius(c);\n\
    \        return c;\n    }\n};\n#line 6 \"verify/library_checker/number/lcm_convolution.test.cpp\"\
    \n\nint main() {\n    int N = in();\n    using mint = mint998244353;\n    vector<mint>\
    \ a = in(N), b = in(N);\n    a.insert(a.begin(), 0);\n    b.insert(b.begin(),\
    \ 0);\n    vector<mint> c = Eratosthenes(N).lcm_convolution(a, b);\n    c.erase(c.begin());\n\
    \    print(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/number/modint.hpp\"\
    \n#include \"../../../src/number/eratosthenes.hpp\"\n\nint main() {\n    int N\
    \ = in();\n    using mint = mint998244353;\n    vector<mint> a = in(N), b = in(N);\n\
    \    a.insert(a.begin(), 0);\n    b.insert(b.begin(), 0);\n    vector<mint> c\
    \ = Eratosthenes(N).lcm_convolution(a, b);\n    c.erase(c.begin());\n    print(c);\n\
    }"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/number/modint.hpp
  - src/number/eratosthenes.hpp
  isVerificationFile: true
  path: verify/library_checker/number/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-10-28 05:38:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/number/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/lcm_convolution.test.cpp
- /verify/verify/library_checker/number/lcm_convolution.test.cpp.html
title: verify/library_checker/number/lcm_convolution.test.cpp
---
