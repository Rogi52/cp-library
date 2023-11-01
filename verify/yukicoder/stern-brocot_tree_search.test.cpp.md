---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':question:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':x:'
    path: src/algorithm/enumrate_quotient.hpp
    title: src/algorithm/enumrate_quotient.hpp
  - icon: ':x:'
    path: src/algorithm/floor_sum.hpp
    title: src/algorithm/floor_sum.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':x:'
    path: src/number/stern-brocot_tree.hpp
    title: src/number/stern-brocot_tree.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/2262
    links:
    - https://yukicoder.me/problems/no/2262
  bundledCode: "#line 1 \"verify/yukicoder/stern-brocot_tree_search.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/2262\"\n\n#line 2 \"src/cp-template.hpp\"\
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
    \        if(over()) return sbt_n.upper_bound();\n        sgn *= -1;\n    }\n}\n\
    #line 2 \"src/algorithm/floor_sum.hpp\"\n\n// sum_{i in [0, n)} floor((a * i +\
    \ b) / m) \nll floor_sum(ll n, ll m, ll a, ll b) {\n    if(n == 0) return ll(0);\n\
    \    ll ans = 0;\n    ans += (n - 1) * n / 2 * (a / m), a %= m;\n    ans += n\
    \ * (b / m), b %= m;\n    ll y_max = a * n + b;\n    ans += floor_sum(y_max /\
    \ m, a, m, y_max % m);\n    return ans;\n}\n#line 1 \"src/algorithm/enumrate_quotient.hpp\"\
    \n// x in [L, R), floor(N/x) == Q\ntemplate < class T, class F >\nvoid for_each_quotient(T\
    \ N, const F& f) {\n    for(T L = 1; L <= N;) {\n        T Q = N / L, R = N /\
    \ Q + 1;\n        f(L, R, Q);\n        L = R;\n    }\n}\n#line 7 \"verify/yukicoder/stern-brocot_tree_search.test.cpp\"\
    \n\nint main() {\n    ll N = in(), K = in();\n\n    /* Mertens */\n    const ll\
    \ B = 10'000;\n    std::vector<ll> bs(N / B + 1, 1), gs(B + 1, 1), vis(N / B +\
    \ 1, 0);\n    bs[0] = gs[0] = 0;\n    for(ll i : rep(2LL, N / B + 1)) if(not vis[i])\
    \ {\n        bs[i] *= -1;\n        for(ll j : rep(2*i, N / B + 1, i)) {\n    \
    \        vis[j] = 1;\n            if((j / i) % i == 0)\n                bs[j]\
    \ = 0;\n            else\n                bs[j] *= -1;\n        }\n    }\n   \
    \ for(ll i : rep(1LL, N / B)) bs[i + 1] += bs[i];\n    for(ll i : revrep(1LL,\
    \ B + 1)) {\n        for(ll L = 2; L <= N / i; ) {\n            ll Q = N / (i\
    \ * L), R = N / (i * Q) + 1;\n            gs[i] -= (i * L <= B ? gs[i * L] : bs[N\
    \ / (i * L)]) * (R - L);\n            L = R;\n        }\n    }\n    auto M = [&](ll\
    \ x) {\n        if(x < ll(bs.size())) {\n            return bs[x];\n        }\
    \ else {\n            return gs[N / x];\n        }\n    };\n\n    auto count =\
    \ [&](std::pair<ll,ll> x) {\n        ll ans = 0;\n        ll upper, lower; std::tie(upper,\
    \ lower) = x;\n        for_each_quotient(N, [&](ll L, ll R, ll Q) {\n        \
    \    ans += M(Q) * (floor_sum(R, lower, upper, 0) - floor_sum(L, lower, upper,\
    \ 0));\n        });\n        return ans;\n    };\n\n    ll C = count({N - 1, N});\n\
    \    if(K == C + 1) return print(\"1/1\");\n\n    bool rev = false;\n    if(K\
    \ <= C) {}\n    else if(K <= 2 * C + 1) {\n        rev = true;\n        K = 2\
    \ * C + 2 - K;\n    } else {\n        return print(-1);\n    }\n\n    auto [f,\
    \ g] = sbt_search(N, [&](std::pair<ll,ll> x) {\n        return count(x) >= K;\n\
    \    });\n\n    if(rev) std::swap(f, g);\n    std::cout << f << \"/\" << g <<\
    \ std::endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2262\"\n\n#include \"\
    ../../src/cp-template.hpp\"\n#include \"../../src/number/stern-brocot_tree.hpp\"\
    \n#include \"../../src/algorithm/floor_sum.hpp\"\n#include \"../../src/algorithm/enumrate_quotient.hpp\"\
    \n\nint main() {\n    ll N = in(), K = in();\n\n    /* Mertens */\n    const ll\
    \ B = 10'000;\n    std::vector<ll> bs(N / B + 1, 1), gs(B + 1, 1), vis(N / B +\
    \ 1, 0);\n    bs[0] = gs[0] = 0;\n    for(ll i : rep(2LL, N / B + 1)) if(not vis[i])\
    \ {\n        bs[i] *= -1;\n        for(ll j : rep(2*i, N / B + 1, i)) {\n    \
    \        vis[j] = 1;\n            if((j / i) % i == 0)\n                bs[j]\
    \ = 0;\n            else\n                bs[j] *= -1;\n        }\n    }\n   \
    \ for(ll i : rep(1LL, N / B)) bs[i + 1] += bs[i];\n    for(ll i : revrep(1LL,\
    \ B + 1)) {\n        for(ll L = 2; L <= N / i; ) {\n            ll Q = N / (i\
    \ * L), R = N / (i * Q) + 1;\n            gs[i] -= (i * L <= B ? gs[i * L] : bs[N\
    \ / (i * L)]) * (R - L);\n            L = R;\n        }\n    }\n    auto M = [&](ll\
    \ x) {\n        if(x < ll(bs.size())) {\n            return bs[x];\n        }\
    \ else {\n            return gs[N / x];\n        }\n    };\n\n    auto count =\
    \ [&](std::pair<ll,ll> x) {\n        ll ans = 0;\n        ll upper, lower; std::tie(upper,\
    \ lower) = x;\n        for_each_quotient(N, [&](ll L, ll R, ll Q) {\n        \
    \    ans += M(Q) * (floor_sum(R, lower, upper, 0) - floor_sum(L, lower, upper,\
    \ 0));\n        });\n        return ans;\n    };\n\n    ll C = count({N - 1, N});\n\
    \    if(K == C + 1) return print(\"1/1\");\n\n    bool rev = false;\n    if(K\
    \ <= C) {}\n    else if(K <= 2 * C + 1) {\n        rev = true;\n        K = 2\
    \ * C + 2 - K;\n    } else {\n        return print(-1);\n    }\n\n    auto [f,\
    \ g] = sbt_search(N, [&](std::pair<ll,ll> x) {\n        return count(x) >= K;\n\
    \    });\n\n    if(rev) std::swap(f, g);\n    std::cout << f << \"/\" << g <<\
    \ std::endl;\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/number/stern-brocot_tree.hpp
  - src/algorithm/floor_sum.hpp
  - src/algorithm/enumrate_quotient.hpp
  isVerificationFile: true
  path: verify/yukicoder/stern-brocot_tree_search.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 09:21:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yukicoder/stern-brocot_tree_search.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/stern-brocot_tree_search.test.cpp
- /verify/verify/yukicoder/stern-brocot_tree_search.test.cpp.html
title: verify/yukicoder/stern-brocot_tree_search.test.cpp
---
