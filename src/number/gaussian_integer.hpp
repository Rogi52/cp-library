#include "../../src/cp-template.hpp"

struct gaussian_integer {
    using gint = gaussian_integer;
    ll x, y;
    gaussian_integer() : x(0), y(0) {}
    gaussian_integer(ll x) : x(x), y(0) {}
    gaussian_integer(ll x, ll y) : x(x), y(y) {}

    friend ll abs(const gint& a) {
        return a.x * a.x + a.y * a.y;
    }
    friend gint conj(const gint& a) {
        return gint(a.x, -a.y);
    }
    gint operator-() { return gint(-x, -y); }
    gint operator+(const gint& r) { return gint(*this) += r; }
    gint operator-(const gint& r) { return gint(*this) -= r; }
    gint operator*(const gint& r) { return gint(*this) *= r; }
    gint operator/(const gint& r) { return gint(*this) /= r; }
    gint operator%(const gint& r) { return gint(*this) %= r; }
    gint& operator+=(const gint& r) { x += r.x, y += r.y; return *this; }
    gint& operator-=(const gint& r) { x -= r.x, y -= r.y; return *this; }
    gint& operator*=(const gint& r) { std::tie(x, y) = std::make_pair(x * r.x - y * r.y, x * r.y + y * r.x); return *this; }
    gint& operator/=(const gint& r) {
        assert(not(r.x == 0 and r.y == 0));

        auto near = [](ll a, ll b) {
            ll q = a / b, r = a - q * b;
            if(abs(r) > abs(r - b)) return q + 1;
            if(abs(r) > abs(r + b)) return q - 1;
            return q;
        };

        gint u = (*this) * conj(r);
        return *this = gint(near(u.x, abs(r)), near(u.y, abs(r)));
    }
    gint& operator%=(const gint& r) { return *this -= (*this) / r * r; }
    bool operator==(const gint& r) { return x == r.x and y == r.y; }
    bool operator!=(const gint& r) { return x != r.x or  y != r.y; }
    friend gint gcd(gint a, gint b) {
        if(b == gint(0, 0)) return a;
        return gcd(b, a % b);
    }
};