vector<int> dijkstra(int src, vector<pair<int, int>> adj[]) {
    vector<int> dis(n + 1, 1e17);
    set<pair<int, int>> s;
    s.insert({0, src});
    dis[src] = 0;
    while (s.size()) {
        auto [w, x] = *s.begin(); s.erase(s.begin());
        for (auto &[i, j]: adj[x]) {
            if (dis[i] <= w + j) {
                continue;
            }
            if (dis[i] != 1e17) {
                s.erase({dis[i], i});
            }
            dis[i] = w + j;
            s.insert({dis[i], i});
        }
    }
    return dis;
};
