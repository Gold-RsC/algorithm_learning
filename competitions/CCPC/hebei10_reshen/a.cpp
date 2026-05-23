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

bool check(int x) {
    cout << "? " << x << endl;
    int f;
    cin >> f;
    return f;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l = 0, r = 100;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << "! " << l << endl;

    return 0;
}
