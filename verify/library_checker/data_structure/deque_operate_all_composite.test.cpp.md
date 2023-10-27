---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/affine.hpp
    title: src/algebra/affine.hpp
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
    path: src/data_structure/sliding_window_aggregation.hpp
    title: src/data_structure/sliding_window_aggregation.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"verify/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\ntemplate < class T, class\
    \ U > T ceil (T x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y);\
    \ }\ntemplate < class T, class U > T floor(T x, U y) { return (x > 0 ?       \
    \    x / y : (x - y + 1) / y); }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate\
    \ < class T > struct itr_rep {\n    T i, d;\n    constexpr itr_rep(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr_rep(const T i, const T d) noexcept\
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
    \ 2 \"src/data_structure/sliding_window_aggregation.hpp\"\n\ntemplate < class\
    \ monoid >\nstruct swag_queue {\n  public:\n    using T = typename monoid::set;\n\
    \    class node {\n      public:\n        T value, sum;\n        node() : value(monoid::id()),\
    \ sum(monoid::id()) {}\n        node(const T& value, const T& sum) : value(value),\
    \ sum(sum) {}\n    };\n    std::stack<node> front_stack, back_stack;\n\n  public:\n\
    \    swag_queue() { front_stack.push(node()), back_stack.push(node()); }\n   \
    \ int size() const {\n        return (int(front_stack.size()) - 1) + (int(back_stack.size())\
    \ - 1);\n    }\n    bool empty() const {\n        return size() == 0;\n    }\n\
    \    T fold() const {\n        return monoid::op(front_stack.top().sum, back_stack.top().sum);\n\
    \    }\n    void push(const T& x) {\n        back_stack.push(node(x, monoid::op(back_stack.top().sum,\
    \ x)));\n    }\n    void pop() {\n        assert(not empty());\n        if(front_stack.size()\
    \ == 1) {\n            while(back_stack.size() > 1) {\n                front_stack.push(node(back_stack.top().value,\
    \ monoid::op(back_stack.top().value, front_stack.top().sum)));\n             \
    \   back_stack.pop();\n            }\n        }\n        front_stack.pop();\n\
    \    }\n};\n\ntemplate < class monoid >\nstruct swag_deque {\n  private:\n   \
    \ using T = typename monoid::set;\n    class node {\n      public:\n        T\
    \ value, sum;\n        node() : value(monoid::id()), sum(monoid::id()) {}\n  \
    \      node(const T& value, const T& sum) : value(value), sum(sum) {}\n    };\n\
    \    std::stack<node> front_stack, back_stack;\n\n  public:\n    swag_deque()\
    \ { front_stack.push(node()), back_stack.push(node()); }\n    int size() const\
    \ { return (int(front_stack.size()) - 1) + (int(back_stack.size()) - 1); }\n \
    \   bool empty() const { return size() == 0; }\n\n    T fold() const { return\
    \ monoid::op(front_stack.top().sum, back_stack.top().sum); }\n    void push_front(const\
    \ T& x) { push(front_stack, x, 1); }\n    void push_back (const T& x) { push(\
    \ back_stack, x, 0); }\n    void pop_front() { assert(not empty()); if(front_stack.size()\
    \ == 1) amortize( back_stack, front_stack, 1); front_stack.pop(); }\n    void\
    \ pop_back () { assert(not empty()); if( back_stack.size() == 1) amortize(front_stack,\
    \  back_stack, 0);  back_stack.pop(); }\n\n  private:\n    void push(std::stack<node>&\
    \ st, const T& x, int f) {\n        st.push(node(x, f ? monoid::op(x, st.top().sum)\
    \ : monoid::op(st.top().sum, x)));\n    }\n    void amortize(std::stack<node>&\
    \ from, std::stack<node>& to, int f) {\n        std::stack< T > st;\n        while(st.size()\
    \ < from.size() - 2) st.push(from.top().value), from.pop();\n        while(from.size()\
    \ > 1) push(to, from.top().value, f), from.pop();\n        while(not st.empty())\
    \ push(from, st.top(), 1 - f), st.pop();\n        printer::flush();\n    }\n};\n\
    #line 2 \"src/number/modint.hpp\"\nstruct modinfo { uint mod, root, isprime; };\n\
    template < modinfo const &ref >\nstruct modint {\n    static constexpr uint const\
    \ &mod = ref.mod;\n    static constexpr uint const &root = ref.root;\n    static\
    \ constexpr uint const &isprime = ref.isprime;\n    uint v = 0;\n    constexpr\
    \ modint& s(uint v) { this->v = v < mod ? v : v - mod; return *this; }\n    constexpr\
    \ modint(ll v = 0) { s(v % mod + mod); }\n    modint operator-() const { return\
    \ modint() - *this; }\n    modint& operator+=(const modint& rhs) { return s(v\
    \ + rhs.v); }\n    modint& operator-=(const modint& rhs) { return s(v + mod -\
    \ rhs.v); }\n    modint& operator*=(const modint& rhs) { v = ull(v) * rhs.v %\
    \ mod; return *this; }\n    modint& operator/=(const modint& rhs) { return *this\
    \ *= inv(rhs); }\n    modint operator+(const modint& rhs) const { return modint(*this)\
    \ += rhs; }\n    modint operator-(const modint& rhs) const { return modint(*this)\
    \ -= rhs; }\n    modint operator*(const modint& rhs) const { return modint(*this)\
    \ *= rhs; }\n    modint operator/(const modint& rhs) const { return modint(*this)\
    \ /= rhs; }\n    friend modint pow(modint x, ll n) { modint res(1); while(n >\
    \ 0) { if(n & 1) res *= x; x *= x; n >>= 1; } return res; }\n    friend modint\
    \ inv(modint v) {\n        if(isprime) {\n            return pow(v, mod - 2);\n\
    \        } else {\n            ll a = v.v, b = modint::mod, x = 1, y = 0, t;\n\
    \            while(b > 0) { t = a / b; swap(a -= t * b, b); swap(x -= t * y, y);\
    \ }\n            return modint(x);\n        }\n    }\n    friend modint operator+(int\
    \ x, const modint& y) { return modint(x) + y; }\n    friend modint operator-(int\
    \ x, const modint& y) { return modint(x) - y; }\n    friend modint operator*(int\
    \ x, const modint& y) { return modint(x) * y; }\n    friend modint operator/(int\
    \ x, const modint& y) { return modint(x) / y; }\n    friend istream& operator>>(istream&\
    \ is, modint& m) { ll x; is >> x; m = modint(x); return is; }\n    friend ostream&\
    \ operator<<(ostream& os, const modint& m) { return os << m.v; }\n    bool operator==(const\
    \ modint& r) const { return v == r.v; }\n    bool operator!=(const modint& r)\
    \ const { return v != r.v; }\n    static uint get_mod() { return mod; }\n    static\
    \ int is_prime() { return isprime; }\n};\nconstexpr modinfo base998244353 { 998244353,\
    \ 3, 1 };\nconstexpr modinfo base1000000007 { 1000000007, 0, 1 };\nusing mint998244353\
    \ = modint< base998244353 >;\nusing mint1000000007 = modint< base1000000007 >;\n\
    #line 1 \"src/algebra/affine.hpp\"\ntemplate < class T > class affine {\n  public:\n\
    \    T a, b; // ax + b\n    constexpr affine() = default;\n    constexpr affine(const\
    \ T &a, const T &b) : a(a), b(b) {}\n    constexpr T eval(const T &x) const {\
    \ return x * a + b; }\n    constexpr affine composite(const affine &r) const {\n\
    \        return affine(a * r.a, b * r.a + r.b);\n    }\n    static constexpr affine\
    \ id() {\n        return affine(T(1), T(0));\n    }\n};\n\ntemplate < class T\
    \ > class affine_composite_monoid {\n  public:\n    using F = affine< T >;\n \
    \   using set = F;\n    static constexpr F op(const F &l, const F &r) { return\
    \ l.composite(r); }\n    static constexpr F id() { return F::id(); }\n};\n#line\
    \ 7 \"verify/library_checker/data_structure/deque_operate_all_composite.test.cpp\"\
    \n\nint main() {\n    using mint = mint998244353;\n    swag_deque<affine_composite_monoid<mint>>\
    \ que;\n\n    int Q = in();\n    for(int _ : rep(Q)) {\n        int t = in();\n\
    \        if(t == 0) {\n            mint a = in(), b = in();\n            que.push_front(affine<mint>(a,\
    \ b));\n        }\n        if(t == 1) {\n            mint a = in(), b = in();\n\
    \            que.push_back(affine<mint>(a, b));\n        }\n        if(t == 2)\
    \ {\n            que.pop_front();\n        }\n        if(t == 3) {\n         \
    \   que.pop_back();\n        }\n        if(t == 4) {\n            mint x = in();\n\
    \            print(que.fold().eval(x));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/sliding_window_aggregation.hpp\"\
    \n#include \"../../../src/number/modint.hpp\"\n#include \"../../../src/algebra/affine.hpp\"\
    \n\nint main() {\n    using mint = mint998244353;\n    swag_deque<affine_composite_monoid<mint>>\
    \ que;\n\n    int Q = in();\n    for(int _ : rep(Q)) {\n        int t = in();\n\
    \        if(t == 0) {\n            mint a = in(), b = in();\n            que.push_front(affine<mint>(a,\
    \ b));\n        }\n        if(t == 1) {\n            mint a = in(), b = in();\n\
    \            que.push_back(affine<mint>(a, b));\n        }\n        if(t == 2)\
    \ {\n            que.pop_front();\n        }\n        if(t == 3) {\n         \
    \   que.pop_back();\n        }\n        if(t == 4) {\n            mint x = in();\n\
    \            print(que.fold().eval(x));\n        }\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/sliding_window_aggregation.hpp
  - src/number/modint.hpp
  - src/algebra/affine.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2023-10-28 05:38:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
- /verify/verify/library_checker/data_structure/deque_operate_all_composite.test.cpp.html
title: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
---
