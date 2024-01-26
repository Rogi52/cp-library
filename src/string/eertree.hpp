template < class char_type > struct eertree {
    using size_type = int;
    struct node_type {
        map<char_type, size_type> nxt;
        size_type link, len, count;

        node_type(size_type link, size_type len, size_type count) : link(link), len(len), count(count) {}
    };

    size_type lsp;
    vector<char_type> s;
    vector<node_type> g;

    eertree() : lsp(0) {
        g.emplace_back(0, -1, 0); // odd
        g.emplace_back(0,  0, 0); // even
    }

    // return node(c + str(?) + c)
    size_type find(size_type v) const {
        const size_type n = s.size() - 1;
        while(true) {
            const size_type i = n - g[v].len - 1;
            if(0 <= i and s[i] == s[n]) return v;
            v = g[v].link;
        }
    }

    void push_back(const char_type c) {
        s.push_back(c);
        const size_type v = find(lsp);

        if(g[v].nxt.contains(c)) {
            lsp = g[v].nxt[c];
            g[lsp].count++;
        } else {
            lsp = g[v].nxt[c] = g.size();
            g.emplace_back(v == 0 ? 1 : g[find(g[v].link)].nxt[c], 1 + g[v].len + 1, 1);
        }
    }

    vector<size_type> freq() const {
        vector<size_type> freq(g.size(), 0);
        for(size_type i = size_type(g.size()) - 1; i > 0; i--) {
            freq[i] += g[i].count;
            freq[g[i].link] += freq[i];
        }
        return freq;
    }

    string str(size_type v) const {
        if(v == 0) return "odd(-1)";
        if(v == 1) return "even(0)";
        string res = "";
        function<bool(size_type)> dfs = [&](size_type x) -> bool {
            if(x == v) return true;
            for(auto [c, nx] : g[x].nxt) {
                if(dfs(nx)) {
                    res.push_back(c);
                    return true;
                }
            }
            return false;
        }; dfs(0); dfs(1);
        string rr = res; reverse(rr.begin(), rr.end());
        if(g[v].len % 2 == 1) rr.pop_back();
        return res + rr;
    }
};
