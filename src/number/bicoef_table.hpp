template < class T >
vector< vector< T > > bicoef_table(int N) {
    vector< vector< T > > table(N + 1, vector< T >(N + 1));
    table[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        table[i][0] = 1;
        for(int j = 1; j <= N; j++) {
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    return table;
}
