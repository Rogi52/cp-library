class rollback_union_find {
  private:
    using size_t = std::size_t;
    class node_type {
        friend rollback_union_find;
        size_t parent;
        size_t size;
        node_type(const size_t parent, const size_t size) : parent(parent), size(size) {}
    };

    std::vector<node_type> tree;
    std::vector<std::pair<size_t, node_type>> history;

  public:
    rollback_union_find() = default;
    explicit rollback_union_find(const size_t n) : tree(n, node_type(n, 1)) {}
    size_t size() const { return tree.size(); }
    size_t find(const size_t x) {
        assert(x < size());
        if(tree[x].parent == size())
            return x;
        else
            return find(tree[x].parent);
    }
    bool same(const size_t x, const size_t y) {
        assert(x < size());
        assert(y < size());
        return find(x) == find(y);
    }
    size_t size(const size_t x) {
        assert(x < size());
        return tree[find(x)].size;
    }
    void unite(size_t x, size_t y) {
        assert(x < size());
        assert(y < size());
        x = find(x);
        y = find(y);
        history.emplace_back(x, tree[x]);
        history.emplace_back(y, tree[y]);
        if(x != y) {
            if(tree[x].size < tree[y].size) std::swap(x, y);
            tree[x].size += tree[y].size;
            tree[y].parent = x;
        }
    }
    void undo() {
        for(int _ = 0; _ < 2; _++) {
            auto [x, state] = history.back(); history.pop_back();
            tree[x] = state;
        }
    }
    size_t inner_snap = 0;
    void snapshot() {
        inner_snap = history.size() / 2;
    }
    size_t now() {
        return history.size() / 2;
    }
    void rollback(size_t t = -1) {
        if(t == -1) t = inner_snap;
        t *= 2;
        while(t < history.size()) undo();
    }
};
