---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/aoj/geometry/polygon_area.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A\"\n\n#line\
    \ 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing uint = unsigned int;\nusing\
    \ ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned int;\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\n\
    template < class T > bool chmin(T& a, T b) { if(a > b) { a = b; return true; }\
    \ return false; }\ntemplate < class T > bool chmax(T& a, T b) { if(a < b) { a\
    \ = b; return true; } return false; }\ntemplate < class T, class U > T ceil (T\
    \ x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y); }\ntemplate <\
    \ class T, class U > T floor(T x, U y) { return (x > 0 ?           x / y : (x\
    \ - y + 1) / y); }\nint popcnt(i32 x) { return __builtin_popcount(x); }\nint popcnt(u32\
    \ x) { return __builtin_popcount(x); }\nint popcnt(i64 x) { return __builtin_popcountll(x);\
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
    \ 2 \"src/geometry/base.hpp\"\n\ntemplate < class T >\nstruct point {\n    T x,\
    \ y;\n    point() : x(0), y(0) {}\n    point(T x, T y) : x(x), y(y) {}\n    point(std::pair<\
    \ T, T > p) : x(p.first), y(p.second) {}\n\n    point& operator+=(const point&\
    \ p) { x += p.x, y += p.y; return *this; }\n    point& operator-=(const point&\
    \ p) { x -= p.x, y -= p.y; return *this; }\n    point& operator*=(const T r) {\
    \ x *= r, y *= r; return *this; }\n    point& operator/=(const T r) { x /= r,\
    \ y /= r; return *this; }\n    point operator+(const point& p) const { return\
    \ point(*this) += p; }\n    point operator-(const point& p) const { return point(*this)\
    \ -= p; }\n    point operator*(const T r) const { return point(*this) *= r; }\n\
    \    point operator/(const T r) const { return point(*this) /= r; }\n    point\
    \ operator-() const { return {-x, -y}; }\n    bool operator==(const point& p)\
    \ const { return x == p.x and y == p.y; }\n    bool operator!=(const point& p)\
    \ const { return x != p.x or  y != p.y; }\n\n    bool operator<(const point& p)\
    \ const {\n        if(x == p.x) return y < p.y;\n        return x < p.x;\n   \
    \ }\n\n    point< T > rot(double theta) {\n        static_assert(is_floating_point_v<\
    \ T >);\n        double cos_ = std::cos(theta), sin_ = std::sin(theta);\n    \
    \    return {cos_ * x - sin_ * y, sin_ * x + cos_ * y};\n    }\n};\ntemplate <\
    \ class T > istream& operator>>(istream& is, point< T >& p) { return is >> p.x\
    \ >> p.y; }\ntemplate < class T > ostream& operator<<(ostream& os, point< T >&\
    \ p) { return os << p.x << \" \" << p.y; }\ntemplate < class T > T dot(const point<\
    \ T >& a, const point< T >& b) { return a.x * b.x + a.y * b.y; }\ntemplate < class\
    \ T > T det(const point< T >& a, const point< T >& b) { return a.x * b.y - a.y\
    \ * b.x; }\ntemplate < class T > T norm(const point< T >& p) { return p.x * p.x\
    \ + p.y * p.y; }\ntemplate < class T > double abs(const point< T >& p) { return\
    \ std::sqrt(norm(p)); }\ntemplate < class T > double angle(const point< T >& p)\
    \ { return std::atan2(p.y, p.x); }\ntemplate < class T >\nint sign(const T x)\
    \ {\n    T e = (is_integral_v< T > ? 1 : 1e-8);\n    if(x <= -e) return -1;\n\
    \    if(x >= +e) return +1;\n    return 0;\n}\ntemplate < class T > bool equals(const\
    \ T& a, const T& b) { return sign(a - b) == 0; }\ntemplate < class T > \nint ccw(const\
    \ point< T >& a, point< T > b, point< T > c) {\n    b -= a, c -= a;\n    if(sign(det(b,\
    \ c)) == +1) return +1; // counter clockwise\n    if(sign(det(b, c)) == -1) return\
    \ -1; //         clockwise\n    if(sign(dot(b, c)) == -1) return +2; // c-a-b\n\
    \    if(norm(b) < norm(c)) return -2;     // a-b-c\n    return 0;            \
    \                // a-c-b\n}\n\ntemplate < class T >\nstruct line {\n    point<\
    \ T > a, b;\n    line() {}\n    line(point< T > a, point< T > b) : a(a), b(b)\
    \ {}\n};\ntemplate < class T > point< T > projection(const line< T >& l, const\
    \ point< T >& p) {\n    static_assert(is_floating_point_v< T >);\n    return l.a\
    \ + (l.a - l.b) * dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n}\ntemplate < class\
    \ T > point< T > reflection(const line< T >& l, const point< T >& p) {\n    static_assert(is_floating_point_v<\
    \ T >);\n    return p + (projection(l, p) - p) * T(2);\n}\ntemplate < class T\
    \ > bool orthogonal(const line< T >& a, const line< T >& b) { return equals(dot(a.b\
    \ - a.a, b.b - b.a), T(0)); }\ntemplate < class T > bool parallel  (const line<\
    \ T >& a, const line< T >& b) { return equals(det(a.b - a.a, b.b - b.a), T(0));\
    \ }\ntemplate < class T > point< T > cross_point_ll(const line< T >& l, const\
    \ line< T >& m) {\n    static_assert(is_floating_point_v< T >);\n    T A = det(l.b\
    \ - l.a, m.b - m.a);\n    T B = det(l.b - l.a, l.b - m.a);\n    if(equals(abs(A),\
    \ T(0)) and equals(abs(B), T(0))) return m.a;\n    return m.a + (m.b - m.a) *\
    \ B / A;\n}\n\ntemplate < class T > using segment = line< T >;\ntemplate < class\
    \ T > bool intersect_ss(const segment< T >& s, const segment< T >& t) {\n    return\
    \ ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a,\
    \ t.b, s.b) <= 0;\n}\ntemplate < class T > double distance_sp(const segment< T\
    \ >& s, const point< T >& p) {\n    static_assert(is_floating_point_v< T >);\n\
    \    point r = projection(s, p);\n    if(ccw(s.a, s.b, r) == 0) return abs(r -\
    \ p);\n    return std::min(abs(s.a - p), abs(s.b - p));\n}\ntemplate < class T\
    \ > double distance_ss(const segment< T >& a, const segment< T >& b) {\n    if(intersect_ss(a,\
    \ b)) return 0;\n    return std::min({ distance_sp(a, b.a), distance_sp(a, b.b),\
    \ distance_sp(b, a.a), distance_sp(b, a.b) });\n}\n\ntemplate < class T > using\
    \ polygon = std::vector< point< T > >;\ntemplate < class T > T area2(const polygon<\
    \ T >& p) {\n    T s = 0;\n    int n = p.size();\n    for(int i = 0; i < n; i++)\
    \ s += det(p[i], p[(i + 1) % n]);\n    return s;\n}\ntemplate < class T > T area(const\
    \ polygon< T >& p) { return area2(p) / T(2); }\n\ntemplate < class T > bool is_convex(const\
    \ polygon< T >& p) {\n    int n = p.size();\n    for(int i = 0; i < n; i++) if(ccw(p[(i\
    \ - 1 + n) % n], p[i], p[(i + 1) % n]) == -1) return false;\n    return true;\n\
    }\ntemplate < class T > int contains(const polygon< T >& g, const point< T >&\
    \ p) {\n    int n = g.size();\n    bool in = false;\n    for(int i = 0; i < n;\
    \ i++) {\n        point a = g[i] - p, b = g[(i + 1) % n] - p;\n        if(sign(a.y\
    \ - b.y) == +1) std::swap(a, b);\n        if(sign(a.y) <= 0 and sign(b.y) ==+1\
    \ and sign(det(a, b)) == -1) in = !in;\n        if(sign(det(a, b)) == 0 and sign(dot(a,\
    \ b)) <= 0) return 1; // ON\n    }\n    return in ? 2 : 0;\n}\ntemplate < class\
    \ T > polygon< T > convex_cut(const polygon< T >& p, const line< T >& l) {\n \
    \   int n = p.size();\n    polygon< T > res;\n    for(int i = 0; i < n; i++) {\n\
    \        point now = p[i], nxt = p[(i + 1) % n];\n        if(ccw(l.a, l.b, now)\
    \ != -1) res.push_back(now);\n        if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt)\
    \ < 0) res.push_back(cross_point_ll(line(now, nxt), l));\n    }\n    return res;\n\
    }\ntemplate < class T > polygon< T > convex_hull(polygon< T >& p) {\n    int n\
    \ = p.size(), k = 0;\n    if(n <= 2) return p;\n    std::sort(p.begin(), p.end());\n\
    \    polygon< T > ch(n + n);\n    for(int i = 0; i < n; ch[k++] = p[i++])\n  \
    \      while(k >= 2 and sign(det(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])) ==\
    \ -1) k--;\n    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--])\n    \
    \    while(k >= t and sign(det(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])) == -1)\
    \ k--;\n    ch.resize(k - 1);\n    return ch;\n}\ntemplate < class T > T diameter2(const\
    \ polygon< T >& p) {\n    static_assert(is_floating_point_v< T >);\n    int n\
    \ = p.size(), is = 0, js = 0;\n    for(int i = 1; i < n; i++) {\n        if(sign(p[i].y\
    \ - p[is].y) == +1) is = i;\n        if(sign(p[i].y - p[js].y) == -1) js = i;\n\
    \    }\n    T dist_max = norm(p[is] - p[js]);\n    int maxi = is, i = is, maxj\
    \ = js, j = js;\n    do {\n        if(sign(det(p[(i + 1) % n] - p[i], p[(j + 1)\
    \ % n] - p[j])) >= 0) j = (j + 1) % n; else i = (i + 1) % n;\n        if(norm(p[i]\
    \ - p[j]) > dist_max) {\n            dist_max = norm(p[i] - p[j]);\n         \
    \   maxi = i, maxj = j;\n        }\n    } while(i != is or j != js);\n    return\
    \ dist_max;\n}\ntemplate < class T > double diameter(const polygon< T >& p) {\n\
    \    static_assert(is_floating_point_v< T >);\n    return std::sqrt(diameter2(p));\n\
    }\n#line 5 \"verify/aoj/geometry/polygon_area.test.cpp\"\n\nint main() {\n   \
    \ int n = in();\n    polygon<i64> p = in(n);\n    i64 s = area2(p);\n    std::cout\
    \ << s / 2 << \".\" << (s % 2 == 0 ? 0 : 5) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A\"\
    \n\n#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/geometry/base.hpp\"\
    \n\nint main() {\n    int n = in();\n    polygon<i64> p = in(n);\n    i64 s =\
    \ area2(p);\n    std::cout << s / 2 << \".\" << (s % 2 == 0 ? 0 : 5) << std::endl;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj/geometry/polygon_area.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/geometry/polygon_area.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/geometry/polygon_area.test.cpp
- /verify/verify/aoj/geometry/polygon_area.test.cpp.html
title: verify/aoj/geometry/polygon_area.test.cpp
---
