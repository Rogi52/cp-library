vector<int> str_to_vec(const string& s, char base) {
    int n = s.size();
    vector<int> a(n);
    for(int i : rep(n)) a[i] = s[i] - base;
    return a;
}

vector<vector<int>> next_pos(const vector<int>& a, int k) {
    int n = a.size();
    vector<vector<int>> pos(n + 1, vector<int>(k, -1));
    for(int i = n - 1; i >= 0; i--) {
        pos[i] = pos[i + 1];
        pos[i][a[i]] = i + 1;
    }
    return pos;
}

using size_type = int;
template < class container > bool is_subsequence(const container& s, const container& t) {
    const size_type n = s.size();
    const size_type m = t.size();
    if(n == 0) return true;
    if(m == 0) return false;
    size_type j = 0;
    for(size_type i = 0; i < n; i++, j++) {
        while(j < m and s[i] != t[j]) j++;
        if(m <= j) return false;
    }
    return true;
}

template < class container > int lcs(const container& s, const container& t) {
    const int n = s.size();
    const int m = t.size();
    vector dp(n + 1, vector(m + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[n][m];
}
