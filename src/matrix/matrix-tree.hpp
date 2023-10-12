#include "../../src/cp-template.hpp"
#include "../../src/matrix/base.hpp"

template < class mint >
struct matrix_tree {
    square_matrix<mint> X;
    matrix_tree(int n) : X(n) {}

    void add(int u, int v, mint x = 1) {
        X[u][v] -= x;
        X[v][u] -= x;
        X[u] += 1;
        X[v] += 1;
    }

    mint count(int i = 0, int j = 0) {
        return det(X.cofactor(i, j));
    }
};