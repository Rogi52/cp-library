#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/binary_trie.hpp"

int main() {
    binary_trie<int,30,int> bt;
    int Q = in();
    for(int _ : rep(Q)) {
        int t = in(), x = in();
        switch(t) {
            case 0: {
                if(bt.count(x) == 0) {
                    bt.insert(x);
                }
            } break;

            case 1: {
                if(bt.count(x) != 0) {
                    bt.erase(x);
                }
            } break;

            case 2: {
                bt.xor_all(x);
                print(bt.min().first);
                bt.xor_all(x);
            } break;
        }
    }
}