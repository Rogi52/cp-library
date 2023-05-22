#include "../../src/cp-template.hpp"

template < class K, int L, class V >
struct binary_trie {
    struct node_t {
        array<int, 2> to = {};
        V cnt;
        vector<int> accept;
        node_t() : cnt(0) { to[0] = to[1] = -1; }
    };

    vector<node_t> node;
    int ROOT;
    K XOR;
    binary_trie() : node(1), ROOT(0), XOR(0) {}

    void xor_all(K x) {
        XOR ^= x;
    }
    int insert(K x, V v = 1, int id = -1) {
        int u = ROOT;
        node[u].cnt += v;
        for(int i : revrep(L)) {
            int p = ((XOR >> i) & 1) ^ ((x >> i) & 1);
            if(node[u].to[p] == -1) {
                node[u].to[p] = node.size();
                node.push_back(node_t());
            }
            u = node[u].to[p];
            node[u].cnt += v;
        }
        if(id != -1) node[u].accept.push_back(id);
        return u;
    }
    int erase(K x, V v = 1) {
        return insert(x, -v, -1);
    }
    int find(K x) {
        int u = ROOT;
        for(int i : revrep(L)) {
            int p = ((XOR >> i) & 1) ^ ((x >> i) & 1);
            u = node[u].to[p];
            if(u == -1) return -1;
        }
        return u;
    }
    pair< K, int > kth(V k) {
        assert(0 <= k && k < size());
        K x(0);
        int u = ROOT;
        for(int i : revrep(L)) {
            int p = (XOR >> i) & 1, v = node[u].to[p];
            K c = v != -1 ? node[v].cnt : 0;
            if(c <= k) {
                k -= c;
                x |= K(1) << i;
                u = node[u].to[p ^ 1];
            } else {
                u = node[u].to[p];
            }
        }
        return {x, u};
    }
    pair< K, int > min() {
        assert(not empty());
        return kth(0);
    }
    pair< K, int > max() {
        assert(not empty());
        return kth(size() - 1);
    }
    V count(K x) {
        int i = find(x);
        return i == -1 ? 0 : node[i].cnt;
    }
    V count_less(K x) {
        int u = ROOT;
        V v = 0;
        for(int i : revrep(L)) {
            int p = (XOR >> i) & 1, q = (x >> i) & 1;
            if(q > 0 and node[u].to[p] != -1) v += node[node[u].to[p]].cnt;
            if(node[u].to[p ^ q] != -1) {
                u = node[u].to[p ^ q];
            } else {
                break;
            }
        }
        return v;
    }
    V size() {
        return node[ROOT].cnt;
    }
    int empty() {
        return size() == 0;
    }
};