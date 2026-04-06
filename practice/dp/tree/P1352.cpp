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

const int N = 6e3 + 5;
int n;
char r[N];

struct Edge {
    int to;
    int next;
};
vector<Edge> edge;
int head[N];
bool isnt_root[N];
vector<bool> visited;


int dp[N][2];
/**
 * dp[i][0]=sum(max(dp[son][1],dp[son][0]))
 * dp[i][1]=sum(dp[son][0])+r[i]
 */
void dfs(int u) {
    if (visited[u]) {
        cerr << "???";
        return;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        dfs(edge[i].to);
        dp[u][0] +=
            max(dp[edge[i].to][1], dp[edge[i].to][0]);
        dp[u][1] += dp[edge[i].to][0];
    }
    dp[u][1] += r[u];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    visited.resize(N);
    for (int i = 1; i <= n; ++i) {
        int _r;
        cin >> _r;
        r[i]    = _r;
        head[i] = -1;
    }


    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> v >> u;

        edge.push_back({v, head[u]});
        head[u] = edge.size() - 1;

        isnt_root[v] = true;
    }

    for (int u = 1; u <= n; ++u) {
        if (!isnt_root[u]) {
            // cerr << "ss" << u;
            dfs(u);
            cout << max(dp[u][0], dp[u][1]);
        }
    }


    return 0;
}
