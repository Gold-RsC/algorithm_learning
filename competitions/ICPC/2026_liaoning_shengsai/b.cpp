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

const int N = 2e5 + 5;
int a[N];
int c[N];

int pre_thinking[N];
// c[i] i
priority_queue<pair<int, int>> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre_thinking[i] = pre_thinking[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    int ans   = 0;
    int sikao = 0;
    for (int i = 1; i <= n; ++i) {
        q.push(pair<int, int>{c[i], i});
        sikao += c[i];
        while (!q.empty() && sikao + pre_thinking[i] > t) {
            auto [cc, idx] = q.top();
            q.pop();
            sikao -= cc;
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans;


    return 0;
}
