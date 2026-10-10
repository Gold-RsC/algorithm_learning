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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int      long long
#define __int128 int
// ×ó¿ªÓÒ¿ª
struct qujian {
    __int128 l, r;
    int cnt;
    bool operator<(const qujian& _) const {
        return r < _.r;
    }
};

vector<qujian> v1;
vector<qujian> v2;

void init() {
    __int128 l = 44, r = 46;
    int cnt = 1;
    while (l <= 1e18) {
        v1.push_back({l, r, cnt});
        if (l >= 1e9) {
            break;
        }
        l *= l;
        r *= r;
        ++cnt;
    }
    l = 2024, r = 2026;
    cnt = 0;
    while (l <= 1e18 && l) {
        v2.push_back({l, r, cnt});
        if (l >= 1e9) {
            break;
        }
        l *= l;
        r *= r;
        ++cnt;
    }
    // for (auto [l, r, v] : v1) {
    //     cerr << l << " " << r << " " << v << endl;
    // }
    // for (auto [l, r, v] : v2) {
    //     cerr << l << " " << r << " " << v << endl;
    // }
}
int s1(int m) {
    auto it = upper_bound(v1.begin(), v1.end(), qujian{0, m});
    if (it == v1.end()) {
        return LLONG_MAX;
    }
    else {
        if (it->l < m) {
            return it->cnt;
        }
        else {
            return LLONG_MAX;
        }
    }
}
int s2(int m) {
    auto it = upper_bound(v2.begin(), v2.end(), qujian{0, m});
    if (it == v2.end()) {
        return LLONG_MAX;
    }
    else {
        if (it->l < m) {
            return it->cnt;
        }
        else {
            return LLONG_MAX;
        }
    }
}
void solve() {
    int m;
    cin >> m;

    int ans = min(s1(m), s2(m));
    // cerr << s1(m) << " " << s2(m);
    if (ans == LLONG_MAX) {
        cout << "(T_T)\n";
    }
    else {
        cout << ans << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
