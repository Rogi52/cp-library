using size_type = int;
i64 inversion_number(const std::vector<size_type>& p) {
    const size_type n = p.size();
    i64 ans = 0;
    fenwick_tree< sum_monoid<i64> > bit(n);
    for(size_type i = 0; i < n; i++) {
        ans += bit.fold(p[i] + 1, n);
        bit.add(p[i], 1);
    }
    return ans;
}
