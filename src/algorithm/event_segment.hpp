template < class Value, bool monotone > struct event_segment {
    using size_t = std::size_t;
    std::map< Value, std::vector<size_t> > adds, removes;

    void add(const size_t time, const Value value) {
        adds[value].emplace_back(time);
    }
    void remove(const size_t time, const Value value) {
        removes[value].emplace_back(time);
    }
    std::vector<std::tuple<size_t, size_t, Value>> trans(const size_t inf) {
        std::vector<std::tuple<size_t, size_t, Value>> res;
        for(auto& [value, L] : adds) {
            std::vector<size_t>& R = removes[value];
            if(R.size() < L.size()) R.emplace_back(inf);
            assert(L.size() == R.size());
            if(not monotone) {
                std::sort(L.begin(), L.end());
                std::sort(R.begin(), R.end());
            }
            for(size_t i = 0; i < L.size(); i++) {
                assert(L[i] <= R[i]);
                if(L[i] < R[i]) res.emplace_back(L[i], R[i], value);
            }
        }
        return res;
    }
};
