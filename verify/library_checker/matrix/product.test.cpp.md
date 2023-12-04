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
    path: src/matrix/base.hpp
    title: src/matrix/base.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"verify/library_checker/matrix/product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#line 2 \"src/cp-template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing uint = unsigned int;\nusing ull  = unsigned long long;\n\
    using i32 = int;\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool chmin(T&\
    \ a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate < class\
    \ T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false;\
    \ }\ntemplate < class T, class U > T ceil (T x, U y) { return (x > 0 ? (x + y\
    \ - 1) / y :           x / y); }\ntemplate < class T, class U > T floor(T x, U\
    \ y) { return (x > 0 ?           x / y : (x - y + 1) / y); }\nint popcnt(i32 x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(i64 x) { return __builtin_popcountll(x); }\nint popcnt(u64 x)\
    \ { return __builtin_popcountll(x); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\n\
    template < class T > struct itr_rep {\n    T i, d;\n    constexpr itr_rep(const\
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
    \ 3 \"src/matrix/base.hpp\"\n\ntemplate < class T > std::vector< T >& operator+=(std::vector<\
    \ T >& x, const std::vector< T >& y) { assert(x.size() == y.size()); for(int i\
    \ : rep(x.size())) x[i] += y[i]; return x; }\ntemplate < class T > std::vector<\
    \ T >& operator-=(std::vector< T >& x, const std::vector< T >& y) { assert(x.size()\
    \ == y.size()); for(int i : rep(x.size())) x[i] -= y[i]; return x; }\ntemplate\
    \ < class T > std::vector< T >& operator*=(std::vector< T >& v, T x) { for(int\
    \ i : rep(v.size())) v[i] *= x; return v; }\ntemplate < class T > std::vector<\
    \ T >& operator/=(std::vector< T >& v, T x) { x = T(1) / x; for(int i : rep(v.size()))\
    \ v[i] *= x; return v; }\ntemplate < class T > std::vector< T > operator+(std::vector<\
    \ T > x, const std::vector< T >& y) { return x += y; }\ntemplate < class T > std::vector<\
    \ T > operator-(std::vector< T > x, const std::vector< T >& y) { return x -= y;\
    \ }\ntemplate < class T > std::vector< T > operator*(std::vector< T > v, T x)\
    \ { return v *= x; }\ntemplate < class T > std::vector< T > operator/(std::vector<\
    \ T > v, T x) { return v /= x; }\n\ntemplate < class T >\nT dot(const std::vector<\
    \ T >& x, const std::vector< T >& y) {\n    assert(x.size() == y.size());\n  \
    \  T res = 0;\n    for(int i : rep(x.size())) res += x[i] * y[i];\n    return\
    \ res;\n}\n\ntemplate < class T >\nstruct matrix : std::vector< std::vector< T\
    \ > > {\n    int h, w;\n    matrix(int h, int w, T e = 0) : h(h), w(w), std::vector<\
    \ std::vector< T > >(h, std::vector< T >(w, e)) {}\n    matrix(std::initializer_list<\
    \ std::initializer_list< T > > m) : std::vector< std::vector< T > >(m.size())\
    \ {\n        auto it = m.begin();\n        for(int i = 0; it != m.end(); i++,\
    \ it++) (*this)[i] = std::vector< T >(*it);\n    }\n    matrix operator*(const\
    \ matrix& rhs) const {\n        int N = this->size(), K = (*this)[0].size(), M\
    \ = rhs[0].size();\n        assert(K == rhs.size());\n        matrix res(N, M);\n\
    \        for(int k : rep(K)) for(int n : rep(N)) for(int m : rep(M)) res[n][m]\
    \ += (*this)[n][k] * rhs[k][m];\n        return res;\n    }\n    matrix& operator*=(const\
    \ matrix& rhs) { return *this = (*this) * rhs; }\n    std::vector< T > operator*(const\
    \ std::vector< T >& rhs) const {\n        assert((*this)[0].size() == rhs.size());\n\
    \        std::vector< T > res(this->size());\n        for(int i : rep(this->size()))\
    \ res[i] = dot((*this)[i], rhs);\n        return res;\n    }\n    std::vector<\
    \ T >& operator[](int i) { return std::vector< std::vector< T > >::operator[](i);\
    \ }\n    const std::vector< T >& operator[](int i) const { return std::vector<\
    \ std::vector< T > >::operator[](i); }\n    bool operator==(const matrix& rhs)\
    \ const {\n        for(int i : rep(this->size())) if((*this)[i] != rhs[i]) return\
    \ false;\n        return true;\n    }\n};\n\ntemplate < class T >\nstruct square_matrix\
    \ : matrix< T > {\n    int n;\n    square_matrix(int n, T e = 0) : n(n), matrix<\
    \ T >(n, n, e) {}\n    square_matrix(std::initializer_list< std::initializer_list<\
    \ T > > m) : matrix< T >(m) {}\n    square_matrix< T > minor(int i, int j) {\n\
    \        square_matrix< T > M(n - 1);\n        for(int i2 : rep(n)) for(int j2\
    \ : rep(n)) {\n            if(i2 != i and j2 = j) {\n                M[i2 < i\
    \ ? i2 : i2 - 1][j2 < j ? j2 : j2 - 1] = (*this)[i][j];\n            }\n     \
    \   }\n        return M;\n    }\n    T cofactor(int i, int j) {\n        return\
    \ ((i + j) % 2 == 0 ? +1 : -1) * det(minor(i, j));\n    }\n};\n\ntemplate < class\
    \ T >\nsquare_matrix< T > unit(int n) {\n    square_matrix< T > I(n);\n    for(int\
    \ i : rep(n)) I[i][i] = 1;\n    return I;\n}\n\ntemplate < class T >\nsquare_matrix<\
    \ T > inv(square_matrix< T > A) {\n    int n = A.size();\n    square_matrix B\
    \ = unit< T >(n);\n    for(int i : rep(n)) {\n        if(A[i][i] == 0) {\n   \
    \         for(int j : rep(i + 1, n)) if(A[j][i] != 0) {\n                for(int\
    \ k : rep(i, n)) std::swap(A[i][k], A[j][k]);\n                for(int k : rep(0,\
    \ n)) std::swap(B[i][k], B[j][k]);\n                break;\n            }\n  \
    \      }\n        if(A[i][i] == 0) throw \"This matrix is not regular.\"s;\n \
    \       const T x = T(1) / A[i][i];\n        for(int k : rep(i, n)) A[i][k] *=\
    \ x;\n        for(int k : rep(0, n)) B[i][k] *= x;\n        for(int j : rep(n))\
    \ if(i != j) {\n            const T y = A[j][i];\n            for(int k : rep(i,\
    \ n)) A[j][k] -= A[i][k] * y;\n            for(int k : rep(0, n)) B[j][k] -= B[i][k]\
    \ * y;\n        }\n    }\n    return B;\n}\n\ntemplate < class T >\nT det(square_matrix<\
    \ T > A) {\n    T res = 1;\n    int n = A.size();\n    for(int i : rep(n)) {\n\
    \        if(A[i][i] == 0) {\n            for(int j : rep(i + 1, n)) if(A[j][i]\
    \ != 0) {\n                for(int k : rep(i, n)) std::swap(A[i][k], A[j][k]);\n\
    \                res *= -1;\n                break;\n            }\n        }\n\
    \        if(A[i][i] == 0) return T(0);\n        res *= A[i][i];\n        const\
    \ T x = T(1) / A[i][i];\n        for(int k : rep(i, n)) A[i][k] *= x;\n      \
    \  for(int j : rep(i + 1, n)) {\n            const T y = A[j][i];\n          \
    \  for(int k : rep(i, n)) A[j][k] -= A[i][k] * y;\n        }\n    }\n    return\
    \ res;\n}\n\ntemplate < class T >\nsquare_matrix< T > pow(square_matrix< T > A,\
    \ ll n) {\n    square_matrix res = unit(A.size());\n    while(n > 0) {\n     \
    \   if(n % 2 == 1) res *= A;\n        A *= A;\n        n /= 2;\n    }\n    return\
    \ res;\n}\n#line 2 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root,\
    \ isprime; };\ntemplate < modinfo const &ref >\nstruct modint {\n    static constexpr\
    \ uint const &mod = ref.mod;\n    static constexpr uint const &root = ref.root;\n\
    \    static constexpr uint const &isprime = ref.isprime;\n    uint v = 0;\n  \
    \  constexpr modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this;\
    \ }\n    constexpr modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-()\
    \ const { return modint() - *this; }\n    modint& operator+=(const modint& rhs)\
    \ { return s(v + rhs.v); }\n    modint& operator-=(const modint& rhs) { return\
    \ s(v + mod - rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v)\
    \ * rhs.v % mod; return *this; }\n    modint& operator/=(const modint& rhs) {\
    \ return *this *= inv(rhs); }\n    modint operator+(const modint& rhs) const {\
    \ return modint(*this) += rhs; }\n    modint operator-(const modint& rhs) const\
    \ { return modint(*this) -= rhs; }\n    modint operator*(const modint& rhs) const\
    \ { return modint(*this) *= rhs; }\n    modint operator/(const modint& rhs) const\
    \ { return modint(*this) /= rhs; }\n    friend modint pow(modint x, ll n) { modint\
    \ res(1); while(n > 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n\
    \    friend modint inv(modint v) {\n        if(isprime) {\n            return\
    \ pow(v, mod - 2);\n        } else {\n            ll a = v.v, b = modint::mod,\
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
    \  static uint get_mod() { return mod; }\n    static int is_prime() { return isprime;\
    \ }\n};\nconstexpr modinfo base998244353 { 998244353, 3, 1 };\nconstexpr modinfo\
    \ base1000000007 { 1000000007, 0, 1 };\nusing mint998244353 = modint< base998244353\
    \ >;\nusing mint1000000007 = modint< base1000000007 >;\n#line 6 \"verify/library_checker/matrix/product.test.cpp\"\
    \n\nint main() {\n    int N = in(), M = in(), K = in();\n    using mint = mint998244353;\n\
    \    matrix<mint> A(N, M), B(M, K);\n    for(int i : rep(N)) A[i] = in(M);\n \
    \   for(int i : rep(M)) B[i] = in(K);\n    matrix<mint> C = A * B;\n    for(int\
    \ i : rep(N)) print(C[i]);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/matrix/base.hpp\"\n\
    #include \"../../../src/number/modint.hpp\"\n\nint main() {\n    int N = in(),\
    \ M = in(), K = in();\n    using mint = mint998244353;\n    matrix<mint> A(N,\
    \ M), B(M, K);\n    for(int i : rep(N)) A[i] = in(M);\n    for(int i : rep(M))\
    \ B[i] = in(K);\n    matrix<mint> C = A * B;\n    for(int i : rep(N)) print(C[i]);\n\
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
  - src/matrix/base.hpp
  - src/number/modint.hpp
  isVerificationFile: true
  path: verify/library_checker/matrix/product.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 14:59:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/matrix/product.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/matrix/product.test.cpp
- /verify/verify/library_checker/matrix/product.test.cpp.html
title: verify/library_checker/matrix/product.test.cpp
---
