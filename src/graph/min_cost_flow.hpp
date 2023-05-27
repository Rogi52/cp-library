template < class Cap, class Cost > struct mcf_graph {
  public:
    explicit mcf_graph(int n) : n(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = _edges.size();
        _edges.push_back({from, to, cap, 0, cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = _edges.size();
        assert(0 <= i and i < m);
        return _edges[i];
    }

    vector<edge> edges() { return _edges; }

    pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, numeric_limits<Cap>::max());
    }
    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s and s < n);
        assert(0 <= t and t < n);
        assert(s != t);

        int m = _edges.size();
        vector<int> e_id(m);
        auto g = [&]() {
            vector<int> degree(n), r_id(m);
            vector<pair<int, _edge>> elist;
            elist.reserve(m + m);
            for(int i : rep(m)) {
                edge e = _edges[i];
                e_id[i] = degree[e.from]++;
                r_id[i] = degree[e.to]++;
                elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
                elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
            }
            csr<_edge> _g(n, elist);
            for(int i : rep(m)) {
                edge e = _edges[i];
                e_id[i] += _g.start[e.from];
                r_id[i] += _g.start[e.to];
                _g.elist[e_id[i]].rev = r_id[i];
                _g.elist[r_id[i]].rev = e_id[i];
            }
            return _g;
        }();

        auto result = slope(g, s, t, flow_limit);
        for(int i : rep(m)) {
            _edge e = g.elist[e_id[i]];
            _edges[i].flow = _edges[i].cap - e.cap;
        }
        return result;
    }

  private:
    int n;
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };
    vector<edge> _edges;

    template < class E > struct csr {
        vector<int> start;
        vector< E > elist;
        explicit csr(int n, const vector<pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {
            for(auto e : edges) start[e.first + 1]++;
            for(int i = 1; i <= n; i++) start[i] += start[i - 1];
            vector<int> counter = start;
            for(auto e : edges) elist[counter[e.first]++] = e.second;
        }
    };

    vector<pair<Cap, Cost>> slope(csr<_edge>& g, int s, int t, Cap flow_limit) {
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge

        // dual_dist[i] = (dual[i], dist[i])
        vector<pair<Cost, Cost>> dual_dist(n);
        vector<int> prev_e(n);
        vector<bool> vis(n);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        vector<int> que_min;
        vector< Q > que;
        auto dual_ref = [&]() {
            for (int i : rep(n)) dual_dist[i].second = numeric_limits<Cost>::max();
            fill(vis.begin(), vis.end(), false);
            que_min.clear();
            que.clear();
            size_t heap_r = 0;
            dual_dist[s].second = 0;
            que_min.push_back(s);
            while (not que_min.empty() or not que.empty()) {
                int v;
                if (not que_min.empty()) {
                    v = que_min.back();
                    que_min.pop_back();
                } else {
                    while (heap_r < que.size()) {
                        heap_r++;
                        push_heap(que.begin(), que.begin() + heap_r);
                    }
                    v = que.front().to;
                    pop_heap(que.begin(), que.end());
                    que.pop_back();
                    heap_r--;
                }
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    _edge e = g.elist[i];
                    if (!e.cap) continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual_dist[e.to].first + dual_v;
                    if (dual_dist[e.to].second - dist_v > cost) {
                        Cost dist_to = dist_v + cost;
                        dual_dist[e.to].second = dist_to;
                        prev_e[e.to] = e.rev;
                        if (dist_to == dist_v) {
                            que_min.push_back(e.to);
                        } else {
                            que.push_back(Q{dist_to, e.to});
                        }
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < n; v++) {
                if (!vis[v]) continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
                //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
                //         t) + dual[t] + shortest(s, v) = shortest(s, v) -
                //         shortest(s, t) >= 0 - (n-1)C
                dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);
            }
            for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
                auto& e = g.elist[prev_e[v]];
                e.cap += c;
                g.elist[e.rev].cap -= c;
            }
            Cost d = -dual_dist[s].first;
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }
};