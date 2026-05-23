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

vector<int> v;
int n, m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = i + 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (v[i] * v[mid] >= m) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        ans += n - l;
    }
    cout << ans;

    return 0;
}
