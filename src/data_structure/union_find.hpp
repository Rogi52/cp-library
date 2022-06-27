class union_find {
  private:
    vector<int> parent;

  public:
    union_find(int n) : parent(n, -1) {}
    int unite(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            if(size(x) < size(y)) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            return x;
        }
        return -1;
    }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int size(int x) { return -parent[root(x)]; }
    bool same(int x, int y) { return root(x) == root(y); }
};

template < class abel_monoid > class union_fold : union_find {
  public:
    using T = typename abel_monoid::set;
    union_fold(vector< T > &a) : union_find(a.size()), value(a) {}
    int unite(int x, int y) {
        if((x = union_find::unite(x, y)) != -1)
            value[x] = abel_monoid::op(value[x], value[y]);
        return x;
    }
    T fold(int x) { return value[root(x)]; }
    void add(int x, T v) {
        x = root(x);
        value[x] = abel_monoid::op(value[x], v);
    }

  private:
    vector< T > value;
};

// union_find == union_fold< int, + >(vector<int>a(n, 1))
