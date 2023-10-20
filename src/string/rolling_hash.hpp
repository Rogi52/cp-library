#include "../../src/cp-template.hpp"
#include "../../src/utility/random.hpp"
#include "../../src/utility/hash.hpp"

template< int num_of_mod = 2 >
struct rolling_hash {

    static const ll BASE;

    vector< hash_vector< num_of_mod > > pb, hs;
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
    hash_vector< num_of_mod > get(int l, int r) const {
        return hs[r] - hs[l] * pb[r - l];
    }

    hash_vector< num_of_mod > concat(hash_vector< num_of_mod > h1, hash_vector< num_of_mod > h2, int h2_len) {
        assert(0 <= h2_len and h2_len <= n);
        return h1 * pb[h2_len] + h2;
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

template < int num_of_mod >
const ll rolling_hash< num_of_mod >::BASE = randnum::gen_int<ll>(ll(0), hash_vector< num_of_mod >::MODS[0]);
