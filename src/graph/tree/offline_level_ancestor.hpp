namespace off_la {

using func = function<void(int, vector<int>&, vector<int>&)>;
void sol(const vector<vector<int>> &tree, int root, const vector<int> &query, func &ans) {
    int N = tree.size();
    vector<int> path, pos(N, -1);
    vector<vector<int>> q(N);
    for(int i : rep(query.size())) q[query[i]].push_back(i);

    function<void(int,int)> dfs = [&](int v, int p) -> void {
        pos[v] = path.size();
        path.push_back(v);
        for(int i : q[v]) ans(i, path, pos);
        for(int to : tree[v]) if(to != p) dfs(to, v);
        pos[v] = -1;
        path.pop_back();
    }; dfs(root, -1);
}

}
