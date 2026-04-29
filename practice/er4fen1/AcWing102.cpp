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
double b[N];
double s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> f;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    double l = 1, r = 2000;
    while (l + 1e-5 < r) {
        double mid = (l + r) / 2;

        for (int i = 1; i <= n; ++i) {
            b[i] = a[i] - mid;
        }
        for (int i = 1; i <= n; ++i) {
            s[i] = b[i] + s[i - 1];
        }

        double minS = INT_MAX;
        double ans  = s[f];
        for (int i = f; i <= n; ++i) {
            minS = min(minS, s[i - f]);
            ans  = max(ans, s[i] - minS);
        }

        if (ans >= 0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << int(r * 1000);


    return 0;
}
