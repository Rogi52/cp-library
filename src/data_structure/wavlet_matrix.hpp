#include "../../src/cp-template.hpp"

using u64 = unsigned long long;
using u8  = unsigned char;

struct bit_vector {
    std::vector<u64> buf;
    std::vector<int> sum;
    bit_vector() {}
    bit_vector(const vector<u8>& a) {
        int n = a.size();
        buf.assign((n + 63) >> 6, 0);
        sum.assign(buf.size() + 1, 0);
        for(int i : rep(n)) if(a[i]) {
            buf[i >> 6] |= u64(1) << (i & 63);
            sum[(i >> 6) + 1]++;
        }
        for(int i : rep(buf.size())) sum[i + 1] += sum[i];
    }
    int rank(int k, int f = 1) {
        int res = sum[k >> 6] + __builtin_popcountll(buf[k >> 6] & ((u64(1) << (k & 63)) - 1));
        return f ? res : k - res;
    }
};

template < class T >
struct wavlet_matrix {
    int n, lg; T m;
    vector<int> mid;
    vector<bit_vector> buf;

    wavlet_matrix(vector< T > a) : n(a.size()), lg(0), m(1) {
        T max_a = 0;
        for(T x : a) chmax(max_a, x);
        while(m <= max_a) m <<= 1, lg++;
        mid.resize(lg);
        buf.resize(lg);
        for(int d : revrep(lg)) {
            vector<u8> add;
            vector<vector< T >> nxt(2);
            for(T x : a) {
                add.push_back(x >> d & 1);
                nxt[x >> d & 1].push_back(x);
            }
            mid[d] = int(nxt[0].size());
            buf[d] = bit_vector(add);
            swap(a, nxt[0]);
            a.insert(a.end(), nxt[1].begin(), nxt[1].end());
        }
    }
    // count x
    int rank(int L, int R, T x) {
        if(m <= x) return 0;
        for(int d : revrep(lg)) {
            int f = x >> d & 1;
            L = buf[d].rank(L, f) + (f ? mid[d] : 0);
            R = buf[d].rank(R, f) + (f ? mid[d] : 0);
        }
        return R - L;
    }
    // kth smallest
    T quantile(int L, int R, int k) {
        T res = 0;
        for(int d : revrep(lg)) {
            int l0 = buf[d].rank(L, 0), r0 = buf[d].rank(R, 0);
            if(k < r0 - l0) {
                L = l0, R = r0;
            } else {
                k -= r0 - l0;
                res |= T(1) << d;
                L += mid[d] - l0, R += mid[d] - r0;
            }
        }
        return res;
    }
    // count v < x
    int freq(int L, int R, T x) {
        if(m <= x) return R - L;
        int res = 0;
        for(int d : revrep(lg)) {
            int f = x >> d & 1;
            if(f) res += buf[d].rank(R, 0) - buf[d].rank(L, 0);
            L = buf[d].rank(L, f) + (f ? mid[d] : 0);
            R = buf[d].rank(R, f) + (f ? mid[d] : 0);
        }
        return res;
    }
    // count [a, b]
    int freq(int L, int R, T a, T b) {
        return freq(L, R, b) - freq(L, R, a);
    }
    // max v <= x
    T prev(int L, int R, T x) {
        int cnt = freq(L, R, x);
        return cnt == R - L ? T(-1) : quantile(L, R, cnt);
    }
    // min v > x
    T next(int L, int R, T x) {
        int cnt = freq(L, R, x);
        return cnt == 0 ? T(-1) : quantile(L, R, cnt - 1);
    }
};
