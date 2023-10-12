#include "../cp-template.hpp"
#include "../matrix/base.hpp"

template < class T >
int sweep(matrix< T >& A, int w = -1) {
    int n = A.size(), m = A[0].size(), rank = 0;
    if(w == -1) w = m;
    for(int j : rep(w)) {
        int at = -1;
        for(int i : rep(rank, n)) if(A[i][j] != 0) { at = i; break; }
        if(at == -1 or rank == n) continue;
        const T x = T(1) / A[at][j];
        for(int k : rep(m)) A[at][k] *= x;
        swap(A[at], A[rank]);
        for(int i : rep(n)) if(i != rank) {
            const T y = A[i][j];
            for(int k : rep(j, m)) A[i][k] -= y * A[rank][k];
        }
        rank++;
    }
    return rank;
}

template < class T >
tuple<int, std::vector< T >, std::vector< std::vector< T > >> linear_equation(matrix< T >& A, std::vector< T >& b) {
    int n = A.size(), m = A[0].size();
    for(int i : rep(n)) A[i].push_back(b[i]);
    int rank = sweep(A, m);
    for(int i : rep(rank, n)) if(A[i][m] != 0) throw "No solution."s;

    int at = 0;
    std::vector< T > x(m);
    std::vector<int> r(n);
    std::vector< std::vector< T > > ker;
    for(int j : rep(m)) {
        bool f = true;
        for(int i : rep(n)) if(i == at and A[i][j] != 1 or i != at and A[i][j] != 0) f = false;
        if(f and at < rank) {
            x[j] = A[at][m];
            r[at] = j;
            at++;
        } else {
            std::vector< T > k(m);
            for(int i : rep(n)) if(i < at) k[r[i]] = - A[i][j];
            k[j] = 1;
            ker.push_back(k);
        }
    }
    return std::make_tuple(rank, x, ker);
}