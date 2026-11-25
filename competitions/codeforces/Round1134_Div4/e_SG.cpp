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
    int n, k;
    cin >> n >> k;
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (i % (k + 1) == 1) {
            x ^= a;
        }
    }
    if (x & 1) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
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
