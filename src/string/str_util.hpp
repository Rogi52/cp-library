vector<int> str_to_vec(const string& s, char base) {
    int n = s.size();
    vector<int> a(n);
    rep(i,n) a[i] = s[i] - base;
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
