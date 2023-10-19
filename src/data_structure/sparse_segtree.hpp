#include "../../src/cp-template.hpp"

template < class I, class monoid > struct sparse_segtree {
    using S = typename monoid::set;

    struct node {
        I index;
        S value, prod;
        std::unique_ptr< node > left, right;
        node(I index, S value) : index(index), value(value), prod(value), left(nullptr), right(nullptr) {}
        void update() {
            prod = monoid::op(monoid::op(left  ? left ->prod : monoid::id(), value), right ? right->prod : monoid::id());
        }
    };
    using node_ptr = std::unique_ptr< node >;

    I n;
    node_ptr root;
    
    sparse_segtree() {}
    sparse_segtree(I n) : n(n), root(nullptr) {}
    void set(I i, S x) {
        assert(0 <= i and i < n);
        set(root, 0, n, i, x);
    }
    S get(I i) {
        assert(0 <= i and i < n);
        return get(root, 0, n, i);
    }
    S prod(I l, I r) {
        assert(0 <= l and l <= r and r <= n);
        return prod(root, 0, n, l, r);
    }
    S all_prod() {
        return root ? root->prod : monoid::id();
    }
    void reset(I l, I r) {
        assert(0 <= l and l <= r and r <= n);
        return reset(root, 0, n, l, r);
    }
    template < class func >
    I max_right(I l, func f) {
        assert(0 <= l and l <= n);
        S prod = monoid::id();
        assert(f(prod));
        return max_right(root, 0, n, l, f, prod);
    }
    template < class func >
    I min_left(I r, func f) {
        assert(0 <= r and r <= n);
        S prod = monoid::id();
        assert(f(prod));
        return min_left(root, 0, n, r, f, prod);
    }

  private:
    void set(node_ptr& t, I a, I b, I p, S x) {
        if(!t) {
            t = std::make_unique< node >(p, x);
            return;
        }
        if(t->index == p) {
            t->value = x;
            t->update();
            return;
        }
        I m = (a + b) / 2;
        if(p < m) {
            if(t->index < p) std::swap(t->index, p), std::swap(t->value, x);
            set(t->left , a, m, p, x);
        } else {
            if(p < t->index) std::swap(p, t->index), std::swap(x, t->value);
            set(t->right, m, b, p, x);
        }
        t->update();
    }

    S get(const node_ptr& t, I a, I b, I i) {
        if(!t) return monoid::id();
        if(t->index == i) return t->value;
        I m = (a + b) / 2;
        if(i < m)
            return get(t->left , a, m, i);
        else
            return get(t->right, m, b, i);
    }

    S prod(const node_ptr& t, I a, I b, I l, I r) {
        if(!t or b <= l or r <= a) return monoid::id();
        if(l <= a and b <= r) return t->prod;
        I m = (a + b) / 2;
        S res = prod(t->left, a, m, l, r);
        if(l <= t->index and t->index < r) res = monoid::op(res, t->value);
        return monoid::op(res, prod(t->right, m, b, l, r));
    }

    void reset(node_ptr& t, I a, I b, I l, I r) {
        if(!t or b <= l or r <= a) return;
        if(l <= a and b <= r) {
            t.reset();
            return;
        }
        I m = (a + b) / 2;
        reset(t->left , a, m, l, r);
        reset(t->right, m, b, l, r);
        t->update();
    }

    template < class func >
    I max_right(const node_ptr& t, I a, I b, I l, const func& f, S& prod) {
        if(!t or b <= l) return n;
        if(f(monoid::op(prod, t->prod))) {
            prod = monoid::op(prod, t->prod);
            return n;
        }
        I m = (a + b) / 2;
        I res = max_right(t->left, a, m, l, f, prod);
        if(res != n) return res;
        if(l <= t->index) {
            prod = monoid::op(prod, t->value);
            if(not f(prod)) return t->index;
        }
        return max_right(t->right, m, b, l, f, prod);
    }

    template < class func >
    I min_left(const node_ptr& t, I a, I b, I r, const func& f, S& prod) {
        if(!t or r <= a) return 0;
        if(f(monoid::op(t->prod, prod))) {
            prod = monoid::op(t->prod, prod);
            return 0;
        }
        I m = (a + b) / 2;
        I res = min_left(t->right, m, b, r, f, prod);
        if(res != 0) return res;
        if(t->index < r) {
            prod = monoid::op(t->value, prod);
            if(not f(prod)) return t->index + 1;
        }
        return min_left(t->left, a, m, r, f, prod);
    }
};
