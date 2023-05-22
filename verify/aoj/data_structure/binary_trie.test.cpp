#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../../src/cp-template.hpp"
#include "../../../src/data_structure/binary_trie.hpp"

int main() {
    int N = in(), Q = in();
    binary_trie<int,20,int> bt;
    for(int _ : rep(Q)) {
        int c = in(), x = in(), y = in();
        switch(c) {
            case 0: {
                bt.insert(x, y);
            } break;

            case 1: {
                print(bt.count_less(y + 1) - bt.count_less(x));
            } break;
        }
    }
}