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
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

int Y, X;
char mp[15][15];
int dis[15][15][15][15];

vector<pair<int, int>> doors;
vector<pair<int, int>> people;

int fx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const int MAXP = 105;
const int MAXR = 50005;

vector<int> adj[MAXP];
int matchR[MAXR];
bool vis[MAXR];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v])
            continue;
        vis[v] = true;
        if (matchR[v] == -1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int hungarian(int n, int m) {
    fill(matchR, matchR + m, -1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        fill(vis, vis + m, false);
        if (dfs(i)) {
            res++;
        }
    }
    return res;
}

// ==================== 判断 T 是否可行 ====================
// 左部：P 个人
// 右部：D * T 个 (门 j, 时刻 t)，编号 j * T + t
bool check(int T) {
    int P = people.size();
    int D = doors.size();
    if (P == 0)
        return true;
    if (D == 0)
        return false;
    if (T <= 0)
        return false;

    int R = D * T;

    // 清空左部邻接表
    for (int i = 0; i < P; i++)
        adj[i].clear();

    // 建边：人 i → (门 j, 时刻 t)
    for (int i = 0; i < P; i++) {
        int px = people[i].first, py = people[i].second;
        for (int j = 0; j < D; j++) {
            int dxx = doors[j].first, dyy = doors[j].second;
            int d = dis[dxx][dyy][px][py];
            if (d >= INF)
                continue;  // 人 i 到不了门 j
            // 人 i 到达门 j 需 d 步，第 d 分钟末即可离开，总时间 = d
            // 0-indexed 时刻 t = d-1 对应第 d 分钟末通过
            for (int t = max(0LL, d - 1); t < T; t++) {
                adj[i].push_back(j * T + t);
            }
        }
    }

    return hungarian(P, R) == P;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        doors.clear();
        people.clear();
        memset(dis, 0x3f, sizeof(dis));
        memset(mp, 0, sizeof(mp));

        cin >> Y >> X;
        char c;
        for (int j = 0; j < Y; ++j) {
            for (int i = 0; i < X; ++i) {
                cin >> c;
                mp[i][j] = c;
                if (c == 'D') {
                    doors.push_back({i, j});
                }
                else if (c == '.') {
                    people.push_back({i, j});
                }
            }
        }

        for (auto [xx, yy] : doors) {
            queue<pair<int, int>> q;
            q.push({xx, yy});
            dis[xx][yy][xx][yy] = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int px = x + fx[i][0], py = y + fx[i][1];
                    if (px < 0 || px >= X || py < 0 || py >= Y) {
                        continue;
                    }
                    if (mp[px][py] != 'X' && dis[xx][yy][px][py] == INF) {
                        dis[xx][yy][px][py] = dis[xx][yy][x][y] + 1;
                        q.push({px, py});
                    }
                }
            }
        }

        int P = people.size();
        if (P == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (doors.empty()) {
            cout << "impossible\n";
            continue;
        }

        // ===== 二分答案 =====
        int lo = 1, hi = Y * X + P + 5, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                hi  = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        if (ans == -1)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
