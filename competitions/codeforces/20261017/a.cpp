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
    int n;
    cin >> n;

    int min_ = n;
    int max_ = 0;
    int m    = 0;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if (c == '1') {
            min_ = min(min_, i);
            max_ = max(max_, i);
            ++m;
        }
    }
    if (m == 2) {
        cout << 1 << '\n';
    }
    else {
        cout << max_ - min_ << '\n';
    }
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
