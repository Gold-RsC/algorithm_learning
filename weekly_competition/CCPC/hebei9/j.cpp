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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string t;
    cin >> t;

    if (t.size() & 1) {
        cout << -1;
        return 0;
    }

    int cnt0 = 0;
    for (auto x : t) {
        if (x == '0') {
            ++cnt0;
        }
    }
    if (cnt0 * 2 != t.size()) {
        cout << -1;
        return 0;
    }


        return 0;
}
