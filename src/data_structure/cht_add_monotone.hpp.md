---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structure/cht_add_monotone.hpp\"\ntemplate < class\
    \ T > class CHT_add_monotone {\n\n    struct Line {\n        T a, b;\n       \
    \ Line(T a, T b) : a(a), b(b) {}\n        T eval(T x) { return a * x + b; }\n\
    \    };\n\n    deque< Line > H;\n    T sgn;\n\n    int sgn_of(T x) { return x\
    \ == 0 ? 0 : (x < 0 ? -1 : 1); }\n\n    using D = long double;\n    bool check(Line\
    \ &a, Line &b, Line &c) {\n        if(a.b == b.b || b.b == c.b) return sgn_of(b.a\
    \ - a.a) * sgn_of(c.b - b.b) >= sgn_of(c.a - b.a) * sgn_of(b.b - a.b);\n     \
    \   return D(b.a - a.a) * sgn_of(c.b - b.b) / D(abs(b.b - a.b)) >= D(c.a - b.a)\
    \ * sgn_of(b.b - a.b) / D(abs(c.b - b.b));\n    }\n\n  public:\n    CHT_add_monotone(bool\
    \ is_min = true) { sgn = is_min ? +1 : -1; }\n\n    bool empty() { return H.empty();\
    \ }\n\n    void clear() { H.clear(); }\n\n    void add(T a, T b) {\n        a\
    \ *= sgn, b *= sgn;\n        Line l(a, b);\n        if(empty()) {\n          \
    \  H.push_front(l);\n        } else if(H.front().a <= a) {\n            if(H.front().a\
    \ == a) {\n                if(H.front().b <= b) return;\n                H.pop_front();\n\
    \            }\n            while(H.size() >= 2 && check(l, H.front(), H[1]))\
    \ H.pop_front();\n            H.push_front(l);\n        } else {\n           \
    \ assert(a <= H.back().a);\n            if(H.back().a == a) {\n              \
    \  if(H.back().b <= b) return;\n                H.pop_back();\n            }\n\
    \            while(H.size() >= 2 && check(H[H.size() - 2], H.back(), l)) H.pop_back();\n\
    \            H.push_back(l);\n        }\n    }\n\n    T query(T x) {\n       \
    \ assert(!empty());\n        int l = -1, r = H.size() - 1;\n        while(l +\
    \ 1 < r) {\n            int m = (l + r) / 2;\n            (H[m].eval(x) >= H[m\
    \ + 1].eval(x) ? l : r) = m;\n        }\n        return sgn * H[r].eval(x);\n\
    \    }\n\n    T query_monotone_inc(T x) {\n        assert(!empty());\n       \
    \ while(H.size() >= 2 && H.front().eval(x) >= H[1].eval(x)) H.pop_front();\n \
    \       return sgn * H.front().eval(x);\n    }\n\n    T query_monotone_dec(T x)\
    \ {\n        assert(!empty());\n        while(H.size() >= 2 && H.back().eval(x)\
    \ >= H[H.size() - 2].eval(x)) H.pop_back();\n        return sgn * H.back().eval(x);\n\
    \    }\n};\n"
  code: "template < class T > class CHT_add_monotone {\n\n    struct Line {\n    \
    \    T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T eval(T x) { return\
    \ a * x + b; }\n    };\n\n    deque< Line > H;\n    T sgn;\n\n    int sgn_of(T\
    \ x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }\n\n    using D = long double;\n\
    \    bool check(Line &a, Line &b, Line &c) {\n        if(a.b == b.b || b.b ==\
    \ c.b) return sgn_of(b.a - a.a) * sgn_of(c.b - b.b) >= sgn_of(c.a - b.a) * sgn_of(b.b\
    \ - a.b);\n        return D(b.a - a.a) * sgn_of(c.b - b.b) / D(abs(b.b - a.b))\
    \ >= D(c.a - b.a) * sgn_of(b.b - a.b) / D(abs(c.b - b.b));\n    }\n\n  public:\n\
    \    CHT_add_monotone(bool is_min = true) { sgn = is_min ? +1 : -1; }\n\n    bool\
    \ empty() { return H.empty(); }\n\n    void clear() { H.clear(); }\n\n    void\
    \ add(T a, T b) {\n        a *= sgn, b *= sgn;\n        Line l(a, b);\n      \
    \  if(empty()) {\n            H.push_front(l);\n        } else if(H.front().a\
    \ <= a) {\n            if(H.front().a == a) {\n                if(H.front().b\
    \ <= b) return;\n                H.pop_front();\n            }\n            while(H.size()\
    \ >= 2 && check(l, H.front(), H[1])) H.pop_front();\n            H.push_front(l);\n\
    \        } else {\n            assert(a <= H.back().a);\n            if(H.back().a\
    \ == a) {\n                if(H.back().b <= b) return;\n                H.pop_back();\n\
    \            }\n            while(H.size() >= 2 && check(H[H.size() - 2], H.back(),\
    \ l)) H.pop_back();\n            H.push_back(l);\n        }\n    }\n\n    T query(T\
    \ x) {\n        assert(!empty());\n        int l = -1, r = H.size() - 1;\n   \
    \     while(l + 1 < r) {\n            int m = (l + r) / 2;\n            (H[m].eval(x)\
    \ >= H[m + 1].eval(x) ? l : r) = m;\n        }\n        return sgn * H[r].eval(x);\n\
    \    }\n\n    T query_monotone_inc(T x) {\n        assert(!empty());\n       \
    \ while(H.size() >= 2 && H.front().eval(x) >= H[1].eval(x)) H.pop_front();\n \
    \       return sgn * H.front().eval(x);\n    }\n\n    T query_monotone_dec(T x)\
    \ {\n        assert(!empty());\n        while(H.size() >= 2 && H.back().eval(x)\
    \ >= H[H.size() - 2].eval(x)) H.pop_back();\n        return sgn * H.back().eval(x);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht_add_monotone.hpp
  requiredBy: []
  timestamp: '2022-03-21 11:21:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/cht_add_monotone.hpp
layout: document
redirect_from:
- /library/src/data_structure/cht_add_monotone.hpp
- /library/src/data_structure/cht_add_monotone.hpp.html
title: src/data_structure/cht_add_monotone.hpp
---
