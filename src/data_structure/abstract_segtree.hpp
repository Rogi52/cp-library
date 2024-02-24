// ノードへのアクセスが高速であれば良い
// https://atcoder.jp/contests/abc342/tasks/abc342_g

// query(l, r)
// for(l += N, r += N; l != r; l >>= 1, r >>= 1) {
//     if(l & 1) operation(data[l++]);
//     if(r & 1) operation(data[r++]);
// }
// query(i)
// for(i += N; i; i >>= 1) {
//     operation(data[i]);
// }
// access(i)
// A[i] == data[i + N]
