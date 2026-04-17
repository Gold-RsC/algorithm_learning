#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define int int64_t
const int N = 2e5 + 5;
int n, m;
vector<int> tree1_bian[N];
vector<int> tree2_bian[N];
int quan1[N];
int quan2[N];
int ans;
// i,j表示节点
void w(int i, int j, int i_fa, int j_fa, int depth) {
    ans = max(ans, depth);
    for (signed i1 = 0, i2 = 0; i1 < tree1_bian[i].size() && i2 < tree2_bian[j].size();) {
        int k1 = tree1_bian[i][i1];
        int k2 = tree2_bian[j][i2];
        if (k1 == i_fa) {
            ++i1;
            continue;
        }
        if (k2 == j_fa) {
            ++i2;
            continue;
        }
        if (quan1[k1] == quan2[k2]) {
            w(k1, k2, i, j, depth + 1);
            ++i1;
            ++i2;
        }
        else if (quan1[k1] < quan2[k2]) {
            ++i1;
        }
        else {
            ++i2;
        }
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> quan1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> quan2[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree1_bian[u].push_back(v);
        tree1_bian[v].push_back(u);
    }
    for (int i = 1; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        tree2_bian[u].push_back(v);
        tree2_bian[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(tree1_bian[i].begin(), tree1_bian[i].end(), [](int a, int b) { return quan1[a] < quan1[b]; });
    }
    for (int i = 1; i <= m; i++) {
        sort(tree2_bian[i].begin(), tree2_bian[i].end(), [](int a, int b) { return quan2[a] < quan2[b]; });
    }
    if (quan1[1] == quan2[1]) {
        w(1, 1, 0, 0, 1);
    }
    cout << ans << endl;
    return 0;
}
