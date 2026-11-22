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
const int N = 2e5 + 8;
int a[N];
int n;
int rk[N];  // 离散后的数组
int t[N];   // 管理树状数组
int lowbit(int x) {
    return x & (-x);
}
void add(int i) {
    for (; i <= n; i += lowbit(i)) {
        t[i]++;
    }
}
int presum(int i) {
    int s = 0;
    for (; i > 0; i -= lowbit(i)) {
        s += t[i];
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += i;
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; ++i) {
        rk[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }

    // 逆序数
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        ans += presum(rk[i] - 1);
        add(rk[i]);
    }
    cout << ((ans & 1) ? "Shion" : "Kanon");

    return 0;
}
