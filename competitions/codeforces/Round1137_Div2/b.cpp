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
void solve() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        while (n--) {
            int y;
            cin >> y;
        }
        cout << k << '\n';
        return;
    }
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= (n - k); ++i) {
        int x;
        cin >> x;
        b[i] = x;
        if (a[x] == 0) {
            ++cnt;
        }
        a[x]++;
    }
    int ans = 0;
    for (int i = (n - k) + 1; i <= n; ++i) {
        int x;
        cin >> x;
        b[i] = x;
        if (a[x] == 0) {
            ++cnt;
        }
        a[x]++;
        if (cnt == 1) {
            ++ans;
        }
        // cerr << "[" << i << "] " << a[x] << ' ' << cnt << endl;
        a[b[i - (n - k)]]--;
        if (a[b[i - (n - k)]] == 0) {
            --cnt;
        }
    }
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
