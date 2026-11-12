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
typedef __int128 ll;

void solve() {
    long long np, nm;
    ll p, m;
    cin >> np >> nm;
    p       = np;
    m       = nm;
    auto md = [&](ll p, ll n) {
        return ((n * p + 1) ^ (p - 1));
    };
    ll l = 0, r = m / p + p + 100;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (md(p, mid) <= m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    ll ans = r + 1;
    for (ll ss = r + 1; ss <= r + 15; ss++) {
        if (md(p, ss) <= m) {
            ans++;
        }
    }
    for (ll ss = 0; ss <= min<ll>(10LL, r); ss++) {
        if (md(p, ss) > m) {
            ans--;
        }
    }
    for (int ss = max<ll>(11LL, r - 10); ss <= r; ss++) {
        if (md(p, ss) > m) {
            ans--;
        }
    }
    long long aaaa = ans;
    cout << aaaa << '\n';
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
