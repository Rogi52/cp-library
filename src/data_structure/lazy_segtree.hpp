template < class A > struct lazy_segtree {
  public:
    using V = typename A::value_structure;
    using S = typename V::set;
    using O = typename A::operator_structure;
    using F = typename O::set;
    int _n, size, log;
    vector< S > d;
    vector< F > lz;

    void update(int k) { d[k] = V::op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = A::op(d[k], f);
        if(k < size) lz[k] = O::op(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = O::id;
    }
    int ceil_pow2(int n) {
        int x = 0;
        while((1U << x) < uint(n)) x++;
        return x;
    }

    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(vector< S >(n, S::id)) {}
    lazy_segtree(const vector< S >& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector< S >(2 * size, V::id);
        lz = vector< F >(size, O::id);
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int i, S x) {
        assert(0 <= i && i < _n);
        i += size;
        for(int p = log; p >= 1; p--) push(i >> p);
        d[i] = x;
        for(int p = 1; p <= log; p++) update(i >> p);
    }
    S get(int i) {
        assert(0 <= i && i < _n);
        i += size;
        for(int p = log; p >= 1; p--) push(i >> p);
        return d[i];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return V::id;
        l += size, r += size;
        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push(r >> i);
        }
        S sml = V::id, smr = V::id;
        while(l < r) {
            if(l & 1) sml = V::op(sml, d[l++]);
            if(r & 1) smr = V::op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return V::op(sml, smr);
    }
    S all_prod() { return d[1]; }
    void apply(int i, F f) {
        assert(0 <= i && i < _n);
        i += size;
        for(int p = log; p >= 1; p--) push(i >> p);
        d[i] = O::mapping(f, d[i]);
        for(int p = 1; p <= log; p++) update(i >> p);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;
        l += size, r += size;
        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1, r >>= 1;
            }
            l = l2, r = r2;
        }
        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template < class G > int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(V::id));
        if(l == _n) return _n;
        l += size;
        for(int i = log; i >= 1; i--) push(l >> i);
        S sm = V::id();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(V::op(sm, d[l]))) {
                while(l < size) {
                    push(l);
                    l = 2 * l;
                    if(g(V::op(sm, d[l]))) {
                        sm = V::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = V::op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }
    template < class G > int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(V::id));
        if(r == 0) return 0;
        r += size;
        for(int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = V::id;
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!g(V::op(d[r], sm))) {
                while(r < size) {
                    push(r);
                    r = 2 * r + 1;
                    if(g(V::op(d[r], sm))) {
                        sm = V::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = V::op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }
};
