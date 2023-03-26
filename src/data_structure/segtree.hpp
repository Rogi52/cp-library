template < class monoid > struct segtree {
    using S = typename monoid::set;

    segtree() : segtree(0) {}
    segtree(int n) : segtree(vector< S >(n, monoid::id)) {}
    segtree(const vector< S >& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector< S >(2 * size, monoid::id);
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) update(i);
    }
    // a[i] <- x
    void set(int i, S x) {
        assert(0 <= i && i < _n);
        i += size;
        d[i] = x;
        for(int p = 1; p <= log; p++) update(i >> p);
    }
    // a[i]
    S get(int i) {
        assert(0 <= i && i < _n);
        return d[i + size];
    }
    // [l, r)
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = monoid::id, smr = monoid::id;
        l += size, r += size;
        while(l < r) {
            if(l & 1) sml = monoid::op(sml, d[l++]);
            if(r & 1) smr = monoid::op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return monoid::op(sml, smr);
    }
    S all_prod() { return d[1]; }
    template < class func > int max_right(int l, func f) {
        assert(0 <= l && l <= _n);
        assert(f(monoid::id));
        if(l == _n) return _n;
        l += size;
        S sm = monoid::id;
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(monoid::op(sm, d[l]))) {
                while(l < size) {
                    l = 2 * l;
                    if(f(monoid::op(sm, d[l]))) {
                        sm = monoid::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = monoid::op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }
    template < class func > int min_left(int r, func f) {
        assert(0 <= r && r <= _n);
        assert(f(monoid::id));
        if(r == 0) return 0;
        r += size;
        S sm = monoid::id;
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(monoid::op(d[r], sm))) {
                while(r < size) {
                    r = 2 * r + 1;
                    if(f(monoid::op(d[r], sm))) {
                        sm = monoid::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = monoid::op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    vector< S > d;
    int ceil_pow2(int n) { int x = 0; while((1U << x) < uint(n)) x++; return x; }
    void update(int k) { d[k] = monoid::op(d[2 * k], d[2 * k + 1]); }
};
