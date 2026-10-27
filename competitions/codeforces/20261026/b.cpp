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
    char c;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == 'f') {
            cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == 'f') {
            cnt++;
        }
    }
    if (cnt & 1) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
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
