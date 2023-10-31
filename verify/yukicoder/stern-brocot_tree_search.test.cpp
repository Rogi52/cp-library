#define PROBLEM "https://yukicoder.me/problems/no/2262"

#include "../../src/cp-template.hpp"
#include "../../src/number/stern-brocot_tree.hpp"
#include "../../src/algorithm/floor_sum.hpp"
#include "../../src/algorithm/enumrate_quotient.hpp"

int main() {
    ll N = in(), K = in();

    /* Mertens */
    const ll B = 10'000;
    std::vector<ll> bs(N / B + 1, 1), gs(B + 1, 1), vis(N / B + 1, 0);
    bs[0] = gs[0] = 0;
    for(ll i : rep(2LL, N / B + 1)) if(not vis[i]) {
        bs[i] *= -1;
        for(ll j : rep(2*i, N / B + 1, i)) {
            vis[j] = 1;
            if((j / i) % i == 0)
                bs[j] = 0;
            else
                bs[j] *= -1;
        }
    }
    for(ll i : rep(1LL, N / B)) bs[i + 1] += bs[i];
    for(ll i : revrep(1LL, B + 1)) {
        for(ll L = 2; L <= N / i; ) {
            ll Q = N / (i * L), R = N / (i * Q) + 1;
            gs[i] -= (i * L <= B ? gs[i * L] : bs[N / (i * L)]) * (R - L);
            L = R;
        }
    }
    auto M = [&](ll x) {
        if(x < ll(bs.size())) {
            return bs[x];
        } else {
            return gs[N / x];
        }
    };

    auto count = [&](std::pair<ll,ll> x) {
        ll ans = 0;
        ll upper, lower; std::tie(upper, lower) = x;
        for_each_quotient(N, [&](ll L, ll R, ll Q) {
            ans += M(Q) * (floor_sum(R, lower, upper, 0) - floor_sum(L, lower, upper, 0));
        });
        return ans;
    };

    ll C = count({N - 1, N});
    if(K == C + 1) return print("1/1");

    bool rev = false;
    if(K <= C) {}
    else if(K <= 2 * C + 1) {
        rev = true;
        K = 2 * C + 2 - K;
    } else {
        return print(-1);
    }

    auto [f, g] = sbt_search(N, [&](std::pair<ll,ll> x) {
        return count(x) >= K;
    });

    if(rev) std::swap(f, g);
    std::cout << f << "/" << g << std::endl;
}