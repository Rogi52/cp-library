template < int num_of_mod >
struct rolling_hash_perm {
    int k;
    vector< rolling_hash< num_of_mod > > rhs;
    rolling_hash_perm(const string& s, int k) : k(k), rhs(k) {
        int n = s.size();
        rep(a,k) {
            string t = "";
            rep(i,n) t += (s[i] - 'a' == a);
            rhs[a] = rolling_hash< num_of_mod >(t);
        }
    }

    using hash = typename rolling_hash< num_of_mod >::hash;
    // [l, r)
    vector< hash > get(int l, int r) const {
        vector< hash > res(k);
        rep(a,k) res[a] = rhs[a].get(l, r);
        sort(res.begin(), res.end());
        return res;
    }

    template < int n >
    static int lcp(const rolling_hash_perm< n >& rh1, int l1, int r1, const rolling_hash_perm< n >& rh2, int l2, int r2) {
        int lo = -1, hi = min(r1 - l1, r2 - l2) + 1;
        while(hi - lo > 1) {
            int mid = (lo + hi) / 2;
            (rh1.get(l1, l1 + mid) == rh2.get(l2, l2 + mid) ? lo : hi) = mid;
        }
        return lo;
    }
};
