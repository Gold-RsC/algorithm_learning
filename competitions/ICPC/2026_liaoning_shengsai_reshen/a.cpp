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
#include <limits>
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
const int N = 5e3 + 5;
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head;
void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}

int n;
pair<int, int> bird[N];
pair<int, int> food[N];
int g[N][N];
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
bool is_valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= 5000 && y <= 5000;
}
vector<int> match;
vector<int> visited;
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

void solve() {
    for (int i = 1; i <= n; ++i) {
        auto [x, y] = bird[i];
        g[x][y]     = 0;
    }
    for (int i = 1; i <= n; ++i) {
        auto [x, y] = food[i];
        g[x][y]     = 0;
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x][y] = i;
        bird[i] = {x, y};
    }
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x][y] = -i;
        food[i] = {x, y};
    }

    init_edge(n * 2 + 1);
    for (int i = 1; i <= n; ++i) {
        for (int d = 0; d < 4; ++d) {
            auto [x, y] = food[i];
            x += dir[d][0];
            y += dir[d][1];
            while (is_valid(x, y) && g[x][y] > 0) {
                add_edge(g[x][y], i + n);
                x += dir[d][0];
                y += dir[d][1];
            }
        }
    }

    match.assign(n * 2 + 1, 0);
    for (int i = 1; i <= n; ++i) {
        visited.assign(n * 2 + 1, 0);
        if (!dfs(i)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
