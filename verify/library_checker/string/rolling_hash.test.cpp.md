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
    path: src/string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':x:'
    path: src/utility/hash.hpp
    title: src/utility/hash.hpp
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
    path: src/utility/random.hpp
    title: src/utility/random.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#line 2 \"\
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
    \ 3 \"src/utility/random.hpp\"\n\nnamespace randnum {\n\nstatic uint seed;\nstatic\
    \ std::mt19937 mt;\nstruct gen_seed {\n    gen_seed() {\n        seed = std::random_device()();\n\
    \        mt = std::mt19937(seed);\n    }\n} gs;\n\n// [L, R)\ntemplate < class\
    \ T >\nT gen_int(T L, T R) {\n    return std::uniform_int_distribution< T >(L,\
    \ R - 1)(mt);\n}\n\ntemplate < class T >\nT get_real(T L, T R) {\n    return std::uniform_real_distribution<\
    \ T >(L, R)(mt);\n}\n\n}\n#line 3 \"src/utility/hash.hpp\"\n\ntemplate < int num_of_mod\
    \ = 2 >\nstruct hash_vector : public array<ll, num_of_mod> {\n    static constexpr\
    \ ll MODS[] = {999999937, 1000000007, 1000000009, 1000000021};\n    static_assert(1\
    \ <= num_of_mod and num_of_mod <= 4);\n    using array<ll, num_of_mod>::operator[];\n\
    \    using H = hash_vector;\n    static constexpr int n = num_of_mod;\n    hash_vector()\
    \ : array<ll,n>() {}\n    hash_vector(ll x) : H() { for(int i : rep(n)) (*this)[i]\
    \ = x % MODS[i]; }\n    H& operator+=(const H& rhs) { for(int i : rep(n)) if(((*this)[i]\
    \ += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n    H& operator-=(const\
    \ H& rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs[i]) >= MODS[i])\
    \ (*this)[i] -= MODS[i]; return *this; }\n    H& operator*=(const H& rhs) { for(int\
    \ i : rep(n)) (*this)[i] = (*this)[i] * rhs[i] % MODS[i]; return *this; }\n  \
    \  H& operator+=(const ll rhs) { for(int i : rep(n)) if(((*this)[i] += rhs % MODS[i])\
    \ >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n    H& operator-=(const\
    \ ll rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs % MODS[i]) >=\
    \ MODS[i]) (*this)[i] -= MODS[i]; return *this; }\n    H& operator*=(const ll\
    \ rhs) { for(int i : rep(n)) (*this)[i] = (*this)[i] * (rhs % MODS[i]) % MODS[i];\
    \ return *this; }\n    H operator+(const H& rhs) const { return H(*this) += rhs;\
    \ }\n    H operator-(const H& rhs) const { return H(*this) -= rhs; }\n    H operator*(const\
    \ H& rhs) const { return H(*this) *= rhs; }\n    H operator+(const ll rhs) const\
    \ { return H(*this) += rhs; }\n    H operator-(const ll rhs) const { return H(*this)\
    \ -= rhs; }\n    H operator*(const ll rhs) const { return H(*this) *= rhs; }\n\
    \    H operator-() const { return H().fill(0) - *this; }\n    friend H operator+(ll\
    \ x, const H& y) { return H(x) + y; }\n    friend H operator-(ll x, const H& y)\
    \ { return H(x) + y; }\n    friend H operator*(ll x, const H& y) { return H(x)\
    \ * y; }\n    bool operator==(const H& rhs) { for(int i : rep(n)) if((*this)[i]\
    \ != rhs[i]) return false; return true ; }\n    bool operator!=(const H& rhs)\
    \ { for(int i : rep(n)) if((*this)[i] != rhs[i]) return true ; return false; }\n\
    };\n#line 4 \"src/string/rolling_hash.hpp\"\n\ntemplate< int num_of_mod = 2 >\n\
    struct rolling_hash {\n\n    static const ll BASE;\n\n    vector< hash_vector<\
    \ num_of_mod > > pb, hs;\n    rolling_hash() {}\n    rolling_hash(const string&\
    \ s) {\n        int n = s.size();\n        hs.resize(n + 1); hs[0].fill(0);\n\
    \        pb.resize(n + 1); pb[0].fill(1);\n        for(int i : rep(n)) {\n   \
    \         hs[i + 1] = hs[i] * BASE + s[i];\n            pb[i + 1] = pb[i] * BASE;\n\
    \        }\n    }\n\n    // [l, r)\n    hash_vector< num_of_mod > get(int l, int\
    \ r) const {\n        return hs[r] - hs[l] * pb[r - l];\n    }\n\n    hash_vector<\
    \ num_of_mod > concat(hash_vector< num_of_mod > h1, hash_vector< num_of_mod >\
    \ h2, int h2_len) {\n        assert(0 <= h2_len and h2_len < int(pb.size()));\n\
    \        return h1 * pb[h2_len] + h2;\n    }\n\n    template < int n >\n    static\
    \ int lcp(const rolling_hash< n >& rh1, int l1, int r1, const rolling_hash< n\
    \ >& rh2, int l2, int r2) {\n        int lo = -1, hi = min(r1 - l1, r2 - l2) +\
    \ 1;\n        while(hi - lo > 1) {\n            int mid = (lo + hi) / 2;\n   \
    \         (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;\n\
    \        }\n        return lo;\n    }\n\n    template < int n >\n    static int\
    \ cmp(const string& s1, const rolling_hash< n >& rh1, int l1, int r1,\n      \
    \             const string& s2, const rolling_hash< n >& rh2, int l2, int r2)\
    \ {\n        int len = lcp(rh1, l1, r1, rh2, l2, r2);\n        if(len == r1 -\
    \ l1 && len == r2 - l2) return 0;\n        if(len == r1 - l1) return -1;\n   \
    \     if(len == r2 - l2) return +1;\n        return (s1[l1 + len] < s2[l2 + len]\
    \ ? -1 : +1);\n    }\n};\n\ntemplate < int num_of_mod >\nconst ll rolling_hash<\
    \ num_of_mod >::BASE = randnum::gen_int<ll>(ll(0), hash_vector< num_of_mod >::MODS[0]);\n\
    #line 5 \"verify/library_checker/string/rolling_hash.test.cpp\"\n\nint main()\
    \ {\n    string s = in();\n    int n = s.size();\n    const int m = 2;\n    rolling_hash<\
    \ m > rh(s);\n    vector<int> I(n);\n    iota(I.begin(), I.end(), 0);\n    sort(I.begin(),\
    \ I.end(), [&](int i, int j) {\n        return rolling_hash< m >::cmp(s, rh, i,\
    \ n, s, rh, j, n) < 0;\n    });\n    print(I);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../../src/cp-template.hpp\"\n#include \"../../../src/string/rolling_hash.hpp\"\
    \n\nint main() {\n    string s = in();\n    int n = s.size();\n    const int m\
    \ = 2;\n    rolling_hash< m > rh(s);\n    vector<int> I(n);\n    iota(I.begin(),\
    \ I.end(), 0);\n    sort(I.begin(), I.end(), [&](int i, int j) {\n        return\
    \ rolling_hash< m >::cmp(s, rh, i, n, s, rh, j, n) < 0;\n    });\n    print(I);\n\
    }\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/string/rolling_hash.hpp
  - src/utility/random.hpp
  - src/utility/hash.hpp
  isVerificationFile: true
  path: verify/library_checker/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 14:59:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/rolling_hash.test.cpp
- /verify/verify/library_checker/string/rolling_hash.test.cpp.html
title: verify/library_checker/string/rolling_hash.test.cpp
---
