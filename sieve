vector<int> pr, lp;

void sieve(int N = 1e6 + 5){
    lp.resize(N, 0);
    for(int i = 2; i < N; i++){
        if(!lp[i]){
            lp[i] = i;
            pr.push_back(i);
        }
        for(auto j : pr){
            if(j > lp[i] || i * j >= N) break;
            lp[i * j] = j;
        }
    }
}
