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
  bundledCode: "#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr_rep\
    \ {\n    T i, d;\n    constexpr itr_rep(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr_rep(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr_rep x) const noexcept\
    \ { return d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class T > struct rep\
    \ {\n    const itr_rep< T > s, t;\n    constexpr rep(const T t) noexcept : s(0),\
    \ t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n\
    \    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d)\
    \ {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr auto\
    \ end  () const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr_rep < T > s, t;\n    constexpr revrep(const T t) noexcept :\
    \ s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end  () const noexcept { return\
    \ t; }\n};\n"
  code: "#pragma once\ntemplate < class T > struct itr_rep {\n    T i, d;\n    constexpr\
    \ itr_rep(const T i) noexcept : i(i), d(1) {}\n    constexpr itr_rep(const T i,\
    \ const T d) noexcept : i(i), d(d) {}\n    void operator++() noexcept { i += d;\
    \ }\n    constexpr int operator*() const noexcept { return i; }\n    constexpr\
    \ bool operator!=(const itr_rep x) const noexcept { return d > 0 ? i < x.i : i\
    \ > x.i; }\n};\n\ntemplate < class T > struct rep {\n    const itr_rep< T > s,\
    \ t;\n    constexpr rep(const T t) noexcept : s(0), t(t) {}\n    constexpr rep(const\
    \ T s, const T t) noexcept : s(s), t(t) {}\n    constexpr rep(const T s, const\
    \ T t, const T d) noexcept : s(s, d), t(t, d) {}\n    constexpr auto begin() const\
    \ noexcept { return s; }\n    constexpr auto end  () const noexcept { return t;\
    \ }\n};\n\ntemplate < class T > struct revrep {\n    const itr_rep < T > s, t;\n\
    \    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}\n    constexpr\
    \ revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr\
    \ revrep(const T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d)\
    \ {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr auto\
    \ end  () const noexcept { return t; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/rep_itr.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/rep_itr.hpp
layout: document
redirect_from:
- /library/src/utility/rep_itr.hpp
- /library/src/utility/rep_itr.hpp.html
title: src/utility/rep_itr.hpp
---
