using size_type = int;

template < class weight_type >
pair<weight_type, vector<size_type>> minimum_spanning_tree(const size_type n, const vector<tuple<size_type, size_type, weight_type>>& edges) {
    const size_type m = edges.size();
    vector<size_type> I(m);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) { return get<2>(edges[i]) < get<2>(edges[j]); });
    union_find uf(n);
    weight_type sum = 0;
    vector<size_type> tree_edges;
    tree_edges.reserve(n - 1);
    for(size_type i : I) {
        auto [u, v, w] = edges[i];
        if(uf.unite(u, v) != -1) {
            sum += w;
            tree_edges.push_back(i);
        }
    }
    return {sum, std::move(tree_edges)};
}
