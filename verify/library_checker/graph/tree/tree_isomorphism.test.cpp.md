---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/argsort.hpp
    title: src/algorithm/argsort.hpp
  - icon: ':heavy_check_mark:'
    path: src/algorithm/bin_search.hpp
    title: src/algorithm/bin_search.hpp
  - icon: ':heavy_check_mark:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/dp_on_tree.hpp
    title: src/graph/tree/dp_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/tree/tree_isomorphism.hpp
    title: src/graph/tree/tree_isomorphism.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/hash.hpp
    title: src/utility/hash.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/heap.hpp
    title: src/utility/heap.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/key_val.hpp
    title: src/utility/key_val.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/random.hpp
    title: src/utility/random.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':heavy_check_mark:'
    path: src/utility/vec_op.hpp
    title: src/utility/vec_op.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/graph/tree/tree_isomorphism.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 3 \"\
    src/utility/heap.hpp\"\n\ntemplate < class T > using heap_min = std::priority_queue<\
    \ T, std::vector< T >, std::greater< T > >;\ntemplate < class T > using heap_max\
    \ = std::priority_queue< T, std::vector< T >, std::less< T > >;\n\n#line 17 \"\
    src/cp-template.hpp\"\n\n#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate <\
    \ class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok - ng)\
    \ > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line\
    \ 2 \"src/algorithm/argsort.hpp\"\n\ntemplate < class T > std::vector< int > argsort(const\
    \ std::vector< T > &a) {\n    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n\
    \        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n\
    }\n#line 3 \"src/utility/hash.hpp\"\n\ntemplate < int num_of_mod = 2 >\nstruct\
    \ hash_vector : public array<ll, num_of_mod> {\n    static constexpr ll MODS[]\
    \ = {999999937, 1000000007, 1000000009, 1000000021};\n    static_assert(1 <= num_of_mod\
    \ and num_of_mod <= 4);\n    using array<ll, num_of_mod>::operator[];\n    using\
    \ H = hash_vector;\n    static constexpr int n = num_of_mod;\n    hash_vector()\
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
    };\n#line 3 \"src/utility/random.hpp\"\n\nnamespace randnum {\n\nstatic uint seed;\n\
    static std::mt19937 mt;\nstruct gen_seed {\n    gen_seed() {\n        seed = std::random_device()();\n\
    \        mt = std::mt19937(seed);\n    }\n} gs;\n\n// [L, R)\ntemplate < class\
    \ T >\nT gen_int(T L, T R) {\n    return std::uniform_int_distribution< T >(L,\
    \ R - 1)(mt);\n}\n\ntemplate < class T >\nT get_real(T L, T R) {\n    return std::uniform_real_distribution<\
    \ T >(L, R)(mt);\n}\n\n}\n#line 2 \"src/graph/tree/dp_on_tree.hpp\"\n\nstruct\
    \ dp_on_tree {\n    int n;\n    std::vector< std::vector< std::pair<int, int>\
    \ > > tree;\n    dp_on_tree(int n) : n(n), tree(n) {}\n    void add_edge(int u,\
    \ int v, int i) {\n        tree[u].push_back({v, i});\n        tree[v].push_back({u,\
    \ i});\n    }\n\n    template < class S, class M, class E, class V >\n    vector<\
    \ S > solve(int root, const M& merge, const E& fe, const V& fv, const S unit)\
    \ {\n        vector< S > dp(n);\n        function<S(int,int)> dfs = [&](int v,\
    \ int p) -> S {\n            S res = unit;\n            for(auto [to, id] : tree[v])\
    \ {\n                if(to != p) res = merge(res, fe(dfs(to, v), id));\n     \
    \       }\n            return dp[v] = fv(res, v);\n        }; dfs(root, -1);\n\
    \        return dp;\n    }\n};\n#line 5 \"src/graph/tree/tree_isomorphism.hpp\"\
    \n\nstruct subtree_hashing {\n    int n;\n    dp_on_tree tree;\n    subtree_hashing(int\
    \ n) : n(n), tree(n) {}\n    void add_edge(int u, int v) {\n        static int\
    \ i = 0;\n        tree.add_edge(u, v, i++);\n    }\n\n    template < int num_of_mod\
    \ >\n    std::pair< int, std::vector<int> > solve(int root) {\n        using hv\
    \ = hash_vector< num_of_mod >;\n        std::vector< hv > h(n);\n        for(int\
    \ i : rep(n)) h[i] = hv(randnum::gen_int<int>(0, hv::MODS[0]));\n\n        using\
    \ S = std::pair< hv, int >;\n        vector< S > dp = tree.solve(\n          \
    \  root,\n            [&](S a, S b) { return S{a.first * b.first, std::max(a.second,\
    \ b.second + 1)}; },\n            [&](S a, int i) { return a; },\n           \
    \ [&](S a, int i) { return S{a.first + h[a.second], a.second}; },\n          \
    \  S{hv(1), 0}\n        );\n\n        vector< S > key = dp;\n        std::sort(key.begin(),\
    \ key.end());\n        key.erase(std::unique(key.begin(), key.end()), key.end());\n\
    \        vector<int> id(n);\n        for(int i : rep(n)) id[i] = std::lower_bound(key.begin(),\
    \ key.end(), dp[i]) - key.begin();\n        return {key.size(), id};\n    }\n\
    };\n#line 7 \"verify/library_checker/graph/tree/tree_isomorphism.test.cpp\"\n\n\
    int main() {\n    int N = in();\n    subtree_hashing g(N);\n    for(int i : rep(1,\
    \ N)) {\n        int p = in();\n        g.add_edge(p, i);\n    }\n\n    auto [K,\
    \ ans] = g.solve< 2 >(0);\n    print(K);\n    print(ans);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../../../src/cp-template.hpp\"\n#include \"../../../../src/utility/hash.hpp\"\
    \n#include \"../../../../src/utility/random.hpp\"\n#include \"../../../../src/graph/tree/tree_isomorphism.hpp\"\
    \n\nint main() {\n    int N = in();\n    subtree_hashing g(N);\n    for(int i\
    \ : rep(1, N)) {\n        int p = in();\n        g.add_edge(p, i);\n    }\n\n\
    \    auto [K, ans] = g.solve< 2 >(0);\n    print(K);\n    print(ans);\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/utility/hash.hpp
  - src/utility/random.hpp
  - src/graph/tree/tree_isomorphism.hpp
  - src/graph/tree/dp_on_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/tree/tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2023-10-19 23:28:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/tree/tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/tree/tree_isomorphism.test.cpp
- /verify/verify/library_checker/graph/tree/tree_isomorphism.test.cpp.html
title: verify/library_checker/graph/tree/tree_isomorphism.test.cpp
---
