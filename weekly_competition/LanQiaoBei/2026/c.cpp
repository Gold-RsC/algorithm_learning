#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int C;
    cin >> C;
    while (C--) {
        int l, v, t;
        cin >> l >> v >> t;
        int PA = v * t;
        int PB = l - v * t;

        cout << (abs((l)-2 * v * t) + 1) / 2 << endl;
    }
    return 0;
}
