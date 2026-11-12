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
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
};
bool check(int xn, int yn, int xr, int yr) {
    if (((xn == 1 || xn == 9) && abs(xr - xn) == 1 && yn == yr) ||
        ((yn == 1 || yn == 10) && abs(yr - yn) == 1 && xn == xr)

    ) {

        return true;
    }
    return false;
}
bool solve() {
    int xn, yn, xr, yr;
    cin >> xn >> yn >> xr >> yr;

    if (check(xn, yn, xr, yr)) {
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        xn += dir[i].first;
        yn += dir[i].second;
        if (xn < 1 || xn > 9 || yn < 1 || yn > 10) {
            xn -= dir[i].first;
            yn -= dir[i].second;
            continue;
        }
        if (xn == xr && yn == yr) {
            return false;
        }


        xn -= dir[i].first;
        yn -= dir[i].second;
    }
    for (int i = 0; i < 8; ++i) {
        xn += dir[i].first;
        yn += dir[i].second;
        if (xn < 1 || xn > 9 || yn < 1 || yn > 10 || xn == xr || yn == yr) {
            xn -= dir[i].first;
            yn -= dir[i].second;
            continue;
        }
        if (!(check(xn, yn, xn, yr) || check(xn, yn, xr, yn))) {
            return false;
        }
        xn -= dir[i].first;
        yn -= dir[i].second;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
