---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/minmax.hpp
    title: src/algebra/minmax.hpp
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
    path: src/data_structure/disjoint_sparse_table.hpp
    title: src/data_structure/disjoint_sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/data_structure/disjoint_sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\ntemplate\
    \ < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return\
    \ false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return\
    \ true; } return false; }\ntemplate < class T, class U > T ceil (T x, U y) { return\
    \ (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate < class T, class U\
    \ > T floor(T x, U y) { return (x > 0 ?           x / y : (x - y + 1) / y); }\n\
    int popcnt(i32 x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(i64 x) { return __builtin_popcountll(x);\
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
    \ 2 \"src/data_structure/disjoint_sparse_table.hpp\"\n\ntemplate < class semi_group\
    \ >\nstruct disjoint_sparse_table {\n    using T = typename semi_group::set;\n\
    \    std::vector<std::vector< T >> table;\n    vector<int> msb;\n    disjoint_sparse_table(const\
    \ std::vector< T >& a) : table(1, a), msb(2) {\n        int n = a.size();\n  \
    \      for(int i = 2; i < n; i <<= 1) {\n            std::vector< T > v;\n   \
    \         for(int j = i; j < n; j += i << 1) {\n                v.push_back(a[j\
    \ - 1]);\n                for(int k = 2; k <= i; k++)\n                    v.push_back(semi_group::op(a[j\
    \ - k], v.back()));\n                v.push_back(a[j]);\n                for(int\
    \ k = 1; k < i and j + k < n; k++)\n                    v.push_back(semi_group::op(v.back(),\
    \ a[j + k]));\n            }\n            table.push_back(v);\n        }\n   \
    \ }\n\n    // [L, R)\n    T fold(int L, int R) {\n        if(L == --R) return\
    \ table.front()[L];\n        else {\n            while(msb.size() <= (L ^ R))\
    \ msb.push_back(msb[msb.size() >> 1] + 1);\n            int p = msb[L ^ R];\n\
    \            return semi_group::op(table[p][L ^ (1 << p) - 1], table[p][R]);\n\
    \        }\n    }\n};\n#line 3 \"src/algebra/minmax.hpp\"\n\ntemplate < class\
    \ T > class min_monoid {\n  public:\n    using set = T;\n    static constexpr\
    \ T op(const T &l, const T &r) { return std::min(l, r); }\n    static constexpr\
    \ T id() { return std::numeric_limits< T >::max(); }\n    static constexpr bool\
    \ comm = true;\n};\n\ntemplate < class T > class max_monoid {\n  public:\n   \
    \ using set = T;\n    static constexpr T op(const T &l, const T &r) { return std::max(l,\
    \ r); }\n    static constexpr T id() { return std::numeric_limits< T >::min();\
    \ }\n    static constexpr bool comm = true;\n};\n#line 6 \"verify/library_checker/data_structure/disjoint_sparse_table.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    std::vector<int> a = in(N);\n\
    \    disjoint_sparse_table< min_monoid<int> > table(a);\n    for(int _ : rep(Q))\
    \ {\n        int l = in(), r = in();\n        print(table.fold(l, r));\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/disjoint_sparse_table.hpp\"\
    \n#include \"../../../src/algebra/minmax.hpp\"\n\nint main() {\n    int N = in(),\
    \ Q = in();\n    std::vector<int> a = in(N);\n    disjoint_sparse_table< min_monoid<int>\
    \ > table(a);\n    for(int _ : rep(Q)) {\n        int l = in(), r = in();\n  \
    \      print(table.fold(l, r));\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/disjoint_sparse_table.hpp
  - src/algebra/minmax.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 14:59:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
- /verify/verify/library_checker/data_structure/disjoint_sparse_table.test.cpp.html
title: verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
---