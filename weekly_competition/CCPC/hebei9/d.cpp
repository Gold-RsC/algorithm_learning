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
#define int long long
int n, k;
vector<int> a;
vector<int> sum;
bool check(int d) {
    int cnt = 0;
    int j   = 1;
    for (int i = 0; i < n; ++i) {
        if (j <= i) {
            j = i + 1;
        }
        while (j < n && a[j] - a[i] <= d) {
            j++;
        }
        cnt += (j - 1) - i;
        if (cnt >= k) {
            return true;
        }
    }
    return cnt >= k;
}
int get_sum(int d) {
    int ans = 0;
    //[]
    for (int i = 0; i < n; ++i) {
        int j = i + 1;


        while (j < n && a[j] - a[i] <= d) {
            ++j;
        }

        --j;

        // if (j != i) {

        ans += (sum[j] - sum[i]) - a[i] * (j - i);
        // }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int newn = a.erase(unique(a.begin(), a.end()), a.end()) - a.begin();
    k -= n - newn;
    if (k <= 0) {
        cout << 0;
        return 0;
    }
    n = newn;

    sum.resize(n);
    for (int i = 0, s = 0; i < n; ++i) {
        s += a[i];
        sum[i] = s;
    }

    int l = 0, r = LLONG_MAX;
    while (l < r) {
        int mid = l + (r - l >> 1);
        // cerr << l << " " << r << " " << mid << endl;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }


    cout << get_sum(l - 1) + (k - (check(l - 1))) * l;
    ;

    return 0;
}
