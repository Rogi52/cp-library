vector<mint> czt(vector<mint> x, mint a, mint w, int m) {
    int n = x.size();
    if(w == mint(0)) {
        vector<mint> X(m, x[0]);
        mint p = a;
        for(int i : rep(1, n)) {
            X[0] += x[i] * p;
            p *= a;
        }
        return X;
    }

    auto tri = [](mint b, int sz) {
        vector<mint> res(sz);
        res[0] = 1;
        mint p = 1;
        for(int i : rep(sz - 1)) {
            res[i + 1] = res[i] * p;
            p *= b;
        }
        return res;
    };
    
    vector<mint> iwt = tri(inv(w), n);
    mint p = 1;
    for(int i : rep(n)) {
        x[i] *= p * iwt[i];
        p *= a;
    }
    reverse(x.begin(), x.end());
    vector<mint> X = ntt::mul(x, tri(w, n + m - 1));
    X = {X.begin() + n - 1, X.begin() + n - 1 + m};
    iwt = tri(inv(w), m);
    for(int k : rep(m)) X[k] *= iwt[k];
    return X;
}
