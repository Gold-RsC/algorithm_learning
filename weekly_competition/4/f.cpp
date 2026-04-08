// ai写的，通过了，之后详细分析一下
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


struct State {
    int S, u, h, t;
    bool operator>(const State& other) const {
        return t > other.t;
    }
};

int N, M, HP;

const int INF = 1e9;

int ans = INF;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> HP;

    vector<int> hurt(N);
    for (int i = 0; i < N; i++)
        cin >> hurt[i];

    vector<vector<pair<int, int>>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 预处理 killCost[S][u]
    vector<vector<int>> killCost(1 << N, vector<int>(N, 0));

    for (int S = 0; S < (1 << N); S++) {
        for (int u = 0; u < N; u++) {
            if (S >> u & 1)
                continue;  // 还没杀 u 时才需要计算
            int damage = 0;
            for (auto [v, w] : g[u]) {
                if (!(S >> v & 1)) {  // v 还没被杀
                    damage += hurt[v];
                }
            }
            killCost[S][u] = damage;
        }
    }

    // Dijkstra
    // dist[S][u][h] 初始 INF

    vector<vector<vector<int>>> dist(
        1 << N,
        vector<vector<int>>(N, vector<int>(HP + 1, INF)));
    priority_queue<State, vector<State>, greater<State>> pq;

    int startS = 0;                    // 还没杀任何怪
    int startH = HP - killCost[0][0];  // 先杀 0 号
    if (startH > 0) {
        dist[1 << 0][0][startH] = 0;
        pq.push({1 << 0, 0, startH, 0});
    }


    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        int S = cur.S, u = cur.u, h = cur.h, t = cur.t;
        if (t > dist[S][u][h])
            continue;

        if (S == (1 << N) - 1 && u == N - 1 && h > 0) {
            ans = min(ans, t);
            continue;
        }

        // 1. 杀当前点 u（如果还没杀）
        if (!(S >> u & 1)) {
            int damage = killCost[S][u];
            int nh     = h - damage;
            if (nh > 0) {
                int nS = S | (1 << u);
                if (t < dist[nS][u][nh]) {
                    dist[nS][u][nh] = t;
                    pq.push({nS, u, nh, t});
                }
            }
        }

        // 2. 移动到邻居 v
        for (auto [v, w] : g[u]) {
            int nt = t + w;
            if (nt < dist[S][v][h]) {
                dist[S][v][h] = nt;
                pq.push({S, v, h, nt});
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
