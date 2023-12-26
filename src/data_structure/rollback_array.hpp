template < class Value > struct rollback_array {
    std::vector<Value> a;
    std::vector<std::pair<int,Value>> history;
    rollback_array() = default;
    rollback_array(const int n) : a(n) {}

    void set(int i, Value v) {
        history.emplace_back(i, a[i]);
        a[i] = v;
    }
    Value get(int i) {
        return a[i];
    }
    void undo() {
        auto [i, v] = history.back(); history.pop_back();
        a[i] = v;
    }
    int now() {
        return history.size();
    }
    void rollback(int t) {
        while(t < history.size()) undo();
    }
};
