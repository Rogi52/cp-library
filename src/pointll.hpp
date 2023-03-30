struct pointll {
    ll x,y;
    pointll(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator==(pointll p) const { return x == p.x && y == p.y; }
};

ll det(pointll p, pointll q) { return p.x * q.y - p.y * q.x; }
ll dot(pointll p, pointll q) { return p.x * q.x + p.y * q.y; }
