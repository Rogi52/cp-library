---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/algorithm/count_subseq.hpp
    title: src/algorithm/count_subseq.hpp
  - icon: ':x:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/number/modint.hpp
    title: modint
  - icon: ':x:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':x:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':x:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':x:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"verify/library_checker/algorithm/count_subseq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\
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
    \ : '\\n');\n    return 0;\n}\n#line 2 \"src/utility/key_val.hpp\"\ntemplate <\
    \ class K, class V >\nstruct key_val {\n    K key; V val;\n    key_val() {}\n\
    \    key_val(K key, V val) : key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T >\nkey_val< int, T > max_of(const vector< T >& a) {\n   \
    \ int i = max_element(a.begin(), a.end()) - a.begin();\n    return {a[i], i};\n\
    }\n\ntemplate < class T >\nkey_val< int, T > min_of(const vector< T >& a) {\n\
    \    int i = min_element(a.begin(), a.end()) - a.begin();\n    return {a[i], i};\n\
    }\n\ntemplate < class T >\nT sum_of(const vector< T >& a) {\n    T sum = 0;\n\
    \    for(const T x : a) sum += x;\n    return sum;\n}\n\ntemplate < class T >\n\
    vector<int> freq(const vector< T >& a, T L = 0, T R) {\n    vector<int> res(R\
    \ - L);\n    for(const T x : a) res[x - L]++;\n    return res;\n}\n\ntemplate\
    \ < class T >\nstruct prefix_sum {\n    vector< T > s;\n    prefix_sum(const vector<\
    \ T >& a) : s(a) {\n        s.insert(sum.begin(), T(0));\n        for(int i :\
    \ rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n    T sum(int L, int\
    \ R) {\n        return s[R] - s[L];\n    }\n};\n#line 1 \"src/number/modint.hpp\"\
    \nstruct modinfo { uint mod, root, isprime; };\ntemplate < modinfo const &ref\
    \ >\nstruct modint {\n    static constexpr uint const &mod = ref.mod;\n    static\
    \ constexpr uint const &root = ref.root;\n    static constexpr uint const &isprime\
    \ = ref.isprime;\n    uint v = 0;\n    constexpr modint& s(uint v) { this->v =\
    \ v < mod ? v : v - mod; return *this; }\n    constexpr modint(ll v = 0) { s(v\
    \ % mod + mod); }\n    modint operator-() const { return modint() - *this; }\n\
    \    modint& operator+=(const modint& rhs) { return s(v + rhs.v); }\n    modint&\
    \ operator-=(const modint& rhs) { return s(v + mod - rhs.v); }\n    modint& operator*=(const\
    \ modint& rhs) { v = ull(v) * rhs.v % mod; return *this; }\n    modint& operator/=(const\
    \ modint& rhs) { return *this *= inv(rhs); }\n    modint operator+(const modint&\
    \ rhs) const { return modint(*this) += rhs; }\n    modint operator-(const modint&\
    \ rhs) const { return modint(*this) -= rhs; }\n    modint operator*(const modint&\
    \ rhs) const { return modint(*this) *= rhs; }\n    modint operator/(const modint&\
    \ rhs) const { return modint(*this) /= rhs; }\n    friend modint pow(modint x,\
    \ ll n) { modint res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; }\
    \ return res; }\n    friend modint inv(modint v) {\n        if(isprime) {\n  \
    \          return pow(v, mod - 2);\n        } else {\n            ll a = v.v,\
    \ b = modint::mod, x = 1, y = 0, t;\n            while(b > 0) { t = a / b; swap(a\
    \ -= t * b, b); swap(x -= t * y, y); }\n            return modint(x);\n      \
    \  }\n    }\n    friend modint operator+(int x, const modint& y) { return modint(x)\
    \ + y; }\n    friend modint operator-(int x, const modint& y) { return modint(x)\
    \ - y; }\n    friend modint operator*(int x, const modint& y) { return modint(x)\
    \ * y; }\n    friend modint operator/(int x, const modint& y) { return modint(x)\
    \ / y; }\n    friend istream& operator>>(istream& is, modint& m) { ll x; is >>\
    \ x; m = modint(x); return is; }\n    friend ostream& operator<<(ostream& os,\
    \ const modint& m) { return os << m.v; }\n    bool operator==(const modint& r)\
    \ const { return v == r.v; }\n    bool operator!=(const modint& r) const { return\
    \ v != r.v; }\n    static uint get_mod() { return mod; }\n};\nconstexpr modinfo\
    \ base998244353 { 998244353, 3, 1 };\nconstexpr modinfo base1000000007 { 1000000007,\
    \ 0, 1 };\nusing mint998244353 = modint< base998244353 >;\nusing mint1000000007\
    \ = modint< base1000000007 >;\n#line 1 \"src/algorithm/count_subseq.hpp\"\ntemplate\
    \ < class mint, class T >\nmint count_subseq(const vector< T >& a) {\n    int\
    \ n = a.size();\n    unordered_map< T, int > mp;\n    vector<mint> dp(n + 1);\n\
    \    dp[0] = 1;\n    for(int i : rep(n)) {\n        dp[i + 1] = dp[i] + dp[i];\n\
    \        if(mp.count(a[i])) dp[i + 1] -= dp[mp[a[i]]];\n        mp[a[i]] = i;\n\
    \    }\n    return dp[n];\n}\n#line 6 \"verify/library_checker/algorithm/count_subseq.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n    \n    int\
    \ N = in();\n    vector<int> A = in(N);\n    print(count_subseq<mint998244353>(A)\
    \ - 1);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"src/cp-template.hpp\"\n#include \"src/number/modint.hpp\"\n#include\
    \ \"src/algorithm/count_subseq.hpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    \n    int N = in();\n    vector<int> A = in(N);\n    print(count_subseq<mint998244353>(A)\
    \ - 1);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/number/modint.hpp
  - src/algorithm/count_subseq.hpp
  isVerificationFile: true
  path: verify/library_checker/algorithm/count_subseq.test.cpp
  requiredBy: []
  timestamp: '2023-05-24 23:37:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/algorithm/count_subseq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp
- /verify/verify/library_checker/algorithm/count_subseq.test.cpp.html
title: verify/library_checker/algorithm/count_subseq.test.cpp
---
