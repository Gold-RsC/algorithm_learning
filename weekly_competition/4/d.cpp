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
typedef long long ll;
const int N = 3e5 + 3;
ll n;
ll a, b, c;
ll s[N];
ll pre[N];
ll ans = 0;
ll f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        pre[i] = s[i] + pre[i - 1];
    }
    f[0] = LLONG_MAX;
    for (int R = 1; R <= n; ++R) {
        f[R] = min(f[R - 1], pre[R - 1] - a * c * R);
        ll x = pre[R] - a * b * R;
        ll l = 0, r = R + 1;
        while (l + 1 < r) {
            ll mid = (l + r) >> 1;
            if (f[mid] < x) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (R >= r) {
            ans = max(ans, R - r + 1);
        }
    }
    cout << ans;
    return 0;
}
