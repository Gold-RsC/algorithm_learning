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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, W, k;
    cin >> n >> W >> k;

    vector<int> w(n + 1, 0);
    vector<int> v(n + 1, 0);

    vector<int> dp(W + 10, 0);
    vector<pair<bitset<5005>, int>> b(W + 10, {bitset<5005>(0), 0});

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            if (j >= w[i]) {
                if (dp[j] < dp[j - w[i]] + v[i] ||
                    (dp[j] == dp[j - w[i]] + v[i] && b[j].second <= b[j - w[i]].second + 1)) {
                    dp[j] = dp[j - w[i]] + v[i];
                    b[j]  = b[j - w[i]];
                    b[j].first.set(i);
                    ++b[j].second;
                }
            }
            else
                break;
        }
    }

    int max_v = dp[W];
    int an    = W;

    // cerr << max_v << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cerr << b[an].test(i) << " ";
    // }


    vector<int> last;
    for (int i = 1; i <= n; ++i) {
        if (!b[an].first.test(i)) {
            last.push_back(i);
            // cerr << i << endl;
        }
    }

    partial_sort(last.begin(), last.begin() + min<int>(k, last.size()), last.end(), [&](int x, int y) {
        return v[x] > v[y];
    });


    int ans = max_v;
    for (int i = 0; i < min<int>(k, last.size()); ++i) {
        ans += v[last[i]];
    }
    cout << ans;


    return 0;
}
