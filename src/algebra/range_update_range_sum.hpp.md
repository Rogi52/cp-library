---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/set_monoid.hpp
    title: src/algebra/set_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: src/algebra/size.hpp
    title: src/algebra/size.hpp
  - icon: ':question:'
    path: src/algebra/sum.hpp
    title: src/algebra/sum.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/data_structure/range_update_range_sum.test.cpp
    title: verify/aoj/data_structure/range_update_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\ntemplate < class T, class\
    \ U > T ceil (T x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y);\
    \ }\ntemplate < class T, class U > T floor(T x, U y) { return (x > 0 ?       \
    \    x / y : (x - y + 1) / y); }\nint popcnt(i32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(i64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr_rep\
    \ {\n    T i, d;\n    constexpr itr_rep(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr_rep(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr_rep x) const noexcept\
    \ { return d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class T > struct rep\
    \ {\n    const itr_rep< T > s, t;\n    constexpr rep(const T t) noexcept : s(0),\
    \ t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n\
    \    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d)\
    \ {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr auto\
    \ end  () const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr_rep < T > s, t;\n    constexpr revrep(const T t) noexcept :\
    \ s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end  () const noexcept { return\
    \ t; }\n};\n#line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer */\nistream& operator>>(istream&\
    \ is, i128& x) {\n    std::string s; is >> s;\n    int pm = (s[0] == '-');\n \
    \   x = 0;\n    for(int i : rep(pm, int(s.size()))) x = x * 10 + (s[i] - '0');\n\
    \    if(pm) x *= -1;\n    return is;\n}\nostream& operator<<(ostream& os, const\
    \ i128& x) {\n    if(x == 0) return os << '0';\n    i128 y = x;\n    if(y < 0)\
    \ {\n        os << '-';\n        y *= -1;\n    }\n    std::vector<int> ny;\n \
    \   while(y > 0) {\n        ny.push_back(y % 10);\n        y /= 10;\n    }\n \
    \   for(int i : revrep(ny.size())) os << ny[i];\n    return os;\n}\n\nnamespace\
    \ scanner {\n    struct sca {\n        template < class T > operator T() {\n \
    \           T s; std::cin >> s; return s;\n        }\n    };\n    struct vec {\n\
    \        int n;\n        vec(int n) : n(n) {}\n        template < class T > operator\
    \ std::vector< T >() {\n            std::vector< T > v(n);\n            for(T&\
    \ x : v) std::cin >> x;\n            return v;\n        }\n    };\n    struct\
    \ mat {\n        int h, w;\n        mat(int h, int w) : h(h), w(w) {}\n      \
    \  template < class T > operator std::vector< std::vector< T > >() {\n       \
    \     std::vector m(h, std::vector< T >(w));\n            for(std::vector< T >&\
    \ v : m) for(T& x : v) std::cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            std::cin.tie(0);\n   \
    \         std::ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n\
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
    \ 1 \"src/algebra/sum.hpp\"\ntemplate < class T > class sum_monoid {\n  public:\n\
    \    using set = T;\n    static constexpr T op(const T &l, const T &r) { return\
    \ l + r; }\n    static constexpr T id() { return T(0); }\n    static constexpr\
    \ T inv(const T &x) { return -x; }\n    static constexpr T pow(const T &x, const\
    \ ll n) { return x * n; }\n    static constexpr bool comm = true;\n};\n#line 1\
    \ \"src/algebra/set_monoid.hpp\"\ntemplate < class T, T none = T(-1) >\nstruct\
    \ set_monoid {\n  public:\n    using set = T;\n    static constexpr T op(const\
    \ T& l, const T& r) { return (r == none ? l : r); }\n    static constexpr T id()\
    \ { return none; }\n    static constexpr bool comm = false;\n};\n#line 2 \"src/algebra/size.hpp\"\
    \n\ntemplate < class M, class T >\nstruct with_size {\n  public:\n    struct VS\
    \ {\n        using V = typename M::set;\n        mutable V value;\n        T size;\n\
    \    };\n    using set = VS;\n    static constexpr set op(const set& l, const\
    \ set& r) {\n        return set{M::op(l.value, r.value), l.size + r.size};\n \
    \   }\n    static constexpr set id() {\n        return set{M::id(), 0};\n    }\n\
    };\n#line 5 \"src/algebra/range_update_range_sum.hpp\"\n\ntemplate < class T,\
    \ T none = T(-1) > class range_update_range_sum {\n  public:\n    using value_structure\
    \ = with_size< sum_monoid< T >, T >;\n    using operator_structure = set_monoid<\
    \ T, none >;\n  private:\n    using S = typename value_structure::set;\n    using\
    \ F = typename operator_structure::set;\n  public:\n    static constexpr S op(const\
    \ S& x, const F& f) {\n        if(f != none) x.value = f * x.size;\n        return\
    \ x;\n    }\n};\n"
  code: "#include \"../../src/cp-template.hpp\"\n#include \"../../src/algebra/sum.hpp\"\
    \n#include \"../../src/algebra/set_monoid.hpp\"\n#include \"../../src/algebra/size.hpp\"\
    \n\ntemplate < class T, T none = T(-1) > class range_update_range_sum {\n  public:\n\
    \    using value_structure = with_size< sum_monoid< T >, T >;\n    using operator_structure\
    \ = set_monoid< T, none >;\n  private:\n    using S = typename value_structure::set;\n\
    \    using F = typename operator_structure::set;\n  public:\n    static constexpr\
    \ S op(const S& x, const F& f) {\n        if(f != none) x.value = f * x.size;\n\
    \        return x;\n    }\n};\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/algebra/sum.hpp
  - src/algebra/set_monoid.hpp
  - src/algebra/size.hpp
  isVerificationFile: false
  path: src/algebra/range_update_range_sum.hpp
  requiredBy: []
  timestamp: '2023-11-01 14:59:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/data_structure/range_update_range_sum.test.cpp
documentation_of: src/algebra/range_update_range_sum.hpp
layout: document
redirect_from:
- /library/src/algebra/range_update_range_sum.hpp
- /library/src/algebra/range_update_range_sum.hpp.html
title: src/algebra/range_update_range_sum.hpp
---