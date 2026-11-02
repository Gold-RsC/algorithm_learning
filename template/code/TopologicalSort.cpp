/**
 * @brief 拓扑排序
 * @note  能拓扑排序与DAG互为充分必要
 * @return 是否为DAG
 */
// Kahn算法
bool topological_sort() {
    queue<int> s;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!in_degree[i]) {
            s.push(i);
        }
    }
    while (!s.empty()) {
        int u = s.front();
        s.pop();
        ans.push_back(u);
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            --in_degree[v];
            if (!in_degree[v]) {
                s.push(v);
            }
        }
    }
    if (ans.size() == n) {
        for (auto i : ans) {
            cout << i << ' ';
        }
        return true;
    }
    return false;
}
