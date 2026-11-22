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

const int N = 2e5 + 5;


int a[N];  // k=idx,w=a[idx]
int n;

int ans;

struct Node {
    int left, right;
    int parent;
};
struct CartesianTree {
    vector<Node> node;
    vector<int> sz;
    int root;
    CartesianTree() {
        node.assign(n + 1, {0, 0, 0});
        sz.assign(n + 1, 0);
        root = 0;
    }
    int build() {  // 单调栈维护右子树
        vector<int> stk(n + 1, 0);
        int top = 0;
        for (int i = 1; i <= n; ++i) {
            int k = top;
            while (k && a[stk[k]] > a[i]) {
                --k;
            }
            if (k) {
                node[stk[k]].right = i;
                node[i].parent     = stk[k];
            }
            else {
                root = i;
            }
            if (k < top) {
                node[i].left            = stk[k + 1];
                node[stk[k + 1]].parent = i;
            }
            stk[++k] = i;
            top      = k;
        }
        return root;
    }
    void dfs(int u) {
        if (!u) {
            return;
        }
        sz[u] = 1;
        dfs(node[u].left);
        dfs(node[u].right);
        sz[u] += sz[node[u].left] + sz[node[u].right];

        // cerr << "[" << a[u] << "]" << ans << " ";
        if (sz[node[u].left] && sz[node[u].right]) {
            ans += 2;
        }
        else {
            ans += sz[u];
        }
        // cerr << ans << endl;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    CartesianTree tree;
    tree.build();
    ans = 0;
    tree.dfs(tree.root);
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
