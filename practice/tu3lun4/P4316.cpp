#include <iostream>
#include <iomanip>
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

const int N = 1e5 + 10;
struct Edge {
    int to;
    int weight;
};
vector<Edge> edge[N];

double dp[N];
bool visited[N];

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;

    for (auto e : edge[u]) {
        dfs(e.to);
        dp[u] += (dp[e.to] + e.weight) / edge[u].size();
    }
}

double ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    dfs(1);

    cout << fixed << setprecision(2) << dp[1];
    // for (int i = 1; i <= n; ++i) {
    //     cerr << dp[i] << endl;
    // }
    return 0;
}
