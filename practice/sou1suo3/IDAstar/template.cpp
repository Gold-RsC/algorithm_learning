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


/**
 * @brief Dijkstra版的A*算法+迭代加深
 */
struct Edge {
    int v, w;
};
// dis=g[u]+w+h[v]
struct Node {
    int dis, u;
    bool operator>(const Node& a) const {
        return dis > a.dis;
    }
};
vector<Edge> edge[N];
int dis[N];
bool vis[N];
priority_queue<Node, vector<Node>, greater<Node>> pq;

int limit;
bool IDAstar(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));

    dis[s] = 0;

    pq.push({h[0], s});

    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        if (dis[u] + h[u] > limit) {
            return false;
        }
        vis[u] = 1;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v] + h[v], v});
            }
        }
    }
}

void solve() {
    while () {
        reset();
        if (!IDAstar(s)) {
            limit *= 1.5;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
