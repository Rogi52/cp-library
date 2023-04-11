namespace scanner {
    static int sz = -1;
    static int first = 1;
    struct input {
        template < class T > operator T() const {
            if(first) {
                first = 0;
                cin.tie(0);
                ios::sync_with_stdio(0);
            }
            if(sz == -1) {
                T t; cin >> t; return t;
            } else {
                T t(sz); sz = -1; cin >> t; return t;
            }
        }
    };

    template < class T > istream& operator>>(istream& is, vector< T >& a) {
        for(auto& x : a) cin >> x; return is;
    }
}
scanner::input input() { return scanner::input(); }
scanner::input input(int sz) { scanner::sz = sz; return scanner::input(); }

namespace printer {
    void precision(int d) {
        cout << fixed << setprecision(d);
    }
}
int print() { cout << "\n"; return 0; }
template < class head, class... tail >
int print(head&& h, tail&&... t) {
    cout << h;
    if(sizeof...(tail)) cout << " ";
    return print(forward<tail>(t)...);
}
template < class T > int print(vector< T >& a, char sep = ' ') {
    int n = a.size();
    rep(i,n) cout << a[i] << (i < n - 1 ? sep : '\n');
    return 0;
}
