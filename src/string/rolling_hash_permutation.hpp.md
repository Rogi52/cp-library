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
  bundledCode: "#line 1 \"src/string/rolling_hash_permutation.hpp\"\ntemplate < int\
    \ num_of_mod >\nstruct rolling_hash_perm {\n    int k;\n    vector< rolling_hash<\
    \ num_of_mod > > rhs;\n    rolling_hash_perm(const string& s, int k) : k(k), rhs(k)\
    \ {\n        int n = s.size();\n        rep(a,k) {\n            string t = \"\"\
    ;\n            rep(i,n) t += (s[i] - 'a' == a);\n            rhs[a] = rolling_hash<\
    \ num_of_mod >(t);\n        }\n    }\n\n    using hash = typename rolling_hash<\
    \ num_of_mod >::hash;\n    // [l, r)\n    vector< hash > get(int l, int r) const\
    \ {\n        vector< hash > res(k);\n        rep(a,k) res[a] = rhs[a].get(l, r);\n\
    \        sort(res.begin(), res.end());\n        return res;\n    }\n\n    template\
    \ < int n >\n    static int lcp(const rolling_hash_perm< n >& rh1, int l1, int\
    \ r1, const rolling_hash_perm< n >& rh2, int l2, int r2) {\n        int lo = -1,\
    \ hi = min(r1 - l1, r2 - l2) + 1;\n        while(hi - lo > 1) {\n            int\
    \ mid = (lo + hi) / 2;\n            (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 +\
    \ mid) ? lo : hi) = mid;\n        }\n        return lo;\n    }\n};\n"
  code: "template < int num_of_mod >\nstruct rolling_hash_perm {\n    int k;\n   \
    \ vector< rolling_hash< num_of_mod > > rhs;\n    rolling_hash_perm(const string&\
    \ s, int k) : k(k), rhs(k) {\n        int n = s.size();\n        rep(a,k) {\n\
    \            string t = \"\";\n            rep(i,n) t += (s[i] - 'a' == a);\n\
    \            rhs[a] = rolling_hash< num_of_mod >(t);\n        }\n    }\n\n   \
    \ using hash = typename rolling_hash< num_of_mod >::hash;\n    // [l, r)\n   \
    \ vector< hash > get(int l, int r) const {\n        vector< hash > res(k);\n \
    \       rep(a,k) res[a] = rhs[a].get(l, r);\n        sort(res.begin(), res.end());\n\
    \        return res;\n    }\n\n    template < int n >\n    static int lcp(const\
    \ rolling_hash_perm< n >& rh1, int l1, int r1, const rolling_hash_perm< n >& rh2,\
    \ int l2, int r2) {\n        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;\n  \
    \      while(hi - lo > 1) {\n            int mid = (lo + hi) / 2;\n          \
    \  (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;\n       \
    \ }\n        return lo;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rolling_hash_permutation.hpp
  requiredBy: []
  timestamp: '2023-03-30 00:39:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rolling_hash_permutation.hpp
layout: document
redirect_from:
- /library/src/string/rolling_hash_permutation.hpp
- /library/src/string/rolling_hash_permutation.hpp.html
title: src/string/rolling_hash_permutation.hpp
---
