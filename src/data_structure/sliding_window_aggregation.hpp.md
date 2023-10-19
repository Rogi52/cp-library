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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
    title: verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \    T sum(int L, int R) {\n        return s[R] - s[L];\n    }\n};\n#line 16 \"\
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
    }\n#line 2 \"src/data_structure/sliding_window_aggregation.hpp\"\n\ntemplate <\
    \ class monoid >\nstruct swag_queue {\n  public:\n    using T = typename monoid::set;\n\
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
    \ push(from, st.top(), 1 - f), st.pop();\n        printer::flush();\n    }\n};\n"
  code: "#include \"../../src/cp-template.hpp\"\n\ntemplate < class monoid >\nstruct\
    \ swag_queue {\n  public:\n    using T = typename monoid::set;\n    class node\
    \ {\n      public:\n        T value, sum;\n        node() : value(monoid::id()),\
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
    \ push(from, st.top(), 1 - f), st.pop();\n        printer::flush();\n    }\n};\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/data_structure/sliding_window_aggregation.hpp
  requiredBy: []
  timestamp: '2023-10-18 21:43:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/deque_operate_all_composite.test.cpp
  - verify/library_checker/data_structure/queue_operate_all_composite.test.cpp
documentation_of: src/data_structure/sliding_window_aggregation.hpp
layout: document
redirect_from:
- /library/src/data_structure/sliding_window_aggregation.hpp
- /library/src/data_structure/sliding_window_aggregation.hpp.html
title: src/data_structure/sliding_window_aggregation.hpp
---
