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
    vector<bitset<5005>> b(W + 10, bitset<5005>(0));


    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            if (j >= w[i]) {
                if (dp[j] < dp[j - w[i]] + v[i]) {
                    dp[j] = dp[j - w[i]] + v[i];
                    b[j]  = b[j - w[i]];
                    b[j].set(i);
                }
            }
            else
                break;
        }
    }
    vector<int> last;
    for (int i = 1; i <= n; ++i) {
        if (!b[W].test(i)) {
            last.push_back(i);
            // cerr << i << endl;
        }
    }

    return 0;
}
