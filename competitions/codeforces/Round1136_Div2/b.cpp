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
    int x, y, m;
    cin >> x >> y >> m;
    string s;
    cin >> s;
    int ans = x + y;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        char d = s[i + 1];
        if (c == '+') {
            if (y) {
                ++y;
            }
            else {
                if (x) {
                    --x;
                    ++y;
                }
                else {
                }
            }
        }
        else {
            if (y) {
                if (y == 1 && x) {
                    --x;
                }
                else {
                    --y;
                    ++x;
                }
            }
            else {
                if (x) {
                    --x;
                }
                else {
                }
            }
        }
        ans = max(ans, x + y);
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
