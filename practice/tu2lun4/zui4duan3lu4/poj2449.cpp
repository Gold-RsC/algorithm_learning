/*
# U644844 poj2449 第k短路

## 题目描述

给定一张 n 个点 m 条边的有向图，求从起点 s 到终点 t 的第 k 短路的长度（允许重复经过边）。如果第 k 短路不存在，则输出
-1。

## 输入格式

第一行包含两个整数 n, m，表示点数和边数。
接下来 m 行，每行包含三个整数 u, v, w，表示一条从 u 到 v 的长度为 w 的有向边。
最后一行包含三个整数 s, t, k，表示起点、终点和第 k 短路。

## 输出格式

输出一个整数，表示从 s 到 t 的第 k 短路的长度。如果不存在，输出 -1。

## 输入输出样例 #1

### 输入 #1

```
2 2
1 2 5
2 1 4
1 2 2
```

### 输出 #1

```
14
```
*/
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
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define int long long
const int N   = 1e3;
const int INF = 0x3f3f3f3f;
struct Edge {
    int v;
    int w;
};
vector<Edge> edge[N];
vector<Edge> fedge[N];
int n, m;

void add_edge(int u, int v, int w) {
    edge[u].push_back({v, w});

    fedge[v].push_back({u, w});
}


struct Node {
    int u;
    int dis;
    bool operator>(const Node& a) const {
        return dis > a.dis;
    }
};

int dis[N];
bool vis[N];
priority_queue<Node, vector<Node>, greater<Node>> pq;

void dijkstra(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));

    dis[s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto e : fedge[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}
// f=g+h
// dis=h
int astar(int s, int t, int k) {
    if (dis[s] == INF) {
        return -1;
    }
    // pii=<h+g+w,{g+w,u}>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({dis[s], {0, s}});
    int cnt = 0;

    while (!pq.empty()) {
        auto [f, state] = pq.top();
        pq.pop();
        auto [g, u] = state;
        if (u == t) {
            cnt++;
            if (cnt == k)
                return g;
        }

        for (auto& e : edge[u]) {
            int v = e.v, w = e.w;
            int h = dis[v];
            pq.push({g + w + h, {g + w, v}});
        }
    }
    return -1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 正反图
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    // 反图的dijkstra
    int s, t, k;
    cin >> s >> t >> k;
    dijkstra(t);

    cout << astar(s, t, k) << endl;

    return 0;
}
