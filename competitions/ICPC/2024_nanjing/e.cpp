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
string m         = "nanjing";
vector<int> fail = {0, 0, 1, 0, 0, 1, 0};
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (s.size() < 7) {
        cout << 0 << '\n';
        return;
    }

    s += s;
    int begin_idx = min<int>(k, n - 1);
    int find_idx  = s.find(m);
    if (find_idx == string::npos) {
        cout << 0 << '\n';
    }
    else {
        if (find_idx < begin_idx) {
            begin_idx = find_idx;
        }
    }

    int j   = 0;
    int ans = 0;
    for (int i = begin_idx; i < begin_idx + n; ++i) {
        while (s[i] != m[j] && j > 0) {
            j = fail[j - 1];
        }
        if (s[i] == m[j]) {
            ++j;
        }
        if (j == fail.size()) {
            ++ans;
            j = fail[j - 1];
        }
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
