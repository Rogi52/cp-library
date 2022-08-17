class union_find {
  public:
    union_find(int n) : data(n, -1) {}
    int unite(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            if(size(x) < size(y)) swap(x, y);
            data[x] += data[y];
            return data[y] = x;
        }
        return -1;
    }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
    bool same(int x, int y) { return root(x) == root(y); }

  private:
    vector<int> data;
};
