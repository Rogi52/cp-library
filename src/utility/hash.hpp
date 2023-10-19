#pragma once
#include "../../src/cp-template.hpp"

template < int num_of_mod = 2 >
struct hash_vector : public array<ll, num_of_mod> {
    static constexpr ll MODS[] = {999999937, 1000000007, 1000000009, 1000000021};
    static_assert(1 <= num_of_mod and num_of_mod <= 4);
    using array<ll, num_of_mod>::operator[];
    using H = hash_vector;
    static constexpr int n = num_of_mod;
    hash_vector() : array<ll,n>() {}
    hash_vector(ll x) : H() { for(int i : rep(n)) (*this)[i] = x % MODS[i]; }
    H& operator+=(const H& rhs) { for(int i : rep(n)) if(((*this)[i] += rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
    H& operator-=(const H& rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
    H& operator*=(const H& rhs) { for(int i : rep(n)) (*this)[i] = (*this)[i] * rhs[i] % MODS[i]; return *this; }
    H& operator+=(const ll rhs) { for(int i : rep(n)) if(((*this)[i] += rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
    H& operator-=(const ll rhs) { for(int i : rep(n)) if(((*this)[i] += MODS[i] - rhs % MODS[i]) >= MODS[i]) (*this)[i] -= MODS[i]; return *this; }
    H& operator*=(const ll rhs) { for(int i : rep(n)) (*this)[i] = (*this)[i] * (rhs % MODS[i]) % MODS[i]; return *this; }
    H operator+(const H& rhs) const { return H(*this) += rhs; }
    H operator-(const H& rhs) const { return H(*this) -= rhs; }
    H operator*(const H& rhs) const { return H(*this) *= rhs; }
    H operator+(const ll rhs) const { return H(*this) += rhs; }
    H operator-(const ll rhs) const { return H(*this) -= rhs; }
    H operator*(const ll rhs) const { return H(*this) *= rhs; }
    H operator-() const { return H().fill(0) - *this; }
    friend H operator+(ll x, const H& y) { return H(x) + y; }
    friend H operator-(ll x, const H& y) { return H(x) + y; }
    friend H operator*(ll x, const H& y) { return H(x) * y; }
    bool operator==(const H& rhs) { for(int i : rep(n)) if((*this)[i] != rhs[i]) return false; return true ; }
    bool operator!=(const H& rhs) { for(int i : rep(n)) if((*this)[i] != rhs[i]) return true ; return false; }
};
