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
struct item {
    int w, v;
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, W, k;
    cin >> n >> W >> k;
    vector<item> a(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
    }

    sort(a.begin() + 1, a.begin() + 1 + n, [&](const item& x, const item& y) {
        if (x.w != y.w) {
            return x.w > y.w;
        }
        return x.v > y.v;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> pre(n + 1, 0);
    if (k) {
        for (int i = 1; i <= n; ++i) {
            // cerr << pq.size() << " ";
            if (pq.size() < k) {
                pre[i] = pre[i - 1] + a[i].v;
                pq.push(a[i].v);
            }
            else {
                if (a[i].v > pq.top()) {
                    pre[i] = pre[i - 1] - pq.top() + a[i].v;
                    pq.pop();
                    pq.push(a[i].v);
                }
                else {
                    pre[i] = pre[i - 1];
                }
            }
            // cerr << pq.size() << "\n";
        }
    }

    // ostream_iterator<int> out(cerr, " ");
    // copy(pre.begin() + 1, pre.end(), out);
    // cerr << endl;


    int ans = 0;
    vector<int> dp(W + 1, 0);
    for (int i = n; i >= 1; --i) {
        for (int w = W; w >= a[i].w; --w) {
            dp[w] = max(dp[w], dp[w - a[i].w] + a[i].v);
        }
        ans = max(ans, dp[W] + pre[i - 1]);
    }
    cout << ans;


    return 0;
}
