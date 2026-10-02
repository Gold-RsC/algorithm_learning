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
 * @brief Dijkstra°æµÄA*Ëã·¨
 */
struct Edge {
    int v, w;
};
// dis[v]=g[v]+h[v]
struct Node {
    int dis, u;
    bool operator>(const Node& a) const {
        return dis > a.dis;
    }
};
vector<Edge> edge[N];
int g[N];
bool vis[N];
priority_queue<Node, vector<Node>, greater<Node>> pq;

void Astar(int s) {
    memset(g, 0x3f, sizeof(g));

    g[s] = 0;

    pq.push({h[0], s});

    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            if (g[v] > g[u] + w) {
                g[v] = g[u] + w;
                pq.push({g[v] + h[v], v});
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
