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

const int N = 50;
int n;
int weight[N][N];

/**
 * @name Floyd#1
 * @details time O(n^3), spaceO(n^3),
 * @details 适用于所有图，无关边权正负
 */
// f[k][x][y]:=只允许经过1-k，x->y的最短路
int f[N][N][N];
// f[k][x][y]=min(f[k-1][x][y],f[k-1][x][k]+f[k-1][k][y])
void Floyd1() {
    for (int k = 1; k <= n; ++k) {
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                f[k][x][y] =
                    min(f[k - 1][x][y],
                        f[k - 1][x][k] + f[k - 1][k][y]);
            }
        }
    }
}

/**
 * @name Floyd#2
 * @details time O(n^3), spaceO(n^2),
 * @brief 压缩一个维度
 * @details 适用于所有图，无关边权正负
 */
// f[x][y]:=x->y的最短路
int f[N][N];
void Floyd2() {
    for (int k = 1; k <= n; ++k) {
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
        }
    }
}

/**
 * @name Bellman_Ford
 * @details time O(nm) space O(n)
 * @details 适用于正负边权的图，可以判断无最短路的情况
 */
struct Edge {
    int u, v, w;
};
vector<Edge> edge;
int dis[N];
const int INF = 0x3f3f3f3f;
// dis[v]=min(dis[v],dis[u]+w[u][v])
bool Bellman_Ford(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));
    // 将源点记为0
    dis[s] = 0;
    // flag:=判断一轮中有没有松弛操作
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        flag = false;
        for (int j = 0; j < edge.size(); ++j) {
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (dis[u] == INF) {
                continue;
            }
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                // 有松弛操作
                flag = true;
            }
        }
        // 没有松弛操作就退出
        if (!flag) {
            break;
        }
    }
    // 正常来说n-1轮已经结束，该返回false
    // 但是若经过n轮后仍可以松弛，则说明达到了一个负环
    return flag;
}

/**
 * @name SPFA
 * @details time<=O(nm) space O(n)
 * @brief Bellman_Ford的队列优化，
 *        很多时候我们并不需要那么多无用的松弛操作．
 *        很显然，只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作
 * @details 适用于正负边权的图，可以判断无最短路的情况
 */
struct Edge {
    int u, v, w;
};
vector<Edge> edge;
int dis[N];
// 和一般标记法不一样，只记录是否在队伍中，允许重复入队
bool vis[N];
int cnt[N];
const int INF = 0x3f3f3f3f;
queue<int> q;
// dis[v]=min(dis[v],dis[u]+w[u][v])
bool SPFA(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));
    // 将源点距离记为0
    dis[s] = 0;
    vis[s] = 1;
    // bfs
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 允许节点反复入列
        vis[u] = 0;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                // 无负环时最多n-1条边
                if (cnt[v] >= n) {
                    // 检测到负环
                    return true;
                }

                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}

/**
 * @name Dijkstra#1
 * @details time O(n^2)
 * @details 只允许非负权图
 */
struct Edge {
    int v, w;
};
vector<Edge> edge[N];
int dis[N];
bool vis[N];

void Dijkstra1(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));

    dis[s] = 0;

    for (int i = 1; i <= n; ++i) {
        int u        = 0;
        int last_min = INF;
        // 找到最短路
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dis[j] < last_min) {
                u        = j;
                last_min = dis[j];
            }
        }
        // 与前面算法不同的是
        // 由于讨论的是正权边，一定不可能需要环
        // 所以不用重复走
        vis[u] = true;

        // 以u为起始点，进行松弛操作
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
}

/**
 * @name Dijkstra#2
 * @details time O(m logn)
 * @brief 用优先队列进行优化
 * @details 只允许非负权图
 */
struct Edge {
    int v, w;
};
struct Node {
    int dis, u;
    bool operator>(const Node& a) {
        return dis > a.dis;
    }
};
vector<Edge> edge[N];
int dis[N];
bool vis[N];
priority_queue<Node, vector<Node>, greater<Node>> pq;

void Dijkstra2(int s) {
    memset(dis, 0x3f, (n + 1) * sizeof(dis[0]));

    dis[s] = 0;

    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().u;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (auto ed : edge[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
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
