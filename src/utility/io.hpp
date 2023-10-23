#pragma once
namespace scanner {
    struct sca {
        template < class T > operator T() {
            T s; cin >> s; return s;
        }
    };
    struct vec {
        int n;
        vec(int n) : n(n) {}
        template < class T > operator vector< T >() {
            vector< T > v(n);
            for(T& x : v) cin >> x;
            return v;
        }
    };
    struct mat {
        int h,w;
        mat(int h, int w) : h(h), w(w) {}
        template < class T > operator vector< vector< T > >() {
            vector m(h, vector< T >(w));
            for(vector< T >& v : m) for(T& x : v) cin >> x;
            return m;
        }
    };
    struct speedup {
        speedup() {
            cin.tie(0);
            ios::sync_with_stdio(0);
        }
    } speedup_instance;
}
scanner::sca in() { return scanner::sca(); }
scanner::vec in(int n) { return scanner::vec(n); }
scanner::mat in(int h, int w) { return scanner::mat(h, w); }

namespace printer {
    void precision(int d) {
        cout << fixed << setprecision(d);
    }
    void flush() {
        cout.flush();
    }
}

template < class T >
ostream& operator<<(ostream& os, const std::vector< T > a) {
    int n = a.size();
    for(int i : rep(n)) { os << a[i]; if(i != n - 1) os << ' '; }
    return os;
}

int print() { cout << '\n'; return 0; }
template < class head, class... tail > int print(head&& h, tail&&... t) {
    cout << h; if(sizeof...(tail)) cout << ' ';
    return print(forward<tail>(t)...);
}

template < class T > int print_n(const std::vector< T > a) {
    int n = a.size();
    for(int i : rep(n)) cout << a[i] << "\n";
    return 0;
}
