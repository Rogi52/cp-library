template< int num_of_mod = 2 >
struct rolling_hash {
    static constexpr long long MODS[] = {999999937, 1000000007, 1000000009, 1000000021};
    static constexpr long long BASE = 9973;
    using H = array< long long, num_of_mod >;
    vector< H > powb, hash;

    rolling_hash() {}
    rolling_hash(const string &s) {
        int n = s.size();
        hash.resize(n + 1); hash[0].fill(0);
        powb.resize(n + 1); powb[0].fill(1);
        for(int i = 0; i < n; i++) {
            for(int k = 0; k < num_of_mod; k++) {
                hash[i + 1][k] = (hash[i][k] * BASE + s[i]) % MODS[k];
                powb[i + 1][k] =  powb[i][k] * BASE % MODS[k];
            }
        }
    }

    H get(int l, int r) {
        H res;
        for(int k = 0; k < num_of_mod; k++) {
            res[k] = hash[r][k] - hash[l][k] * powb[r - l][k] % MODS[k];
            if(res[k] < 0) res[k] += MODS[k];
        }
        return res;
    }
};
