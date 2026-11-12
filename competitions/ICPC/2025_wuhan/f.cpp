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
const int N   = 1e9 + 5;
const int MOD = 998244353;

int n, m;

// b a
map<int, int> item;


void add_item(int a, int b) {
    item[b] += a;
    if (!item[b])
        return;
    while (item[b] > m) {
        if ((item[b] - m) % 2 == 0) {
            item[b + 1] += (item[b] - m) / 2;
        }
        else {
            item[b + 1] += (item[b] - m + 1) / 2;
        }
        item[b] = m - (item[b] - m) % 2;
        b++;
    }
}
int ans;

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

bool try_feisheng(int expect, map<int, int>::reverse_iterator it, map<int, int>::reverse_iterator jt) {
    if (jt == item.rend()) {
        return false;
    }
    if (jt->second == 0) {
        jt++;
        return try_feisheng(expect, it, jt);
    }

    auto [b, _]   = *it;
    auto& a       = item[b];
    auto [jb, __] = *jt;
    auto& ja      = item[jb];
    if (b - jb > 31) {
        return false;
    }
    int ok = ja >> (b - jb);

    // cerr << "jb: " << jb << "expecet: " << expect << " ok: " << ok << endl;
    if (ok >= expect) {
        ja -= expect << (b - jb);
        a += expect;
        return true;
    }
    else {
        ja -= ok << (b - jb);
        a += ok;
        expect -= ok;
    }

    auto kt = jt;
    kt++;
    if (expect >> (31 - (b - jb))) {
        return false;
    }
    bool flag = try_feisheng((expect << (b - jb)) - ja, jt, kt);
    if (flag) {
        ok = ja >> (b - jb);
        if (ok >= expect) {
            ja -= expect << (b - jb);
            a += expect;
            return true;
        }
        else {
            ja -= ok << (b - jb);
            a += ok;
            expect -= ok;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    item.clear();
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        add_item(a, b);
    }
    // cerr << "===================" << endl;
    // for (int i = 0; i <= 5; ++i) {
    //     cerr << "[" << i << "] " << item[i] << endl;
    // }
    // cerr << "===================" << endl;
    for (auto it = item.rbegin(); it != item.rend(); ++it) {
        auto& [b, a] = *it;
        if (!a) {
            continue;
        }

        int left = m - a;
        // cerr << "left: " << left << endl;
        ans = (ans + qpow(2, b) % MOD) % MOD;
        // cerr << "add ans: " << ans << endl;
        if (left) {
            auto jt = it;
            jt++;
            bool flag = try_feisheng(left, it, jt);
            a         = 0;

            if (flag) {
            }
            else {
                break;
            }
        }
        // cerr << "===================" << endl;
        // for (int i = 0; i <= 5; ++i) {
        //     cerr << "[" << i << "] " << item[i] << endl;
        // }
        // cerr << "===================" << endl;
    }

    cout << ans << '\n';
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
