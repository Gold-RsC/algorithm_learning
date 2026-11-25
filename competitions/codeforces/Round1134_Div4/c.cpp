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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    vector<int> b;
    vector<int> c;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i - 1]) {
            b.push_back(a[i]);
        }
        else {
            c.push_back(a[i]);
        }
    }
    int ans = b.size();
    if (c.size()) {
        ++ans;
    }
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] != c[i - 1]) {
            ++ans;
        }
    }
    cout << ans << '\n';
    for (auto x : b) {
        cout << x << ' ';
    }
    for (auto it = c.rbegin(); it != c.rend(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
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
