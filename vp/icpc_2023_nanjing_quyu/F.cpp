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
typedef long long ll;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m + 1, 0), cur(m + 1, 0), rd(n + 1, 0);
    vector<vector<ll>> ord(n + 1, vector<ll>()), tu(n + 1, vector<ll>());
    for (int i = 1; i <= n; i++) {
        ll p, tem;
        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> tem;
            ord[i].push_back(tem);
            a[tem] = i;
        }
    }
    if (n == 1) {
        cout << "No\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (auto mem : ord[i]) {
            if (a[mem] == i && cur[mem] != 0) {
                rd[cur[mem]]++;
                tu[i].push_back(cur[mem]);
            }
            cur[mem] = i;
        }
    }
    queue<ll> q, nq;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (rd[i] == 0)
            q.push(i);
    }
    while (cnt < n) {
        if (q.size() >= 2) {
            queue<ll> temq = q;
            ll w1 = -1, w2 = 1e18;
            while (!temq.empty()) {
                w1 = max(w1, temq.front());
                w2 = min(w2, temq.front());
                temq.pop();
            }

            cout << "Yes\n";
            for (int i = 1; i <= n; i++) {
                if (i == w1)
                    cout << w2;
                else if (i == w2)
                    cout << w1;
                else
                    cout << i;
                if (i != n)
                    cout << ' ';
                else
                    cout << '\n';
            }
            return;
        }
        while (!q.empty()) {
            ll tem = q.front();
            q.pop();
            for (auto mem : tu[tem]) {
                rd[mem]--;
                if (!rd[mem])
                    nq.push(mem);
            }
            cnt++;
        }
        swap(q, nq);
    }
    cout << "No\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
