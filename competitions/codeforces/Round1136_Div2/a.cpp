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
const int N = 1e4 + 5;

int ans[N];

void init() {
    int last_damage = 0;
    for (int k = 1; k < N; ++k) {
        int m      = (4 * k - 3) / 6;
        int damage = (3 + 3 * m - k) * (k - m) / 2;
        ++m;
        damage = max(damage, (3 + 3 * m - k) * (k - m) / 2);
        for (int i = last_damage + 1; i <= min(N - 1, damage); ++i) {
            ans[i] = k;
        }
        if (damage >= N) {
            break;
        }


        last_damage = damage;
    }
}
void solve() {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
