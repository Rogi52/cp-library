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
  bundledCode: "#line 1 \"src/data_structure/cht_offline_get_min.hpp\"\ntemplate <\
    \ class T > class CHT_offline_get_min {\n  private:\n    struct Line {\n     \
    \   T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T eval(T x) { return\
    \ a * x + b; }\n    };\n\n    T sgn;\n    int n;\n    vector< Line > ls;\n   \
    \ vector< T > xs;\n\n  public:\n    T inf = numeric_limits< T >::max();\n\n  \
    \  CHT_offline_get_min(vector< T > &x, bool is_min = true) : xs(x) {\n       \
    \ sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = xs.size();\n        ls.assign(n << 1, Line(0, inf));\n\
    \        sgn = is_min ? +1 : -1;\n    }\n\n    void add_line(T a, T b) { update(a,\
    \ b, 0, n); }\n\n    void add_segment(T a, T b, T l, T r) {\n        int xl =\
    \ distance(xs.begin(), lower_bound(xs.begin(), xs.end(), l));\n        int xr\
    \ = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), r));\n        update(a,\
    \ b, xl, xr);\n    }\n\n    T query(T x) {\n        int i = distance(xs.begin(),\
    \ lower_bound(xs.begin(), xs.end(), x));\n        assert(i != n && x == xs[i]);\n\
    \        T v = inf;\n        for(i += n; i > 0; i >>= 1) v = min(v, ls[i].eval(x));\n\
    \        return sgn * v;\n    }\n\n  private:\n    void update(T a, T b, int l,\
    \ int r) {\n        a *= sgn, b *= sgn;\n        Line f(a, b);\n        for(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) descend(f, l++);\n\
    \            if(r & 1) descend(f, --r);\n        }\n    }\n\n    void descend(Line\
    \ g, int i) {\n        int l = i, r = i + 1;\n        while(l < n) l <<= 1, r\
    \ <<= 1;\n        while(l < r) {\n            int m = (l + r) >> 1;\n        \
    \    T xl = xs[l - n], xm = xs[m - n], xr = xs[r - 1 - n];\n            Line &f\
    \ = ls[i];\n            if(f.eval(xl) <= g.eval(xl) && f.eval(xr) <= g.eval(xr))\
    \ return;\n            if(f.eval(xl) >= g.eval(xl) && f.eval(xr) >= g.eval(xr))\
    \ { f = g; return; }\n            if(f.eval(xm) >  g.eval(xm)) swap(f, g);\n \
    \           if(f.eval(xl) >  g.eval(xl)) i = i << 1 | 0, r = m; else i = i <<\
    \ 1 | 1, l = m;\n        }\n    }\n};\n"
  code: "template < class T > class CHT_offline_get_min {\n  private:\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T eval(T\
    \ x) { return a * x + b; }\n    };\n\n    T sgn;\n    int n;\n    vector< Line\
    \ > ls;\n    vector< T > xs;\n\n  public:\n    T inf = numeric_limits< T >::max();\n\
    \n    CHT_offline_get_min(vector< T > &x, bool is_min = true) : xs(x) {\n    \
    \    sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = xs.size();\n        ls.assign(n << 1, Line(0, inf));\n\
    \        sgn = is_min ? +1 : -1;\n    }\n\n    void add_line(T a, T b) { update(a,\
    \ b, 0, n); }\n\n    void add_segment(T a, T b, T l, T r) {\n        int xl =\
    \ distance(xs.begin(), lower_bound(xs.begin(), xs.end(), l));\n        int xr\
    \ = distance(xs.begin(), lower_bound(xs.begin(), xs.end(), r));\n        update(a,\
    \ b, xl, xr);\n    }\n\n    T query(T x) {\n        int i = distance(xs.begin(),\
    \ lower_bound(xs.begin(), xs.end(), x));\n        assert(i != n && x == xs[i]);\n\
    \        T v = inf;\n        for(i += n; i > 0; i >>= 1) v = min(v, ls[i].eval(x));\n\
    \        return sgn * v;\n    }\n\n  private:\n    void update(T a, T b, int l,\
    \ int r) {\n        a *= sgn, b *= sgn;\n        Line f(a, b);\n        for(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) descend(f, l++);\n\
    \            if(r & 1) descend(f, --r);\n        }\n    }\n\n    void descend(Line\
    \ g, int i) {\n        int l = i, r = i + 1;\n        while(l < n) l <<= 1, r\
    \ <<= 1;\n        while(l < r) {\n            int m = (l + r) >> 1;\n        \
    \    T xl = xs[l - n], xm = xs[m - n], xr = xs[r - 1 - n];\n            Line &f\
    \ = ls[i];\n            if(f.eval(xl) <= g.eval(xl) && f.eval(xr) <= g.eval(xr))\
    \ return;\n            if(f.eval(xl) >= g.eval(xl) && f.eval(xr) >= g.eval(xr))\
    \ { f = g; return; }\n            if(f.eval(xm) >  g.eval(xm)) swap(f, g);\n \
    \           if(f.eval(xl) >  g.eval(xl)) i = i << 1 | 0, r = m; else i = i <<\
    \ 1 | 1, l = m;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht_offline_get_min.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/cht_offline_get_min.hpp
layout: document
redirect_from:
- /library/src/data_structure/cht_offline_get_min.hpp
- /library/src/data_structure/cht_offline_get_min.hpp.html
title: src/data_structure/cht_offline_get_min.hpp
---
