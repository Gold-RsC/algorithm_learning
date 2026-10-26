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

void solve() {
    int n, k;
    cin >> n >> k;
    array<int, 100> a;
    a.fill(0);
    for (int i = 0; i < n; ++i) {
        int _;
        cin >> _;
        a[_]++;
    }
    int ans  = 0;
    int capa = 0;
    for (int i = 0; i < 100; ++i) {
        if (a[i]) {
            a[i]--;
        }
        else {
            break;
        }
        capa += a[i];
        capa -= (k - 1);
        if (capa >= 0) {
            ans++;
        }
        else {
            break;
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
