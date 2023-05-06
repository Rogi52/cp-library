template < class mint, class T >
mint count_subseq(const vector< T >& a) {
    int n = a.size();
    unordered_map< T, int > mp;
    vector<mint> dp(n + 1);
    dp[0] = 1;
    for(int i : rep(n)) {
        dp[i + 1] = dp[i] + dp[i];
        if(mp.count(a[i])) dp[i + 1] -= dp[mp[a[i]]];
        mp[a[i]] = i;
    }
    return dp[n];
}
