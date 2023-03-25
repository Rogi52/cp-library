namespace mo {
 
using func = function<void(int)>;
void sol(int N, vector<pair<int,int>> &query, func &add_left, func &del_left, func &add_right, func &del_right, func &ans, int block_size = -1) {
    if(block_size == -1) block_size = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(query.size() * 2.0 / 3.0)));
    vector<int> I(query.size());
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
        auto [Li, Ri] = query[i];
        auto [Lj, Rj] = query[j];
        if(Li / block_size != Lj / block_size) return Li < Lj;
        if(Li / block_size & 1) return Ri < Rj;
        return Ri > Rj;
    });
    int nL = 0, nR = 0;
    for(int i : I) {
        auto [L, R] = query[i];
        while(nL > L) add_left (--nL);
        while(nR < R) add_right(nR++);
        while(nL < L) del_left (nL++);
        while(nR > R) del_right(--nR);
        ans(i);
    }
}
 
} // namespace mo
