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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yukicoder/sparse_segtree.test.cpp
    title: verify/yukicoder/sparse_segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    }\n#line 2 \"src/data_structure/sparse_segtree.hpp\"\n\ntemplate < class I, class\
    \ monoid > struct sparse_segtree {\n    using S = typename monoid::set;\n\n  \
    \  struct node {\n        I index;\n        S value, prod;\n        std::unique_ptr<\
    \ node > left, right;\n        node(I index, S value) : index(index), value(value),\
    \ prod(value), left(nullptr), right(nullptr) {}\n        void update() {\n   \
    \         prod = monoid::op(monoid::op(left  ? left ->prod : monoid::id(), value),\
    \ right ? right->prod : monoid::id());\n        }\n    };\n    using node_ptr\
    \ = std::unique_ptr< node >;\n\n    I n;\n    node_ptr root;\n    \n    sparse_segtree()\
    \ {}\n    sparse_segtree(I n) : n(n), root(nullptr) {}\n    void set(I i, S x)\
    \ {\n        assert(0 <= i and i < n);\n        set(root, 0, n, i, x);\n    }\n\
    \    S get(I i) {\n        assert(0 <= i and i < n);\n        return get(root,\
    \ 0, n, i);\n    }\n    S prod(I l, I r) {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        return prod(root, 0, n, l, r);\n    }\n    S all_prod() {\n\
    \        return root ? root->prod : monoid::id();\n    }\n    void reset(I l,\
    \ I r) {\n        assert(0 <= l and l <= r and r <= n);\n        return reset(root,\
    \ 0, n, l, r);\n    }\n    template < class func >\n    I max_right(I l, func\
    \ f) {\n        assert(0 <= l and l <= n);\n        S prod = monoid::id();\n \
    \       assert(f(prod));\n        return max_right(root, 0, n, l, f, prod);\n\
    \    }\n    template < class func >\n    I min_left(I r, func f) {\n        assert(0\
    \ <= r and r <= n);\n        S prod = monoid::id();\n        assert(f(prod));\n\
    \        return min_left(root, 0, n, r, f, prod);\n    }\n\n  private:\n    void\
    \ set(node_ptr& t, I a, I b, I p, S x) {\n        if(!t) {\n            t = std::make_unique<\
    \ node >(p, x);\n            return;\n        }\n        if(t->index == p) {\n\
    \            t->value = x;\n            t->update();\n            return;\n  \
    \      }\n        I m = (a + b) / 2;\n        if(p < m) {\n            if(t->index\
    \ < p) std::swap(t->index, p), std::swap(t->value, x);\n            set(t->left\
    \ , a, m, p, x);\n        } else {\n            if(p < t->index) std::swap(p,\
    \ t->index), std::swap(x, t->value);\n            set(t->right, m, b, p, x);\n\
    \        }\n        t->update();\n    }\n\n    S get(const node_ptr& t, I a, I\
    \ b, I i) {\n        if(!t) return monoid::id();\n        if(t->index == i) return\
    \ t->value;\n        I m = (a + b) / 2;\n        if(i < m)\n            return\
    \ get(t->left , a, m, i);\n        else\n            return get(t->right, m, b,\
    \ i);\n    }\n\n    S prod(const node_ptr& t, I a, I b, I l, I r) {\n        if(!t\
    \ or b <= l or r <= a) return monoid::id();\n        if(l <= a and b <= r) return\
    \ t->prod;\n        I m = (a + b) / 2;\n        S res = prod(t->left, a, m, l,\
    \ r);\n        if(l <= t->index and t->index < r) res = monoid::op(res, t->value);\n\
    \        return monoid::op(res, prod(t->right, m, b, l, r));\n    }\n\n    void\
    \ reset(node_ptr& t, I a, I b, I l, I r) {\n        if(!t or b <= l or r <= a)\
    \ return;\n        if(l <= a and b <= r) {\n            t.reset();\n         \
    \   return;\n        }\n        I m = (a + b) / 2;\n        reset(t->left , a,\
    \ m, l, r);\n        reset(t->right, m, b, l, r);\n        t->update();\n    }\n\
    \n    template < class func >\n    I max_right(const node_ptr& t, I a, I b, I\
    \ l, const func& f, S& prod) {\n        if(!t or b <= l) return n;\n        if(f(monoid::op(prod,\
    \ t->prod))) {\n            prod = monoid::op(prod, t->prod);\n            return\
    \ n;\n        }\n        I m = (a + b) / 2;\n        I res = max_right(t->left,\
    \ a, m, l, f, prod);\n        if(res != n) return res;\n        if(l <= t->index)\
    \ {\n            prod = monoid::op(prod, t->value);\n            if(not f(prod))\
    \ return t->index;\n        }\n        return max_right(t->right, m, b, l, f,\
    \ prod);\n    }\n\n    template < class func >\n    I min_left(const node_ptr&\
    \ t, I a, I b, I r, const func& f, S& prod) {\n        if(!t or r <= a) return\
    \ 0;\n        if(f(monoid::op(t->prod, prod))) {\n            prod = monoid::op(t->prod,\
    \ prod);\n            return 0;\n        }\n        I m = (a + b) / 2;\n     \
    \   I res = min_left(t->right, m, b, r, f, prod);\n        if(res != 0) return\
    \ res;\n        if(t->index < r) {\n            prod = monoid::op(t->value, prod);\n\
    \            if(not f(prod)) return t->index + 1;\n        }\n        return min_left(t->left,\
    \ a, m, r, f, prod);\n    }\n};\n"
  code: "#include \"../../src/cp-template.hpp\"\n\ntemplate < class I, class monoid\
    \ > struct sparse_segtree {\n    using S = typename monoid::set;\n\n    struct\
    \ node {\n        I index;\n        S value, prod;\n        std::unique_ptr< node\
    \ > left, right;\n        node(I index, S value) : index(index), value(value),\
    \ prod(value), left(nullptr), right(nullptr) {}\n        void update() {\n   \
    \         prod = monoid::op(monoid::op(left  ? left ->prod : monoid::id(), value),\
    \ right ? right->prod : monoid::id());\n        }\n    };\n    using node_ptr\
    \ = std::unique_ptr< node >;\n\n    I n;\n    node_ptr root;\n    \n    sparse_segtree()\
    \ {}\n    sparse_segtree(I n) : n(n), root(nullptr) {}\n    void set(I i, S x)\
    \ {\n        assert(0 <= i and i < n);\n        set(root, 0, n, i, x);\n    }\n\
    \    S get(I i) {\n        assert(0 <= i and i < n);\n        return get(root,\
    \ 0, n, i);\n    }\n    S prod(I l, I r) {\n        assert(0 <= l and l <= r and\
    \ r <= n);\n        return prod(root, 0, n, l, r);\n    }\n    S all_prod() {\n\
    \        return root ? root->prod : monoid::id();\n    }\n    void reset(I l,\
    \ I r) {\n        assert(0 <= l and l <= r and r <= n);\n        return reset(root,\
    \ 0, n, l, r);\n    }\n    template < class func >\n    I max_right(I l, func\
    \ f) {\n        assert(0 <= l and l <= n);\n        S prod = monoid::id();\n \
    \       assert(f(prod));\n        return max_right(root, 0, n, l, f, prod);\n\
    \    }\n    template < class func >\n    I min_left(I r, func f) {\n        assert(0\
    \ <= r and r <= n);\n        S prod = monoid::id();\n        assert(f(prod));\n\
    \        return min_left(root, 0, n, r, f, prod);\n    }\n\n  private:\n    void\
    \ set(node_ptr& t, I a, I b, I p, S x) {\n        if(!t) {\n            t = std::make_unique<\
    \ node >(p, x);\n            return;\n        }\n        if(t->index == p) {\n\
    \            t->value = x;\n            t->update();\n            return;\n  \
    \      }\n        I m = (a + b) / 2;\n        if(p < m) {\n            if(t->index\
    \ < p) std::swap(t->index, p), std::swap(t->value, x);\n            set(t->left\
    \ , a, m, p, x);\n        } else {\n            if(p < t->index) std::swap(p,\
    \ t->index), std::swap(x, t->value);\n            set(t->right, m, b, p, x);\n\
    \        }\n        t->update();\n    }\n\n    S get(const node_ptr& t, I a, I\
    \ b, I i) {\n        if(!t) return monoid::id();\n        if(t->index == i) return\
    \ t->value;\n        I m = (a + b) / 2;\n        if(i < m)\n            return\
    \ get(t->left , a, m, i);\n        else\n            return get(t->right, m, b,\
    \ i);\n    }\n\n    S prod(const node_ptr& t, I a, I b, I l, I r) {\n        if(!t\
    \ or b <= l or r <= a) return monoid::id();\n        if(l <= a and b <= r) return\
    \ t->prod;\n        I m = (a + b) / 2;\n        S res = prod(t->left, a, m, l,\
    \ r);\n        if(l <= t->index and t->index < r) res = monoid::op(res, t->value);\n\
    \        return monoid::op(res, prod(t->right, m, b, l, r));\n    }\n\n    void\
    \ reset(node_ptr& t, I a, I b, I l, I r) {\n        if(!t or b <= l or r <= a)\
    \ return;\n        if(l <= a and b <= r) {\n            t.reset();\n         \
    \   return;\n        }\n        I m = (a + b) / 2;\n        reset(t->left , a,\
    \ m, l, r);\n        reset(t->right, m, b, l, r);\n        t->update();\n    }\n\
    \n    template < class func >\n    I max_right(const node_ptr& t, I a, I b, I\
    \ l, const func& f, S& prod) {\n        if(!t or b <= l) return n;\n        if(f(monoid::op(prod,\
    \ t->prod))) {\n            prod = monoid::op(prod, t->prod);\n            return\
    \ n;\n        }\n        I m = (a + b) / 2;\n        I res = max_right(t->left,\
    \ a, m, l, f, prod);\n        if(res != n) return res;\n        if(l <= t->index)\
    \ {\n            prod = monoid::op(prod, t->value);\n            if(not f(prod))\
    \ return t->index;\n        }\n        return max_right(t->right, m, b, l, f,\
    \ prod);\n    }\n\n    template < class func >\n    I min_left(const node_ptr&\
    \ t, I a, I b, I r, const func& f, S& prod) {\n        if(!t or r <= a) return\
    \ 0;\n        if(f(monoid::op(t->prod, prod))) {\n            prod = monoid::op(t->prod,\
    \ prod);\n            return 0;\n        }\n        I m = (a + b) / 2;\n     \
    \   I res = min_left(t->right, m, b, r, f, prod);\n        if(res != 0) return\
    \ res;\n        if(t->index < r) {\n            prod = monoid::op(t->value, prod);\n\
    \            if(not f(prod)) return t->index + 1;\n        }\n        return min_left(t->left,\
    \ a, m, r, f, prod);\n    }\n};\n"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  isVerificationFile: false
  path: src/data_structure/sparse_segtree.hpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yukicoder/sparse_segtree.test.cpp
documentation_of: src/data_structure/sparse_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/sparse_segtree.hpp
- /library/src/data_structure/sparse_segtree.hpp.html
title: src/data_structure/sparse_segtree.hpp
---
