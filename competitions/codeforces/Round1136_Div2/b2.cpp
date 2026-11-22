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

string s;
void solve() {
    int n;
    cin >> n;


    cout << '+';
    for (int i = 1; i < n; ++i) {
        cout << "--+";
    }
    cout << '\n';
    cout.flush();
    int k;
    cin >> k;
    if (k == 0) {
        cout << n << '\n';
    }
    else {
        cout << n + (k + 2) / 3 << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout.flush();
    }
    return 0;
}
