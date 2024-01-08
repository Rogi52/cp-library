// c[k] = max_{i+j=k} a[i] + b[j]
// b: concave
template < class T >
std::vector< T > concave_max_plus_convolution(const std::vector< T >& a, const std::vector< T >& b) {
    const std::size_t n = a.size();
    const std::size_t m = b.size();
    const auto get = [&](const std::size_t k, const std::size_t i) {
        const std::size_t j = k - i;
        return a[i] + b[j];
    };
    const std::vector<int> amax
      = smawk (n + m - 1, n,
            [&](const std::size_t i, const std::size_t j, const std::size_t k) {
                if(i < k) return false;
                if(m <= i - j) return true;
                return get(i, j) <= get(i, k);
            }
        );
    std::vector< T > c(n + m - 1);
    for(std::size_t i = 0; i < n + m - 1; i++) c[i] = get(i, amax[i]);
    return c;
}
