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
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> fac;
    int ans = 0;

    multiset<pair<int, int>> s;
    multiset<pair<int, int>> tmp;

    int sum = 0;

    int wcnt = 0;

    int last_wcnt = -1;

    auto doit = [&] {
        int len = fac.size() + 1;

        while (s.size() < wcnt) {
            if (tmp.empty()) {
                break;
            }
            s.insert(*tmp.rbegin());
            auto [q, r] = *tmp.rbegin();
            sum += q;
            tmp.erase(prev(tmp.end()));
        }

        for (int i = 0; i < fac.size(); ++i) {
            s.insert({fac[i] * (fac.size() - i) / len, fac[i] * (fac.size() - i) % len});
            ans += fac[i] * (fac.size() - i);
        }
        ans += sum * len;

        int num = s.size() - wcnt;
        for (auto it = s.begin(); num > 0; it++) {
            num--;
            auto [q, r] = *it;
            ans -= q * len + r;
        }
        for (int i = 0; i < fac.size(); i++) {
            s.extract({fac[i] * (fac.size() - i) / len, fac[i] * (fac.size() - i) % len});
            s.insert({fac[i], 0});
            sum += fac[i];
        }
        while (s.size() > wcnt) {
            auto it = s.begin();
            sum -= it->first;
            tmp.insert(*it);
            s.erase(it);
        }

        fac.clear();
    };


    for (int i = 0; i < n; ++i) {
        char c;

        cin >> c;
        if (c == 'F') {
            int x;
            cin >> x;
            fac.push_back(x);
        }
        else {
            doit();
            ++wcnt;
        }
    }
    doit();
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
