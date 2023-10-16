template < class T >
struct zipper {
  public:
    zipper() {}
    vector< T > data;
    void insert(const T x) {
        built = 0;
        data.push_back(x);
    }
    void insert(const vector< T > v) {
        built = 0;
        data.insert(data.end(), v.begin(), v.end());
    }
    template < class... args > zipper(args... a) { insert(a...); }
    template < class... args > void insert(const T x, args... a) { insert(x); insert(a...); }
    template < class... args > void insert(const vector< T > x, args... a) { insert(x); insert(a...); }

    void build() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
        built = 1;
    }

    int id(const T x) {
        if(not built) build();
        return lower_bound(data.begin(), data.end(), x) - data.begin();
    }
    vector<int> zip(const vector< T >& x) {
        if(not built) build();
        vector<int> idx(x.size());
        for(int i : rep(x.size())) idx[i] = id(x[i]);
        return idx;
    }
    int size() {
        if(not built) build();
        return data.size();
    }

  private:
    int built = 0;
};
