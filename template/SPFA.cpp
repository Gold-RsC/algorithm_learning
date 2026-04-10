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
struct Edge {
    int v, w;
};
int n;
vector<Edge> edge[N];
int dis[N];
int cnt[N];
bool vis[N];

queue<int> q;
bool SPFA(int s) {
    memset(dis, 0x3f, (n + 1) * (sizeof(dis[0])));

    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : edge[u]) {
            int v = e.v, w = e.w;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    return true;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
