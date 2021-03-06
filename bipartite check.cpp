const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N], col[N];

//returns 0 if graph isn't bipartite, else assigns colors such that vertices with same color will lie in same partition
bool dfs(int x){
    vis[x] = 1;
    for(auto &i: adj[x]){
        if(vis[i]){
            if(col[i] == col[x])    return 0;
            continue;
        }
        col[i] = 1 - col[x];
        if(!dfs(i)) return 0;   
    }
    return 1;
}
