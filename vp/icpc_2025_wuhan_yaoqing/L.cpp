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
const int N = 1e3 + 5;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 0;
    unordered_map<ll, ll> num;
    for (int i = 1; i <= n; i++) {
        num[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (num[2 * a[i] - a[j]] != 0 && num[2 * a[i] - a[j]] >= i) {
                ans = max(1 + 2 * min(i - j, num[2 * a[i] - a[j]] - i), ans);
                if (i - j + 1 <= num[2 * a[i] - a[j]] - i)
                    ans = max(2 + 2 * min(i - j, num[2 * a[i] - a[j]] - i), ans);
            }
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
