#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
const int N   = 1e3;
const int INF = 0x3f3f3f3f;
int n;
struct Edge {
    int v, w;
};
struct Node {
    int u;
    int dis;
    bool operator>(const Node& a) {
        return dis > a.dis;
    }
};
vector<Edge> edge[N];
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
        for (auto e : edge[u]) {
            int v = e.v, w = e.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
