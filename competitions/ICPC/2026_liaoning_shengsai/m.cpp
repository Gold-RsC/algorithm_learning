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

void solve_first() {
    int n;
    cin >> n;
    vector<int> parent(n + 1, 0);
    vector<int> ans;
    int p           = 1;
    int last_parent = 2;
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        if (parent[i] == 1) {
            continue;
        }
        else if (last_parent != parent[i]) {
            p += parent[i] - last_parent;
            last_parent = parent[i];
        }
        ans.push_back(p++);
    }
    ans.push_back(n - 1);
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
void solve_second() {
    int m;
    cin >> m;
    vector<int> a(m, 0);
    int n = 0;
    for (auto& x : a) {
        cin >> x;
        n = max(n, x);
    }
    ++n;
    vector<bool> exist(n + 1, 0);
    for (auto x : a) {
        exist[x] = true;
    }

    vector<int> parent(n + 1, 0);
    int cnt    = 1;
    int erceng = 0;
    for (int i = 1; i < n; ++i) {
        if (!exist[i] || i == n - 1) {
            parent[erceng + 2] = 1;
            ++erceng;
        }
        ++cnt;
        if (cnt == n) {
            break;
        }
    }
    int p = 2;
    cnt   = 1;
    for (int i = 1; i < n; ++i) {
        int c = erceng + 3 + i - p;
        if (exist[i] && i != n - 1) {
            parent[c] = p;
        }
        else {
            ++p;
        }
        ++cnt;
        if (cnt == n) {
            break;
        }
    }
    cout << n << '\n';
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int t;
    cin >> t;

    if (s == "first") {
        while (t--) {
            solve_first();
            cout.flush();
        }
    }
    else {
        while (t--) {
            solve_second();
            cout.flush();
        }
    }

    return 0;
}
