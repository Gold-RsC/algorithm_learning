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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

struct structure {
    int X, Y;
    int sz;
    vector<vector<pair<int, int>>> g;
    structure(int x, int y)
        : g(X + 1) {
    }
    bool in(const structure& another) const {
        if (X > another.X || Y > another.Y) {
            return false;
        }

        for (int offset_x = 0; offset_x < another.X - X; ++offset_x) {
            for (int offset_y = 0; offset_y < another.Y - Y; ++offset_y) {
                for (int x = 1; x <= X; ++x) {
                    for (int i = 0, j = 0; i < g[x + offset_x].size();) {
                        if (j >= another.g[x].size()) {
                            return false;
                        }
                        else if (g[x + offset_x][i].first <= another.g[x][j].second ||
                                 g[x + offset_x][i].second >= another.g[x][j].first) {
                            return false;
                        }
                        else if (g[x + offset_x][i].first >= another.g[x][j].first &&
                                 g[x + offset_x][i].second <= another.g[x][j].second) {
                            ++i;
                        }

                        else {
                            ++j;
                        }
                    }
                }
            }
        }
        return true;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n + 1, vector<char>(m + 1, 0));
    vector<vector<int>> biaoji(n + 1, vector<int>(m + 1, 0));

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
                structure stru(xr - xl + 1, yr - yl + 1);
                s.push_back({stru, false});
            }
        }
    }
    cerr << "ddd" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (biaoji[i][j]) {
                cerr << "?" << endl;
                ++s[biaoji[i][j] - 1].first.sz;
                if (s[biaoji[i][j] - 1].first.g[i].empty()) {
                    s[biaoji[i][j] - 1].first.g[i].push_back({j, j});
                }
                else if (s[biaoji[i][j] - 1].first.g[i].back().second == j - 1) {
                    s[biaoji[i][j] - 1].first.g[i].back().second = j;
                }
                else {
                    s[biaoji[i][j] - 1].first.g[i].push_back({j, j});
                }
                cerr << "!" << endl;
            }
        }
    }
    cerr << "ccc" << endl;
    sort(s.begin(), s.end(), [&](const pair<structure, bool>& a, const pair<structure, bool>& b) {
        if (a.first.X != b.first.X) {
            return a.first.X < b.first.X;
        }
        return a.first.Y < b.first.Y;
    });
    int ans_cnt = s.size();
    for (int i = 0; i < s.size(); ++i) {
        if (s[i].second) {
            continue;
        }
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i].second || s[j].second) {
                continue;
            }
            if (s[i].first.in(s[j].first)) {
                s[i].second = true;
                ans_cnt--;
            }
        }
    }
    if (ans_cnt == 1) {
        for (const auto& [a, b] : s) {
            if (!b) {
                cout << a.sz;
                return;
            }
        }
    }
    else {
        cout << "0\n";
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
