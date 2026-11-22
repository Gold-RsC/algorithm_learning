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
const int N   = 5e5 + 5;
const int MAX = 1e7 + 5;
int a[N];
int u[MAX + 1];
vector<int> primes;
bool is_prime[MAX + 1];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            continue;
        }
        if (a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 5 || a[i] == 7) {
            cout << -1 << '\n';
            return;
        }
        else {
            ++ans;
            ans += is_prime[a[i]];
            // cerr << "[]" << ans << endl;
        }
    }
    cout << ans << '\n';
}


void init() {
    for (int i = 2; i <= MAX; ++i) {
        if (u[i] == 0) {
            u[i] = i;
            primes.push_back(i);
            is_prime[i] = true;
        }
        for (auto x : primes) {
            if (x > u[i] || x > MAX / i) {
                break;
            }
            u[i * x] = x;
        }
    }
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
