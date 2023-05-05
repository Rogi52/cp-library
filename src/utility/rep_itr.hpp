template < class T > struct itr {
    T i, d;
    constexpr itr(const T i) noexcept : i(i), d(1) {}
    constexpr itr(const T i, const T d) noexcept : i(i), d(d) {}
    void operator++() noexcept { i += d; }
    constexpr int operator*() const noexcept { return i; }
    constexpr bool operator!=(const itr x) const noexcept {
        return d > 0 ? i < x.i : i > x.i;
    }
};

template < class T > struct rep {
    const itr< T > s, t;
    constexpr rep(const T t) noexcept : s(0), t(t) {}
    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}
    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d) {}
    constexpr auto begin() const noexcept { return s; }
    constexpr auto end() const noexcept { return t; }
};

template < class T > struct revrep {
    const itr < T > s, t;
    constexpr revrep(const T t) noexcept : s(t - 1, -1), t(-1, -1) {}
    constexpr revrep(const T s, const T t) noexcept : s(t - 1, -1), t(s - 1, -1) {}
    constexpr revrep(const T s, const T t, const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}
    constexpr auto begin() const noexcept { return s; }
    constexpr auto end() const noexcept { return t; }
};
