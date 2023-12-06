// https://noshi91.hatenablog.com/entry/2023/12/06/002723
template < class T > class suffix_xor_base {
    int sz;
    std::vector<std::pair<int, T>> b;

  public:
    suffix_xor_base() : sz(0), b{{-1, 0}} {}
    void push_back(T x) {
        assert(0 <= x);
        std::pair<int, T> q = {sz++, x};
        for(auto it = b.begin(); it != b.end(); it++) {
            if((q.second & ~it->second) > it->second) {
                b.insert(it, q);
                break;
            }
            if(q.second <= (q.second ^ it->second)) continue;
            if(q.first > it->first) std::swap(q, *it);
            q.second ^= it->second;
        }
    }
    std::vector< T > get(int l) const {
        assert(0 <= l);
        std::vector< T > res;
        for(const auto& [i, x] : b) if(l <= i) res.push_back(x);
        return res;
    }
};
