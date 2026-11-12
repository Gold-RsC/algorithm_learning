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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.begin() + m + 1);
    for (int i = 1; i <= m; i++) {
        if (a[i].first < a[i].second) {
            cout << "No\n";
            return;
        }
    }
    for (int i = 2; i <= m; i++) {
        if (a[i].second - a[i - 1].second != a[i].first - a[i - 1].first) {
            if (a[i].first - a[i - 1].first < 1 + a[i].second) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}
