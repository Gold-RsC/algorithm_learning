#include <iostream>
#include <iomanip>
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
using namespace std;

const int N = 1e5 + 5;

int n, f;

short a[N];
int s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> f;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }

    double l = 1, r = 2000;
    while (l + 1e-4 < r) {
        double mid = (l + r) / 2;

        int minS   = INT_MAX;
        double ans = INT_MIN;
        int sl     = 0;
        int length = f;
        for (int i = f; i <= n; ++i) {
            if (minS > s[i - f]) {
                minS = s[i - f];
                sl   = i - f;
            }

            if (ans < s[i] - minS) {
                ans    = s[i] - minS;
                length = i - sl;
            }
        }

        if (ans >= length * mid) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << int(r * 1000);


    return 0;
}
