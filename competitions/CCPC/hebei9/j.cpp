#include <iostream>
#include <iomanip>
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
using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> pii;

vector<pii> ans;
map<int, vector<int>> pos;

int pre[N];

string s;

//[)
void dfs(int b, int e, int base) {
    if (b >= e) {
        return;
    }


    int target = pre[b] - (s[b] == '1' ? 1 : -1);

    const vector<int>& v = pos[target];


    int begin_idx;
    if (b) {
        begin_idx = lower_bound(v.begin(), v.end(), b - 1) - v.begin();
    }
    else {
        begin_idx = -1;
    }

    if (s[b] == '1') {
        ans.push_back({base, 2});
    }
    else {
        ans.push_back({base, 1});
    }

    dfs(b + 1, v[begin_idx + 1], base);
    int cnt = (v[begin_idx + 1] + 1 - b) / 2;
    dfs(v[begin_idx + 1] + 1, e, base + cnt);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> s;

    if (s.size() & 1) {
        cout << -1;
        return 0;
    }

    int cnt0 = 0;
    for (auto x : s) {
        if (x == '0') {
            ++cnt0;
        }
    }
    if (cnt0 * 2 != s.size()) {
        cout << -1;
        return 0;
    }

    int n = s.length();


    for (int i = 0, su = 0; i < n; ++i) {
        su += (s[i] == '1' ? 1 : -1);
        pre[i] = su;
        pos[su].push_back(i);
    }
    if (pre[n] != 0) {
        cout << -1 << endl;
        return 0;
    }

    dfs(0, n, 1);


    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }

    return 0;
}
