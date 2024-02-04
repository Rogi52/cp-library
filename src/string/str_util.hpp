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
