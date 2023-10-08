class fente2d {
public:
    int n, m;
    vector<vector<int>> tree;

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        tree.resize(n + 5, vector<int>(m + 5, 0));
    }

    void update(int x, int y, int inc) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                tree[i][j] += inc;
            }
        }
    }

    int query_pref(int x, int y) {
        int tot = 0;
        for (int i = x; i >= 1; i -= i & -i) {
            for (int j = y; j >= 1; j -= j & -j) {
                tot += tree[i][j];
            }
        }
        return tot;
    }


    int query(int x1, int y1, int x2, int y2) {
        int tot = query_pref(x2,y2);
        tot -= query_pref(x2,y1-1);
        tot -= query_pref(x1-1,y2);
        tot += query_pref(x1-1,y1-1);
        return tot;
    }
};