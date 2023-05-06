template < class mint >
class bicoef {
    int N;
    vector<mint> fact_, inv_, finv_;
  public:
    bicoef(int N) : N(N), fact_(N+1, 1), inv_(N+1, 1), finv_(N+1, 1) {
        uint mod = mint::get_mod();
        for(int i = 2; i <= N; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_ [i] = - inv_[mod % i] * (mod / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    mint fact(int n) { assert(0 <= n && n <= N); return fact_[n]; }
    mint inv (int n) { assert(0 <= n && n <= N); return inv_ [n]; }
    mint finv(int n) { assert(0 <= n && n <= N); return finv_[n]; }
    mint comb(int n, int k) {
        if(k < 0 || n < k) return mint(0);
        return fact(n) * finv(k) * finv(n - k);
    }
    mint perm(int n, int k) { return fact(n) * finv(n - k); }
    mint homo(int n, int k) { return comb(n + k - 1, k); }
};
