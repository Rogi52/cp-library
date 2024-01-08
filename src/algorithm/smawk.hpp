template < class Select >
std::vector<int> smawk(const int row_size, const int col_size, const Select& select) {
    const std::function<std::vector<int>(const std::vector<int>&, const std::vector<int>&)> dfs = 
        [&](const std::vector<int>& row, const std::vector<int>& col) -> std::vector<int> {
        const int n = row.size();
        if(n == 0) return {};

        /* Reduce step */
        std::vector<int> c2;
        for(const int i : col) {
            while(not c2.empty() and select(row[c2.size() - 1], c2.back(), i)) c2.pop_back();
            if(c2.size() < n) c2.push_back(i);
        }

        /* Recurse step */
        std::vector<int> r2;
        for(int i : rep(1, n, 2)) r2.push_back(row[i]);
        const std::vector<int> a2 = dfs(r2, c2);

        /* Interpolate step */
        std::vector<int> ans(n);
        for(int i : rep(a2.size())) ans[i * 2 + 1] = a2[i];
        int j = 0;
        for(int i : rep(0, n, 2)) {
            ans[i] = c2[j];
            while(c2[j] != (i + 1 == n ? c2.back() : ans[i + 1])) {
                j += 1;
                if(select(row[i], ans[i], c2[j])) ans[i] = c2[j];
            }
        }
        return ans;
    };

    std::vector<int> row(row_size), col(col_size);
    std::iota(row.begin(), row.end(), 0);
    std::iota(col.begin(), col.end(), 0);
    return dfs(row, col);
}
