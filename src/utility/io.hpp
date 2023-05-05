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
    } su;
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
int print() { cout << '\n'; return 0; }
template < class head, class... tail > int print(head&& h, tail&&... t) {
    cout << h; if(sizeof...(tail)) cout << ' ';
    return print(forward<tail>(t)...);
}
template < class T > int print(vector< T >& a, char sep = ' ') {
    int n = a.size();
    rep(i,n) cout << a[i] << (i != n - 1 ? sep : '\n');
    return 0;
}
template < class T > int print(vector< vector< T > >& a) {
    if(a.empty()) return 0;
    int h = a.size(), w = a[0].size();
    rep(i,h)rep(j,w) cout << a[i][j] << (j != w - 1 ? ' ' : '\n');
    return 0;
}
