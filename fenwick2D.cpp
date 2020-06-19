struct fenwick2D {
    int N, M;
    vector<vector<int>> Bit;
 
    fenwick2D(int n = 1e3, int m = 1e3) {
        init(n, m);
    }
 
    void init(int n, int m) {
        N = n, M = m;
        n += 5; m += 5;
        Bit.assign(n, vector<int> (m));
    }
    
    int next(int n) { return n & -n; }
 
    void update(int x, int y, int add) {
        for (int i = x; i <= N; i += next(i))
            for (int j = y; j <= M; j += next(j))
                Bit[i][j] += add;
    }
 
    int query(int x, int y) { 
        int res = 0;
        for (int i = x; i; i -= next(i))
            for (int j = y; j; j -= next(j))
                res += Bit[i][j];
        return res;
    }
 
    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};
