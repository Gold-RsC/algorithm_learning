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

const int N = 2e6 + 5;
int offset;
int a[N];
int n, T;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (T--) {
        int o, x;
        cin >> o >> x;
        if (o == 1) {
            a[n++] = x - offset;
        }
        else {
            offset += x;
        }
    }
    sort(a, a + n);

    int L, R;
    cin >> L >> R;
    L -= offset;
    R -= offset;

    int left_idx  = lower_bound(a, a + n, L) - a;
    int right_idx = upper_bound(a + left_idx, a + n, R) - a;
    cout << right_idx - left_idx;

    return 0;
}
