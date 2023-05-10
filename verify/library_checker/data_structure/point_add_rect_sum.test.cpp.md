---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/algebra/plus.hpp
    title: src/algebra/plus.hpp
  - icon: ':question:'
    path: src/cp-template.hpp
    title: src/cp-template.hpp
  - icon: ':question:'
    path: src/data_structure/fenwick_tree.hpp
    title: src/data_structure/fenwick_tree.hpp
  - icon: ':x:'
    path: src/data_structure/point_add_rect_sum.hpp
    title: src/data_structure/point_add_rect_sum.hpp
  - icon: ':question:'
    path: src/data_structure/static_point_add_rect_sum.hpp
    title: src/data_structure/static_point_add_rect_sum.hpp
  - icon: ':question:'
    path: src/utility/io.hpp
    title: src/utility/io.hpp
  - icon: ':question:'
    path: src/utility/rep_itr.hpp
    title: src/utility/rep_itr.hpp
  - icon: ':question:'
    path: src/utility/zip.hpp
    title: src/utility/zip.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/point_add_rect_sum.test.cpp\"\
    \n#define PROMLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i128 = __int128_t;\ntemplate < class T > bool\
    \ chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }\ntemplate\
    \ < class T > bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return\
    \ false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct\
    \ itr {\n    T i, d;\n    constexpr itr(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}\n    void operator++()\
    \ noexcept { i += d; }\n    constexpr int operator*() const noexcept { return\
    \ i; }\n    constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate < class T > struct rep {\n\
    \    const itr< T > s, t;\n    constexpr rep(const T t) noexcept : s(0), t(t)\
    \ {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n    constexpr\
    \ rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr\
    \ auto begin() const noexcept { return s; }\n    constexpr auto end() const noexcept\
    \ { return t; }\n};\n\ntemplate < class T > struct revrep {\n    const itr < T\
    \ > s, t;\n    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1)\
    \ {}\n    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s\
    \ - 1, -1) {}\n    constexpr revrep(const T s, const T t, const T d) noexcept\
    \ : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin() const noexcept {\
    \ return s; }\n    constexpr auto end() const noexcept { return t; }\n};\n#line\
    \ 2 \"src/utility/io.hpp\"\nnamespace scanner {\n    struct sca {\n        template\
    \ < class T > operator T() {\n            T s; cin >> s; return s;\n        }\n\
    \    };\n    struct vec {\n        int n;\n        vec(int n) : n(n) {}\n    \
    \    template < class T > operator vector< T >() {\n            vector< T > v(n);\n\
    \            for(T& x : v) cin >> x;\n            return v;\n        }\n    };\n\
    \    struct mat {\n        int h,w;\n        mat(int h, int w) : h(h), w(w) {}\n\
    \        template < class T > operator vector< vector< T > >() {\n           \
    \ vector m(h, vector< T >(w));\n            for(vector< T >& v : m) for(T& x :\
    \ v) cin >> x;\n            return m;\n        }\n    };\n    struct speedup {\n\
    \        speedup() {\n            cin.tie(0);\n            ios::sync_with_stdio(0);\n\
    \        }\n    } su;\n}\nscanner::sca in() { return scanner::sca(); }\nscanner::vec\
    \ in(int n) { return scanner::vec(n); }\nscanner::mat in(int h, int w) { return\
    \ scanner::mat(h, w); }\n\nnamespace printer {\n    void precision(int d) {\n\
    \        cout << fixed << setprecision(d);\n    }\n    void flush() {\n      \
    \  cout.flush();\n    }\n}\nint print() { cout << '\\n'; return 0; }\ntemplate\
    \ < class head, class... tail > int print(head&& h, tail&&... t) {\n    cout <<\
    \ h; if(sizeof...(tail)) cout << ' ';\n    return print(forward<tail>(t)...);\n\
    }\ntemplate < class T > int print(vector< T > a, char sep = ' ') {\n    int n\
    \ = a.size();\n    for(int i : rep(n)) cout << a[i] << (i != n - 1 ? sep : '\\\
    n');\n    return 0;\n}\ntemplate < class T > int print(vector< vector< T > > a)\
    \ {\n    if(a.empty()) return 0;\n    int h = a.size(), w = a[0].size();\n   \
    \ for(int i : rep(h)) for(int j : rep(w)) cout << a[i][j] << (j != w - 1 ? ' '\
    \ : '\\n');\n    return 0;\n}\n#line 1 \"src/utility/zip.hpp\"\ntemplate < class\
    \ T >\nstruct zipper {\n  public:\n    zipper() {}\n    vector< T > data;\n  \
    \  void insert(const T x) {\n        built = 0;\n        data.push_back(x);\n\
    \    }\n    void insert(const vector< T > v) {\n        built = 0;\n        data.insert(data.end(),\
    \ v.begin(), v.end());\n    }\n    template < class... args > zipper(args... a)\
    \ { insert(a...); }\n    template < class... args > void insert(const T x, args...\
    \ a) { insert(x); insert(a...); }\n    template < class... args > void insert(const\
    \ vector< T > x, args... a) { insert(x); insert(a...); }\n\n    void build() {\n\
    \        sort(data.begin(), data.end());\n        data.erase(unique(data.begin(),\
    \ data.end()), data.end());\n        built = 1;\n    }\n\n    int id(const T x)\
    \ {\n        assert(built);\n        return lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n    }\n    vector<int> zip(const vector< T >& x) {\n   \
    \     assert(built);\n        vector<int> idx(x.size());\n        for(int i :\
    \ rep(x.size())) idx[i] = id(x[i]);\n        return idx;\n    }\n    int size()\
    \ {\n        assert(built);\n        return data.size();\n    }\n\n  private:\n\
    \    int built = 0;\n};\n#line 1 \"src/data_structure/fenwick_tree.hpp\"\ntemplate\
    \ < class comm_monoid > class fenwick_tree {\n  public:\n    using T = typename\
    \ comm_monoid::set;\n\n  private:\n    int n, n2;\n    vector< T > data;\n\n \
    \   int ceil_pow2(int n) {\n        int x = 1;\n        while(x < n) x <<= 1;\n\
    \        return x;\n    }\n\n  public:\n    fenwick_tree() : fenwick_tree(0) {}\n\
    \    fenwick_tree(int n) : n(n), n2(ceil_pow2(n)), data(n + 1, comm_monoid::id)\
    \ { assert(comm_monoid::comm); }\n    fenwick_tree(const vector< T > &a) : n(a.size()),\
    \ n2(ceil_pow2(n)), data(a) {\n        assert(comm_monoid::comm);\n        data.insert(data.begin(),\
    \ {comm_monoid::id});\n        for(int i = 1; i <= n; i++) {\n            int\
    \ p = i + (i & -i);\n            if(p <= n) data[p] = comm_monoid::op(data[i],\
    \ data[p]);\n        }\n    }\n\n    void add(int i, T x) {\n        for(int p\
    \ = i + 1; p <= n; p += p & -p) data[p] = comm_monoid::op(data[p], x);\n    }\n\
    \    // [0, r)\n    T fold(int r) {\n        T s = comm_monoid::id;\n        for(int\
    \ p = r; p > 0; p -= p & -p) s = comm_monoid::op(data[p], s);\n        return\
    \ s;\n    }\n    // [l, r)\n    T fold(int l, int r) {\n        return comm_monoid::op(comm_monoid::inv(fold(l)),\
    \ fold(r));\n    }\n    T get(int i) {\n        return fold(i, i + 1);\n    }\n\
    \    void set(int i, T x) {\n        add(i, comm_monoid::op(comm_monoid::inv(get(i)),\
    \ x));\n    }\n    template< class func > int search(const func &f) {\n      \
    \  T s = comm_monoid::id;\n        if(f(s)) return 0;\n        int i = 0, k =\
    \ n2;\n        while(k >>= 1) {\n            int p = i | k;\n            if(p\
    \ <= n && !f(comm_monoid::op(s, data[p]))) s = comm_monoid::op(s, data[i = p]);\n\
    \        }\n        return i;\n    }\n};\n#line 4 \"src/data_structure/static_point_add_rect_sum.hpp\"\
    \n\nnamespace tag {\n\nstruct STATIC;\nstruct DYNAMIC;\n\nstruct POINT;\nstruct\
    \ RECTANGLE;\n\n}\n\ntemplate < class SD, class ADD_TYPE, class T, class abel_group\
    \ >\nstruct rect_sum {};\n\ntemplate < class T, class abel_group >\nstruct rect_sum\
    \ < tag::STATIC, tag::POINT, T, abel_group > {\n    using W = typename abel_group::set;\n\
    \    vector<tuple< T, T, W >> P;\n    vector<tuple< T, T, T, T >> R;\n    zipper<\
    \ T > X, Y;\n    rect_sum() {}\n    void add(T x, T y, W w) {\n        P.emplace_back(x,\
    \ y, w);\n        X.insert(x); Y.insert(y);\n    }\n    void query(T xL, T xR,\
    \ T yL, T yR) {\n        R.emplace_back(xL, xR, yL, yR);\n        X.insert(xL);\
    \ X.insert(xR);\n        Y.insert(yL); Y.insert(yR);\n    }\n\n    vector< W >\
    \ solve() {\n        X.build(); Y.build();\n        vector< vector< pair< int,\
    \ W > > > P2(X.size());\n        vector< vector< tuple< int, int, int, int > >\
    \ > R2(X.size());\n        for(auto [x, y, w] : P) P2[X.id(x)].emplace_back(Y.id(y),\
    \ w);\n        for(int i : rep(R.size())) {\n            auto [xL, xR, yL, yR]\
    \ = R[i];\n            int iyL = Y.id(yL), iyR = Y.id(yR);\n            R2[X.id(xL)].emplace_back(iyL,\
    \ iyR, i, 1);\n            R2[X.id(xR)].emplace_back(iyL, iyR, i, 0);\n      \
    \  }\n\n        vector< W > ans(R.size(), abel_group::id);\n        fenwick_tree<\
    \ abel_group > bit(Y.size());\n        for(int x : rep(X.size())) {\n        \
    \    for(auto [yL, yR, i, inv] : R2[x]) {\n                W w = bit.fold(yL,\
    \ yR);\n                if(inv) w = abel_group::inv(w);\n                ans[i]\
    \ = abel_group::op(ans[i], w);\n            }\n            for(auto [y, w] : P2[x])\
    \ bit.add(y, w);\n        }\n        return ans;\n    }\n};\n#line 3 \"src/data_structure/point_add_rect_sum.hpp\"\
    \n\ntemplate < class T, class abel_group >\nstruct rect_sum < tag::DYNAMIC, tag::POINT,\
    \ T, abel_group > {\n    using A = abel_group;\n    using W = typename A::set;\n\
    \    using add_t = tuple< T, T, W >;\n    using query_t = tuple< T, T, T, T >;\n\
    \    vector< variant< add_t, query_t > > qs;\n\n    void add(T x, T y, W w) {\n\
    \        qs.push_back(add_t{x, y, w});\n    }\n    void query(T xL, T xR, T yL,\
    \ T yR) {\n        qs.push_back(query_t{xL, xR, yL, yR});\n    }\n    vector<\
    \ W > solve() {\n        int Q = qs.size();\n        queue<pair<int,int>> que;\n\
    \        que.emplace(0, Q);\n        vector<int> q_id(Q);\n        int id = 0;\n\
    \        for(int i : rep(Q)) {\n            if(holds_alternative< query_t >(qs[i]))\
    \ {\n                q_id[i] = id++;\n            }\n        }\n        vector<\
    \ W > ans(id);\n        while(not que.empty()) {\n            auto [L, R] = que.front();\
    \ que.pop();\n            if(L + 1 >= R) continue;\n            int M = (L + R)\
    \ / 2;\n            que.emplace(L, M);\n            que.emplace(M, R);\n     \
    \       rect_sum< tag::STATIC, tag::POINT, T, A > rs;\n            for(int i :\
    \ rep(L, M)) {\n                if(holds_alternative< add_t >(qs[i])) {\n    \
    \                auto [x, y, w] = get< add_t >(qs[i]);\n                    rs.add(x,\
    \ y, w);\n                }\n            }\n            for(int i : rep(M, R))\
    \ {\n                if(holds_alternative< query_t >(qs[i])) {\n             \
    \       auto [xL, xR, yL, yR] = get< query_t >(qs[i]);\n                    rs.query(xL,\
    \ xR, yL, yR);\n                }\n            }\n            vector< W > res\
    \ = rs.solve();\n            int k = 0;\n            for(int i : rep(M, R)) {\n\
    \                if(holds_alternative< query_t >(qs[i])) {\n                 \
    \   ans[q_id[i]] += res[k++];\n                }\n            }\n        }\n \
    \       return ans;\n    }\n};\n#line 1 \"src/algebra/plus.hpp\"\ntemplate < class\
    \ T > class PLUS {\n  public:\n    using set = T;\n    static constexpr T op(const\
    \ T &l, const T &r) { return l + r; }\n    static constexpr T id = T(0);\n   \
    \ static constexpr T inv(const T &x) { return -x; }\n    static constexpr T pow(const\
    \ T &x, const ll n) { return x * n; }\n    static constexpr bool comm = true;\n\
    };\n#line 6 \"verify/library_checker/data_structure/point_add_rect_sum.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    rect_sum< tag::DYNAMIC, tag::POINT,\
    \ int, PLUS<ll> > rs;\n    for(int i : rep(N)) {\n        int x = in(), y = in(),\
    \ w = in();\n        rs.add(x, y, w);\n    }\n    for(int i : rep(Q)) {\n    \
    \    int t = in();\n        if(t == 0) {\n            int x = in(), y = in(),\
    \ w = in();\n            rs.add(x, y, w);\n        }\n        if(t == 1) {\n \
    \           int l = in(), d = in(), r = in(), u = in();\n            rs.query(l,\
    \ r, d, u);\n        }\n    }\n    print(rs.solve(), '\\n');\n}\n"
  code: "#define PROMLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/data_structure/point_add_rect_sum.hpp\"\
    \n#include \"../../../src/algebra/plus.hpp\"\n\nint main() {\n    int N = in(),\
    \ Q = in();\n    rect_sum< tag::DYNAMIC, tag::POINT, int, PLUS<ll> > rs;\n   \
    \ for(int i : rep(N)) {\n        int x = in(), y = in(), w = in();\n        rs.add(x,\
    \ y, w);\n    }\n    for(int i : rep(Q)) {\n        int t = in();\n        if(t\
    \ == 0) {\n            int x = in(), y = in(), w = in();\n            rs.add(x,\
    \ y, w);\n        }\n        if(t == 1) {\n            int l = in(), d = in(),\
    \ r = in(), u = in();\n            rs.query(l, r, d, u);\n        }\n    }\n \
    \   print(rs.solve(), '\\n');\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/data_structure/point_add_rect_sum.hpp
  - src/data_structure/static_point_add_rect_sum.hpp
  - src/utility/zip.hpp
  - src/data_structure/fenwick_tree.hpp
  - src/algebra/plus.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-10 11:13:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_rect_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_rect_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_rect_sum.test.cpp
---
