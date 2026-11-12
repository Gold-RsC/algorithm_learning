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

const int N = 22;

int n, m;

char g[N][N];
char num[N][N];

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
char chd[4] = {'R', 'L', 'D', 'U'};
bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}
struct Point {
    int x, y;
    bool operator==(const Point& _) const {
        return x == _.x && y == _.y;
    }
    bool operator!=(const Point& _) const {
        return !(*this == _);
    }
};
int kangroo_cnt;
int now_cnt;
void move(Point s, Point t) {
    if (g[t.x][t.y] == '1') {
        now_cnt -= num[s.x][s.y];
    }
    num[t.x][t.y] += num[s.x][s.y];
    num[s.x][s.y] = 0;
    g[t.x][t.y]   = '1';
    g[s.x][s.y]   = '.';
}
#define _jump()                                                                                                        \
    if (g[i][j] == '1') {                                                                                              \
        if (is_valid(i + dx, j + dy) && g[i + dx][j + dy] != '0') {                                                    \
            move(Point{i, j}, Point{i + dx, j + dy});                                                                  \
        }                                                                                                              \
    }
void jump(int d) {
    auto [dx, dy] = dir[d];

    if (dx == 1) {
        for (int i = n; i >= 1; --i) {
            for (int j = 1; j <= m; ++j) {
                _jump();
            }
        }
    }
    else if (dx == -1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                _jump();
            }
        }
    }
    else if (dy == 1) {
        for (int j = m; j >= 1; --j) {
            for (int i = 1; i <= n; ++i) {
                _jump();
            }
        }
    }
    else {
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                _jump();
            }
        }
    }
}
string ans;
pair<Point, Point> get_now_2_kangroo() {
    Point s{-1, -1}, t{-1, -1};
    int cc = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == '1') {
                if (cc == 0) {
                    s = {i, j};
                }
                else if (cc == 1) {
                    t = {i, j};
                    goto finish;
                }
                ++cc;
            }
        }
    }
finish:
    return {s, t};
}
pair<vector<int>, int> get_path(Point s, Point t, Point fa) {


    for (int dd = 0; dd < 4; ++dd) {
        Point v = {s.x + dir[dd][0], s.y + dir[dd][1]};
        if (v == fa) {
            continue;
        }
        if (!is_valid(v.x, v.y) || g[v.x][v.y] == '0') {
            continue;
        }
        if (v == t) {
            return {{dd}, 1};
        }
        auto [x, y] = get_path(v, t, s);
        if (y != -1) {
            x.push_back(dd);
            return {x, y + 1};
        }
    }
    return {{}, -1};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '1') {
                num[i][j] = 1;
                ++kangroo_cnt;
            }
        }
    }
    now_cnt = kangroo_cnt;

    while (true) {
        // cerr << "=====================cnt= " << now_cnt << endl;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         cerr << g[i][j];
        //     }
        //     cerr << endl;
        // }
        auto [s, t] = get_now_2_kangroo();
        if (t.x == -1) {
            break;
        }
        auto [p, num] = get_path(s, t, {-1, -1});
        reverse(p.begin(), p.end());

        for (int i = 0; s != t; ++i) {
            s.x += dir[p[i]][0];
            s.y += dir[p[i]][1];
            ans.push_back(chd[p[i]]);
            jump(p[i]);
            if (is_valid(t.x + dir[p[i]][0], t.y + dir[p[i]][1])) {
                t.x += dir[p[i]][0];
                t.y += dir[p[i]][1];
                p.push_back(p[i]);
            }
        }
    }


    cout << ans;

    return 0;
}
