#include <iostream>
#include <iomanip>
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
int n, m, t;
const int N = 5e5 + 5;

int a[N];
int s[N];

int check(int l, int r) {
    for (int i = l; i <= r; ++i) {
        s[i] = a[i];
    }
    sort(s + l, s + r + 1);

    int q = 0;
    for (int i = 0; i < m && l + 2 * i < r; ++i) {
        q += (s[r - i] - s[l + i]) * (s[r - i] - s[l + i]);
    }
    return q;
}
void solve() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    for (int start = 0; start < n;) {
        int end = start, p = 1;
        while (p) {
            if (end + p < n && check(start, end + p) <= t) {
                end += p;
                p *= 2;
            }
            else {
                p /= 2;
            }
        }
        start = end + 1;
        ans++;
    }

    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;
    while (K--) {
        solve();
    }
    return 0;
}
