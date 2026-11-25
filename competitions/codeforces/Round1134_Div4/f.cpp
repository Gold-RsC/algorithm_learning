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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        if (b + n + 1 - i < 1 || b + n + 1 - i > n || a[b + n + 1 - i]) {
            flag = false;
        }
        else {
            a[b + n + 1 - i] = i;
        }
    }
    if (flag) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
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
