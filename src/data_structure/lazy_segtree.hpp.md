---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/lazy_segtree.test.cpp
    title: verify/library_checker/data_structure/lazy_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data_structure/lazy_segtree.hpp\"\ntemplate < class\
    \ A > struct lazy_segtree {\n  public:\n    using V = typename A::value_structure;\n\
    \    using S = typename V::set;\n    using O = typename A::operator_structure;\n\
    \    using F = typename O::set;\n    int _n, size, log;\n    vector< S > d;\n\
    \    vector< F > lz;\n\n    void update(int k) { d[k] = V::op(d[2 * k], d[2 *\
    \ k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = A::op(d[k], f);\n\
    \        if(k < size) lz[k] = O::op(lz[k], f);\n    }\n    void push(int k) {\n\
    \        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n    \
    \    lz[k] = O::id;\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n \
    \       while((1U << x) < uint(n)) x++;\n        return x;\n    }\n\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    lazy_segtree(int n) : lazy_segtree(vector< S >(n,\
    \ S::id)) {}\n    lazy_segtree(const vector< S >& v) : _n(int(v.size())) {\n \
    \       log = ceil_pow2(_n);\n        size = 1 << log;\n        d = vector< S\
    \ >(2 * size, V::id);\n        lz = vector< F >(size, O::id);\n        for(int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >=\
    \ 1; i--) update(i);\n    }\n\n    void set(int i, S x) {\n        assert(0 <=\
    \ i && i < _n);\n        i += size;\n        for(int p = log; p >= 1; p--) push(i\
    \ >> p);\n        d[i] = x;\n        for(int p = 1; p <= log; p++) update(i >>\
    \ p);\n    }\n    S get(int i) {\n        assert(0 <= i && i < _n);\n        i\
    \ += size;\n        for(int p = log; p >= 1; p--) push(i >> p);\n        return\
    \ d[i];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if(l == r) return V::id;\n        l += size, r += size;\n\
    \        for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push(r >> i);\n        }\n\
    \        S sml = V::id, smr = V::id;\n        while(l < r) {\n            if(l\
    \ & 1) sml = V::op(sml, d[l++]);\n            if(r & 1) smr = V::op(d[--r], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return V::op(sml, smr);\n \
    \   }\n    S all_prod() { return d[1]; }\n    void apply(int i, F f) {\n     \
    \   assert(0 <= i && i < _n);\n        i += size;\n        for(int p = log; p\
    \ >= 1; p--) push(i >> p);\n        d[i] = O::op(d[i], f);\n        for(int p\
    \ = 1; p <= log; p++) update(i >> p);\n    }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n\
    \        l += size, r += size;\n        for(int i = log; i >= 1; i--) {\n    \
    \        if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while(l < r) {\n                if(l & 1) all_apply(l++, f);\n\
    \                if(r & 1) all_apply(--r, f);\n                l >>= 1, r >>=\
    \ 1;\n            }\n            l = l2, r = r2;\n        }\n        for(int i\
    \ = 1; i <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n\
    \            if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    template < class G > int max_right(int l, G g) {\n        assert(0 <= l &&\
    \ l <= _n);\n        assert(g(V::id));\n        if(l == _n) return _n;\n     \
    \   l += size;\n        for(int i = log; i >= 1; i--) push(l >> i);\n        S\
    \ sm = V::id();\n        do {\n            while(l % 2 == 0) l >>= 1;\n      \
    \      if(!g(V::op(sm, d[l]))) {\n                while(l < size) {\n        \
    \            push(l);\n                    l = 2 * l;\n                    if(g(V::op(sm,\
    \ d[l]))) {\n                        sm = V::op(sm, d[l]);\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = V::op(sm, d[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return _n;\n    }\n    template < class\
    \ G > int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n       \
    \ assert(g(V::id));\n        if(r == 0) return 0;\n        r += size;\n      \
    \  for(int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = V::id;\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!g(V::op(d[r], sm))) {\n                while(r < size) {\n  \
    \                  push(r);\n                    r = 2 * r + 1;\n            \
    \        if(g(V::op(d[r], sm))) {\n                        sm = V::op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = V::op(d[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n};\n"
  code: "template < class A > struct lazy_segtree {\n  public:\n    using V = typename\
    \ A::value_structure;\n    using S = typename V::set;\n    using O = typename\
    \ A::operator_structure;\n    using F = typename O::set;\n    int _n, size, log;\n\
    \    vector< S > d;\n    vector< F > lz;\n\n    void update(int k) { d[k] = V::op(d[2\
    \ * k], d[2 * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = A::op(d[k],\
    \ f);\n        if(k < size) lz[k] = O::op(lz[k], f);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = O::id;\n    }\n    int ceil_pow2(int n) {\n        int x = 0;\n\
    \        while((1U << x) < uint(n)) x++;\n        return x;\n    }\n\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    lazy_segtree(int n) : lazy_segtree(vector< S >(n,\
    \ S::id)) {}\n    lazy_segtree(const vector< S >& v) : _n(int(v.size())) {\n \
    \       log = ceil_pow2(_n);\n        size = 1 << log;\n        d = vector< S\
    \ >(2 * size, V::id);\n        lz = vector< F >(size, O::id);\n        for(int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size - 1; i >=\
    \ 1; i--) update(i);\n    }\n\n    void set(int i, S x) {\n        assert(0 <=\
    \ i && i < _n);\n        i += size;\n        for(int p = log; p >= 1; p--) push(i\
    \ >> p);\n        d[i] = x;\n        for(int p = 1; p <= log; p++) update(i >>\
    \ p);\n    }\n    S get(int i) {\n        assert(0 <= i && i < _n);\n        i\
    \ += size;\n        for(int p = log; p >= 1; p--) push(i >> p);\n        return\
    \ d[i];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if(l == r) return V::id;\n        l += size, r += size;\n\
    \        for(int i = log; i >= 1; i--) {\n            if(((l >> i) << i) != l)\
    \ push(l >> i);\n            if(((r >> i) << i) != r) push(r >> i);\n        }\n\
    \        S sml = V::id, smr = V::id;\n        while(l < r) {\n            if(l\
    \ & 1) sml = V::op(sml, d[l++]);\n            if(r & 1) smr = V::op(d[--r], smr);\n\
    \            l >>= 1, r >>= 1;\n        }\n        return V::op(sml, smr);\n \
    \   }\n    S all_prod() { return d[1]; }\n    void apply(int i, F f) {\n     \
    \   assert(0 <= i && i < _n);\n        i += size;\n        for(int p = log; p\
    \ >= 1; p--) push(i >> p);\n        d[i] = O::op(d[i], f);\n        for(int p\
    \ = 1; p <= log; p++) update(i >> p);\n    }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return;\n\
    \        l += size, r += size;\n        for(int i = log; i >= 1; i--) {\n    \
    \        if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while(l < r) {\n                if(l & 1) all_apply(l++, f);\n\
    \                if(r & 1) all_apply(--r, f);\n                l >>= 1, r >>=\
    \ 1;\n            }\n            l = l2, r = r2;\n        }\n        for(int i\
    \ = 1; i <= log; i++) {\n            if(((l >> i) << i) != l) update(l >> i);\n\
    \            if(((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    template < class G > int max_right(int l, G g) {\n        assert(0 <= l &&\
    \ l <= _n);\n        assert(g(V::id));\n        if(l == _n) return _n;\n     \
    \   l += size;\n        for(int i = log; i >= 1; i--) push(l >> i);\n        S\
    \ sm = V::id();\n        do {\n            while(l % 2 == 0) l >>= 1;\n      \
    \      if(!g(V::op(sm, d[l]))) {\n                while(l < size) {\n        \
    \            push(l);\n                    l = 2 * l;\n                    if(g(V::op(sm,\
    \ d[l]))) {\n                        sm = V::op(sm, d[l]);\n                 \
    \       l++;\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = V::op(sm, d[l]);\n            l++;\n\
    \        } while((l & -l) != l);\n        return _n;\n    }\n    template < class\
    \ G > int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n       \
    \ assert(g(V::id));\n        if(r == 0) return 0;\n        r += size;\n      \
    \  for(int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = V::id;\n\
    \        do {\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!g(V::op(d[r], sm))) {\n                while(r < size) {\n  \
    \                  push(r);\n                    r = 2 * r + 1;\n            \
    \        if(g(V::op(d[r], sm))) {\n                        sm = V::op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = V::op(d[r],\
    \ sm);\n        } while((r & -r) != r);\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-26 20:40:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/lazy_segtree.test.cpp
documentation_of: src/data_structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/src/data_structure/lazy_segtree.hpp
- /library/src/data_structure/lazy_segtree.hpp.html
title: src/data_structure/lazy_segtree.hpp
---
