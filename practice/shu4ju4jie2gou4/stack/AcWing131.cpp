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
#define int long long
int a[100010];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a[n] = 0;

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                int height = a[s.top()];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                ans      = max(ans, (i - left - 1) * height);
            }
            s.push(i);
        }
        cout << ans << endl;
    }

    return 0;
}
