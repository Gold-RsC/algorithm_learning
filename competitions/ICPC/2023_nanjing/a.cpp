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
#include <limits.h>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head;
vector<int> degree;

void init_edge(int n) {
    edge.clear();
    head.assign(n + 1, -1);
    degree.assign(n + 1, 0);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
    degree[v]++;
    // cerr << "add: " << u << " " << v << endl;
}

struct structure {
    int X, Y;
    int sz;
    vector<vector<pair<int, int>>> g;
    structure(int x, int y)
        : X(x),
          Y(y),
          sz(0),
          g(x + 1) {
    }
    bool in(const structure& another) const {
        if (X > another.X || Y > another.Y) {
            return false;
        }

        for (int offset_x = 0; offset_x <= another.X - X; ++offset_x) {
            for (int offset_y = 0; offset_y <= another.Y - Y; ++offset_y) {
                for (int x = 1; x <= X; ++x) {
                    int another_x = x + offset_x;

                    for (int i = 0, j = 0; i < g[x].size(); ++i) {
                        auto& another_g_x = another.g[another_x];
                        while (j < another_g_x.size() && (another_g_x[j].second < g[x][i].first + offset_y)) {
                            ++j;
                        }
                        if (j == another_g_x.size()) {
                            goto next;
                        }
                        if (another_g_x[j].first <= g[x][i].first + offset_y &&
                            another_g_x[j].second >= g[x][i].second + offset_y) {
                            continue;
                        }
                        goto next;
                    }
                }
                return true;
            next:;
            }
        }
        return false;
    }
    bool operator==(const structure& another) const {
        return X == another.X && Y == another.Y && sz == another.sz && g == another.g;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n + 1, vector<char>(m + 1, 0));
    vector<vector<int>> biaoji(n + 1, vector<int>(m + 1, 0));
    vector<int> x_left;
    vector<int> y_left;

    int biaoji_cnt = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> graph[i][j];
        }
    }
    vector<pair<structure, bool>> s;
    auto dfs = [&](auto&& dfs, int i, int j, int& xl, int& xr, int& yl, int& yr) {
        if (i < 1 || i > n || j < 1 || j > m) {
            return;
        }
        if (graph[i][j] != '.') {
            return;
        }
        graph[i][j]  = ' ';
        biaoji[i][j] = biaoji_cnt;

        xl = min(xl, i);
        xr = max(xr, i);
        yl = min(yl, j);
        yr = max(yr, j);

        dfs(dfs, i - 1, j, xl, xr, yl, yr);
        dfs(dfs, i, j - 1, xl, xr, yl, yr);
        dfs(dfs, i, j + 1, xl, xr, yl, yr);
        dfs(dfs, i + 1, j, xl, xr, yl, yr);
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (graph[i][j] == '.') {
                biaoji_cnt = s.size() + 1;
                int xl = LLONG_MAX, xr = 0, yl = LLONG_MAX, yr = 0;
                dfs(dfs, i, j, xl, xr, yl, yr);
                x_left.push_back(xl);
                y_left.push_back(yl);
                structure stru(xr - xl + 1, yr - yl + 1);
                s.push_back({stru, false});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (biaoji[i][j]) {


                auto& stru = s[biaoji[i][j] - 1].first;
                int x_ref  = i - x_left[biaoji[i][j] - 1] + 1;
                int y_ref  = j - y_left[biaoji[i][j] - 1] + 1;
                ++stru.sz;

                if (stru.g[x_ref].empty()) {
                    stru.g[x_ref].push_back({y_ref, y_ref});
                }
                else if (stru.g[x_ref].back().second == y_ref - 1) {
                    stru.g[x_ref].back().second = y_ref;
                }
                else {
                    stru.g[x_ref].push_back({y_ref, y_ref});
                }
            }
        }
    }

    sort(s.begin(), s.end(), [&](const pair<structure, bool>& a, const pair<structure, bool>& b) {
        if (a.first.X != b.first.X) {
            return a.first.X < b.first.X;
        }
        return a.first.Y < b.first.Y;
    });
    // for (auto& [stru, _] : s) {
    //     cerr << "----" << endl;
    //     cerr << stru.X << " " << stru.Y << endl;
    //     for (int i = 1; i <= stru.X; ++i) {
    //         cerr << i << ": ";
    //         for (auto& [b, e] : stru.g[i]) {
    //             cerr << "[" << b << " " << e << "],";
    //         }
    //         cerr << endl;
    //     }
    // }

    init_edge(s.size());
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i].first == s[j].first) {
                add_edge(i, j);
                add_edge(j, i);
            }
            else if (s[i].first.in(s[j].first)) {
                add_edge(j, i);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (degree[i]) {
            continue;
        }
        ans += s[i].first.sz;
    }
    cout << ans << '\n';
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
