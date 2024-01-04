using u64 = unsigned long long;

// 大小関係を保ちながら cast する
namespace float_to_uint_cast {
    using f64 = double;
    using u64 = unsigned long long;
    constexpr int digits = 64;
    u64 float_to_uint(f64 f) {
        u64 u = std::bit_cast<u64>(f);
        return u ^ ((-(u >> (digits - 1))) | 1ULL << (digits - 1));
    }
    f64 uint_to_float(u64 u) {
        u = u ^ (((u >> (digits - 1)) - 1) | 1ULL << (digits - 1));
        return std::bit_cast<f64>(u);
    }

} // namespace my_cast

template < class Key, class Value > class radix_heap {
    std::size_t size_;
    Key last;
    std::vector<std::pair<Key, Value>> container[64 + 1];

    std::size_t pos(Key x) {
        return x == 0 ? 0 : 64 - __builtin_clzll(x);
    }

  public:
    radix_heap() : size_(0), last(0) {
        static_assert(std::is_same<Key, u64>::value, "Key must be u64.");
    }
    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    void push(const Key key, const Value value) {
        container[pos(key ^ last)].emplace_back(key, value);
        size_++;
    }
    std::pair<Key, Value> pop() {
        if(container[0].empty()) {
            std::size_t i = 1; while(container[i].empty()) i++;
            last = std::min_element(container[i].begin(), container[i].end())->first;
            for(std::pair<Key, Value>& p : container[i]) container[pos(p.first ^ last)].emplace_back(p);
            container[i].clear();
        }
        std::pair<Key, Value> p = container[0].back(); container[0].pop_back();
        size_--;
        return p;
    }
};
