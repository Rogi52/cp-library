#pragma once
#include "../cp-template.hpp"

template < class T > std::vector< T >& operator+=(std::vector< T >& x, const std::vector< T >& y) { assert(x.size() == y.size()); for(int i : rep(x.size())) x[i] += y[i]; return x; }
template < class T > std::vector< T >& operator-=(std::vector< T >& x, const std::vector< T >& y) { assert(x.size() == y.size()); for(int i : rep(x.size())) x[i] -= y[i]; return x; }
template < class T > std::vector< T >& operator*=(std::vector< T >& v, T x) { for(int i : rep(v.size())) v[i] *= x; return v; }
template < class T > std::vector< T >& operator/=(std::vector< T >& v, T x) { x = T(1) / x; for(int i : rep(v.size())) v[i] *= x; return v; }
template < class T > std::vector< T > operator+(std::vector< T > x, const std::vector< T >& y) { return x += y; }
template < class T > std::vector< T > operator-(std::vector< T > x, const std::vector< T >& y) { return x -= y; }
template < class T > std::vector< T > operator*(std::vector< T > v, T x) { return v *= x; }
template < class T > std::vector< T > operator/(std::vector< T > v, T x) { return v /= x; }

template < class T >
T dot(const std::vector< T >& x, const std::vector< T >& y) {
    assert(x.size() == y.size());
    T res = 0;
    for(int i : rep(x.size())) res += x[i] * y[i];
    return res;
}

template < class T >
struct matrix : std::vector< std::vector< T > > {
    int h, w;
    matrix(int h, int w, T e = 0) : h(h), w(w), std::vector< std::vector< T > >(h, std::vector< T >(w, e)) {}
    matrix(std::initializer_list< std::initializer_list< T > > m) : std::vector< std::vector< T > >(m.size()) {
        auto it = m.begin();
        for(int i = 0; it != m.end(); i++, it++) (*this)[i] = std::vector< T >(*it);
    }
    matrix operator*(const matrix& rhs) const {
        int N = this->size(), K = (*this)[0].size(), M = rhs[0].size();
        assert(K == rhs.size());
        matrix res(N, M);
        for(int k : rep(K)) for(int n : rep(N)) for(int m : rep(M)) res[n][m] += (*this)[n][k] * rhs[k][m];
        return res;
    }
    matrix& operator*=(const matrix& rhs) { return *this = (*this) * rhs; }
    std::vector< T > operator*(const std::vector< T >& rhs) const {
        assert((*this)[0].size() == rhs.size());
        std::vector< T > res(this->size());
        for(int i : rep(this->size())) res[i] = dot((*this)[i], rhs);
        return res;
    }
    std::vector< T >& operator[](int i) { return std::vector< std::vector< T > >::operator[](i); }
    const std::vector< T >& operator[](int i) const { return std::vector< std::vector< T > >::operator[](i); }
    bool operator==(const matrix& rhs) const {
        for(int i : rep(this->size())) if((*this)[i] != rhs[i]) return false;
        return true;
    }
};

template < class T >
struct square_matrix : matrix< T > {
    int n;
    square_matrix(int n, T e = 0) : n(n), matrix< T >(n, n, e) {}
    square_matrix(std::initializer_list< std::initializer_list< T > > m) : matrix< T >(m) {}
    square_matrix< T > minor(int i, int j) {
        square_matrix< T > M(n - 1);
        for(int i2 : rep(n)) for(int j2 : rep(n)) {
            if(i2 != i and j2 = j) {
                M[i2 < i ? i2 : i2 - 1][j2 < j ? j2 : j2 - 1] = (*this)[i][j];
            }
        }
        return M;
    }
    T cofactor(int i, int j) {
        return ((i + j) % 2 == 0 ? +1 : -1) * det(minor(i, j));
    }
};

template < class T >
square_matrix< T > unit(int n) {
    square_matrix< T > I(n);
    for(int i : rep(n)) I[i][i] = 1;
    return I;
}

template < class T >
square_matrix< T > inv(square_matrix< T > A) {
    int n = A.size();
    square_matrix B = unit< T >(n);
    for(int i : rep(n)) {
        if(A[i][i] == 0) {
            for(int j : rep(i + 1, n)) if(A[j][i] != 0) {
                for(int k : rep(i, n)) std::swap(A[i][k], A[j][k]);
                for(int k : rep(0, n)) std::swap(B[i][k], B[j][k]);
                break;
            }
        }
        if(A[i][i] == 0) throw "This matrix is not regular."s;
        const T x = T(1) / A[i][i];
        for(int k : rep(i, n)) A[i][k] *= x;
        for(int k : rep(0, n)) B[i][k] *= x;
        for(int j : rep(n)) if(i != j) {
            const T y = A[j][i];
            for(int k : rep(i, n)) A[j][k] -= A[i][k] * y;
            for(int k : rep(0, n)) B[j][k] -= B[i][k] * y;
        }
    }
    return B;
}

template < class T >
T det(square_matrix< T > A) {
    T res = 1;
    int n = A.size();
    for(int i : rep(n)) {
        if(A[i][i] == 0) {
            for(int j : rep(i + 1, n)) if(A[j][i] != 0) {
                for(int k : rep(i, n)) std::swap(A[i][k], A[j][k]);
                res *= -1;
                break;
            }
        }
        if(A[i][i] == 0) return T(0);
        res *= A[i][i];
        const T x = T(1) / A[i][i];
        for(int k : rep(i, n)) A[i][k] *= x;
        for(int j : rep(i + 1, n)) {
            const T y = A[j][i];
            for(int k : rep(i, n)) A[j][k] -= A[i][k] * y;
        }
    }
    return res;
}

template < class T >
square_matrix< T > pow(square_matrix< T > A, ll n) {
    square_matrix res = unit(A.size());
    while(n > 0) {
        if(n % 2 == 1) res *= A;
        A *= A;
        n /= 2;
    }
    return res;
}