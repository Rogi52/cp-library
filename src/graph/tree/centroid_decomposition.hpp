struct c_tree {
    using size_type = int;
    size_type n;
    std::vector<std::vector<size_type>> g;
    std::vector<size_type> size;
    std::vector<bool> active;
    c_tree(const size_type n) : n(n), g(n), size(n), active(n, true) {}

    void add_edge(const size_type u, const size_type v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    size_type centroid(const size_type root) {
        auto get_size = [&](auto self, const size_type v, const size_type p) -> void {
            size[v] = 1;
            for(const size_type to : g[v]) {
                if(to != p and active[to]) {
                    self(self, to, v);
                    size[v] += size[to];
                }
            }
        }; get_size(get_size, root, -1);

        const size_type m = size[root] / 2;
        auto get_centroid = [&](auto self, const size_type v, const size_type p) -> size_type {
            for(const size_type to : g[v])
                if(to != p and active[to] and size[to] > m) return self(self, to, v);
            return v;
        };
        return get_centroid(get_centroid, root, -1);
    }

    // calc : (int, int, vector<bool>&) -> void
    template < class function > void decomposition(const function& calc) {
        auto rec = [&](auto self, const size_type v, const size_type cp) -> void {
            const size_type c = centroid(v);
            calc(c, cp, active);
            active[c] = false;
            for(const size_type to : g[c])
                if(active[to]) self(self, to, c);
            active[c] = true;
        }; rec(rec, 0, -1);
    }
};

// https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
// tree.decomposition([&](int c, int cp, vector<bool>& active) {
//     vector<i64> freq = {1};
//     for(int cto : tree.g[c]) if(active[cto]) {
//         vector<i64> curr;
//         auto get_freq = [&](auto self, int v, int p, int d) -> void {
//             while(int(freq.size()) <= d) freq.push_back(0); freq[d]++;
//             while(int(curr.size()) <= d) curr.push_back(0); curr[d]++;
//             for(int to : tree.g[v])
//                 if(to != p and active[to]) self(self, to, v, d + 1);
//         }; get_freq(get_freq, cto, c, 1);

//         auto curr_conv = atcoder::convolution_ll(curr, curr);
//         for(int i : rep(min<int>(N, curr_conv.size()))) ans[i] -= curr_conv[i];
//     }
//     auto freq_conv = atcoder::convolution_ll(freq, freq);
//     for(int i : rep(min<int>(N, freq_conv.size()))) ans[i] += freq_conv[i];
// });
// for(int i = 1; i <= N - 1; i++) cout << ans[i] / 2 << " "; cout << endl;
