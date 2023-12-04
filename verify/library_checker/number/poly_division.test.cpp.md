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
  - icon: ':heavy_check_mark:'
    path: src/number/binom_mod.hpp
    title: src/number/binom_mod.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/fps.hpp
    title: src/number/fps.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/modfunc.hpp
    title: src/number/modfunc.hpp
  - icon: ':question:'
    path: src/number/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: src/number/ntt.hpp
    title: src/number/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: src/number/poly.hpp
    title: src/number/poly.hpp
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
    path: src/utility/random.hpp
    title: src/utility/random.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "#line 1 \"verify/library_checker/number/poly_division.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\n\n\
    #line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\ntemplate < class T, class U > T ceil (T\
    \ x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate <\
    \ class T, class U > T floor(T x, U y) { return (x > 0 ?           x / y : (x\
    \ - y + 1) / y); }\nint popcnt(i32 x) { return __builtin_popcount(x); }\nint popcnt(u32\
    \ x) { return __builtin_popcount(x); }\nint popcnt(i64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\
    \ntemplate < class T > struct itr_rep {\n    T i, d;\n    constexpr itr_rep(const\
    \ T i) noexcept : i(i), d(1) {}\n    constexpr itr_rep(const T i, const T d) noexcept\
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
    \ T, std::vector< T >, std::less< T > >;\n\n#line 27 \"src/cp-template.hpp\"\n\
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
    #line 3 \"src/number/ntt.hpp\"\nnamespace ntt {\n\ntemplate < class mint >\nvoid\
    \ trans(vector<mint>& v, bool is_inv) {\n    if(v.empty()) return;\n    int n\
    \ = v.size();\n    uint mod = mint::mod, root = mint::root;\n    static bool first\
    \ = true;\n    static vector<ll> vbw(30), vibw(30);\n    if(first) {\n       \
    \ first = false;\n        for(int k : rep(30)) {\n            vbw[k] = pow(mint(root),\
    \ (mod - 1) >> (k + 1)).v;\n            vibw[k] = inv(mint(vbw[k])).v;\n     \
    \   }\n    }\n    for(int i = 0, j = 1; j < n - 1; j++) {\n        for(int k =\
    \ n >> 1; k > (i ^= k); k >>= 1);\n        if(i > j) swap(v[i], v[j]);\n    }\n\
    \    for(int k = 0, t = 2; t <= n; ++k, t <<= 1) {\n        mint bw = (is_inv\
    \ ? vibw[k] : vbw[k]);\n        for (int i = 0; i < n; i += t) {\n           \
    \ mint w = 1;\n            for (int j = 0; j < t / 2; ++j) {\n               \
    \ int j1 = i + j, j2 = i + j + t/2;\n                mint c1 = v[j1], c2 = v[j2]\
    \ * w;\n                v[j1] = c1 + c2;\n                v[j2] = c1 - c2;\n \
    \               w *= bw;\n            }\n        }\n    }\n    if(is_inv) {\n\
    \        mint iv = inv(mint(n));\n        for(int i : rep(n)) v[i] *= iv;\n  \
    \  }\n}\ntemplate < class mint > void ntt(vector<mint>& v) { trans(v, false);\
    \ }\ntemplate < class mint > void intt(vector<mint>& v) { trans(v, true); }\n\n\
    // for garner\nconstexpr modinfo base0 { 754974721, 11, 1};\nconstexpr modinfo\
    \ base1 { 167772161,  3, 1};\nconstexpr modinfo base2 { 469762049,  3, 1};\nusing\
    \ mint0 = modint< base0 >;\nusing mint1 = modint< base1 >;\nusing mint2 = modint<\
    \ base2 >;\nstatic const mint1 imod0  =  95869806; // MOD0^-1 mod MOD1\nstatic\
    \ const mint2 imod1  = 104391568; // MOD1^^1 mod MOD2\nstatic const mint2 imod01\
    \ = 187290749; // imod1 / MOD0;\n\ntemplate < class T >\nvector< T > naive(const\
    \ vector< T >& a, const vector< T >& b) {\n    if(a.empty() || b.empty()) return\
    \ {};\n    int n = a.size(), m = b.size();\n    vector< T > c(n + m - 1);\n  \
    \  for(int i : rep(n)) for(int j : rep(m)) c[i + j] += a[i] * b[j];\n    return\
    \ c;\n}\n\ntemplate < class mint >\nvector<mint> mul(const vector<mint>& a, const\
    \ vector<mint>& b) {\n    if(a.empty() || b.empty()) return {};\n    int n = a.size(),\
    \ m = b.size();\n    if(min(n, m) < 30) return naive(a, b);\n    uint mod = mint::mod;\n\
    \n    int sz = [&]() {\n        int n2 = 1, m2 = 1;\n        while(n2 < n) n2\
    \ <<= 1;\n        while(m2 < m) m2 <<= 1;\n        return max(n2, m2) << 1;\n\
    \    }();\n\n    if(mod == 998244353) {\n        vector<mint> a2(sz, 0), b2(sz,\
    \ 0), c(sz, 0);\n        for(int i : rep(n)) a2[i] = a[i];\n        for(int i\
    \ : rep(m)) b2[i] = b[i];\n        ntt(a2), ntt(b2);\n        for(int i : rep(sz))\
    \ c[i] = a2[i] * b2[i];\n        intt(c);\n        c.resize(n + m - 1);\n    \
    \    return c;\n    }\n\n    vector<mint0> a0(sz, 0), b0(sz, 0), c0(sz, 0);\n\
    \    vector<mint1> a1(sz, 0), b1(sz, 0), c1(sz, 0);\n    vector<mint2> a2(sz,\
    \ 0), b2(sz, 0), c2(sz, 0);\n    for(int i : rep(n)) a0[i].v = a1[i].v = a2[i].v\
    \ = a[i].v;\n    for(int i : rep(m)) b0[i].v = b1[i].v = b2[i].v = b[i].v;\n \
    \   ntt(a0), ntt(b0), ntt(a1), ntt(b1), ntt(a2), ntt(b2);\n    for(int i : rep(sz))\
    \ {\n        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] * b1[i];\n        c2[i]\
    \ = a2[i] * b2[i];\n    }\n    intt(c0), intt(c1), intt(c2);\n    \n    vector<mint>\
    \ c(n + m - 1);\n    static const mint mod0 = mint0::mod, mod01 = mod0 * mint1::mod;\n\
    \    for(int i : rep(n + m - 1)) {\n        ll y0 = c0[i].v;\n        ll y1 =\
    \ (imod0 * (c1[i] - y0)).v;\n        ll y2 = (imod01 * (c2[i] - y0) - imod1 *\
    \ y1).v;\n        c[i] = mod01 * y2 + mod0 * y1 + y0;\n    }\n    return c;\n\
    }\n\n} // namespace ntt\n#line 3 \"src/utility/random.hpp\"\n\nnamespace randnum\
    \ {\n\nstatic uint seed;\nstatic std::mt19937 mt;\nstruct gen_seed {\n    gen_seed()\
    \ {\n        seed = std::random_device()();\n        mt = std::mt19937(seed);\n\
    \    }\n} gs;\n\n// [L, R)\ntemplate < class T >\nT gen_int(T L, T R) {\n    return\
    \ std::uniform_int_distribution< T >(L, R - 1)(mt);\n}\n\ntemplate < class T >\n\
    T get_real(T L, T R) {\n    return std::uniform_real_distribution< T >(L, R)(mt);\n\
    }\n\n}\n#line 4 \"src/number/modfunc.hpp\"\n\nu64 modpow64(u64 a, u64 n, u64 mod)\
    \ {\n    a %= mod;\n    u64 res = 1;\n    while(n > 0) {\n        if(n % 2 ==\
    \ 1) res = i128(res) * a % mod;\n        a = i128(a) * a % mod;\n        n /=\
    \ 2;\n    }\n    return res;\n}\n\nu64 modpow(u64 a, u64 n, u64 mod) {\n    a\
    \ %= mod;\n    u64 res = 1;\n    while(n > 0) {\n        if(n % 2 == 1) res =\
    \ res * a % mod;\n        a = a * a % mod;\n        n /= 2;\n    }\n    return\
    \ res;\n}\n\n// solve x^2 = a (mod p)\n// return x\n// or No Solution (-1)\ni32\
    \ modsqrt(i32 a, i32 p) {\n    if(p == 2) return a;\n    a %= p;\n    if(a ==\
    \ 0) return 0;\n    if(modpow(a, (p - 1) / 2, p) != 1) return -1;\n    i32 q =\
    \ p - 1, m = 0; while(q % 2 == 0) q /= 2, m++;\n    i32 z; do { z = randnum::gen_int<i32>(1,\
    \ p); } while(modpow(z, (p - 1) / 2, p) != p - 1);\n    i64 c = modpow(z, q, p),\
    \ t = modpow(a, q, p), r = modpow(a, (q + 1) / 2, p);\n    while(m > 1) {\n  \
    \      if(modpow(t, 1 << (m - 2), p) != 1) r = r * c % p, t = t * (c * c % p)\
    \ % p;\n        c = c * c % p;\n        m -= 1;\n    }\n    return r;\n}\n#line\
    \ 5 \"src/number/fps.hpp\"\n\nclass undefined {};\ntemplate < class mint > struct\
    \ fps : std::vector<mint> {\n    using std::vector<mint>::vector;\n    fps(const\
    \ std::vector<mint>& f) : std::vector<mint>(f) {}\n    int size() const { return\
    \ int(std::vector<mint>::size()); }\n    void ups(int s) { if(size() < s) this->resize(s,\
    \ 0); }\n    fps low(int s) const {\n        return fps(this->begin(), this->begin()\
    \ + min(this->size(), s));\n    }\n    fps rev() const {\n        return fps(this->rbegin(),\
    \ this->rend());\n    }\n    fps operator-() const {\n        fps g = *this;\n\
    \        for(int i : rep(g.size())) g[i] = -g[i];\n        return g;\n    }\n\
    \    fps operator+(const mint& v) const { return fps(*this) += v; }\n    fps operator-(const\
    \ mint& v) const { return fps(*this) -= v; }\n    fps operator*(const mint& v)\
    \ const { return fps(*this) *= v; }\n    fps operator/(const mint& v) const {\
    \ return fps(*this) /= v; }\n    fps operator+(const fps& r) const { return fps(*this)\
    \ += r; }\n    fps operator-(const fps& r) const { return fps(*this) -= r; }\n\
    \    fps operator*(const fps& r) const { return fps(*this) *= r; }\n    fps operator/(const\
    \ fps& r) const { return fps(*this) /= r; }\n    fps operator<<(int s) const {\
    \ return fps(*this) <<= s; }\n    fps operator>>(int s) const { return fps(*this)\
    \ >>= s; }\n    fps& operator+=(const fps& r) { ups(r.size()); for(int i : rep(r.size()))\
    \ (*this)[i] += r[i]; return *this; }\n    fps& operator-=(const fps& r) { ups(r.size());\
    \ for(int i : rep(r.size())) (*this)[i] -= r[i]; return *this; }\n    fps& operator*=(const\
    \ fps& r) { return *this = ntt::mul(*this, r); } // ntt\n    fps& operator/=(const\
    \ fps& r) { return *this *= inv(r); }\n    template < class T > fps& operator+=(T\
    \ v) { ups(1); (*this)[0] += v; return *this; }\n    template < class T > fps&\
    \ operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }\n    template < class\
    \ T > fps& operator*=(T v) { for(auto &x : *this) x *= v; return *this; }\n  \
    \  template < class T > fps& operator/=(T v) { assert(v != T(0)); return *this\
    \ *= mint(1) / v; }\n\n    fps& operator<<=(int s) {\n        fps g(s, 0);\n \
    \       g.insert(g.end(), this->begin(), this->end());\n        return *this =\
    \ g;\n    }\n    fps& operator>>=(int s) {\n        return *this = {this->begin()\
    \ + s, this->end()};\n    }\n    friend fps differential(const fps& f) {\n   \
    \     int n = f.size();\n        fps g(n - 1);\n        for(int i : rep(1, n))\
    \ g[i - 1] = f[i] * i;\n        return g;\n    }\n    friend fps integral_(const\
    \ fps& f) { // std \u3068\u885D\u7A81\n        int n = f.size();\n        fps\
    \ g(n + 1, 0);\n        for(int i : rep(0, n)) g[i + 1] = f[i] / (i + 1);\n  \
    \      return g;\n    }\n    friend fps inv(const fps& f, int deg) {\n       \
    \ assert(f[0] != 0);\n        fps g = {mint(1) / f[0]};\n        for(int i = 1;\
    \ i < deg; i <<= 1) {\n            g = (g + g - g * g * f.low(i << 1)).low(i <<\
    \ 1);\n        }\n        g.resize(deg);\n        return g;\n    }\n    friend\
    \ fps log(const fps& f, int deg) {\n        assert(f[0] == 1);\n        fps g\
    \ = integral_((differential(f) * inv(f, deg)));\n        g.resize(deg);\n    \
    \    return g;\n    }\n    friend fps exp(const fps& f, int deg) {\n        assert(f[0]\
    \ == 0);\n        fps g = {1};\n        for(int i = 1; i < deg; i <<= 1) {\n \
    \           g = g * (f.low(i << 1) - log(g, i << 1) + 1).low(i << 1);\n      \
    \  }\n        g.resize(deg);\n        return g;\n    }\n    friend fps pow(const\
    \ fps& f, ll n, int deg) {\n        if(n == 0) {\n            fps g(deg, 0);\n\
    \            g[0] = 1;\n            return g;\n        }\n        int i = 0;\n\
    \        while(i < f.size() and f[i] == 0) i++;\n        if(i == f.size() or i128(i)\
    \ * n >= deg) return fps(deg, 0);\n        mint k = f[i];\n        fps g = exp(log((f\
    \ >> i) / k, deg) * n, deg) * pow(k, n) << (i * n);\n        g.resize(deg);\n\
    \        return g;\n    }\n    friend fps sqrt(const fps& f, int deg) {\n    \
    \    int n = f.size(), d = n;\n        for(int i : revrep(0, n)) if(f[i] != 0)\
    \ d = i;\n        if(d == n) return f;\n        if(d % 2 == 1) throw undefined();\n\
    \        mint y = f[d], x = modsqrt(y.v, mint::get_mod());\n        if(x * x !=\
    \ y) throw undefined();\n        mint c = mint(1) / y;\n        fps g(n - d);\n\
    \        for(int i : rep(n - d)) g[i] = f[d + i] * c;\n        \n        assert(g[0]\
    \ == 1);\n        mint inv2 = mint(1) / 2;\n        fps h = {1};\n        for(int\
    \ i = 1; i < deg; i <<= 1) {\n            h = (h + g.low(i << 1) * inv(h, i <<\
    \ 1)).low(i << 1);\n            for(mint& a : h) a *= inv2;\n        }\n     \
    \   h.resize(deg);\n\n        for(int i : rep(deg)) h[i] *= x;\n        for(int\
    \ i : revrep(deg)) h[i] = (i >= d / 2 ? h[i - d / 2] : 0);\n        return h;\n\
    \    }\n\n    friend fps inv(const fps& f) { return inv(f, f.size()); }\n    friend\
    \ fps log(const fps& f) { return log(f, f.size()); }\n    friend fps exp(const\
    \ fps& f) { return exp(f, f.size()); }\n    friend fps pow(const fps& f, ll n)\
    \ { return pow(f, n, f.size()); }\n    friend fps sqrt(const fps& f) { return\
    \ sqrt(f, f.size()); }\n\n    fps operator() (const fps<mint>& g) {\n        fps<mint>&\
    \ f = *this;\n        assert(f.size() == g.size());\n        int n = f.size(),\
    \ k = ceil(sqrt(n));\n\n        vector< fps<mint> > bs(k + 1);\n        bs[0]\
    \ = {1};\n        for(int i : rep(k)) bs[i + 1] = (bs[i] * g).low(n);\n\n    \
    \    vector< fps<mint> > gs(k + 1);\n        gs[0] = {1};\n        for(int i :\
    \ rep(k)) gs[i + 1] = (gs[i] * bs[k]).low(n);\n\n        fps<mint> h(n);\n   \
    \     for(int i : rep(0, n, k)) {\n            fps<mint> c;\n            for(int\
    \ j : rep(i, min(i + k, n))) c += bs[j - i] * f[j];\n            h += (c * gs[i\
    \ / k]).low(n);\n        }\n        return h;\n    }\n};\n\n#line 2 \"src/number/binom_mod.hpp\"\
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
    #line 6 \"src/number/poly.hpp\"\n\ntemplate < class mint > struct poly : std::vector<mint>\
    \ {\n    using std::vector<mint>::vector;\n    poly(const std::vector<mint>& f)\
    \ : std::vector<mint>(f) {}\n    int size() const { return int(std::vector<mint>::size());\
    \ }\n    void ups(int s) { if(size() < s) this->resize(s, 0); }\n    poly low(int\
    \ s) const {\n        return poly(this->begin(), this->begin() + min(this->size(),\
    \ s));\n    }\n    friend poly rev(const poly& f) {\n        return poly(f.rbegin(),\
    \ f.rend());\n    }\n    poly operator-() const {\n        poly g = *this;\n \
    \       for(int i : rep(g.size())) g[i] = -g[i];\n        return g;\n    }\n \
    \   poly operator+(const mint& v) const { return poly(*this) += v; }\n    poly\
    \ operator-(const mint& v) const { return poly(*this) -= v; }\n    poly operator*(const\
    \ mint& v) const { return poly(*this) *= v; }\n    poly operator/(const mint&\
    \ v) const { return poly(*this) /= v; }\n    poly operator+(const poly& r) const\
    \ { return poly(*this) += r; }\n    poly operator-(const poly& r) const { return\
    \ poly(*this) -= r; }\n    poly operator*(const poly& r) const { return poly(*this)\
    \ *= r; }\n    poly operator/(const poly& r) const { return poly(*this) /= r;\
    \ }\n    poly operator%(const poly& r) const { return poly(*this) %= r; }\n  \
    \  poly operator<<(int s) const { return poly(*this) <<= s; }\n    poly operator>>(int\
    \ s) const { return poly(*this) >>= s; }\n    poly& operator+=(const poly& r)\
    \ { ups(r.size()); for(int i : rep(r.size())) (*this)[i] += r[i]; return *this;\
    \ }\n    poly& operator-=(const poly& r) { ups(r.size()); for(int i : rep(r.size()))\
    \ (*this)[i] -= r[i]; return *this; }\n    poly& operator*=(const poly& r) { return\
    \ *this = ntt::mul(*this, r); }\n    poly& operator/=(const poly& r) {\n     \
    \   assert(r.size() > 0);\n        assert(r.back() != 0);\n        int s = size()\
    \ - r.size() + 1;\n        if(s <= 0) return *this = poly{0};\n        return\
    \ *this = rev((rev(*this).low(s) * inv(fps<mint>(rev(r)), s).low(s)).low(s));\n\
    \    }\n    poly& operator%=(const poly& r) {\n        *this -= *this / r * r;\n\
    \        return *this = low(r.size() - 1);\n    }\n    template < class T > poly&\
    \ operator+=(T v) { ups(1); (*this)[0] += v; return *this; }\n    template < class\
    \ T > poly& operator-=(T v) { ups(1); (*this)[0] -= v; return *this; }\n    template\
    \ < class T > poly& operator*=(T v) { for(auto &x : *this) x *= v; return *this;\
    \ }\n    template < class T > poly& operator/=(T v) { assert(v != T(0)); return\
    \ *this *= mint(1) / v; }\n    poly& operator<<=(int s) {\n        poly g(s, 0);\n\
    \        g.insert(g.end(), this->begin(), this->end());\n        return *this\
    \ = g;\n    }\n    poly& operator>>=(int s) {\n        return *this = {this->begin()\
    \ + s, this->end()};\n    }\n    friend poly differential(const poly& f) {\n \
    \       int n = f.size();\n        poly g(n - 1);\n        for(int i : rep(1,\
    \ n)) g[i - 1] = f[i] * i;\n        return g;\n    }\n    friend poly integral_(const\
    \ poly& f) { // std \u3068\u885D\u7A81\n        int n = f.size();\n        poly\
    \ g(n + 1, 0);\n        for(int i : rep(0, n)) g[i + 1] = f[i] / (i + 1);\n  \
    \      return g;\n    }\n    friend poly taylor_shift(const poly& f, mint c) {\n\
    \        int n = f.size();\n        std::vector<mint> c_pow(n);\n        c_pow[0]\
    \ = 1;\n        for(int i : rep(1, n)) c_pow[i] = c * c_pow[i - 1];\n\n      \
    \  poly<mint> p(n), q(n);\n        for(int i : rep(n)) p[i] = f[i] * fact<mint>(i);\n\
    \        for(int i : rep(n)) q[i] = c_pow[i] * fact_inv<mint>(i);\n        poly<mint>\
    \ r = (p * rev(q)) >> n - 1;\n        for(int i : rep(n)) r[i] *= fact_inv<mint>(i);\n\
    \        return r;\n    }\n};\n\ntemplate < class mint >\npoly<mint> all_product(vector<\
    \ poly<mint> >& fs) {\n    if(int(fs.size()) == 0) return {1};\n    using P =\
    \ std::pair<int, int>;\n    std::priority_queue< P, std::vector< P >, std::greater<\
    \ P >> pq;\n    for(int i : rep(fs.size())) pq.push({fs[i].size(), i});\n    while(int(pq.size())\
    \ >= 2) {\n        auto [n1, i1] = pq.top(); pq.pop();\n        auto [n2, i2]\
    \ = pq.top(); pq.pop();\n        fs[i1] *= fs[i2];\n        pq.push({n1 + n2,\
    \ i1});\n    }\n    return fs[pq.top().second];\n}\n#line 6 \"verify/library_checker/number/poly_division.test.cpp\"\
    \n\nint main() {\n    int N = in(), M = in();\n    using mint = mint998244353;\n\
    \    poly<mint> f(N), g(M);\n    for(int i : rep(N)) f[i] = in();\n    for(int\
    \ i : rep(M)) g[i] = in();\n\n    poly<mint> q = f / g, r = f % g;\n    while(q.size()\
    \ >= 1 and q.back() == 0) q.pop_back();\n    while(r.size() >= 1 and r.back()\
    \ == 0) r.pop_back();\n    print(q.size(), r.size());\n    print(q);\n    print(r);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/number/modint.hpp\"\
    \n#include \"../../../src/number/poly.hpp\"\n\nint main() {\n    int N = in(),\
    \ M = in();\n    using mint = mint998244353;\n    poly<mint> f(N), g(M);\n   \
    \ for(int i : rep(N)) f[i] = in();\n    for(int i : rep(M)) g[i] = in();\n\n \
    \   poly<mint> q = f / g, r = f % g;\n    while(q.size() >= 1 and q.back() ==\
    \ 0) q.pop_back();\n    while(r.size() >= 1 and r.back() == 0) r.pop_back();\n\
    \    print(q.size(), r.size());\n    print(q);\n    print(r);\n}\n"
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
  - src/number/poly.hpp
  - src/number/ntt.hpp
  - src/number/fps.hpp
  - src/number/modfunc.hpp
  - src/utility/random.hpp
  - src/number/binom_mod.hpp
  isVerificationFile: true
  path: verify/library_checker/number/poly_division.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 14:59:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number/poly_division.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/poly_division.test.cpp
- /verify/verify/library_checker/number/poly_division.test.cpp.html
title: verify/library_checker/number/poly_division.test.cpp
---
