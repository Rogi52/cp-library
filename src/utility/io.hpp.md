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
  bundledCode: "#line 1 \"src/utility/io.hpp\"\nnamespace scanner {\n    static int\
    \ sz = -1;\n    static int first = 1;\n    struct input {\n        template <\
    \ class T > operator T() const {\n            if(first) {\n                first\
    \ = 0;\n                cin.tie(0);\n                ios::sync_with_stdio(0);\n\
    \            }\n            if(sz == -1) {\n                T t; cin >> t; return\
    \ t;\n            } else {\n                T t(sz); sz = -1; cin >> t; return\
    \ t;\n            }\n        }\n    };\n\n    template < class T > istream& operator>>(istream&\
    \ is, vector< T >& a) {\n        for(auto& x : a) cin >> x; return is;\n    }\n\
    }\nscanner::input input() { return scanner::input(); }\nscanner::input input(int\
    \ sz) { scanner::sz = sz; return scanner::input(); }\n\nnamespace printer {\n\
    \    void precision(int d) {\n        cout << fixed << setprecision(d);\n    }\n\
    }\nint print() { cout << \"\\n\"; return 0; }\ntemplate < class head, class...\
    \ tail >\nint print(head&& h, tail&&... t) {\n    cout << h;\n    if(sizeof...(tail))\
    \ cout << \" \";\n    return print(forward<tail>(t)...);\n}\ntemplate < class\
    \ T > int print(vector< T >& a, char sep = ' ') {\n    int n = a.size();\n   \
    \ rep(i,n) cout << a[i] << (i < n - 1 ? sep : '\\n');\n    return 0;\n}\n"
  code: "namespace scanner {\n    static int sz = -1;\n    static int first = 1;\n\
    \    struct input {\n        template < class T > operator T() const {\n     \
    \       if(first) {\n                first = 0;\n                cin.tie(0);\n\
    \                ios::sync_with_stdio(0);\n            }\n            if(sz ==\
    \ -1) {\n                T t; cin >> t; return t;\n            } else {\n    \
    \            T t(sz); sz = -1; cin >> t; return t;\n            }\n        }\n\
    \    };\n\n    template < class T > istream& operator>>(istream& is, vector< T\
    \ >& a) {\n        for(auto& x : a) cin >> x; return is;\n    }\n}\nscanner::input\
    \ input() { return scanner::input(); }\nscanner::input input(int sz) { scanner::sz\
    \ = sz; return scanner::input(); }\n\nnamespace printer {\n    void precision(int\
    \ d) {\n        cout << fixed << setprecision(d);\n    }\n}\nint print() { cout\
    \ << \"\\n\"; return 0; }\ntemplate < class head, class... tail >\nint print(head&&\
    \ h, tail&&... t) {\n    cout << h;\n    if(sizeof...(tail)) cout << \" \";\n\
    \    return print(forward<tail>(t)...);\n}\ntemplate < class T > int print(vector<\
    \ T >& a, char sep = ' ') {\n    int n = a.size();\n    rep(i,n) cout << a[i]\
    \ << (i < n - 1 ? sep : '\\n');\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/io.hpp
  requiredBy: []
  timestamp: '2023-04-12 08:09:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/io.hpp
layout: document
redirect_from:
- /library/src/utility/io.hpp
- /library/src/utility/io.hpp.html
title: src/utility/io.hpp
---
