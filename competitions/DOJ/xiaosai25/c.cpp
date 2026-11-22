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
    string s;
    cin >> s;

    int one = 0;
    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];
        if (c == '1') {
            ++one;
        }
    }
    int ans = ((s[0] == '1') * 2 - 1) * ((one - (s[0] == '1')) * 2 - (n - 1));
    for (int i = 1, onecnt = 0; i < n; ++i) {
        char c = s[i - 1];
        if (c == '1') {
            ++onecnt;
        }
        ans = max(ans, (onecnt * 2 - i) * ((one - onecnt) * 2 - (n - i)));
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
