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
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/number/fps_sparse.hpp
    title: src/number/fps_sparse.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
    title: verify/library_checker/number/binom_coeff_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_exp_sparse.test.cpp
    title: verify/library_checker/number/fps_exp_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_inv_sparse.test.cpp
    title: verify/library_checker/number/fps_inv_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_log_sparse.test.cpp
    title: verify/library_checker/number/fps_log_sparse.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number/fps_pow_sparse.test.cpp
    title: verify/library_checker/number/fps_pow_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/fps_sqrt_sparse.test.cpp
    title: verify/library_checker/number/fps_sqrt_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    }\n#line 2 \"src/number/binom_mod.hpp\"\n\ntemplate < class mint >\nmint fact(int\
    \ n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static const uint\
    \ mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n    while(int(data.size())\
    \ <= n) {\n        int i = data.size();\n        data.push_back(data.back() *\
    \ i);\n    }\n    return data[n];\n}\n\ntemplate < class mint >\nmint inv(int\
    \ n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static const uint\
    \ mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n    while(int(data.size())\
    \ <= n) {\n        int i = data.size();\n        data.push_back(- data[mod % i]\
    \ * (mod / i));\n    }\n    return data[n];\n}\n\ntemplate < class mint >\nmint\
    \ fact_inv(int n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static\
    \ const uint mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n\
    \    while(int(data.size()) <= n) {\n        int i = data.size();\n        data.push_back(data.back()\
    \ * inv<mint>(i));\n    }\n    return data[n];\n}\n\ntemplate < class mint >\n\
    mint comb(int n, int k) {\n    if(k < 0 or n < k) return 0;\n    return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n}\n\ntemplate < class mint >\n\
    mint perm(int n, int k) {\n    return fact<mint>(n) * fact_inv<mint>(n - k);\n\
    }\n\ntemplate < class mint >\nmint homo(int n, int k) {\n    return comb<mint>(n\
    \ + k - 1, k);\n}\n"
  code: "#include \"../../src/cp-template.hpp\"\n\ntemplate < class mint >\nmint fact(int\
    \ n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static const uint\
    \ mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n    while(int(data.size())\
    \ <= n) {\n        int i = data.size();\n        data.push_back(data.back() *\
    \ i);\n    }\n    return data[n];\n}\n\ntemplate < class mint >\nmint inv(int\
    \ n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static const uint\
    \ mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n    while(int(data.size())\
    \ <= n) {\n        int i = data.size();\n        data.push_back(- data[mod % i]\
    \ * (mod / i));\n    }\n    return data[n];\n}\n\ntemplate < class mint >\nmint\
    \ fact_inv(int n) {\n    assert(0 <= n);\n    assert(mint::is_prime());\n    static\
    \ const uint mod = mint::get_mod();\n    static std::vector<mint> data = {1, 1};\n\
    \    while(int(data.size()) <= n) {\n        int i = data.size();\n        data.push_back(data.back()\
    \ * inv<mint>(i));\n    }\n    return data[n];\n}\n\ntemplate < class mint >\n\
    mint comb(int n, int k) {\n    if(k < 0 or n < k) return 0;\n    return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n}\n\ntemplate < class mint >\n\
    mint perm(int n, int k) {\n    return fact<mint>(n) * fact_inv<mint>(n - k);\n\
    }\n\ntemplate < class mint >\nmint homo(int n, int k) {\n    return comb<mint>(n\
    \ + k - 1, k);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/number/binom_mod.hpp
  requiredBy:
  - src/number/fps_sparse.hpp
  timestamp: '2023-10-24 23:33:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/number/fps_inv_sparse.test.cpp
  - verify/library_checker/number/fps_pow_sparse.test.cpp
  - verify/library_checker/number/fps_sqrt_sparse.test.cpp
  - verify/library_checker/number/binom_coeff_prime_mod.test.cpp
  - verify/library_checker/number/fps_exp_sparse.test.cpp
  - verify/library_checker/number/fps_log_sparse.test.cpp
documentation_of: src/number/binom_mod.hpp
layout: document
redirect_from:
- /library/src/number/binom_mod.hpp
- /library/src/number/binom_mod.hpp.html
title: src/number/binom_mod.hpp
---
