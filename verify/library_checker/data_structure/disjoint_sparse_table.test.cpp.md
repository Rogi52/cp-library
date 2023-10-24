---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/minmax.hpp
    title: src/algebra/minmax.hpp
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
    path: src/data_structure/disjoint_sparse_table.hpp
    title: src/data_structure/disjoint_sparse_table.hpp
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
    \ true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class\
    \ T > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i),\
    \ d(1) {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n\
    \    void operator++() noexcept { i += d; }\n    constexpr int operator*() const\
    \ noexcept { return i; }\n    constexpr bool operator!=(const itr x) const noexcept\
    \ {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class\
    \ T > struct rep {\n    const itr< T > s, t;\n    constexpr rep(const T t) noexcept\
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
    \    ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n}\nscanner::sca\
    \ in() { return scanner::sca(); }\nscanner::vec in(int n) { return scanner::vec(n);\
    \ }\nscanner::mat in(int h, int w) { return scanner::mat(h, w); }\n\nnamespace\
    \ printer {\n    void precision(int d) {\n        cout << fixed << setprecision(d);\n\
    \    }\n    void flush() {\n        cout.flush();\n    }\n}\n\ntemplate < class\
    \ T >\nostream& operator<<(ostream& os, const std::vector< T > a) {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os << ' ';\
    \ }\n    return os;\n}\n\nint print() { cout << '\\n'; return 0; }\ntemplate <\
    \ class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\n\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n =\
    \ a.size();\n    for(int i : rep(n)) cout << a[i] << \"\\n\";\n    return 0;\n\
    }\n#line 2 \"src/utility/key_val.hpp\"\ntemplate < class K, class V >\nstruct\
    \ key_val {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) :\
    \ key(key), val(val) {}\n};\n#line 2 \"src/utility/vec_op.hpp\"\ntemplate < class\
    \ T >\nkey_val< int, T > max_of(const vector< T >& a) {\n    int i = max_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nkey_val<\
    \ int, T > min_of(const vector< T >& a) {\n    int i = min_element(a.begin(),\
    \ a.end()) - a.begin();\n    return {i, a[i]};\n}\n\ntemplate < class T >\nT sum_of(const\
    \ vector< T >& a) {\n    T sum = 0;\n    for(const T x : a) sum += x;\n    return\
    \ sum;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector< T >& a, T\
    \ L, T R) {\n    vector<int> res(R - L);\n    for(const T x : a) res[x - L]++;\n\
    \    return res;\n}\n\ntemplate < class T >\nvector<int> freq_of(const vector<\
    \ T >& a, T R) {\n    return freq_of(a, T(0), R);\n}\n\ntemplate < class T >\n\
    struct prefix_sum {\n    vector< T > s;\n    prefix_sum(const vector< T >& a)\
    \ : s(a) {\n        s.insert(s.begin(), T(0));\n        for(int i : rep(a.size()))\
    \ s[i + 1] += s[i];\n    }\n    // [L, R)\n    T sum(int L, int R) {\n       \
    \ return s[R] - s[L];\n    }\n};\n#line 3 \"src/utility/heap.hpp\"\n\ntemplate\
    \ < class T > using heap_min = std::priority_queue< T, std::vector< T >, std::greater<\
    \ T > >;\ntemplate < class T > using heap_max = std::priority_queue< T, std::vector<\
    \ T >, std::less< T > >;\n\n#line 21 \"src/cp-template.hpp\"\n\n#line 1 \"src/algorithm/bin_search.hpp\"\
    \ntemplate < class T, class F >\nT bin_search(T ok, T ng, F& f) {\n    while(abs(ok\
    \ - ng) > 1) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate < class T, class F >\nT bin_search_real(T\
    \ ok, T ng, F& f, int step = 80) {\n    while(step--) {\n        T mid = (ok +\
    \ ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line\
    \ 2 \"src/algorithm/argsort.hpp\"\n\ntemplate < class T > std::vector< int > argsort(const\
    \ std::vector< T > &a) {\n    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n\
    \        return a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n\
    }\n#line 2 \"src/data_structure/disjoint_sparse_table.hpp\"\n\ntemplate < class\
    \ semi_group >\nstruct disjoint_sparse_table {\n    using T = typename semi_group::set;\n\
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
  timestamp: '2023-10-25 04:25:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
- /verify/verify/library_checker/data_structure/disjoint_sparse_table.test.cpp.html
title: verify/library_checker/data_structure/disjoint_sparse_table.test.cpp
---
