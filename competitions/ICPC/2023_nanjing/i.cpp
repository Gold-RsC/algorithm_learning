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
    int n, m;
    cin >> n >> m;

    vector<int> s(n + 1, -1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        s[a] = b;
    }

    int base = 0;
    int step = 0;
    for (int i = 1; i <= n; ++i) {
        ++step;
        if (s[i] != -1) {
            if (s[i] == step + base || s[i] < step) {
                base = s[i];
                step = 0;
            }
            else {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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
