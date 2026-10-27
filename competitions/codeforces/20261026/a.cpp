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
#include <cstdint>
using namespace std;
#define int long long

const int N = 110;
int a[N];
int check(int n, int k) {
    int ans = n;
    for (int i = n; i >= 1 && k >= 2; --i, --k) {
        if (a[i] < ans) {
            ans = a[i];
        }
    }
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans_i = 0, ans_j = 0;
    int m = check(n, k);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            swap(a[i], a[j]);
            int t = check(n, k);
            if (t > m) {
                ans_i = i;
                ans_j = j;
                m     = t;
            }
            swap(a[i], a[j]);
        }
    }
    if (ans_i == 0 && ans_j == 0) {
        cout << "-1\n";
    }
    else {
        cout << ans_i << ' ' << ans_j << '\n';
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
