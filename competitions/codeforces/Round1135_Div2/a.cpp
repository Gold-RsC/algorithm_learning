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
    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }

    int p = n;
    cout << 4 << ' ';
    for (int i = 2; i < 4; ++i) {
        if (p == 4) {
            --p;
        }
        cout << p << ' ';
        p--;
    }
    cout << 1 << ' ';
    for (int i = 5; i <= n; ++i) {
        if (p == 4) {
            --p;
        }
        cout << p << ' ';
        p--;
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
