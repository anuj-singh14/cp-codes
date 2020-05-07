struct fenwick{
    int N;
    vector<int> Bit;

    fenwick(int n = 1e5){
        init(n);
    }

    void init(int n){
        N = n;
        n += 5;
        Bit.resize(n, 0);
    }
    
    void update(int id, int val){
        while(id <= N){
            Bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id){
        int res = 0;
        while(id){
            res += Bit[id];
            id -= id & -id;
        }
        return res;
    }

    int query(int l, int r){
        return query(r) - query(l - 1);
    }
};
