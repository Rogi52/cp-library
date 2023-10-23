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
  - icon: ':heavy_check_mark:'
    path: src/data_structure/binary_trie.hpp
    title: src/data_structure/binary_trie.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/aoj/data_structure/binary_trie.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\
    \ntemplate < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i)\
    \ noexcept : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept :\
    \ i(i), d(d) {}\n    void operator++() noexcept { i += d; }\n    constexpr int\
    \ operator*() const noexcept { return i; }\n    constexpr bool operator!=(const\
    \ itr x) const noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n\
    };\n\ntemplate < class T > struct rep {\n    const itr< T > s, t;\n    constexpr\
    \ rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const\
    \ T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const\
    \ T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept\
    \ { return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n\n\
    template < class T > struct revrep {\n    const itr < T > s, t;\n    constexpr\
    \ revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const\
    \ T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n#line 2 \"src/utility/io.hpp\"\nnamespace scanner {\n   \
    \ struct sca {\n        template < class T > operator T() {\n            T s;\
    \ cin >> s; return s;\n        }\n    };\n    struct vec {\n        int n;\n \
    \       vec(int n) : n(n) {}\n        template < class T > operator vector< T\
    \ >() {\n            vector< T > v(n);\n            for(T& x : v) cin >> x;\n\
    \            return v;\n        }\n    };\n    struct mat {\n        int h,w;\n\
    \        mat(int h, int w) : h(h), w(w) {}\n        template < class T > operator\
    \ vector< vector< T > >() {\n            vector m(h, vector< T >(w));\n      \
    \      for(vector< T >& v : m) for(T& x : v) cin >> x;\n            return m;\n\
    \        }\n    };\n    struct speedup {\n        speedup() {\n            cin.tie(0);\n\
    \            ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n}\n\
    scanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) {\n        cout << fixed\
    \ << setprecision(d);\n    }\n    void flush() {\n        cout.flush();\n    }\n\
    }\n\ntemplate < class T >\nostream& operator<<(ostream& os, const std::vector<\
    \ T > a) {\n    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i\
    \ != n - 1) os << ' '; }\n    return os;\n}\n\nint print() { cout << '\\n'; return\
    \ 0; }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t)\
    \ {\n    cout << h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
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
    }\n#line 2 \"src/data_structure/binary_trie.hpp\"\n\ntemplate < class K, int L,\
    \ class V >\nstruct binary_trie {\n    struct node_t {\n        array<int, 2>\
    \ to = {};\n        V cnt;\n        vector<int> accept;\n        node_t() : cnt(0)\
    \ { to[0] = to[1] = -1; }\n    };\n\n    vector<node_t> node;\n    int ROOT;\n\
    \    K XOR;\n    binary_trie() : node(1), ROOT(0), XOR(0) {}\n\n    void xor_all(K\
    \ x) {\n        XOR ^= x;\n    }\n    int insert(K x, V v = 1, int id = -1) {\n\
    \        int u = ROOT;\n        node[u].cnt += v;\n        for(int i : revrep(L))\
    \ {\n            int p = ((XOR >> i) & 1) ^ ((x >> i) & 1);\n            if(node[u].to[p]\
    \ == -1) {\n                node[u].to[p] = node.size();\n                node.push_back(node_t());\n\
    \            }\n            u = node[u].to[p];\n            node[u].cnt += v;\n\
    \        }\n        if(id != -1) node[u].accept.push_back(id);\n        return\
    \ u;\n    }\n    int erase(K x, V v = 1) {\n        return insert(x, -v, -1);\n\
    \    }\n    int find(K x) {\n        int u = ROOT;\n        for(int i : revrep(L))\
    \ {\n            int p = ((XOR >> i) & 1) ^ ((x >> i) & 1);\n            u = node[u].to[p];\n\
    \            if(u == -1) return -1;\n        }\n        return u;\n    }\n   \
    \ pair< K, int > kth(V k) {\n        assert(0 <= k && k < size());\n        K\
    \ x(0);\n        int u = ROOT;\n        for(int i : revrep(L)) {\n           \
    \ int p = (XOR >> i) & 1, v = node[u].to[p];\n            K c = v != -1 ? node[v].cnt\
    \ : 0;\n            if(c <= k) {\n                k -= c;\n                x |=\
    \ K(1) << i;\n                u = node[u].to[p ^ 1];\n            } else {\n \
    \               u = node[u].to[p];\n            }\n        }\n        return {x,\
    \ u};\n    }\n    pair< K, int > min() {\n        assert(not empty());\n     \
    \   return kth(0);\n    }\n    pair< K, int > max() {\n        assert(not empty());\n\
    \        return kth(size() - 1);\n    }\n    V count(K x) {\n        int i = find(x);\n\
    \        return i == -1 ? 0 : node[i].cnt;\n    }\n    V count_less(K x) {\n \
    \       int u = ROOT;\n        V v = 0;\n        for(int i : revrep(L)) {\n  \
    \          int p = (XOR >> i) & 1, q = (x >> i) & 1;\n            if(q > 0 and\
    \ node[u].to[p] != -1) v += node[node[u].to[p]].cnt;\n            if(node[u].to[p\
    \ ^ q] != -1) { u = node[u].to[p ^ q]; } else break;\n        }\n        return\
    \ v;\n    }\n    V size() {\n        return node[ROOT].cnt;\n    }\n    int empty()\
    \ {\n        return size() == 0;\n    }\n};\n#line 5 \"verify/aoj/data_structure/binary_trie.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    binary_trie<int,20,int> bt;\n\
    \    for(int _ : rep(Q)) {\n        int c = in(), x = in(), y = in();\n      \
    \  switch(c) {\n            case 0: {\n                bt.insert(x, y);\n    \
    \        } break;\n\n            case 1: {\n                print(bt.count_less(y\
    \ + 1) - bt.count_less(x));\n            } break;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/binary_trie.hpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    binary_trie<int,20,int> bt;\n\
    \    for(int _ : rep(Q)) {\n        int c = in(), x = in(), y = in();\n      \
    \  switch(c) {\n            case 0: {\n                bt.insert(x, y);\n    \
    \        } break;\n\n            case 1: {\n                print(bt.count_less(y\
    \ + 1) - bt.count_less(x));\n            } break;\n        }\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/data_structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/aoj/data_structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/data_structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/data_structure/binary_trie.test.cpp
- /verify/verify/aoj/data_structure/binary_trie.test.cpp.html
title: verify/aoj/data_structure/binary_trie.test.cpp
---