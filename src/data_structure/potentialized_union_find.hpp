template < class Group > class potentialized_union_find {
  public:
    using T = typename Group::set;

  private:
    using size_t = std::size_t;
    class node_type {
        friend potentialized_union_find;
        T value;
        size_t parent;
        size_t size;

        node_type(const T value, const size_t parent, const size_t size)
            : value(value), parent(parent), size(size) {}
    };

    std::vector<node_type> tree;
    size_t size() const { return tree.size(); }
    void compress(const size_t x) {
        const std::size_t p = tree[x].parent;
        if(p == x) return;
        compress(p);
        tree[x].value = Group::op(tree[p].value, tree[x].value);
        tree[x].parent = tree[p].parent;
    }

  public:
    potentialized_union_find() = default;
    explicit potentialized_union_find(const size_t n)
        : tree(n, node_type(Group::id(), 0, 1)) {
        for(size_t i = 0; i < n; i++) tree[i].parent = i;
    }

    size_t find(const size_t x) {
        assert(x < size());
        compress(x);
        return tree[x].parent;
    }
    T potential(const size_t x) {
        assert(x < size());
        compress(x);
        return tree[x].value;
    }
    bool same(const size_t x, const size_t y) {
        assert(x < size());
        compress(x);
        return find(x) == find(y);
    }
    T distance(const size_t x, const size_t y) {
        assert(x < size());
        assert(y < size());
        return Group::op(Group::inv(potential(x)), potential(y));
    }
    size_t size(const size_t x) {
        assert(x < size());
        return tree[find(x)].size;
    }
    void unite(size_t x, size_t y, T d) {
        if(same(x, y)) return;
        if(size(x) < size(y)) {
            d = Group::inv(d);
            std::swap(x, y);
        }
        d = Group::op(Group::op(potential(x), d), Group::inv(potential(y)));
        x = find(x), y = find(y);
        tree[x].size += tree[y].size;
        tree[y].parent = x;
        tree[y].value = d;
    }
};
