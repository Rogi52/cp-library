#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "src/cp-template.hpp"
#include "src/geometry/pointll.hpp"
#include "src/geometry/angle_sort.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    vector<pointll> P(N);
    rep(i,N) cin >> P[i].x >> P[i].y;
    auto I = angle_argsort(P);
    for(int i : I) cout << P[i].x << " " << P[i].y << "\n";
}
