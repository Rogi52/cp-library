---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cp-template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nusing ld = long double;\nusing uint = unsigned\
    \ int;\nusing ull  = unsigned long long;\nusing i32 = int;\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\ntemplate < class T > bool chmin(T& a, T b) { if(a > b) { a = b;\
    \ return true; } return false; }\ntemplate < class T > bool chmax(T& a, T b) {\
    \ if(a < b) { a = b; return true; } return false; }\ntemplate < class T, class\
    \ U > T ceil (T x, U y) { return (x > 0 ? (x + y - 1) / y :           x / y);\
    \ }\ntemplate < class T, class U > T floor(T x, U y) { return (x > 0 ?       \
    \    x / y : (x - y + 1) / y); }\nint popcnt(i32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(i64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n\n#line 2 \"src/utility/rep_itr.hpp\"\ntemplate < class T > struct itr_rep\
    \ {\n    T i, d;\n    constexpr itr_rep(const T i) noexcept : i(i), d(1) {}\n\
    \    constexpr itr_rep(const T i, const T d) noexcept : i(i), d(d) {}\n    void\
    \ operator++() noexcept { i += d; }\n    constexpr int operator*() const noexcept\
    \ { return i; }\n    constexpr bool operator!=(const itr_rep x) const noexcept\
    \ { return d > 0 ? i < x.i : i > x.i; }\n};\n\ntemplate < class T > struct rep\
    \ {\n    const itr_rep< T > s, t;\n    constexpr rep(const T t) noexcept : s(0),\
    \ t(t) {}\n    constexpr rep(const T s, const T t) noexcept : s(s), t(t) {}\n\
    \    constexpr rep(const T s, const T t, const T d) noexcept : s(s, d), t(t, d)\
    \ {}\n    constexpr auto begin() const noexcept { return s; }\n    constexpr auto\
    \ end  () const noexcept { return t; }\n};\n\ntemplate < class T > struct revrep\
    \ {\n    const itr_rep < T > s, t;\n    constexpr revrep(const T t) noexcept :\
    \ s(t - 1, -1), t(-1, -1) {}\n    constexpr revrep(const T s, const T t) noexcept\
    \ : s(t - 1, -1), t(s - 1, -1) {}\n    constexpr revrep(const T s, const T t,\
    \ const T d) noexcept : s(t - 1, -d), t(s - 1, -d) {}\n    constexpr auto begin()\
    \ const noexcept { return s; }\n    constexpr auto end  () const noexcept { return\
    \ t; }\n};\n#line 3 \"src/utility/io.hpp\"\n\n/* 128bit integer */\nistream& operator>>(istream&\
    \ is, i128& x) {\n    std::string s; is >> s;\n    int pm = (s[0] == '-');\n \
    \   x = 0;\n    for(int i : rep(pm, int(s.size()))) x = x * 10 + (s[i] - '0');\n\
    \    if(pm) x *= -1;\n    return is;\n}\nostream& operator<<(ostream& os, const\
    \ i128& x) {\n    if(x == 0) return os << '0';\n    i128 y = x;\n    if(y < 0)\
    \ {\n        os << '-';\n        y *= -1;\n    }\n    std::vector<int> ny;\n \
    \   while(y > 0) {\n        ny.push_back(y % 10);\n        y /= 10;\n    }\n \
    \   for(int i : revrep(ny.size())) os << ny[i];\n    return os;\n}\n\nnamespace\
    \ scanner {\n    struct sca {\n        template < class T > operator T() {\n \
    \           T s; std::cin >> s; return s;\n        }\n    };\n    struct vec {\n\
    \        int n;\n        vec(int n) : n(n) {}\n        template < class T > operator\
    \ std::vector< T >() {\n            std::vector< T > v(n);\n            for(T&\
    \ x : v) std::cin >> x;\n            return v;\n        }\n    };\n    struct\
    \ mat {\n        int h, w;\n        mat(int h, int w) : h(h), w(w) {}\n      \
    \  template < class T > operator std::vector< std::vector< T > >() {\n       \
    \     std::vector m(h, std::vector< T >(w));\n            for(std::vector< T >&\
    \ v : m) for(T& x : v) std::cin >> x;\n            return m;\n        }\n    };\n\
    \    struct speedup {\n        speedup() {\n            std::cin.tie(0);\n   \
    \         std::ios::sync_with_stdio(0);\n        }\n    } speedup_instance;\n\
    }\nscanner::sca in() { return scanner::sca(); }\nscanner::vec in(int n) { return\
    \ scanner::vec(n); }\nscanner::mat in(int h, int w) { return scanner::mat(h, w);\
    \ }\n\nnamespace printer {\n    void precision(int d) { std::cout << std::fixed\
    \ << std::setprecision(d); }\n    void flush() { std::cout.flush(); }\n}\n\ntemplate\
    \ < class T >\nostream& operator<<(ostream& os, const std::vector< T > a) {\n\
    \    int n = a.size();\n    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os\
    \ << ' '; }\n    return os;\n}\n\nint print() { std::cout << '\\n'; return 0;\
    \ }\ntemplate < class head, class... tail > int print(head&& h, tail&&... t) {\n\
    \    std::cout << h; if(sizeof...(tail)) std::cout << ' ';\n    return print(std::forward<tail>(t)...);\n\
    }\ntemplate < class T > int print_n(const std::vector< T > a) {\n    int n = a.size();\n\
    \    for(int i : rep(n)) std::cout << a[i] << \"\\n\";\n    return 0;\n}\n\n\n\
    #line 2 \"src/utility/key_val.hpp\"\n\ntemplate < class K, class V >\nstruct key_val\
    \ {\n    K key; V val;\n    key_val() {}\n    key_val(K key, V val) : key(key),\
    \ val(val) {}\n    template < std::size_t Index >\n    std::tuple_element_t< Index,\
    \ key_val >& get() {\n        if constexpr (Index == 0) return key;\n        if\
    \ constexpr (Index == 1) return val;\n    }\n};\n\nnamespace std {\n\ntemplate\
    \ < class K, class V > struct tuple_size < key_val< K, V > > : integral_constant<\
    \ size_t, 2 > {};\ntemplate < class K, class V > struct tuple_element < 0, key_val<\
    \ K, V > > { using type = K; };\ntemplate < class K, class V > struct tuple_element\
    \ < 1, key_val< K, V > > { using type = V; };\n\n}\n#line 2 \"src/utility/vec_op.hpp\"\
    \ntemplate < class T > key_val< int, T > max_of(const vector< T >& a) {\n    int\
    \ i = std::max_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class T > key_val< int, T > min_of(const vector< T >& a) {\n   \
    \ int i = std::min_element(a.begin(), a.end()) - a.begin();\n    return {i, a[i]};\n\
    }\ntemplate < class S, class T > S sum_of(const vector< T >& a) {\n    S sum =\
    \ 0;\n    for(const T x : a) sum += x;\n    return sum;\n}\ntemplate < class S,\
    \ class T > vector< S > freq_of(const vector< T >& a, T L, T R) {\n    vector<\
    \ S > res(R - L, S(0));\n    for(const T x : a) res[x - L] += 1;\n    return res;\n\
    }\ntemplate < class S, class T > struct prefix_sum {\n    vector< S > s;\n   \
    \ prefix_sum(const vector< T >& a) : s(a) {\n        s.insert(s.begin(), S(0));\n\
    \        for(int i : rep(a.size())) s[i + 1] += s[i];\n    }\n    // [L, R)\n\
    \    S sum(int L, int R) { return s[R] - s[L]; }\n};\n#line 3 \"src/utility/heap.hpp\"\
    \n\ntemplate < class T > using heap_min = std::priority_queue< T, std::vector<\
    \ T >, std::greater< T > >;\ntemplate < class T > using heap_max = std::priority_queue<\
    \ T, std::vector< T >, std::less< T > >;\n\n#line 27 \"src/cp-template.hpp\"\n\
    \n#line 1 \"src/algorithm/bin_search.hpp\"\ntemplate < class T, class F >\nT bin_search(T\
    \ ok, T ng, F& f) {\n    while(abs(ok - ng) > 1) {\n        T mid = (ok + ng)\
    \ / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate\
    \ < class T, class F >\nT bin_search_real(T ok, T ng, F& f, int step = 80) {\n\
    \    while(step--) {\n        T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ok;\n}\n#line 2 \"src/algorithm/argsort.hpp\"\n\n\
    template < class T > std::vector< int > argsort(const std::vector< T > &a) {\n\
    \    std::vector< int > ids((int)a.size());\n    std::iota(ids.begin(), ids.end(),\
    \ 0);\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n        return\
    \ a[i] < a[j] || (a[i] == a[j] && i < j);\n    });\n    return ids;\n}\n#line\
    \ 3 \"src/graph/tree/tree.hpp\"\n\ntemplate < class T >\nstruct tree_graph {\n\
    \    int n;\n    struct edge {\n        int from, to, id; T cost;\n    };\n  \
    \  std::vector<std::vector< edge >> g, g_org;\n    tree_graph(int n) : n(n), g(n),\
    \ g_org(n) {}\n\n    void add_edge(int u, int v, int i = 0, T c = 1) {\n     \
    \   g[u].push_back(edge{u, v, i, c});\n        g[v].push_back(edge{v, u, i, c});\n\
    \        g_org[u].push_back(edge{u, v, i, c});\n        g_org[v].push_back(edge{v,\
    \ u, i, c});\n    }\n\n    std::pair< std::pair<int,int>, T > diameter() {\n \
    \       std::vector< T > dist(n);\n        std::function<void(int,int)> dfs =\
    \ [&](int v, int p) -> void {\n            for(auto [to, c] : g[v]) if(to != p)\
    \ {\n                dist[to] = dist[v] + c;\n                dfs(to, v);\n  \
    \          }\n        };\n        dist[0] = 0; dfs(0, -1);\n        int u = max_of(dist).key;\n\
    \        dist[u] = 0; dfs(u, -1);\n        auto [v, d] = max_of(dist);\n     \
    \   return {{u, v}, d};\n    }\n\n    std::vector<int> path(int u, int v) {\n\
    \        std::vector<int> parent(n, -1);\n        std::function<void(int,int)>\
    \ dfs = [&](int v, int p) -> void {\n            parent[v] = p;\n            for(auto\
    \ e : g[v]) if(e.to != p) dfs(e.to, v);\n        };\n        dfs(v, -1);\n   \
    \     std::vector<int> res;\n        while(u != -1) res.push_back(u), u = parent[u];\n\
    \        return res;\n    }\n\n    int id, root, heavy_light_decomposed;\n   \
    \ std::vector<int> size, depth, down, up, nxt, par, tour;\n\n    void heavy_light_decomposition(int\
    \ root = 0) {\n        id = 0;\n        this->root = root;\n        size .assign(n,\
    \ 0);\n        depth.assign(n, 0);\n        down.assign(n, -1);\n        up  .assign(n,\
    \ -1);\n        tour.assign(n, -1);\n        nxt.assign(n, root);\n        par.assign(n,\
    \ root);\n        dfs_size(root);\n        dfs_hld(root);\n        heavy_light_decomposed\
    \ = 1;\n    }\n\n    void dfs_size(int v) {\n        size[v] = 1;\n        for(auto&\
    \ e : g[v]) {\n            if(e.to == par[v]) {\n                if(std::ssize(g[v])\
    \ >= 2 and e.to == g[v][0].to) {\n                    std::swap(g[v][0], g[v][1]);\n\
    \                } else continue;\n            }\n            depth[e.to] = depth[v]\
    \ + 1;\n            par[e.to] = v;\n            dfs_size(e.to);\n            size[v]\
    \ += size[e.to];\n            if(size[e.to] > size[g[v][0].to]) std::swap(e, g[v][0]);\n\
    \        }\n    }\n    void dfs_hld(int v) {\n        down[v] = id++;\n      \
    \  tour[down[v]] = v;\n        for(auto e : g[v]) if(e.to != par[v]) {\n     \
    \       nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n            dfs_hld(e.to);\n\
    \        }\n        up[v] = id;\n    }\n\n    std::vector<std::pair<int,int>>\
    \ ascend(int u, int v) {\n        assert(heavy_light_decomposed);\n        std::vector<std::pair<int,int>>\
    \ res;\n        while(nxt[u] != nxt[v]) res.push_back({down[u] + 1, down[nxt[v]]}),\
    \ u = par[nxt[u]];\n        if(u != v) res.push_back({down[u] + 1, down[v] + 1});\n\
    \        return res;\n    }\n    std::vector<std::pair<int,int>> descend(int u,\
    \ int v) {\n        assert(heavy_light_decomposed);\n        if(u == v) return\
    \ {};\n        if(nxt[u] == nxt[v]) return {{down[u] + 1, down[v] + 1}};\n   \
    \     std::vector<std::pair<int,int>> res = descend(u, par[nxt[v]]);\n       \
    \ res.push_back({down[nxt[v]], down[v] + 1});\n        return res;\n    }\n  \
    \  std::pair<int,int> idx(int v) { \n        assert(heavy_light_decomposed);\n\
    \        return {down[v], up[v]};\n    }\n\n    template < class func >\n    void\
    \ path_query_comm(int u, int v, bool vertex, const func& f) {\n        assert(heavy_light_decomposed);\n\
    \        int x = lca(u, v);\n        for(auto [a, b] : ascend(u, x)) {\n     \
    \       std::tie(a, b) = std::minmax({a, b});\n            f(a, b);\n        }\n\
    \        if(vertex) f(down[x], down[x] + 1);\n        for(auto [a, b] : descend(x,\
    \ v)) {\n            std::tie(a, b) = std::minmax({a, b});\n            f(a, b);\n\
    \        }\n    }\n    template < class func >\n    void path_query(int u, int\
    \ v, bool vertex, const func& f) {\n        assert(heavy_light_decomposed);\n\
    \        int x = lca(u, v);\n        for(auto [a, b] : ascend(u, x)) f(a, b);\n\
    \        if(vertex) f(down[x], down[x] + 1);\n        for(auto [a, b] : descend(x,\
    \ v)) f(a, b);\n    }\n    template < class func >\n    void subtree_query(int\
    \ v, bool vertex, const func& f) {\n        assert(heavy_light_decomposed);\n\
    \        f(down[v] + !vertex, up[v]);\n    }\n    int parent(int v) {\n      \
    \  assert(heavy_light_decomposed);\n        return v == root ? -1 : par[v];\n\
    \    }\n    int la(int v, int d) {\n        assert(heavy_light_decomposed);\n\
    \        while(v != -1) {\n            int u = nxt[v];\n            if(down[v]\
    \ - d >= down[u]) return tour[down[v] - d];\n            d -= down[v] - down[u]\
    \ + 1;\n            v = parent(u);\n        }\n        return v;\n    }\n    int\
    \ lca(int u, int v) {\n        assert(heavy_light_decomposed);\n        while(nxt[u]\
    \ != nxt[v]) {\n            if(down[u] < down[v]) std::swap(u, v);\n         \
    \   u = par[nxt[u]];\n        }\n        return depth[u] < depth[v] ? u : v;\n\
    \    }\n    int dist(int u, int v) {\n        assert(heavy_light_decomposed);\n\
    \        return depth[u] + depth[v] - depth[lca(u, v)] * 2;\n    }\n    int jump(int\
    \ u, int v, int d) {\n        assert(heavy_light_decomposed);\n        int x =\
    \ lca(u, v);\n        if(d <= depth[u] - depth[x]) return la(u, d);\n        d\
    \ -= depth[u] - depth[x];\n        if(d <= depth[v] - depth[x]) return la(v, depth[v]\
    \ - depth[x] - d);\n        return -1;\n    }\n    int in_subtree(int r, int v)\
    \ {\n        return down[v] < down[r] and up[r] <= up[v];\n    }\n};\n\n#line\
    \ 3 \"src/graph/tree/rerooting.hpp\"\n\ntemplate < class S, class TREE, class\
    \ EE, class EV, class VP, class I >\nstruct dp_on_tree {\n    TREE& tree;\n  \
    \  \n    std::vector< S > dp, dp_rev, answer;\n    std::vector<std::vector< S\
    \ >> dp_sub;\n    EE f_ee;\n    EV f_ev;\n    VP f_vp;\n    I id;\n    int root;\n\
    \    dp_on_tree(TREE& tree, const EE f_ee, const EV f_ev, const VP f_vp, const\
    \ I id) : tree(tree), f_ee(f_ee), f_ev(f_ev), f_vp(f_vp), id(id) {}\n    \n  \
    \  void solve(int root) {\n        this->root = root;\n        dp.assign(tree.n,\
    \ id());\n        dp_sub.resize(tree.n);\n        for(int v : rep(tree.n)) dp_sub[v].resize(tree.g_org[v].size());\n\
    \        std::function<S(int,int)> dfs = [&](int v, int p) -> S {\n          \
    \  for(int i : rep(tree.g_org[v].size())) {\n                auto e = tree.g_org[v][i];\n\
    \                if(e.to != p) {\n                    dp_sub[v][i] = dfs(e.to,\
    \ v);\n                    dp[v] = f_ee(dp[v], f_ev(dp_sub[v][i], e.id));\n  \
    \              }\n            }\n            return dp[v] = f_vp(dp[v], v);\n\
    \        }; dfs(root, -1);\n    }\n\n    void reroot() {\n        tree.heavy_light_decomposition(root);\n\
    \        auto g = tree.g_org;\n        dp_rev.assign(tree.n, id());\n        std::function<void(int,int,S)>\
    \ dfs = [&](int v, int p, S s) -> void {\n            for(int i : rep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                if(e.to == p) dp_sub[v][i]\
    \ = s;\n            }\n            std::vector< S > R(g[v].size() + 1u);\n   \
    \         R[g[v].size()] = id();\n            for(int i : revrep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                R[i] = f_ee(R[i + 1],\
    \ f_ev(dp_sub[v][i], e.id));\n            }\n            S L = id();\n       \
    \     for(int i : rep(g[v].size())) {\n                auto e = g[v][i];\n   \
    \             if(e.to != p) {\n                    dfs(e.to, v, f_vp(f_ee(L, R[i\
    \ + 1]), v));\n                }\n                dp_rev[e.to] = f_vp(f_ee(L,\
    \ R[i + 1]), v);\n                L = f_ee(L, f_ev(dp_sub[v][i], e.id));\n   \
    \         }\n        }; dfs(root, -1, id());\n        \n        answer.assign(tree.n,\
    \ id());\n        for(int v : rep(tree.n)) {\n            for(int i : rep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                answer[v] = f_ee(answer[v],\
    \ f_ev(dp_sub[v][i], e.id));\n            }\n            answer[v] = f_vp(answer[v],\
    \ v);\n        }\n    }\n\n    S get(int root, int v) {\n        if(root == v)\
    \ return answer[v];\n        if(not tree.in_subtree(root, v)) return dp[v];\n\
    \        return dp_rev[tree.jump(v, root, 1)];\n    }\n};\n"
  code: "#include \"../../../src/cp-template.hpp\"\n#include \"../../../src/graph/tree/tree.hpp\"\
    \n\ntemplate < class S, class TREE, class EE, class EV, class VP, class I >\n\
    struct dp_on_tree {\n    TREE& tree;\n    \n    std::vector< S > dp, dp_rev, answer;\n\
    \    std::vector<std::vector< S >> dp_sub;\n    EE f_ee;\n    EV f_ev;\n    VP\
    \ f_vp;\n    I id;\n    int root;\n    dp_on_tree(TREE& tree, const EE f_ee, const\
    \ EV f_ev, const VP f_vp, const I id) : tree(tree), f_ee(f_ee), f_ev(f_ev), f_vp(f_vp),\
    \ id(id) {}\n    \n    void solve(int root) {\n        this->root = root;\n  \
    \      dp.assign(tree.n, id());\n        dp_sub.resize(tree.n);\n        for(int\
    \ v : rep(tree.n)) dp_sub[v].resize(tree.g_org[v].size());\n        std::function<S(int,int)>\
    \ dfs = [&](int v, int p) -> S {\n            for(int i : rep(tree.g_org[v].size()))\
    \ {\n                auto e = tree.g_org[v][i];\n                if(e.to != p)\
    \ {\n                    dp_sub[v][i] = dfs(e.to, v);\n                    dp[v]\
    \ = f_ee(dp[v], f_ev(dp_sub[v][i], e.id));\n                }\n            }\n\
    \            return dp[v] = f_vp(dp[v], v);\n        }; dfs(root, -1);\n    }\n\
    \n    void reroot() {\n        tree.heavy_light_decomposition(root);\n       \
    \ auto g = tree.g_org;\n        dp_rev.assign(tree.n, id());\n        std::function<void(int,int,S)>\
    \ dfs = [&](int v, int p, S s) -> void {\n            for(int i : rep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                if(e.to == p) dp_sub[v][i]\
    \ = s;\n            }\n            std::vector< S > R(g[v].size() + 1u);\n   \
    \         R[g[v].size()] = id();\n            for(int i : revrep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                R[i] = f_ee(R[i + 1],\
    \ f_ev(dp_sub[v][i], e.id));\n            }\n            S L = id();\n       \
    \     for(int i : rep(g[v].size())) {\n                auto e = g[v][i];\n   \
    \             if(e.to != p) {\n                    dfs(e.to, v, f_vp(f_ee(L, R[i\
    \ + 1]), v));\n                }\n                dp_rev[e.to] = f_vp(f_ee(L,\
    \ R[i + 1]), v);\n                L = f_ee(L, f_ev(dp_sub[v][i], e.id));\n   \
    \         }\n        }; dfs(root, -1, id());\n        \n        answer.assign(tree.n,\
    \ id());\n        for(int v : rep(tree.n)) {\n            for(int i : rep(g[v].size()))\
    \ {\n                auto e = g[v][i];\n                answer[v] = f_ee(answer[v],\
    \ f_ev(dp_sub[v][i], e.id));\n            }\n            answer[v] = f_vp(answer[v],\
    \ v);\n        }\n    }\n\n    S get(int root, int v) {\n        if(root == v)\
    \ return answer[v];\n        if(not tree.in_subtree(root, v)) return dp[v];\n\
    \        return dp_rev[tree.jump(v, root, 1)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/src/graph/tree/rerooting.hpp
- /library/src/graph/tree/rerooting.hpp.html
title: src/graph/tree/rerooting.hpp
---
