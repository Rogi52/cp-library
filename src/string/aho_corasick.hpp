struct aho_corasick {
    static constexpr int C_SIZE = 26;
    static constexpr int C_BEGIN = 'a';
    static constexpr int ROOT = 0;
    struct node {
        array<int, C_SIZE> to = {};
        vector<int> ids; // このノードでマッチする文字列のIDリスト
        int fail = ROOT; // 失敗時の遷移先
        int drct = ROOT; // suffixでマッチする遷移先
        node() { to.fill(-1); }
    };
    vector<node> nodes;
    vector<string> patterns;
    aho_corasick() : nodes(1) {}

    int insert(const string& s) {
        int v = ROOT;
        for(char c : s) {
            const int k = c - C_BEGIN;
            if(nodes[v].to[k] == -1) {
                nodes[v].to[k] = nodes.size();
                nodes.push_back(node());
            }
            v = nodes[v].to[k];
        }
        nodes[v].ids.push_back(patterns.size());
        patterns.push_back(s);
        return v;
    }

    int next(int v, char c) {
        const int k = c - C_BEGIN;
        while(nodes[v].to[k] == -1 and v != ROOT) v = nodes[v].fail;
        return nodes[v].to[k] != -1 ? nodes[v].to[k] : ROOT;
    }

    void build() {
        std::queue<int> q;
        for(int v : nodes[ROOT].to) if(v != -1) q.push(v);
        while(not q.empty()) {
            int v = q.front(); q.pop();
            int fail = nodes[v].fail;
            for(int k = 0; k < C_SIZE; k++) {
                int nv = nodes[v].to[k];
                if(nv != -1) {
                    q.push(nv);
                    nodes[nv].fail = next(fail, k + C_BEGIN);
                }
            }
            nodes[v].drct = (nodes[fail].ids.empty() ? nodes[fail].drct : fail);
        }
    }

    // v で完成している (受理される) 
    bool accept(int v) {
        return nodes[v].drct != ROOT or not nodes[v].ids.empty();
    }
    vector<int> match(int v) {
        vector<int> res;
        while(v != ROOT) {
            for(int id : nodes[v].ids) res.push_back(id);
            v = nodes[v].drct;
        }
        return res;
    }
    vector<vector<int>> search(const string& s) {
        vector<vector<int>> res;
        int now = ROOT;
        for(char c : s) {
            now = next(now, c);
            res.emplace_back(match(now));
        }
        return res;
    }
};
