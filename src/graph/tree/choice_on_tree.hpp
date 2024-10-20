#include "rogi/data_structure/union_find.hpp"

template < class tomd >
pair< typename tomd::value_type, vector<int> > choice_on_tree(vector<int> parent, vector<typename tomd::value_type> value) {
    const int n = parent.size();
    const int root = [&] {
        for(int v = 0; v < n; v++) if(parent[v] == -1) return v;
        assert(0);
    }();

    union_find uf(n);
    vector<int> head(n), tail(n), succ(n, -1);
    for(int v = 0; v < n; v++) head[v] = tail[v] = v;

    struct data {
        tomd::value_type x; int id, sz;
        bool operator < (const data& r) const { return tomd::cmp(x, r.x); }
    };
    priority_queue<data> pq;
    for(int v = 0; v < n; v++) if(v != root) pq.push(data{value[v], v, 1});

    while(not pq.empty()) {
        auto [_, v, sv] = pq.top(); pq.pop();
        if(uf.size(v) != sv) continue;
        v = uf.root(v);
        int hv = head[v], tv = tail[v];
        int p = uf.root(parent[hv]);
        int hp = head[p], tp = tail[p];
        int x = uf.unite(p, v);
        value[x] = tomd::op(value[p], value[v]);
        head[x] = hp, tail[x] = tv, succ[tp] = hv;
        if(x != uf.root(root)) pq.push(data{value[x], x, uf.size(x)});
    }
    vector<int> ord = {root};
    while(succ[ord.back()] != -1) ord.push_back(succ[ord.back()]);
    return {value[uf.root(root)], ord};
}

// AGC023-F 01 on Tree (https://atcoder.jp/contests/agc023/tasks/agc023_f)
// https://atcoder.jp/contests/agc023/submissions/59018603
struct i01 {
    struct value_type {
        i64 c0, c1, inv;
    };
    static value_type op(const value_type& l, const value_type& r) {
        value_type x;
        x.inv = l.inv + r.inv + l.c1 * r.c0;
        x.c0 = l.c0 + r.c0;
        x.c1 = l.c1 + r.c1;
        return x;
    }
    static value_type id() {
        return value_type{0, 0, 0};
    }
    static bool cmp(const value_type& l, const value_type& r) {
        return l.c0 * r.c1 < r.c0 * l.c1;
    }
};
