// problem : https://onlinejudge.u-aizu.ac.jp/problems/2425
// solution: https://onlinejudge.u-aizu.ac.jp/solutions/problem/2425/review/8994730/rogi_52/C++17

vector<int> dx = {0, +1, +1, 0, -1, -1};
vector<vector<int>> dy = {
    {+1, 0, -1, -1, -1, 0},
    {+1, +1, 0, -1, 0, +1}
};
for(int d = 0; d < 6; d++) {
    int nx = x + dx[d], ny = y + dy[abs(x) % 2][d];
}
