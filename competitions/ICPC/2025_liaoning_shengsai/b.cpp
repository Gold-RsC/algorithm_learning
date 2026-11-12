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
    set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int m, k;
    cin >> m >> k;
    while (k--) {
        int a;
        cin >> a;
        s.erase(a);
    }
    if (s.empty()) {
        cout << "-1\n";
        return;
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
