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
    path: src/data_structure/heap_rich.hpp
    title: src/data_structure/heap_rich.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/library_checker/data_structure/heap_rich.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
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
    }\n#line 2 \"src/data_structure/heap_rich.hpp\"\n\nnamespace std_ex {\n\ntemplate\
    \ < class T > T pop(std::queue < T >& c) { T x = c.front(); c.pop(); return x;\
    \ }\ntemplate < class T > T pop(std::stack < T >& c) { T x = c.top();   c.pop();\
    \ return x; }\ntemplate < class T > T pop(std::vector< T >& c) { T x = c.top();\
    \   c.pop(); return x; } \ntemplate < class T > T pop(   heap_min< T >& c) { T\
    \ x = c.top();   c.pop(); return x; }\ntemplate < class T > T pop(   heap_max<\
    \ T >& c) { T x = c.top();   c.pop(); return x; }\n\n}\n\ntemplate < class container\
    \ >\nstruct erasable {\n    using T = typename container::value_type;\n    container\
    \ c, rm_c;\n\n    erasable() {}\n    erasable(std::vector< T >& a) : c(a.begin(),\
    \ a.end()) {}\n    void push(T x) { c.push(x); }\n    int size() { return c.size()\
    \ - rm_c.size(); }\n    int empty() { return size() == 0; }\n    T pop() { set();\
    \ return std_ex::pop(c); }\n    T top() { set(); return c.top(); }\n    void erase(T\
    \ x) { rm_c.push(x); }\n\n  private:\n    void set() { while(not rm_c.empty()\
    \ and rm_c.top() == c.top()) rm_c.pop(), c.pop(); }\n};\n\n\ntemplate < class\
    \ T >\nstruct heap_minmax {\n    erasable< heap_min< T > > h_min;\n    erasable<\
    \ heap_max< T > > h_max;\n\n    heap_minmax() {}\n    heap_minmax(std::vector<\
    \ T >& a) : h_min(a), h_max(a) {}\n    void push(T x) {\n        h_min.push(x),\
    \ h_max.push(x);\n    }\n    int size() { return h_min.size(); }\n    int empty()\
    \ { return size() == 0; }\n    T min() { return h_min.top(); }\n    T max() {\
    \ return h_max.top(); }\n    T pop_min() {\n        T x = h_min.top(); h_min.pop();\n\
    \        h_max.erase(x);\n        return x;\n    }\n    T pop_max() {\n      \
    \  T x = h_max.top(); h_max.pop();\n        h_min.erase(x);\n        return x;\n\
    \    }\n    void erase(T x) {\n        h_min.erase(x);\n        h_max.erase(x);\n\
    \    }\n};\n#line 5 \"verify/library_checker/data_structure/heap_rich.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    vector<int> A = in(N);\n  \
    \  heap_minmax<int> q(A);\n\n    for(int _ : rep(Q)) {\n        int t = in();\n\
    \        if(t == 0) {\n            int x = in();\n            q.push(x);\n   \
    \     }\n        if(t == 1) {\n            print(q.pop_min());\n        }\n  \
    \      if(t == 2) {\n            print(q.pop_max());\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/heap_rich.hpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    vector<int> A = in(N);\n  \
    \  heap_minmax<int> q(A);\n\n    for(int _ : rep(Q)) {\n        int t = in();\n\
    \        if(t == 0) {\n            int x = in();\n            q.push(x);\n   \
    \     }\n        if(t == 1) {\n            print(q.pop_min());\n        }\n  \
    \      if(t == 2) {\n            print(q.pop_max());\n        }\n    }\n}\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/heap_rich.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/heap_rich.test.cpp
  requiredBy: []
  timestamp: '2023-10-19 23:41:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/heap_rich.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/heap_rich.test.cpp
- /verify/verify/library_checker/data_structure/heap_rich.test.cpp.html
title: verify/library_checker/data_structure/heap_rich.test.cpp
---
