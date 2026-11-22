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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> jishu;
    vector<int> oushu;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a & 1) {
            jishu.push_back(a);
        }
        else {
            oushu.push_back(a);
        }
    }
    int bodong_max = 0;
    if (jishu.size() == oushu.size()) {
        bodong_max = n - 1;
    }
    else {
        bodong_max = min(jishu.size() * 2, oushu.size() * 2);
    }
    int bodong_min = n;
    if (jishu.size() && oushu.size()) {
        bodong_min = 1;
    }
    else {
        bodong_min = 0;
    }
    if (bodong_max < k || bodong_min > k) {
        cout << -1 << '\n';
        return;
    }
    int i = 0, j = 0;
    bool flag = (jishu.size() >= oushu.size());
    for (int m = 1; m <= k; ++m) {
        if (flag) {
            cout << jishu[i++] << ' ';
        }
        else {
            cout << oushu[j++] << ' ';
        }
        flag = !flag;
    }
    flag = !flag;
    if (flag) {
        for (; i < jishu.size(); ++i) {
            cout << jishu[i] << ' ';
        }
    }
    else {
        for (; j < oushu.size(); ++j) {
            cout << oushu[j] << ' ';
        }
    }
    flag = !flag;
    if (flag) {
        for (; i < jishu.size(); ++i) {
            cout << jishu[i] << ' ';
        }
    }
    else {
        for (; j < oushu.size(); ++j) {
            cout << oushu[j] << ' ';
        }
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
