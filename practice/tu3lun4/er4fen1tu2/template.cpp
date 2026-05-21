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


struct Edge {
    int next;
    int to;
    int weight;
};
vector<Edge> edge;

vector<int> head(N, -1);

void add_edge(int u, int v, int w) {
    edge.push_back({head[u], v, w});
    head[u] = edge.size() - 1;
}

/**
 * @brief 二分图的染色判定法
 */
int color[N];
bool dfs_color(int u, int c) {
    color[u] = c;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        int w = edge[i].weight;
        if (color[v] == 0) {
            if (!dfs_color(v, 3 - c)) {
                return false;
            }
        }
        else if (color[v] == c) {
            return false;
        }
    }
    return true;
}
bool judge() {
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (!dfs_color(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 二分图的最大匹配
 * @brief 匈牙利算法
 * @return 最大匹配数
 */
int match[N];
int visited[N];
bool dfs(int u) {
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;

        if (!visited[v]) {
            visited[v] = true;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int Hungarian() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) {
            ans++;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
