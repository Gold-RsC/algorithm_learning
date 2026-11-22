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
    int n, x;
    cin >> n >> x;
    map<int, int> a;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        b = (b - 1) / x + 1;
        ++a[b];
    }
    if (a.rbegin()->second == 1) {
        a.erase(prev(a.end()));
    }
    else {
        a.rbegin()->second--;
    }
    int ans      = 0;
    int resource = 0;
    int damage   = 0;
    for (auto it = a.begin(); it != a.end(); ++it) {
        auto [u, l] = *it;

        int delta = u - 1 - damage;

        if (resource - delta >= 0) {
            resource -= delta;
        }
        else {
            ans += (delta - resource);
            resource = 0;
        }
        resource += l - 1;
        damage = u;
        // cerr << "[" << u << "]" << ans << " " << resource << endl;
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
