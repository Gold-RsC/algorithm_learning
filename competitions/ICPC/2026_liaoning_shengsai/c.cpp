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
const int N   = 1e3 + 5;
const int INF = 2e6 + 5;


char g[N][N];
int dis[N][N];


struct Point {
    int x, y;
};
int n, m;
int dir[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
bool is_valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}
void bfs(Point s) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dis[i][j] = INF;
        }
    }
    queue<Point> q;
    q.push(s);
    dis[s.x][s.y] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            auto [dx, dy] = dir[d];
            if (is_valid(x + dx, y + dy) && dis[x + dx][y + dy] > dis[x][y] + 1 && g[x + dx][y + dy] != '#') {
                dis[x + dx][y + dy] = min(dis[x][y] + 1, dis[x + dx][y + dy]);
                q.push({x + dx, y + dy});
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    Point S, E, o, _;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                S = {i, j};
            }
            else if (g[i][j] == 'E') {
                E = {i, j};
            }
            else if (g[i][j] == '_') {
                _ = {i, j};
            }
            else if (g[i][j] == 'o') {
                o = {i, j};
            }
        }
    }
    bfs(S);
    int d1 = dis[E.x][E.y];
    int d2 = dis[o.x][o.y];
    bfs(_);
    int d3 = dis[o.x][o.y];
    int d4 = dis[E.x][E.y];

    int ans = min({d1, d2 + d3 + 2, d3 + d4 + 1, d2 + d4 + 1});
    // cerr << "[] " << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << endl;
    if (ans == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
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
