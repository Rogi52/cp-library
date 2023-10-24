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
    path: src/data_structure/wavlet_matrix.hpp
    title: src/data_structure/wavlet_matrix.hpp
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
  - icon: ':heavy_check_mark:'
    path: src/utility/zip.hpp
    title: src/utility/zip.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/wavlet_matrix.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\n\n#line 2 \"src/utility/rep_itr.hpp\"\n\
    template < class T > struct itr {\n    T i, d;\n    constexpr itr(const T i) noexcept\
    \ : i(i), d(1) {}\n    constexpr itr(const T i, const T d) noexcept : i(i), d(d)\
    \ {}\n    void operator++() noexcept { i += d; }\n    constexpr int operator*()\
    \ const noexcept { return i; }\n    constexpr bool operator!=(const itr x) const\
    \ noexcept {\n        return d > 0 ? i < x.i : i > x.i;\n    }\n};\n\ntemplate\
    \ < class T > struct rep {\n    const itr< T > s, t;\n    constexpr rep(const\
    \ T t) noexcept : s(0), t(t) {}\n    constexpr rep(const T s, const T t) noexcept\
    \ : s(s), t(t) {}\n    constexpr rep(const T s, const T t, const T d) noexcept\
    \ : s(s, d), t(t, d) {}\n    constexpr auto begin() const noexcept { return s;\
    \ }\n    constexpr auto end() const noexcept { return t; }\n};\n\ntemplate < class\
    \ T > struct revrep {\n    const itr < T > s, t;\n    constexpr revrep(const T\
    \ t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const\
    \ T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T\
    \ s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr\
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
    }\n#line 1 \"src/utility/zip.hpp\"\ntemplate < class T >\nstruct zipper {\n  public:\n\
    \    zipper() {}\n    vector< T > data;\n    void insert(const T x) {\n      \
    \  built = 0;\n        data.push_back(x);\n    }\n    void insert(const vector<\
    \ T > v) {\n        built = 0;\n        data.insert(data.end(), v.begin(), v.end());\n\
    \    }\n    template < class... args > zipper(args... a) { insert(a...); }\n \
    \   template < class... args > void insert(const T x, args... a) { insert(x);\
    \ insert(a...); }\n    template < class... args > void insert(const vector< T\
    \ > x, args... a) { insert(x); insert(a...); }\n\n    void build() {\n       \
    \ sort(data.begin(), data.end());\n        data.erase(unique(data.begin(), data.end()),\
    \ data.end());\n        built = 1;\n    }\n\n    int id(const T x) {\n       \
    \ if(not built) build();\n        return lower_bound(data.begin(), data.end(),\
    \ x) - data.begin();\n    }\n    vector<int> zip(const vector< T >& x) {\n   \
    \     if(not built) build();\n        vector<int> idx(x.size());\n        for(int\
    \ i : rep(x.size())) idx[i] = id(x[i]);\n        return idx;\n    }\n    int size()\
    \ {\n        if(not built) build();\n        return data.size();\n    }\n\n  private:\n\
    \    int built = 0;\n};\n#line 2 \"src/data_structure/wavlet_matrix.hpp\"\n\n\
    using u64 = unsigned long long;\nusing u8  = unsigned char;\n\nstruct bit_vector\
    \ {\n    std::vector<u64> buf;\n    std::vector<int> sum;\n    bit_vector() {}\n\
    \    bit_vector(const vector<u8>& a) {\n        int n = a.size();\n        buf.assign((n\
    \ + 63) >> 6, 0);\n        sum.assign(buf.size() + 1, 0);\n        for(int i :\
    \ rep(n)) if(a[i]) {\n            buf[i >> 6] |= u64(1) << (i & 63);\n       \
    \     sum[(i >> 6) + 1]++;\n        }\n        for(int i : rep(buf.size())) sum[i\
    \ + 1] += sum[i];\n    }\n    int rank(int k, int f = 1) {\n        int res =\
    \ sum[k >> 6] + __builtin_popcountll(buf[k >> 6] & ((u64(1) << (k & 63)) - 1));\n\
    \        return f ? res : k - res;\n    }\n};\n\ntemplate < class T >\nstruct\
    \ wavlet_matrix {\n    int n, lg; T m;\n    vector<int> mid;\n    vector<bit_vector>\
    \ buf;\n\n    wavlet_matrix(vector< T > a) : n(a.size()), lg(0), m(1) {\n    \
    \    T max_a = 0;\n        for(T x : a) chmax(max_a, x);\n        while(m <= max_a)\
    \ m <<= 1, lg++;\n        mid.resize(lg);\n        buf.resize(lg);\n        for(int\
    \ d : revrep(lg)) {\n            vector<u8> add;\n            vector<vector< T\
    \ >> nxt(2);\n            for(T x : a) {\n                add.push_back(x >> d\
    \ & 1);\n                nxt[x >> d & 1].push_back(x);\n            }\n      \
    \      mid[d] = int(nxt[0].size());\n            buf[d] = bit_vector(add);\n \
    \           swap(a, nxt[0]);\n            a.insert(a.end(), nxt[1].begin(), nxt[1].end());\n\
    \        }\n    }\n    // count x\n    int rank(int L, int R, T x) {\n       \
    \ if(m <= x) return 0;\n        for(int d : revrep(lg)) {\n            int f =\
    \ x >> d & 1;\n            L = buf[d].rank(L, f) + (f ? mid[d] : 0);\n       \
    \     R = buf[d].rank(R, f) + (f ? mid[d] : 0);\n        }\n        return R -\
    \ L;\n    }\n    // kth smallest\n    T quantile(int L, int R, int k) {\n    \
    \    T res = 0;\n        for(int d : revrep(lg)) {\n            int l0 = buf[d].rank(L,\
    \ 0), r0 = buf[d].rank(R, 0);\n            if(k < r0 - l0) {\n               \
    \ L = l0, R = r0;\n            } else {\n                k -= r0 - l0;\n     \
    \           res |= T(1) << d;\n                L += mid[d] - l0, R += mid[d] -\
    \ r0;\n            }\n        }\n        return res;\n    }\n    // count v <\
    \ x\n    int freq(int L, int R, T x) {\n        if(m <= x) return R - L;\n   \
    \     int res = 0;\n        for(int d : revrep(lg)) {\n            int f = x >>\
    \ d & 1;\n            if(f) res += buf[d].rank(R, 0) - buf[d].rank(L, 0);\n  \
    \          L = buf[d].rank(L, f) + (f ? mid[d] : 0);\n            R = buf[d].rank(R,\
    \ f) + (f ? mid[d] : 0);\n        }\n        return res;\n    }\n    // count\
    \ [a, b)\n    int freq(int L, int R, T a, T b) {\n        return freq(L, R, b)\
    \ - freq(L, R, a);\n    }\n    // max v <= x\n    T prev(int L, int R, T x) {\n\
    \        int cnt = freq(L, R, x);\n        return cnt == R - L ? T(-1) : quantile(L,\
    \ R, cnt);\n    }\n    // min v > x\n    T next(int L, int R, T x) {\n       \
    \ int cnt = freq(L, R, x);\n        return cnt == 0 ? T(-1) : quantile(L, R, cnt\
    \ - 1);\n    }\n};\n#line 6 \"verify/library_checker/data_structure/wavlet_matrix.test.cpp\"\
    \n\nint main() {\n    int N = in(), Q = in();\n    using value_type = int;\n \
    \   vector< value_type > a = in(N);\n    zipper< value_type > z(a);\n    wavlet_matrix<\
    \ int > wm(z.zip(a));\n    \n    for(int _ : rep(Q)) {\n        int L = in(),\
    \ R = in(), k = in();\n        print(z.data[wm.quantile(L, R, k)]);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../src/cp-template.hpp\"\n#include \"../../../src/utility/zip.hpp\"\
    \n#include \"../../../src/data_structure/wavlet_matrix.hpp\"\n\nint main() {\n\
    \    int N = in(), Q = in();\n    using value_type = int;\n    vector< value_type\
    \ > a = in(N);\n    zipper< value_type > z(a);\n    wavlet_matrix< int > wm(z.zip(a));\n\
    \    \n    for(int _ : rep(Q)) {\n        int L = in(), R = in(), k = in();\n\
    \        print(z.data[wm.quantile(L, R, k)]);\n    }\n}"
  dependsOn:
  - src/cp-template.hpp
  - src/utility/rep_itr.hpp
  - src/utility/io.hpp
  - src/utility/key_val.hpp
  - src/utility/vec_op.hpp
  - src/utility/heap.hpp
  - src/algorithm/bin_search.hpp
  - src/algorithm/argsort.hpp
  - src/utility/zip.hpp
  - src/data_structure/wavlet_matrix.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/wavlet_matrix.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 04:26:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/wavlet_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/wavlet_matrix.test.cpp
- /verify/verify/library_checker/data_structure/wavlet_matrix.test.cpp.html
title: verify/library_checker/data_structure/wavlet_matrix.test.cpp
---
