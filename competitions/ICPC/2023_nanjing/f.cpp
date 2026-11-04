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
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head;
vector<int> in_degree;
namespace std {
template <>
struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) + 0x9e3779b9 + (p.first << 6) + (p.first >> 2));
    }
};
}  // namespace std
unordered_set<pair<int, int>> hs;

void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
    in_degree.assign(n + 1, 0);
    hs.clear();
}
void add_edge(int u, int v) {
    if (hs.count({u, v})) {
        return;
    }
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
    ++in_degree[v];
    hs.insert({u, v});
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> b(m + 1);


    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        for (int j = 1; j <= p; ++j) {
            int bb;
            cin >> bb;
            b[bb].push_back(i);
        }
    }

    init_edge(n);
    for (int i = 1; i <= m; ++i) {
        if (b[i].size() >= 2) {
            int v = b[i].back();
            for (int j = 0; j + 1 < b[i].size(); ++j) {
                int u = b[i][j];
                add_edge(u, v);
            }
        }
    }

    priority_queue<int> s;
    vector<int> ans;
    bool flag = false;
    vector<int> q;

    for (int i = n; i >= 1; --i) {
        if (!in_degree[i]) {
            // cerr << "[!] " << i << endl;
            s.push(i);
        }
    }
    if (s.size() >= 2) {
        flag = true;
    }
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        ans.push_back(u);
        // cerr << "[?] " << u << " ";
        // for (auto x : ans) {
        //     // cerr << x << " ";
        // }
        // cerr << endl;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            --in_degree[v];
            if (!in_degree[v]) {
                s.push(v);
            }
        }

        if (s.size() >= 2) {
            flag = true;
        }
    }

    if (flag) {
        cout << "Yes\n";
        for (int i = 0; i + 1 < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans.back() << '\n';
    }
    else {
        cout << "No\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
