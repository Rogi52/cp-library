#include "../../src/cp-template.hpp"

struct Eratosthenes {
    int N;
    vector<int> isprime, primes, spf, mobius;
    Eratosthenes(int N) : N(N), isprime(N + 1, 1), spf(N + 1, -1), mobius(N + 1, 1) {
        isprime[1] = 0;
        spf[1] = 1;
        for(int n = 2; n <= N; n++) if(isprime[n]) {
            primes.push_back(n);
            spf[n] = n;
            mobius[n] = -1;
            for(int m = n + n; m <= N; m += n) {
                isprime[m] = 0;
                if(spf[m] == -1) spf[m] = n;
                mobius[m] = ((m / n) % n == 0 ? 0 : - mobius[m]);
            }
        }
    }
    vector<pair<int,int>> factorize(int n) {
        assert(1 <= n and n <= N);
        vector<pair<int,int>> res;
        while(n > 1) {
            int p = spf[n], e = 0;
            while(spf[n] == p) n /= p, e++;
            res.push_back({p, e});
        }
        return res;
    }
    vector<int> divisors(int n) {
        vector<int> res = {1};
        auto pf = factorize(n);
        for(auto [p, e] : pf) {
            for(int i : rep(res.size())) {
                int v = 1;
                for(int j : rep(e)) {
                    v *= p;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
    int euler_phi(int n) {
        assert(1 <= n and n <= N);
        int res = n;
        for(auto [p, e] : factorize(n)) {
            res /= p;
            res *= p - 1;
        }
        return res;
    }

    template < class T >
    void multiple_zeta(vector< T >& a) {
        int n = a.size() - 1;
        assert(1 <= n and n <= N);
        for(int p : primes) {
            if(p <= n)
                for(int k = n / p; k > 0; k--) a[k] += a[k * p];
            else
                break;
        }
    }
    template < class T >
    void multiple_mobius(vector< T >& a) {
        int n = a.size() - 1;
        assert(1 <= n and n <= N);
        for(int p : primes) {
            if(p <= n)
                for(int k = 1; k * p <= n; k++) a[k] -= a[k * p];
            else
                break;
        }
    }
    template < class T >
    void divisor_zeta(vector< T >& a) {
        int n = a.size() - 1;
        assert(1 <= n and n <= N);
        for(int p : primes) {
            if(p <= n)
                for(int k = 1; k * p <= n; k++) a[k * p] += a[k];
            else
                break;
        }
    }
    template < class T >
    void divisor_mobius(vector< T >& a) {
        int n = a.size() - 1;
        assert(1 <= n and n <= N);
        for(int p : primes) {
            if(p <= n)
                for(int k = n / p; k > 0; k--) a[k * p] -= a[k];
            else
                break;
        }
    }
    template < class T >
    vector< T > gcd_convolution(vector< T > a, vector< T > b) {
        int n = max(a.size(), b.size());
        a.resize(n, 0);
        b.resize(n, 0);
        multiple_zeta(a);
        multiple_zeta(b);
        vector< T > c(n);
        for(int i : rep(n)) c[i] = a[i] * b[i];
        multiple_mobius(c);
        return c;
    }
    template < class T >
    vector< T > lcm_convolution(vector< T > a, vector< T > b) {
        int n = max(a.size(), b.size());
        a.resize(n, 0);
        b.resize(n, 0);
        divisor_zeta(a);
        divisor_zeta(b);
        vector< T > c(n);
        for(int i : rep(n)) c[i] = a[i] * b[i];
        divisor_mobius(c);
        return c;
    }
};
