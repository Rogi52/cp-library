template< int num_of_mod = 2 >
struct rolling_hash {
    static constexpr ll MODS[] = {999999937, 1000000007, 1000000009, 1000000021};
    static constexpr ll BASE = 9973;
    
    struct hash : array<ll, num_of_mod> {
        using array<ll, num_of_mod>::operator[];
        static constexpr int n = num_of_mod;
        hash() : array<ll,n>() {}
        hash(ll x) : hash() { for(int i : rep(n)) (*this)[i] = x % MODS[i]; }
        hash& operator+=(const hash& rhs) { for(int i : rep(n)) if(((*this)[i] += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
        hash& operator-=(const hash& rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
        hash& operator*=(const hash& rhs) { for(int i : rep(n)) (*this)[i] = (*this)[i] * rhs[i] % MODS[i]; return *this; }
        hash& operator+=(const ll rhs) { for(int i : rep(n)) if(((*this)[i] += rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
        hash& operator-=(const ll rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
        hash& operator*=(const ll rhs) { for(int i : rep(n)) (*this)[i] = (*this)[i] * (rhs % MODS[i]) % MODS[i]; return *this; }
        hash operator+(const hash& rhs) const { return hash(*this) += rhs; }
        hash operator-(const hash& rhs) const { return hash(*this) -= rhs; }
        hash operator*(const hash& rhs) const { return hash(*this) *= rhs; }
        hash operator+(const ll rhs) const { return hash(*this) += rhs; }
        hash operator-(const ll rhs) const { return hash(*this) -= rhs; }
        hash operator*(const ll rhs) const { return hash(*this) *= rhs; }
        hash operator-() const { return hash().fill(0) - *this; }
        friend hash operator+(ll x, const hash& y) { return hash(x) + y; }
        friend hash operator-(ll x, const hash& y) { return hash(x) + y; }
        friend hash operator*(ll x, const hash& y) { return hash(x) * y; }
        bool operator==(const hash& rhs) { for(int i : rep(n)) if((*this)[i] != rhs[i]) return false; return true ; }
        bool operator!=(const hash& rhs) { for(int i : rep(n)) if((*this)[i] != rhs[i]) return true ; return false; }
    };

    vector< hash > pb, hs;
    rolling_hash() {}
    rolling_hash(const string& s) {
        int n = s.size();
        hs.resize(n + 1); hs[0].fill(0);
        pb.resize(n + 1); pb[0].fill(1);
        for(int i : rep(n)) {
            hs[i + 1] = hs[i] * BASE + s[i];
            pb[i + 1] = pb[i] * BASE;
        }
    }

    // [l, r)
    hash get(int l, int r) const {
        return hs[r] - hs[l] * pb[r - l];
    }

    template < int n >
    static int lcp(const rolling_hash< n >& rh1, int l1, int r1, const rolling_hash< n >& rh2, int l2, int r2) {
        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;
        while(hi - lo > 1) {
            int mid = (lo + hi) / 2;
            (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;
        }
        return lo;
    }

    template < int n >
    static int cmp(const string& s1, const rolling_hash< n >& rh1, int l1, int r1,
                   const string& s2, const rolling_hash< n >& rh2, int l2, int r2) {
        int len = lcp(rh1, l1, r1, rh2, l2, r2);
        if(len == r1 - l1 && len == r2 - l2) return 0;
        if(len == r1 - l1) return -1;
        if(len == r2 - l2) return +1;
        return (s1[l1 + len] < s2[l2 + len] ? -1 : +1);
    }
};
