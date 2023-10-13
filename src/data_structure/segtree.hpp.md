---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/segtree.test.cpp
    title: verify/library_checker/data_structure/segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structure/segtree.hpp\"\ntemplate < class monoid\
    \ > struct segtree {\n    using S = typename monoid::set;\n\n    segtree() : segtree(0)\
    \ {}\n    segtree(int n) : segtree(vector< S >(n, monoid::id())) {}\n    segtree(int\
    \ n, S s) : segtree(vector< S >(n, s)) {}\n    segtree(const vector< S >& v) :\
    \ _n(int(v.size())) {\n        log = ceil_pow2(_n);\n        size = 1 << log;\n\
    \        d = vector< S >(2 * size, monoid::id());\n        for(int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >= 1; i--) update(i);\n\
    \    }\n    // a[i] <- x\n    void set(int i, S x) {\n        assert(0 <= i &&\
    \ i < _n);\n        i += size;\n        d[i] = x;\n        for(int p = 1; p <=\
    \ log; p++) update(i >> p);\n    }\n    // a[i]\n    S get(int i) {\n        assert(0\
    \ <= i && i < _n);\n        return d[i + size];\n    }\n    // [l, r)\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = monoid::id(),\
    \ smr = monoid::id();\n        l += size, r += size;\n        while(l < r) {\n\
    \            if(l & 1) sml = monoid::op(sml, d[l++]);\n            if(r & 1) smr\
    \ = monoid::op(d[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n     \
    \   return monoid::op(sml, smr);\n    }\n    S all_prod() { return d[1]; }\n \
    \   template < class func > int max_right(int l, func f) {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(monoid::id()));\n        if(l == _n) return\
    \ _n;\n        l += size;\n        S sm = monoid::id();\n        do {\n      \
    \      while(l % 2 == 0) l >>= 1;\n            if(!f(monoid::op(sm, d[l]))) {\n\
    \                while(l < size) {\n                    l = 2 * l;\n         \
    \           if(f(monoid::op(sm, d[l]))) {\n                        sm = monoid::op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = monoid::op(sm,\
    \ d[l]);\n            l++;\n        } while((l & -l) != l);\n        return _n;\n\
    \    }\n    template < class func > int min_left(int r, func f) {\n        assert(0\
    \ <= r && r <= _n);\n        assert(f(monoid::id()));\n        if(r == 0) return\
    \ 0;\n        r += size;\n        S sm = monoid::id();\n        do {\n       \
    \     r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n            if(!f(monoid::op(d[r],\
    \ sm))) {\n                while(r < size) {\n                    r = 2 * r +\
    \ 1;\n                    if(f(monoid::op(d[r], sm))) {\n                    \
    \    sm = monoid::op(d[r], sm);\n                        r--;\n              \
    \      }\n                }\n                return r + 1 - size;\n          \
    \  }\n            sm = monoid::op(d[r], sm);\n        } while((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    vector< S\
    \ > d;\n    int ceil_pow2(int n) { int x = 0; while((1U << x) < uint(n)) x++;\
    \ return x; }\n    void update(int k) { d[k] = monoid::op(d[2 * k], d[2 * k +\
    \ 1]); }\n};\n"
  code: "template < class monoid > struct segtree {\n    using S = typename monoid::set;\n\
    \n    segtree() : segtree(0) {}\n    segtree(int n) : segtree(vector< S >(n, monoid::id()))\
    \ {}\n    segtree(int n, S s) : segtree(vector< S >(n, s)) {}\n    segtree(const\
    \ vector< S >& v) : _n(int(v.size())) {\n        log = ceil_pow2(_n);\n      \
    \  size = 1 << log;\n        d = vector< S >(2 * size, monoid::id());\n      \
    \  for(int i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size -\
    \ 1; i >= 1; i--) update(i);\n    }\n    // a[i] <- x\n    void set(int i, S x)\
    \ {\n        assert(0 <= i && i < _n);\n        i += size;\n        d[i] = x;\n\
    \        for(int p = 1; p <= log; p++) update(i >> p);\n    }\n    // a[i]\n \
    \   S get(int i) {\n        assert(0 <= i && i < _n);\n        return d[i + size];\n\
    \    }\n    // [l, r)\n    S prod(int l, int r) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        S sml = monoid::id(), smr = monoid::id();\n     \
    \   l += size, r += size;\n        while(l < r) {\n            if(l & 1) sml =\
    \ monoid::op(sml, d[l++]);\n            if(r & 1) smr = monoid::op(d[--r], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return monoid::op(sml, smr);\n\
    \    }\n    S all_prod() { return d[1]; }\n    template < class func > int max_right(int\
    \ l, func f) {\n        assert(0 <= l && l <= _n);\n        assert(f(monoid::id()));\n\
    \        if(l == _n) return _n;\n        l += size;\n        S sm = monoid::id();\n\
    \        do {\n            while(l % 2 == 0) l >>= 1;\n            if(!f(monoid::op(sm,\
    \ d[l]))) {\n                while(l < size) {\n                    l = 2 * l;\n\
    \                    if(f(monoid::op(sm, d[l]))) {\n                        sm\
    \ = monoid::op(sm, d[l]);\n                        l++;\n                    }\n\
    \                }\n                return l - size;\n            }\n        \
    \    sm = monoid::op(sm, d[l]);\n            l++;\n        } while((l & -l) !=\
    \ l);\n        return _n;\n    }\n    template < class func > int min_left(int\
    \ r, func f) {\n        assert(0 <= r && r <= _n);\n        assert(f(monoid::id()));\n\
    \        if(r == 0) return 0;\n        r += size;\n        S sm = monoid::id();\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!f(monoid::op(d[r], sm))) {\n                while(r < size) {\n\
    \                    r = 2 * r + 1;\n                    if(f(monoid::op(d[r],\
    \ sm))) {\n                        sm = monoid::op(d[r], sm);\n              \
    \          r--;\n                    }\n                }\n                return\
    \ r + 1 - size;\n            }\n            sm = monoid::op(d[r], sm);\n     \
    \   } while((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n,\
    \ size, log;\n    vector< S > d;\n    int ceil_pow2(int n) { int x = 0; while((1U\
    \ << x) < uint(n)) x++; return x; }\n    void update(int k) { d[k] = monoid::op(d[2\
    \ * k], d[2 * k + 1]); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-10-14 00:28:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/segtree.test.cpp
documentation_of: src/data_structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/segtree.hpp
- /library/src/data_structure/segtree.hpp.html
title: src/data_structure/segtree.hpp
---
