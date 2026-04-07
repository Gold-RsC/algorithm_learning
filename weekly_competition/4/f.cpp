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
const int N = 16;

int n;
int m;
int HP;

int hurt[N];
bool killed[N];
int killnum = 1;
int weight[N][N];
int visited[N];
struct State {
    int i;
    int hp;
    int time;
};
int ans = INT_MAX;

void dfs(State x) {
    // cerr << "dfs" << endl;
    if (visited[x.i] == 4) {
        // cerr << "miss" << endl;
        return;
    }
    visited[x.i]++;
    if (!killed[x.i]) {

        for (int j = 0; j < n; ++j) {
            // 有前往的路
            if (weight[x.i][j] == 0) {
                continue;
            }
            if (killed[j]) {
                continue;
            }
            // 不是初始节点
            if (x.i) {
                x.hp -= hurt[j];
            }
        }
        killed[x.i] = true;
        killnum++;
    }
    if (x.hp <= 0) {
        // cerr << "die" << endl;
        return;
    }
    // cerr << x.i << " " << x.hp << " " << x.time << " "
    //  << visited[x.i] << " " << killnum << endl;
    if (x.i == n - 1 && x.hp > 0) {
        if (killnum == n) {
            ans = min(ans, x.time);
        }
        // cerr << "end" << endl;
        return;
    }
    for (int j = 0; j < n; ++j) {
        // 有前往的路
        if (weight[x.i][j] == 0) {
            continue;
        }


        dfs({j, x.hp, x.time + weight[x.i][j]});
    }
    visited[x.i]--;
    killnum--;
    killed[x.i] = false;
    // cerr << "dfs-end" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> HP;
    for (int i = 0; i < n; ++i) {
        cin >> hurt[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        weight[v][u] = weight[u][v] = w;
    }

    if (n == 1) {
        cout << 0;
    }
    else {
        for (int j = 0; j < n; ++j) {
            // 有前往的路
            if (weight[0][j] == 0) {
                continue;
            }
            dfs({j, HP, weight[0][j]});
        }
    }


    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}
