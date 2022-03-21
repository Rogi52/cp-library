#include "src/algorithm/argsort.hpp"

template < class T >
pair< vector< int >, vector< pair< T, T > > > convex_hull(vector< pair< T, T > > &points, string mode = "full", bool inclusive = false) {
    assert(mode == "full" || mode == "lower" || mode == "upper");
    int n = points.size();
    if(n == 1) return {{0}, {points[0]}};
    if(n == 2) return {{0, 1}, {points[0], points[1]}};
    vector<int> I = argsort(points);

    auto check = [&](int i, int j, int k) {
        auto [xi, yi] = points[i];
        auto [xj, yj] = points[j];
        auto [xk, yk] = points[k];
        T det = (xj - xi) * (yk - yj) - (yj - yi) * (xk - xj);
        return inclusive ? det >= 0 : det > 0;
    };

    auto calc = [&]() {
        vector<int> J;
        for(int k : I) {
            while(J.size() >= 2 && !check(J[J.size() - 2], J.back(), k)) J.pop_back();
            J.push_back(k);
        }
        return J;
    };

    vector<int> ids;
    if(mode == "full" || mode == "lower") {
        vector<int> J = calc();
        ids.insert(ids.end(), J.begin(), J.end());
    }
    if(mode == "full" || mode == "upper") {
        if(!ids.empty()) ids.pop_back();
        reverse(I.begin(), I.end());
        vector<int> J = calc();
        ids.insert(ids.end(), J.begin(), J.end());
    }
    if(mode == "upper") reverse(ids.begin(), ids.end());
    if(ids.size() >= 2 && ids[0] == ids.back()) ids.pop_back();
    vector< pair< T, T > > ch;
    for(int i : ids) ch.push_back(points[i]);
    return {ids, ch};
}
