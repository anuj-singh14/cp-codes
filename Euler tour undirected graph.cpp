#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 3e5 + 5;

vector<pair<int, int>> adj[N];
vector<int> vis(N), ans;

void dfs(int x) {
    while (adj[x].size()) {
        auto [v, i] = adj[x].back(); adj[x].pop_back();
        if (vis[i])
            continue;
        vis[i] = 1;
        dfs(v);
        ans.push_back(x);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    ans.push_back(1);
    dfs(1);
    if (ans.size() < m + 1) 
        cout << "IMPOSSIBLE";
    else
        for (auto i: ans)
            cout << i << ' ';
}
