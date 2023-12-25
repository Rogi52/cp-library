template < class Value > class offline_dynamic_data_structure {
  public:
    using size_t = std::size_t;
    size_t Q, Q2;
    std::vector<std::vector<Value>> seg;
    offline_dynamic_data_structure(const size_t Q) : Q(Q), Q2(1) {
        while(Q2 < Q) Q2 *= 2;
        seg.resize(2 * Q2 - 1);
    }
    void add(const size_t a, const size_t b, const Value v) {
        add(a, b, v, 0, 0, Q2);
    }
    template < class Add, class Undo, class Query >
    void run(const Add add, const Undo undo, const Query query, const size_t k = 0) {
        std::for_each(seg[k].begin(), seg[k].end(), [&](Value& v) { add(v); });
        if(k < Q2 - 1) {
            run(add, undo, query, 2 * k + 1);
            run(add, undo, query, 2 * k + 2);
        } else if(k - (Q2 - 1) < Q) {
            query(k - (Q2 - 1));
        }
        std::for_each(seg[k].rbegin(), seg[k].rend(), [&](Value& v) { undo(v); });
    }

  private:
    void add(const size_t a, const size_t b, const Value v, const size_t k, const size_t l, const size_t r) {
        if(r <= a or  b <= l) { return; }
        if(a <= l and r <= b) { seg[k].emplace_back(v); return; }
        add(a, b, v, 2 * k + 1, l, (l + r) / 2);
        add(a, b, v, 2 * k + 2, (l + r) / 2, r);
    }
};
