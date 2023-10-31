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
    path: src/number/modfunc.hpp
    title: src/number/modfunc.hpp
  - icon: ':question:'
    path: src/number/prime.hpp
    title: src/number/prime.hpp
  - icon: ':x:'
    path: src/number/tetration.hpp
    title: src/number/tetration.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
  bundledCode: "#line 1 \"verify/library_checker/number/tetration.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n\n#line 2 \"src/cp-template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n\
    using i32 = int;\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool chmin(T&\
    \ a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate < class\
    \ T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false;\
    \ }\ntemplate < class T, class U > T ceil (T x, U y) { return (x > 0 ? (x + y\
    \ - 1) / y :           x / y); }\ntemplate < class T, class U > T floor(T x, U\
    \ y) { return (x > 0 ?           x / y : (x - y + 1) / y); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\
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
    \ 3 \"src/utility/random.hpp\"\n\nnamespace randnum {\n\nstatic uint seed;\nstatic\
    \ std::mt19937 mt;\nstruct gen_seed {\n    gen_seed() {\n        seed = std::random_device()();\n\
    \        mt = std::mt19937(seed);\n    }\n} gs;\n\n// [L, R)\ntemplate < class\
    \ T >\nT gen_int(T L, T R) {\n    return std::uniform_int_distribution< T >(L,\
    \ R - 1)(mt);\n}\n\ntemplate < class T >\nT get_real(T L, T R) {\n    return std::uniform_real_distribution<\
    \ T >(L, R)(mt);\n}\n\n}\n#line 4 \"src/number/modfunc.hpp\"\n\nu64 modpow64(u64\
    \ a, u64 n, u64 mod) {\n    a %= mod;\n    u64 res = 1;\n    while(n > 0) {\n\
    \        if(n % 2 == 1) res = i128(res) * a % mod;\n        a = i128(a) * a %\
    \ mod;\n        n /= 2;\n    }\n    return res;\n}\n\nu64 modpow(u64 a, u64 n,\
    \ u64 mod) {\n    a %= mod;\n    u64 res = 1;\n    while(n > 0) {\n        if(n\
    \ % 2 == 1) res = res * a % mod;\n        a = a * a % mod;\n        n /= 2;\n\
    \    }\n    return res;\n}\n\n// solve x^2 = a (mod p)\n// return x\n// or No\
    \ Solution (-1)\ni32 modsqrt(i32 a, i32 p) {\n    if(p == 2) return a;\n    a\
    \ %= p;\n    if(a == 0) return 0;\n    if(modpow(a, (p - 1) / 2, p) != 1) return\
    \ -1;\n    i32 q = p - 1, m = 0; while(q % 2 == 0) q /= 2, m++;\n    i32 z; do\
    \ { z = randnum::gen_int<i32>(1, p); } while(modpow(z, (p - 1) / 2, p) != p -\
    \ 1);\n    i64 c = modpow(z, q, p), t = modpow(a, q, p), r = modpow(a, (q + 1)\
    \ / 2, p);\n    while(m > 1) {\n        if(modpow(t, 1 << (m - 2), p) != 1) r\
    \ = r * c % p, t = t * (c * c % p) % p;\n        c = c * c % p;\n        m -=\
    \ 1;\n    }\n    return r;\n}\n#line 5 \"src/number/prime.hpp\"\n\nbool miller_rabin(u64\
    \ n, std::vector<u64> witness) {\n    if(n == 1) return false;\n    if(n % 2 ==\
    \ 0) return n == 2;\n\n    u64 d = n - 1;\n    while(d % 2 == 0) d /= 2;\n   \
    \ for(u64 a : witness) if(a < n) {\n        u64 y = modpow64(a, d, n), t = d;\n\
    \        while(t != n - 1 and y != 1 and y != n - 1) {\n            y = i128(y)\
    \ * y % n;\n            t *= 2;\n        }\n        if(y != n - 1 and t % 2 ==\
    \ 0) return false;\n    }\n    return true;\n}\n\nbool prime_test(u64 n) {\n \
    \   if(n < (u64(1) << 32)) return miller_rabin(n, {2, 7, 61});\n    return miller_rabin(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\nu64 pollard_rho(u64\
    \ n) {\n    if(n % 2 == 0) return 2;\n    if(prime_test(n)) return n;\n    while(true)\
    \ {\n        u64 R = randnum::gen_int<u64>(2, n), x, y = randnum::gen_int<u64>(2,\
    \ n), ys, q = 1, g = 1, m = 128;\n        auto f = [&](u64 x) {\n            return\
    \ (i128(x) * x % n + R) % n;\n        };\n        for(int r = 1; g == 1; r *=\
    \ 2) {\n            x = y;\n            for(int i : rep(r)) y = f(y);\n      \
    \      for(int k = 0; g == 1 and k < r; k += m) {\n                ys = y;\n \
    \               for(int i = 0; i < m and i < r - k; i++) {\n                 \
    \   q = i128(q) * ((x - (y = f(y)) + n) % n) % n;\n                }\n       \
    \         g = gcd(q, n);\n            }\n        }\n        if(g == n) { do {\
    \ g = gcd((x - (ys = f(ys))), n); } while(g == 1); }\n        if(g != n) return\
    \ g;\n    }\n    return 0;\n}\n\nstd::vector<u64> factor(u64 n) {\n    function<std::vector<u64>(u64)>\
    \ dfs = [&](u64 n) {\n        if(n <= 1) return std::vector<u64>{};\n        u64\
    \ d = pollard_rho(n);\n        if(d == n) return std::vector<u64>{n};\n      \
    \  std::vector<u64> L = dfs(d), R = dfs(n / d);\n        L.insert(L.end(), R.begin(),\
    \ R.end());\n        return L;\n    };\n    std::vector<u64> res = dfs(n);\n \
    \   sort(res.begin(), res.end());\n    return res;\n}\n\nstd::vector<std::pair<u64,\
    \ i32>> factor_pair(u64 n) {\n    std::vector<u64> pf = factor(n);\n    std::vector<std::pair<u64,\
    \ i32>> res;\n    if(pf.empty()) return res;\n    res.push_back({pf[0], 1});\n\
    \    for(int i : rep(1, int(pf.size()))) {\n        if(res.back().first == pf[i])\
    \ res.back().second++;\n        else res.push_back({pf[i], 1});\n    }\n    return\
    \ res;\n}\n\nu64 euler_phi(u64 n) {\n    std::vector<std::pair<u64,i32>> pf =\
    \ factor_pair(n);\n    for(auto [p, e] : pf) n -= n / p;\n    return n;\n}\n#line\
    \ 5 \"src/number/tetration.hpp\"\n\nu32 tetration(std::vector<u32> a, u32 mod)\
    \ {\n    for(u32 x : a) assert(x > 0);\n    std::vector<u32> m = {mod};\n    while(m.back()\
    \ != 1) m.push_back(euler_phi(m.back()));\n    u64 n = 1;\n    for(int i : revrep(min(a.size(),\
    \ m.size()))) {\n        u64 x = 1, v = a[i];\n        while(n > 0) {\n      \
    \      if(n % 2 == 1) {\n                x *= v;\n                if(x >= m[i])\
    \ x = x % m[i] + m[i];\n            }\n            v *= v;\n            if(v >=\
    \ m[i]) v = v % m[i] + m[i];\n            n /= 2;\n        }\n        n = x;\n\
    \    }\n    return n % mod;\n}\n\nu32 tetration(u32 a, u32 b, u32 mod) {\n   \
    \ if(a == 0) return (b % 2 == 0) % mod;\n    return tetration(std::vector<u32>(std::min<u32>(b,\
    \ 64), a), mod);\n}\n#line 5 \"verify/library_checker/number/tetration.test.cpp\"\
    \n\nint main() {\n    int T = in();\n    for(int _ : rep(T)) {\n        int A\
    \ = in(), B = in(), M = in();\n        print(tetration(A, B, M));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/number/tetration.hpp\"\
    \n\nint main() {\n    int T = in();\n    for(int _ : rep(T)) {\n        int A\
    \ = in(), B = in(), M = in();\n        print(tetration(A, B, M));\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/number/tetration.hpp
  - src/number/prime.hpp
  - src/number/modfunc.hpp
  - src/utility/random.hpp
  isVerificationFile: true
  path: verify/library_checker/number/tetration.test.cpp
  requiredBy: []
  timestamp: '2023-10-28 05:38:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/number/tetration.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number/tetration.test.cpp
- /verify/verify/library_checker/number/tetration.test.cpp.html
title: verify/library_checker/number/tetration.test.cpp
---
