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
const int N = 2e5 + 5;
int v[N];
int l[N];
int preL[N];
int preV[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l[i];
    }
    sort(v + 1, v + n + 1, greater<int>());
    sort(l + 1, l + n + 1);
    for (int i = 1; i <= n; i++) {
        preV[i] = preV[i - 1] + v[i];
        preL[i] = preL[i - 1] + l[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int left = 1, right = n;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid] - l[mid] * t >= 0) {
                ans  = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        cout << preV[ans] - preL[ans] * t << ' ';
    }
    cout << '\n';
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
