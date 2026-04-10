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

const int N   = 16;
const int INF = 0x3f3f3f3f;

int n;
int hp;
int m;
int hurt[N];
struct Edge {
    int v, w;
};
vector<Edge> edge[N];

int dis[1 << N][N][105];
bool vis[N];


struct State {
    int S, pos, heart, time;
    bool operator>(const State& a) const {
        return this->time > a.time;
    }
};
int killcost[1 << N][N];

priority_queue<State, vector<State>, greater<State>> pq;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ////////////////////////////////////////
    // 输入+存储
    cin >> n >> m >> hp;
    for (int i = 0; i < n; ++i) {
        cin >> hurt[i];
    }
    // 标准的邻接链表存储法
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    //////////////////////////////////
    // 预处理一个常量数组
    for (int S = 0; S <= (1 << n); S++) {
        for (int u = 0; u < n; u++) {
            if (S >> u & 1)
                continue;
            int damage = 0;
            for (auto [v, w] : edge[u]) {
                if (!(S >> v & 1)) {
                    damage += hurt[v];
                }
            }
            killcost[S][u] = damage;
        }
    }

    ////////////////////////////////////////////
    // dijkstra algorithm
    // 1.初始化为INF
    for (int u = 1; u <= (1 << n); ++u) {
        for (int v = 0; v < n; ++v) {
            for (int h = 0; h <= hp; ++h) {
                dis[u][v][h] = INF;
            }
        }
    }


    int ans = INF;

    // 2.处理第一个点，塞入priority_queue
    int startS = 0;
    int startH = hp - killcost[0][0];
    if (startH > 0) {
        dis[1 << 0][0][startH] = 0;
        pq.push({1 << 0, 0, startH, 0});
    }
    // 3.bfs查找最优路径
    while (!pq.empty()) {
        // 4.获取堆顶元素
        State cur = pq.top();
        pq.pop();
        int S = cur.S;
        int u = cur.pos;
        int h = cur.heart;
        int t = cur.time;

        // 5.剪枝：没有前一个答案更优，则直接剪枝
        if (t > ans) {
            continue;
        }
        // 5.剪枝：相同状态下时间更长，则直接剪枝
        if (t > dis[S][u][h]) {
            continue;
        }
        // 6.剪枝完立即看是不是终点状态：把怪物全杀了&&到达了终点&&还有生命值
        if (S == (1 << n) - 1 && u == n - 1 && h > 0) {
            ans = min(ans, t);
            continue;
        }

        // 7.在continue的情况后再进行本点的处理
        if (!(S & (1 << u))) {
            int damage   = killcost[S][u];
            int nowheart = h - damage;
            if (nowheart > 0) {
                int nowS = S | (1 << u);
                if (t < dis[nowS][u][nowheart]) {
                    dis[nowS][u][nowheart] = t;
                    pq.push({nowS, u, nowheart, t});
                }
            }
        }
        // 8.标准dijkstra后续处理
        for (auto e : edge[u]) {
            int v = e.v;
            int w = e.w;

            if (dis[S][v][h] > t + w) {
                dis[S][v][h] = t + w;
                pq.push({S, v, h, t + w});
            }
        }
    }

    cout << (ans == INF ? -1 : ans);
    return 0;
}
