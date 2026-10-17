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
    for (int m = 1; 'a' * m <= n; ++m) {
        if ('z' * m >= n) {
            cout << "Yes\n";

            int u = (n - 'a' * m) / m;
            int v = (n - 'a' * m) % m;
            int i = 1;
            for (; i <= v; ++i) {
                cout << char('a' + u + 1);
            }
            for (; i <= m; ++i) {
                cout << char('a' + u);
            }
            cout << '\n';

            return;
        }
    }
    cout << "No\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
