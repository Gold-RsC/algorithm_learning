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

void solve() {
    int n, k;
    int a[51][51];
    int i0 = 1, j0, cur;
    cin >> n >> k;
    if (k < n || k > n * n - n + 1) {
        cout << "No" << '\n';
        return;
    }
    j0 = k + 1;
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                cur = k;
            else if (i == j)
                cur = j0++;
            else {
                cur = i0++;
                if (i0 > k) {
                    cur = j0++;
                }
            }
            cout << cur;
            if (j != n)
                cout << ' ';
            else
                cout << '\n';
        }
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
