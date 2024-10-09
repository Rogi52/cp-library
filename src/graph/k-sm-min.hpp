template < class Cost, Cost INF > class k_sm_min {
  public:
    int n;
    vector<int> k;
    vector<vector<int>> id;
    Cost c0;
    vector<vector<Cost>> c1;
    vector<vector<vector<vector<Cost>>>> c2;
    sm_min< Cost > sm;
    
    k_sm_min(int n, vector<int> k) : n(n), k(k), id(n), c0(0), c1(n), c2(n) {
        int m = 0;
        for(int i = 0; i < n; i++) {
            id[i].resize(k[i] - 1);
            for(int f = 0; f < k[i] - 1; f++) id[i][f] = m++;
        }
        sm = sm_min< Cost >(m);
        for(int i = 0; i < n; i++) {
            c1[i].resize(k[i], 0);
            c2[i].resize(n);
            for(int j = 0; j < n; j++) {
                c2[i][j].resize(k[i]);
                for(int f = 0; f < k[i]; f++) c2[i][j][f].resize(k[j]);
            }
        }
    }
    void add_0(Cost cost) {
        c0 += cost;
    }
    void add_1(int i, int f, Cost cost) {
        c1[i][f] += cost;
    }
    void add_2(int i, int f, int j, int g, Cost cost) {
        c2[i][j][f][g] += cost;
    }

    Cost answer() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                auto& c = c2[i][j];

                for(int f = 0; f < k[i]; f++) {
                    const Cost d = c[f][0];
                    add_1(i, f, d);
                    for(int g = 0; g < k[j]; g++) c[f][g] -= d;
                }
                for(int g = 0; g < k[j]; g++) {
                    const Cost d = c[0][g];
                    add_1(j, g, d);
                    for(int f = 0; f < k[i]; f++) c[f][g] -= d;
                }

                for(int f = 0; f < k[i] - 1; f++) {
                    for(int g = 0; g < k[j] - 1; g++) {
                        sm.add_2(id[i][f], 0, id[j][g], 0, c[f + 1][g + 1] - c[f + 1][g] - c[f][g + 1] + c[f][g]);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            auto& c = c1[i];
            for(int f = 1; f + 1 < k[i]; f++) {
                sm.add_2(id[i][f - 1], 1, id[i][f], 0, INF);
            }
            for(int f = 1; f < k[i]; f++) {
                sm.add_1(id[i][f - 1], 1, c[f - 1] - c[f]);
            }
            add_0(c[k[i] - 1]);
        }

        sm.add_0(c0);
        return sm.answer();
    }
};
