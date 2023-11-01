---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: src/data_structure/fenwick_tree.hpp
    title: src/data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/static_point_add_rect_sum.hpp
    title: src/data_structure/static_point_add_rect_sum.hpp
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
  - icon: ':heavy_check_mark:'
    path: src/utility/zip.hpp
    title: src/utility/zip.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#line 2 \"\
    src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing ull\
    \  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\ntemplate\
    \ < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return\
    \ false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return\
    \ true; } return false; }\ntemplate < class T, class U > T ceil (T x, U y) { return\
    \ (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate < class T, class U\
    \ > T floor(T x, U y) { return (x > 0 ?           x / y : (x - y + 1) / y); }\n\
    \n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr_rep {\n\
    \    T i, d;\n    constexpr itr_rep(const T i) noexcept : i(i), d(1) {}\n    constexpr\
    \ itr_rep(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr_rep x) const noexcept { return\
    \ d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class T > struct rep {\n    const\
    \ itr_rep< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n\
    \    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end  () const\
    \ noexcept { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const\
    \ itr_rep < T > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1),\
    \ t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1,\
    \ -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d)\
    \ noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end  () const noexcept { return t; }\n};\n\
    #line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer */\nistream& operator>>(istream&\
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
    \ 1 \"src/utility/zip.hpp\"\ntemplate < class T >\nstruct zipper {\n  public:\n\
    \    zipper() {}\n    vector< T > data;\n    void insert(const T x) {\n      \
    \  built = 0;\n        data.push_back(x);\n    }\n    void insert(const vector<\
    \ T > v) {\n        built = 0;\n        data.insert(data.end(), v.begin(), v.end());\n\
    \    }\n    template < class... args > zipper(args... a) { insert(a...); }\n \
    \   template < class... args > void insert(const T x, args... a) { insert(x);\
    \ insert(a...); }\n    template < class... args > void insert(const vector< T\
    \ > x, args... a) { insert(x); insert(a...); }\n\n    void build() {\n       \
    \ sort(data.begin(), data.end());\n        data.erase(unique(data.begin(), data.end()),\
    \ data.end());\n        built = 1;\n    }\n\n    int id(const T x) {\n       \
    \ if(not built) build();\n        return lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n    }\n    vector<int> zip(const vector< T >& x) {\n   \
    \     if(not built) build();\n        vector<int> idx(x.size());\n        for(int\
    \ i : rep(x.size())) idx[i] = id(x[i]);\n        return idx;\n    }\n    int size()\
    \ {\n        if(not built) build();\n        return data.size();\n    }\n\n  private:\n\
    \    int built = 0;\n};\n#line 2 \"src/data_structure/fenwick_tree.hpp\"\n\ntemplate\
    \ < class comm_monoid > class fenwick_tree {\n  public:\n    using T = typename\
    \ comm_monoid::set;\n\n  private:\n    int n, n2;\n    vector< T > data;\n\n \
    \   int ceil_pow2(int n) {\n        int x = 1;\n        while(x < n) x <<= 1;\n\
    \        return x;\n    }\n\n  public:\n    fenwick_tree() : fenwick_tree(0) {}\n\
    \    fenwick_tree(int n) : n(n), n2(ceil_pow2(n)), data(n + 1, comm_monoid::id())\
    \ { assert(comm_monoid::comm); }\n    fenwick_tree(const vector< T > &a) : n(a.size()),\
    \ n2(ceil_pow2(n)), data(a) {\n        assert(comm_monoid::comm);\n        data.insert(data.begin(),\
    \ {comm_monoid::id()});\n        for(int i = 1; i <= n; i++) {\n            int\
    \ p = i + (i & -i);\n            if(p <= n) data[p] = comm_monoid::op(data[i],\
    \ data[p]);\n        }\n    }\n\n    void add(int i, T x) {\n        for(int p\
    \ = i + 1; p <= n; p += p & -p) data[p] = comm_monoid::op(data[p], x);\n    }\n\
    \    // [0, r)\n    T fold(int r) {\n        T s = comm_monoid::id();\n      \
    \  for(int p = r; p > 0; p -= p & -p) s = comm_monoid::op(data[p], s);\n     \
    \   return s;\n    }\n    // [l, r)\n    T fold(int l, int r) {\n        return\
    \ comm_monoid::op(comm_monoid::inv(fold(l)), fold(r));\n    }\n    T get(int i)\
    \ {\n        return fold(i, i + 1);\n    }\n    void set(int i, T x) {\n     \
    \   add(i, comm_monoid::op(comm_monoid::inv(get(i)), x));\n    }\n    template<\
    \ class func > int search(const func &f) {\n        T s = comm_monoid::id();\n\
    \        if(f(s)) return 0;\n        int i = 0, k = n2;\n        while(k >>= 1)\
    \ {\n            int p = i | k;\n            if(p <= n && !f(comm_monoid::op(s,\
    \ data[p]))) s = comm_monoid::op(s, data[i = p]);\n        }\n        return i;\n\
    \    }\n};\n#line 4 \"src/data_structure/static_point_add_rect_sum.hpp\"\n\nnamespace\
    \ tag {\n\nstruct STATIC;\nstruct DYNAMIC;\n\nstruct POINT;\nstruct RECTANGLE;\n\
    \n}\n\ntemplate < class SD, class ADD_TYPE, class T, class abel_group >\nstruct\
    \ rect_sum {};\n\ntemplate < class T, class abel_group >\nstruct rect_sum < tag::STATIC,\
    \ tag::POINT, T, abel_group > {\n    using W = typename abel_group::set;\n   \
    \ vector<tuple< T, T, W >> P;\n    vector<tuple< T, T, T, T >> R;\n    zipper<\
    \ T > X, Y;\n    rect_sum() {}\n    void add(T x, T y, W w) {\n        P.emplace_back(x,\
    \ y, w);\n        X.insert(x); Y.insert(y);\n    }\n    void query(T xL, T xR,\
    \ T yL, T yR) {\n        R.emplace_back(xL, xR, yL, yR);\n        X.insert(xL);\
    \ X.insert(xR);\n        Y.insert(yL); Y.insert(yR);\n    }\n\n    vector< W >\
    \ solve() {\n        X.build(); Y.build();\n        vector< vector< pair< int,\
    \ W > > > P2(X.size());\n        vector< vector< tuple< int, int, int, int > >\
    \ > R2(X.size());\n        for(auto [x, y, w] : P) P2[X.id(x)].emplace_back(Y.id(y),\
    \ w);\n        for(int i : rep(R.size())) {\n            auto [xL, xR, yL, yR]\
    \ = R[i];\n            int iyL = Y.id(yL), iyR = Y.id(yR);\n            R2[X.id(xL)].emplace_back(iyL,\
    \ iyR, i, 1);\n            R2[X.id(xR)].emplace_back(iyL, iyR, i, 0);\n      \
    \  }\n\n        vector< W > ans(R.size(), abel_group::id());\n        fenwick_tree<\
    \ abel_group > bit(Y.size());\n        for(int x : rep(X.size())) {\n        \
    \    for(auto [yL, yR, i, inv] : R2[x]) {\n                W w = bit.fold(yL,\
    \ yR);\n                if(inv) w = abel_group::inv(w);\n                ans[i]\
    \ = abel_group::op(ans[i], w);\n            }\n            for(auto [y, w] : P2[x])\
    \ bit.add(y, w);\n        }\n        return ans;\n    }\n};\n#line 1 \"src/algebra/sum.hpp\"\
    \ntemplate < class T > class sum_monoid {\n  public:\n    using set = T;\n   \
    \ static constexpr T op(const T &l, const T &r) { return l + r; }\n    static\
    \ constexpr T id() { return T(0); }\n    static constexpr T inv(const T &x) {\
    \ return -x; }\n    static constexpr T pow(const T &x, const ll n) { return x\
    \ * n; }\n    static constexpr bool comm = true;\n};\n#line 5 \"verify/library_checker/data_structure/rectangle_sum.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    rect_sum< tag::STATIC, tag::POINT,\
    \ int, sum_monoid<ll> > rs;\n    for(int i : rep(N)) {\n        int x = in(),\
    \ y = in(), w = in();\n        rs.add(x, y, w);\n    }\n    for(int i : rep(Q))\
    \ {\n        int l = in(), d = in(), r = in(), u = in();\n        rs.query(l,\
    \ r, d, u);\n    }\n    print(rs.solve(), '\\n');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/static_point_add_rect_sum.hpp\"\
    \n#include \"../../../src/algebra/sum.hpp\"\n\nint main() {\n    int N = in(),\
    \ Q = in();\n    rect_sum< tag::STATIC, tag::POINT, int, sum_monoid<ll> > rs;\n\
    \    for(int i : rep(N)) {\n        int x = in(), y = in(), w = in();\n      \
    \  rs.add(x, y, w);\n    }\n    for(int i : rep(Q)) {\n        int l = in(), d\
    \ = in(), r = in(), u = in();\n        rs.query(l, r, d, u);\n    }\n    print(rs.solve(),\
    \ '\\n');\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/utility/zip.hpp
  - src/data_structure/fenwick_tree.hpp
  - src/algebra/sum.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 09:21:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/rectangle_sum.test.cpp
- /verify/verify/library_checker/data_structure/rectangle_sum.test.cpp.html
title: verify/library_checker/data_structure/rectangle_sum.test.cpp
---
