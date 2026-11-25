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
    int ans = 0;

    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if ((flag && c == 'R') || (!flag && c == 'B')) {
        }
        else {
            ++ans;
            flag = !flag;
        }
        flag = !flag;
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
