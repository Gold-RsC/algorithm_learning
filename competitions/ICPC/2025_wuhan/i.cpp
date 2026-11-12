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

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k > n * n - n + 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    a[1][1] = k;
    for (int i = 1; i <= n - 1; ++i) {
        a[1][i + 1]     = i;
        a[i + 1][i + 1] = k + i;
    }
    int cur = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!a[i][j]) {
                a[i][j] = cur++;
            }
            if (cur == k) {
                cur = k + n;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ((j == n) ? "" : " ");
        }
        cout << '\n';
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
