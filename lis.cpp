int LIS(vector<int> &a) {
    vector<int> s;
    for (auto i: a) {
        auto k = lower_bound(a.begin(), a.end(), i);
        if (k == s.end())
            s.push_back(i);
        else
            *k = i;
    }
    return s.size();
}
