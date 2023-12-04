---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ 2 \"src/number/stern-brocot_tree.hpp\"\n\ntemplate < class T >\nT sgn(T x) {\n\
    \    return (0 < x) - (x < 0);\n}\n\ntemplate < class I >\nclass stern_brocot_tree_node\
    \ {\n    struct fraction {\n        I upper, lower;\n        fraction(I upper\
    \ = 0, I lower = 1) : upper(upper), lower(lower) {}\n        fraction& operator+=(const\
    \ fraction& r) {\n            this->upper += r.upper;\n            this->lower\
    \ += r.lower;\n            return *this;\n        }\n        fraction& operator-=(const\
    \ fraction& r) {\n            this->upper -= r.upper;\n            this->lower\
    \ -= r.lower;\n            return *this;\n        }\n        fraction& operator*=(I\
    \ v) {\n            this->upper *= v;\n            this->lower *= v;\n       \
    \     return *this;\n        }\n        fraction operator+(const fraction& r)\
    \ const { return fraction(*this) += r; }\n        fraction operator-(const fraction&\
    \ r) const { return fraction(*this) -= r; }\n        fraction operator*(I v) {\
    \ return fraction(*this) *= v; }\n    };\n    fraction L, M, R;\n\n  public:\n\
    \    std::vector< I > history;\n    I depth;\n\n    stern_brocot_tree_node() :\
    \ L(0, 1), M(1, 1), R(1, 0), depth(0) {}\n    stern_brocot_tree_node(I a, I b)\
    \ : stern_brocot_tree_node() {\n        assert(1 <= a);\n        assert(1 <= b);\n\
    \        I s = a < b ? -1 : +1;\n        if(s == -1) std::swap(a, b);\n      \
    \  for(; b != 0; s *= -1) {\n            auto [q, r] = std::div(a, b);\n     \
    \       down(s * (q - (r == 0)));\n            a = b, b = r;\n        }\n    }\n\
    \    stern_brocot_tree_node(std::vector< I > history) : stern_brocot_tree_node()\
    \ {\n        for(I k : history) down(k);\n        assert(this->history == history);\n\
    \    }\n    using sbt_n = stern_brocot_tree_node< I >;\n\n    std::pair< I, I\
    \ > value()       { return std::make_pair(M.upper, M.lower); }\n    std::pair<\
    \ I, I > lower_bound() { return std::make_pair(L.upper, L.lower); }\n    std::pair<\
    \ I, I > upper_bound() { return std::make_pair(R.upper, R.lower); }\n\n    void\
    \ down_left(I k) {\n        assert(1 <= k);\n        std::tie(L, M, R)\n     \
    \       = std::make_tuple(L, L * k + M, L * (k - 1) + M);\n        history.push_back(-k);\n\
    \        depth += k;\n    }\n    void down_right(I k) {\n        assert(1 <= k);\n\
    \        std::tie(L, M, R)\n            = std::make_tuple(R * (k - 1) + M, R *\
    \ k + M, R);\n        history.push_back(+k);\n        depth += k;\n    }\n   \
    \ void down(I k) {\n        switch(sgn(k)) {\n            case  0: return;\n \
    \           case -1: return down_left (-k);\n            case +1: return down_right(+k);\n\
    \        }\n    }\n    void up(I k) {\n        assert(0 <= k and k <= depth);\n\
    \        while(k != 0) {\n            I x = std::min(k, std::abs(history.back()));\n\
    \            if(history.back() > 0) {\n                std::tie(L, M, R)\n   \
    \                 = std::make_tuple(L - R * x, L - R * (x - 1), R);\n        \
    \        history.back() -= x;\n            } else {\n                std::tie(L,\
    \ M, R)\n                    = std::make_tuple(L, R - L * (x - 1), R - L * x);\n\
    \                history.back() += x;\n            }\n            if(history.back()\
    \ == 0) history.pop_back();\n            k -= x;\n            depth -= x;\n  \
    \      }\n    }\n    friend sbt_n lca(const sbt_n& L, const sbt_n& R) {\n    \
    \    sbt_n M;\n        for(int i : rep(min(L.history.size(), R.history.size())))\
    \ {\n            I Lx = L.history[i], Rx = R.history[i];\n            if(sgn(Lx)\
    \ == sgn(Rx)) {\n                M.down(sgn(Lx) * std::min(abs(Lx), abs(Rx)));\n\
    \                if(Lx != Rx) break;\n            } else break;\n        }\n \
    \       return M;\n    }\n};\n\ntemplate < class I, class F >\nstd::pair< I, I\
    \ > sbt_search(const I N, const F& f) {\n    assert(1 <= N);\n    if(f({0, 1}))\
    \ return {0, 1};\n\n    stern_brocot_tree_node< I > sbt_n;\n    auto over = [&]()\
    \ {\n        auto [a, b] = sbt_n.value();\n        return std::max(a, b) > N;\n\
    \    };\n    int sgn = f(sbt_n.value()) ? -1 : +1;\n    auto ng = [&]() { return\
    \ over() or f(sbt_n.value()) == (sgn > 0); };\n\n    while(true) {\n        I\
    \ x = 1;\n        while(true) {\n            sbt_n.down(x * sgn);\n          \
    \  if(ng()) { sbt_n.up(x); break; }\n            x *= 2;\n        }\n        x\
    \ /= 2;\n        while(x > 0) {\n            sbt_n.down(x * sgn);\n          \
    \  if(ng()) sbt_n.up(x);\n            x /= 2;\n        }\n        sbt_n.down(sgn);\n\
    \        if(over()) return sbt_n.upper_bound();\n        sgn *= -1;\n    }\n}\n"
  code: "#include \"../../src/cp-template.hpp\"\n\ntemplate < class T >\nT sgn(T x)\
    \ {\n    return (0 < x) - (x < 0);\n}\n\ntemplate < class I >\nclass stern_brocot_tree_node\
    \ {\n    struct fraction {\n        I upper, lower;\n        fraction(I upper\
    \ = 0, I lower = 1) : upper(upper), lower(lower) {}\n        fraction& operator+=(const\
    \ fraction& r) {\n            this->upper += r.upper;\n            this->lower\
    \ += r.lower;\n            return *this;\n        }\n        fraction& operator-=(const\
    \ fraction& r) {\n            this->upper -= r.upper;\n            this->lower\
    \ -= r.lower;\n            return *this;\n        }\n        fraction& operator*=(I\
    \ v) {\n            this->upper *= v;\n            this->lower *= v;\n       \
    \     return *this;\n        }\n        fraction operator+(const fraction& r)\
    \ const { return fraction(*this) += r; }\n        fraction operator-(const fraction&\
    \ r) const { return fraction(*this) -= r; }\n        fraction operator*(I v) {\
    \ return fraction(*this) *= v; }\n    };\n    fraction L, M, R;\n\n  public:\n\
    \    std::vector< I > history;\n    I depth;\n\n    stern_brocot_tree_node() :\
    \ L(0, 1), M(1, 1), R(1, 0), depth(0) {}\n    stern_brocot_tree_node(I a, I b)\
    \ : stern_brocot_tree_node() {\n        assert(1 <= a);\n        assert(1 <= b);\n\
    \        I s = a < b ? -1 : +1;\n        if(s == -1) std::swap(a, b);\n      \
    \  for(; b != 0; s *= -1) {\n            auto [q, r] = std::div(a, b);\n     \
    \       down(s * (q - (r == 0)));\n            a = b, b = r;\n        }\n    }\n\
    \    stern_brocot_tree_node(std::vector< I > history) : stern_brocot_tree_node()\
    \ {\n        for(I k : history) down(k);\n        assert(this->history == history);\n\
    \    }\n    using sbt_n = stern_brocot_tree_node< I >;\n\n    std::pair< I, I\
    \ > value()       { return std::make_pair(M.upper, M.lower); }\n    std::pair<\
    \ I, I > lower_bound() { return std::make_pair(L.upper, L.lower); }\n    std::pair<\
    \ I, I > upper_bound() { return std::make_pair(R.upper, R.lower); }\n\n    void\
    \ down_left(I k) {\n        assert(1 <= k);\n        std::tie(L, M, R)\n     \
    \       = std::make_tuple(L, L * k + M, L * (k - 1) + M);\n        history.push_back(-k);\n\
    \        depth += k;\n    }\n    void down_right(I k) {\n        assert(1 <= k);\n\
    \        std::tie(L, M, R)\n            = std::make_tuple(R * (k - 1) + M, R *\
    \ k + M, R);\n        history.push_back(+k);\n        depth += k;\n    }\n   \
    \ void down(I k) {\n        switch(sgn(k)) {\n            case  0: return;\n \
    \           case -1: return down_left (-k);\n            case +1: return down_right(+k);\n\
    \        }\n    }\n    void up(I k) {\n        assert(0 <= k and k <= depth);\n\
    \        while(k != 0) {\n            I x = std::min(k, std::abs(history.back()));\n\
    \            if(history.back() > 0) {\n                std::tie(L, M, R)\n   \
    \                 = std::make_tuple(L - R * x, L - R * (x - 1), R);\n        \
    \        history.back() -= x;\n            } else {\n                std::tie(L,\
    \ M, R)\n                    = std::make_tuple(L, R - L * (x - 1), R - L * x);\n\
    \                history.back() += x;\n            }\n            if(history.back()\
    \ == 0) history.pop_back();\n            k -= x;\n            depth -= x;\n  \
    \      }\n    }\n    friend sbt_n lca(const sbt_n& L, const sbt_n& R) {\n    \
    \    sbt_n M;\n        for(int i : rep(min(L.history.size(), R.history.size())))\
    \ {\n            I Lx = L.history[i], Rx = R.history[i];\n            if(sgn(Lx)\
    \ == sgn(Rx)) {\n                M.down(sgn(Lx) * std::min(abs(Lx), abs(Rx)));\n\
    \                if(Lx != Rx) break;\n            } else break;\n        }\n \
    \       return M;\n    }\n};\n\ntemplate < class I, class F >\nstd::pair< I, I\
    \ > sbt_search(const I N, const F& f) {\n    assert(1 <= N);\n    if(f({0, 1}))\
    \ return {0, 1};\n\n    stern_brocot_tree_node< I > sbt_n;\n    auto over = [&]()\
    \ {\n        auto [a, b] = sbt_n.value();\n        return std::max(a, b) > N;\n\
    \    };\n    int sgn = f(sbt_n.value()) ? -1 : +1;\n    auto ng = [&]() { return\
    \ over() or f(sbt_n.value()) == (sgn > 0); };\n\n    while(true) {\n        I\
    \ x = 1;\n        while(true) {\n            sbt_n.down(x * sgn);\n          \
    \  if(ng()) { sbt_n.up(x); break; }\n            x *= 2;\n        }\n        x\
    \ /= 2;\n        while(x > 0) {\n            sbt_n.down(x * sgn);\n          \
    \  if(ng()) sbt_n.up(x);\n            x /= 2;\n        }\n        sbt_n.down(sgn);\n\
    \        if(over()) return sbt_n.upper_bound();\n        sgn *= -1;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/number/stern-brocot_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/number/stern-brocot_tree.hpp
layout: document
redirect_from:
- /library/src/number/stern-brocot_tree.hpp
- /library/src/number/stern-brocot_tree.hpp.html
title: src/number/stern-brocot_tree.hpp
---
