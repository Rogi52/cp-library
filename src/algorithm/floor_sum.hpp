#include "../cp-template.hpp"

// sum_{i in [0, n)} floor((a * i + b) / m) 
ll floor_sum(ll n, ll m, ll a, ll b) {
    if(n == 0) return ll(0);
    ll ans = 0;
    ans += (n - 1) * n / 2 * (a / m), a %= m;
    ans += n * (b / m), b %= m;
    ll y_max = a * n + b;
    ans += floor_sum(y_max / m, a, m, y_max % m);
    return ans;
}