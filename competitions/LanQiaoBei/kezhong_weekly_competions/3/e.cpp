#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define int int64_t
int n, m, k;
int a[100005];
int b[100005];
bool check(int ans) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += upper_bound(b, b + m, ans - a[i]) - b;
        if (num >= k) {
            return true;
        }
    }
    return false;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);

    int l = 0, r = a[n - 1] + b[m - 1] + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r;
    return 0;
}
