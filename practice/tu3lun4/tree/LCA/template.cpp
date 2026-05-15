#include <iostream>
#include <iomanip>
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
const int N    = 1e5 + 5;
const int LOGN = 20;
struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);

int n;

void init_edge() {
    edge.clear();
    fill(head.begin(), head.end(), -1);
}
void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}

bool find_edge(int u, int v) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        if (edge[i].to == v) {
            return true;
        }
    }
    return false;
}


/**
 * @brief 树的直径
 * @details 树形dp
 * @param d[x]: 以x节点为根节点，向下延申可形成的最长距离
 * @param ans: 经过x节点形成的最长直径
 */
int d[N];
int ans;
void dp(int u) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;

        dp(v);

        // 这里的d[u]为1-(i-1)内的最大向下距离
        ans  = max(ans, d[u] + d[v] + w);
        d[u] = max(d[u], d[v] + w);
    }
}


/**
 * @brief LCA
 * @details 树上倍增
 * @details 预处理O(nlogn)，询问O(logn)
 * @param f[x][k]:表示x的2^k辈祖先
 * @param d[x]:表示x深度
 */

int f[N][LOGN];
int d[N];


void prework() {
    queue<int> q;
    q.push(1);
    int t = (int)(log(n) / log(2)) + 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;

            q.push(v);

            d[v] = d[u] + 1;

            f[v][0] = u;
            for (int j = 1; j <= t; ++j) {
                f[v][j] = f[f[v][j - 1]][j - 1];
            }
        }
    }
}
int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    int t = (int)(log(n) / log(2)) + 1;

    for (int i = t; i >= 0; --i) {
        if (d[f[y][i]] >= d[x]) {
            y = f[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = t; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
