// No.502 階乗を計算するだけ
// https://yukicoder.me/submissions/1022071
namespace factorial {

// set
// - mod
// - width
// - filename in precalc()
// - filename at vector fs
constexpr i64 mod = 1000000007;
constexpr int width = 1'000'000;
void precalc() {
    i64 f = 1;
    fstream io("f107.txt");
    io << 1 << ",";
    int cnt = 1;
    for(int i = 1; i < mod; i++) {
        f = (f * i) % mod;
        if(i % width == 0) {
            io << f << ",";
            cnt++;
            if(cnt % 100 == 0) io << "\n";
        }
    }
}

// vector<i64> fs = {
// #include "f107.txt"
// };
// i64 get(i64 n) {
//     if(n < mod) {
//         int i = 0;
//         while((i + 1) * width <= n) i++;
//         i64 ans = fs[i];
//         for(i64 v = i * width + 1; v <= n; v++) ans = (ans * v) % mod;
//         return ans;
//     } else {
//         return 0;
//     }
// }

}

int main() {
    // factorial::precalc();
    i64 n = in();
    print(factorial::get(n));
}
