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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '2') {
            ++c;
        }
        else if ((i & 1) ^ (s[i] == '0')) {
            ++a;
        }
        else {
            ++b;
        }
    }
    cout << max<int>(abs(a - b) - c, (s.size() & 1) ? 1 : 0) << '\n';
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
