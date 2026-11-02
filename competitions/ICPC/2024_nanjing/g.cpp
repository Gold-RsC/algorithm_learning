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
const int N = 1e5 + 5;

void ask(int x, int y) {
    cout << "? " << x << " " << y << '\n';
    cout.flush();
}
int req() {
    int x;
    cin >> x;
    return x;
}
void answer(int x) {
    cout << "! " << x << '\n';
    cout.flush();
}

struct Edge {
    int next;
    int to;
};
vector<Edge> edge;
vector<int> head(N, -1);

vector<bool> burn;
vector<int> sz(N, 0);
int n;

void init_edge() {
    edge.clear();
    head.assign(n + 1, -1);
    burn.assign(n + 1, 0);
}
void add_edge(int u, int v) {
    edge.push_back({head[u], v});
    head[u] = edge.size() - 1;
}


void dfs_sz(int u, int fa) {
    sz[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        if (burn[v]) {
            continue;
        }

        dfs_sz(v, u);

        sz[u] += sz[v];
    }
}
void dfs(int u, int fa, int& now_min, int& ans, int root) {


    int max_part = 0;  // 表示删掉x后分成的最大子树的大小


    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        if (burn[v]) {
            continue;
        }

        dfs(v, u, now_min, ans, root);

        max_part = max(max_part, sz[v]);
    }
    max_part = max(max_part, sz[root] - sz[u]);
    if (max_part < now_min) {
        now_min = max_part;
        ans     = u;
    }
}

void solve() {
    cin >> n;
    init_edge();
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x) {
            add_edge(i, x);
            add_edge(x, i);
        }
        if (y) {
            add_edge(i, y);
            add_edge(y, i);
        }
    }

    int cent = 0;
    int x    = 1;
    while (1) {
        int now_min = N;
        dfs_sz(x, 0);
        dfs(x, 0, now_min, cent, x);
        dfs_sz(cent, 0);
        // cerr << "[] cerr: " << cent << endl;


        vector<int> q;
        for (int i = head[cent]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (burn[v]) {
                continue;
            }
            q.push_back(v);
        }
        sort(q.begin(), q.end(), [&](int a, int b) {
            return sz[a] > sz[b];
        });
        if (q.size() >= 2) {
            ask(q[0], q[1]);
            int ans = req();
            if (ans == 0) {
                x          = q[0];
                burn[q[1]] = burn[cent] = true;
            }
            else if (ans == 1) {
                x          = cent;
                burn[q[0]] = burn[q[1]] = true;
            }
            else {
                x          = q[1];
                burn[q[0]] = burn[cent] = true;
            }
        }
        else if (q.size() == 1) {
            ask(cent, q[0]);
            int ans = req();
            if (ans == 0) {
                answer(cent);
                break;
            }
            else if (ans == 2) {
                answer(q[0]);
                break;
            }
        }
        else {
            answer(cent);
            break;
        }
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
/*
1
11
2 3
0 0
4 5
6 7
10 11
8 9
0 0
0 0
0 0
0 0
0 0
*/
