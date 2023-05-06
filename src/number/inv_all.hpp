vector<mint> inv_all(const vector<mint>& a) {
    int n = a.size();
    vector<mint> L(n + 1, 1), R(n + 1, 1);
    for(int i : rep(n)) L[i + 1] = L[i] * a[i];
    for(int i : revrep(n)) R[i] = R[i + 1] * a[i];
    mint P = inv(L[n]);
    vector<mint> inva(n);
    for(int i : rep(n)) inva[i] = L[i] * P * R[i + 1];
    return inva;
}
