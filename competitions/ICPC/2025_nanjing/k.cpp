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

pair<int, int> dir[8] = {
    {1, 2},
    {-1, 2},
    {1, -2},
    {-1, -2},
    {2, 1},
    {-2, 1},
    {2, -1},
    {-2, -1},
};
bool check(int x, int y) {
    return !(x < 1 || x > 9 || y < 1 || y > 10);
}
bool solve() {
    int xN, yN, xR, yR;
    cin >> xN >> yN >> xR >> yR;
    for (int i = 0; i < 8; ++i) {
        if (!check(xN + dir[i].first, yN + dir[i].second)) {
            continue;
        }
        if (xN + dir[i].first / 2 == xR && yN + dir[i].second / 2 == yR) {
            continue;
        }
        if (xN + dir[i].first == xR && yN + dir[i].second == yR) {
            return false;
        }
        if (xN + dir[i].first == xR || yN + dir[i].second == yR) {
            continue;
        }
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

    return 0;
}
