using ll = long long;
vector< pair< pair< ll, ll >, ll > > quotient_range(ll N) {
    vector< pair< pair< ll, ll >, ll > > res;
    for(ll L = 1; L <= N; L = N / (N / L) + 1) {
        ll X = N / L, R = N / X;
        res.push_back({{L, R}, X});
    }
    return res;
}
