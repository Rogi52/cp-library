namespace ntt {

template < class mint >
void trans(vector<mint>& v, bool is_inv) {
    if(v.empty()) return;
    int n = v.size();
    uint mod = mint::mod, root = mint::root;
    static bool first = true;
    static vector<ll> vbw(30), vibw(30);
    if(first) {
        first = false;
        for(int k : rep(30)) {
            vbw[k] = pow(mint(root), (mod - 1) >> (k + 1)).v;
            vibw[k] = inv(mint(vbw[k])).v;
        }
    }
    for(int i = 0, j = 1; j < n - 1; j++) {
        for(int k = n >> 1; k > (i ^= k); k >>= 1);
        if(i > j) swap(v[i], v[j]);
    }
    for(int k = 0, t = 2; t <= n; ++k, t <<= 1) {
        mint bw = (inv ? vibw[k] : vbw[k]);
        for (int i = 0; i < n; i += t) {
            mint w = 1;
            for (int j = 0; j < t / 2; ++j) {
                int j1 = i + j, j2 = i + j + t/2;
                mint c1 = v[j1], c2 = v[j2] * w;
                v[j1] = c1 + c2;
                v[j2] = c1 - c2;
                w *= bw;
            }
        }
    }
    if(is_inv) {
        mint iv = inv(mint(n));
        for(int i : rep(n)) v[i] *= iv;
    }
}
template < class mint > void ntt(vector<mint>& v) { trans(v, false); }
template < class mint > void intt(vector<mint>& v) { trans(v, true); }

// for garner
constexpr modinfo base0 { 754974721, 11 };
constexpr modinfo base1 { 167772161,  3 };
constexpr modinfo base2 { 469762049,  3 };
using mint0 = modint< base0 >;
using mint1 = modint< base1 >;
using mint2 = modint< base2 >;
static const mint1 imod0  =  95869806; // MOD0^-1 mod MOD1
static const mint2 imod1  = 104391568; // MOD1^^1 mod MOD2
static const mint2 imod01 = 187290749; // imod1 / MOD0;

template < class T >
vector< T > naive(const vector< T >& a, const vector< T >& b) {
    if(a.empty() || b.empty()) return {};
    int n = a.size(), m = b.size();
    vector< T > c(n + m - 1);
    for(int i : rep(n)) for(int j : rep(m)) c[i + j] += a[i] * b[j];
    return c;
}

template < class mint >
vector<mint> mul(const vector<mint>& a, const vector<mint>& b) {
    if(a.empty() || b.empty()) return {};
    int n = a.size(), m = b.size();
    if(min(n, m) < 30) return naive(a, b);
    uint mod = mint::mod;

    int sz = [&]() {
        int n2 = 1, m2 = 1;
        while(n2 < n) n2 <<= 1;
        while(m2 < m) m2 <<= 1;
        return max(n2, m2) << 1;
    }();

    if(mod == 998244353) {
        vector<mint> a2(sz, 0), b2(sz, 0), c(sz, 0);
        for(int i : rep(n)) a2[i] = a[i];
        for(int i : rep(m)) b2[i] = b[i];
        ntt(a2), ntt(b2);
        for(int i : rep(sz)) c[i] = a2[i] * b2[i];
        intt(c);
        c.resize(n + m - 1);
        return c;
    }

    vector<mint0> a0(sz, 0), b0(sz, 0), c0(sz, 0);
    vector<mint1> a1(sz, 0), b1(sz, 0), c1(sz, 0);
    vector<mint2> a2(sz, 0), b2(sz, 0), c2(sz, 0);
    for(int i : rep(n)) a0[i].v = a1[i].v = a2[i].v = a[i].v;
    for(int i : rep(m)) b0[i].v = b1[i].v = b2[i].v = b[i].v;
    ntt(a0), ntt(b0), ntt(a1), ntt(b1), ntt(a2), ntt(b2);
    for(int i : rep(sz)) {
        c0[i] = a0[i] * b0[i];
        c1[i] = a1[i] * b1[i];
        c2[i] = a2[i] * b2[i];
    }
    intt(c0), intt(c1), intt(c2);
    
    vector<mint> c(n + m - 1);
    static const mint mod0 = mint0::mod, mod01 = mod0 * mint1::mod;
    for(int i : rep(n + m - 1)) {
        ll y0 = c0[i].v;
        ll y1 = (imod0 * (c1[i] - y0)).v;
        ll y2 = (imod01 * (c2[i] - y0) - imod1 * y1).v;
        c[i] = mod01 * y2 + mod0 * y1 + y0;
    }
    return c;
}

} // namespace ntt
