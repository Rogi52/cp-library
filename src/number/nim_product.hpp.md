---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number/nim_product.test.cpp
    title: verify/library_checker/number/nim_product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate <\
    \ class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false;\
    \ }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true;\
    \ } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T\
    \ > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1)\
    \ {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n\
    \        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T >\
    \ struct rep {\n    const itr< T > s, t;\n    constexpr rep(const T t) noexcept\
    \ : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t)\
    \ {}\n    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t,\
    \ d) {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr\
    \ auto end() const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr < T > s, t;\n    constexpr revrep(const T t) noexcept : s(t\
    \ - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end() const noexcept { return\
    \ t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca\
    \ {\n        template < class T > operator T() {\n            T s; cin >> s; return\
    \ s;\n        }\n    };\n    struct vec {\n        int n;\n        vec(int n)\
    \ : n(n) {}\n        template < class T > operator vector< T >() {\n         \
    \   vector< T > v(n);\n            for(T& x : v) cin >> x;\n            return\
    \ v;\n        }\n    };\n    struct mat {\n        int h,w;\n        mat(int h,\
    \ int w) : h(h), w(w) {}\n        template < class T > operator vector< vector<\
    \ T > >() {\n            vector m(h, vector< T >(w));\n            for(vector<\
    \ T >& v : m) for(T& x : v) cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            cin.tie(0);\n        \
    \    ios::sync_with_stdio(0);\n        }\n    } su;\n}\nscanner::sca in() { return\
    \ scanner::sca(); }\nscanner::vec in(int n) { return scanner::vec(n); }\nscanner::mat\
    \ in(int h, int w) { return scanner::mat(h, w); }\n\nnamespace printer {\n   \
    \ void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    \    void flush() {\n        cout.flush();\n    }\n}\nint print() { cout << '\\\
    n'; return 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&...\
    \ t) {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/utility/key_val.hpp\"\ntemplate <\
    \ class K, class V >\nstruct key_val {\n    K key; V val;\n    key_val() {}\n\
    \    key_val(K key, V val) : key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T >\nkey_val< int, T > max_of(const vector< T >& a) {\n   \
    \ int i = max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nkey_val< int, T > min_of(const vector< T >& a) {\n\
    \    int i = min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\n\ntemplate < class T >\nT sum_of(const vector< T >& a) {\n    T sum = 0;\n\
    \    for(const T x : a) sum += x;\n    return sum;\n}\n\ntemplate < class T >\n\
    vector<int> freq_of(const vector< T >& a, T L, T R) {\n    vector<int> res(R -\
    \ L);\n    for(const T x : a) res[x - L]++;\n    return res;\n}\n\ntemplate <\
    \ class T >\nvector<int> freq_of(const vector< T >& a, T R) {\n    return freq_of(a,\
    \ T(0), R);\n}\n\ntemplate < class T >\nstruct prefix_sum {\n    vector< T > s;\n\
    \    prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), T(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 2 \"\
    src/number/nim_product.hpp\"\n\nnamespace nim {\n    constexpr ull SMALL_BIT =\
    \ 1 << 3;\n    constexpr ull SMALL = 1 << SMALL_BIT;\n    ull _prod(ull a, ull\
    \ b, ull n_bit) {\n        static ull memo[SMALL][SMALL], vis[SMALL][SMALL];\n\
    \        if(n_bit == 1) return a & b;\n        if(n_bit <= SMALL_BIT and vis[a][b])\
    \ return memo[a][b];\n        ull n = n_bit >> 1, m = 1ULL << n;\n        auto\
    \ [au, al] = make_pair(a / m, a % m);\n        auto [bu, bl] = make_pair(b / m,\
    \ b % m);\n        ull ans = 0;\n        ans ^= (_prod(au, bu, n) ^ _prod(al,\
    \ bu, n) ^ _prod(au, bl, n)) * m;\n        ans ^= _prod(_prod(au, bu, n), m >>\
    \ 1, n_bit / 2);\n        ans ^= _prod(al, bl, n);\n        if(n_bit <= SMALL_BIT)\
    \ vis[a][b] = 1ULL, memo[a][b] = ans;\n        return ans;\n    }\n\n    ull prod(ull\
    \ a, ull b) {\n        return _prod(a, b, 64);\n    }\n}\n"
  code: "#include \"../cp-template.hpp\"\n\nnamespace nim {\n    constexpr ull SMALL_BIT\
    \ = 1 << 3;\n    constexpr ull SMALL = 1 << SMALL_BIT;\n    ull _prod(ull a, ull\
    \ b, ull n_bit) {\n        static ull memo[SMALL][SMALL], vis[SMALL][SMALL];\n\
    \        if(n_bit == 1) return a & b;\n        if(n_bit <= SMALL_BIT and vis[a][b])\
    \ return memo[a][b];\n        ull n = n_bit >> 1, m = 1ULL << n;\n        auto\
    \ [au, al] = make_pair(a / m, a % m);\n        auto [bu, bl] = make_pair(b / m,\
    \ b % m);\n        ull ans = 0;\n        ans ^= (_prod(au, bu, n) ^ _prod(al,\
    \ bu, n) ^ _prod(au, bl, n)) * m;\n        ans ^= _prod(_prod(au, bu, n), m >>\
    \ 1, n_bit / 2);\n        ans ^= _prod(al, bl, n);\n        if(n_bit <= SMALL_BIT)\
    \ vis[a][b] = 1ULL, memo[a][b] = ans;\n        return ans;\n    }\n\n    ull prod(ull\
    \ a, ull b) {\n        return _prod(a, b, 64);\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  isVerificationFile: false
  path: src/number/nim_product.hpp
  requiredBy: []
  timestamp: '2023-08-06 01:11:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number/nim_product.test.cpp
documentation_of: src/number/nim_product.hpp
layout: document
redirect_from:
- /library/src/number/nim_product.hpp
- /library/src/number/nim_product.hpp.html
title: src/number/nim_product.hpp
---