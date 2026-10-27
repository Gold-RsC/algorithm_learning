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
const int N = 2e5 + 5;
int a[N];
int d[N];
void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    auto check = [&](int mid) -> bool {
        int y     = 0;
        bool flag = false;  // 0表示前无依靠，1表示有依靠
        for (int i = 2; i <= n; ++i) {
            if (a[i] - a[i - 1] <= mid) {
                flag = true;
            }
            else {
                if (flag) {
                    flag = false;
                }
                else {
                    int bridge = a[i - 1] + mid;
                    ++y;
                    if (y > x) {
                        return false;
                    }
                    if (a[i] - bridge <= mid) {
                        flag = true;
                    }
                    else {
                        flag = false;
                    }
                }
            }
        }
        if (!flag) {
            ++y;
        }
        return y <= x;
    };
    int l = 1, r = a[n] + 2;
    int mid = (l + r) / 2;
    int ans = mid;
    while (l < r) {  //[)
        mid = (l + r) / 2;
        // cerr << "! " << mid << endl;
        if (check(mid)) {
            ans = mid;
            r   = mid;
        }
        else {
            l = mid + 1;
        }
    }
    // cerr << "? " << check(ans) << endl;
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
