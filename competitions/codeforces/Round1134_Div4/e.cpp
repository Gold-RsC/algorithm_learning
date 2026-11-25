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

const int N = 2e5 + 5;

int a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int p = 0;
    queue<pair<int, int>> q;
    int sum = 0;
    for (int i = n; i >= 1; --i) {
        while (!q.empty() && q.front().second - k > i) {
            sum ^= q.front().first;
            q.pop();
        }
        p ^= sum ^ a[i];
        q.push({sum ^ a[i], i});
        sum ^= sum ^ a[i];
    }
    if (p & 1) {
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
