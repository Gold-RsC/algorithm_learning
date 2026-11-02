#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;
vector<int> head;
vector<int> in_degree;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
    in_degree.assign(n + 1, 0);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
    ++in_degree[v];
}
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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}
