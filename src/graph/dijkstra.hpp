template < class T > class min_plus {
  public:
    using set = T;
    static constexpr T add(const T& l, const T& r) { return std::min(l, r); }
    static constexpr T id0 = numeric_limits< T >::max();
    static constexpr T mul(const T& l, const T& r) { return l + r; }
    static constexpr T id1 = T(0);
};

template < class T > class max_min {
  public:
    using set = T;
    static constexpr T add(const T& l, const T& r) { return std::max(l, r); }
    static constexpr T id0 = -numeric_limits< T >::max();
    static constexpr T mul(const T& l, const T& r) { return std::min(l, r); }
    static constexpr T id1 = +numeric_limits< T >::max();
};

template < class closed_semiring, class F >
vector< typename closed_semiring::set > dijkstra(vector<vector<tuple<int, typename closed_semiring::set, int>>>& graph, int s, const F& f) {
    using CS = closed_semiring;
    using T = typename CS::set;
    vector< T > dist(graph.size(), CS::id0);
    using P = pair< T, int >;
    auto cmp = [&](const P& a, const P& b) {
        if(a.first != b.first) return CS::add(a.first, b.first) == b.first;
        return a.second < b.second;
    };
    priority_queue< P, vector< P >, decltype(cmp)> q(cmp);
    q.push({dist[s] = CS::id1, s});
    while(!q.empty()) {
        auto [uc, ui] = q.top(); q.pop();
        if(uc != dist[ui]) continue;
        for(auto [vi, vc, id] : graph[ui]) {
            T nd = CS::add(dist[vi], CS::mul(f(uc, id), vc));
            if(dist[vi] != nd) q.push({dist[vi] = nd, vi});
        }
    }
    return dist;
}
