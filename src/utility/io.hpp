#pragma once
#include "../../src/cp-template.hpp"

/* 128bit integer */
istream& operator>>(istream& is, i128& x) {
    std::string s; is >> s;
    int pm = (s[0] == '-');
    x = 0;
    for(int i : rep(pm, int(s.size()))) x = x * 10 + (s[i] - '0');
    if(pm) x *= -1;
    return is;
}
ostream& operator<<(ostream& os, const i128& x) {
    if(x == 0) return os << '0';
    i128 y = x;
    if(y < 0) {
        os << '-';
        y *= -1;
    }
    std::vector<int> ny;
    while(y > 0) {
        ny.push_back(y % 10);
        y /= 10;
    }
    for(int i : revrep(ny.size())) os << ny[i];
    return os;
}

namespace scanner {
    struct sca {
        template < class T > operator T() {
            T s; std::cin >> s; return s;
        }
    };
    struct vec {
        int n;
        vec(int n) : n(n) {}
        template < class T > operator std::vector< T >() {
            std::vector< T > v(n);
            for(T& x : v) std::cin >> x;
            return v;
        }
    };
    struct mat {
        int h, w;
        mat(int h, int w) : h(h), w(w) {}
        template < class T > operator std::vector< std::vector< T > >() {
            std::vector m(h, std::vector< T >(w));
            for(std::vector< T >& v : m) for(T& x : v) std::cin >> x;
            return m;
        }
    };
    struct speedup {
        speedup() {
            std::cin.tie(0);
            std::ios::sync_with_stdio(0);
        }
    } speedup_instance;
}
scanner::sca in() { return scanner::sca(); }
scanner::vec in(int n) { return scanner::vec(n); }
scanner::mat in(int h, int w) { return scanner::mat(h, w); }

namespace printer {
    void precision(int d) { std::cout << std::fixed << std::setprecision(d); }
    void flush() { std::cout.flush(); }
}

template < class T >
ostream& operator<<(ostream& os, const std::vector< T > a) {
    int n = a.size();
    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os << ' '; }
    return os;
}

int print() { std::cout << '\n'; return 0; }
template < class head, class... tail > int print(head&& h, tail&&... t) {
    std::cout << h; if(sizeof...(tail)) std::cout << ' ';
    return print(std::forward<tail>(t)...);
}
template < class T > int print_n(const std::vector< T > a) {
    int n = a.size();
    for(int i : rep(n)) std::cout << a[i] << "\n";
    return 0;
}


