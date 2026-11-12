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
const int N = 1e6 + 5;
struct P {
    int a, b;
    bool operator<(const P& _) const {
        if (max(a, b) != max(_.a, _.b)) {
            return max(a, b) < max(_.a, _.b);
        }
        if (a != _.a) {
            return a < _.a;
        }
        return b < _.b;
    }
};
vector<P> a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    a.assign(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a.begin(), a.end());
    int x   = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].a >= x) {
            x = max(a[i].b, x);
            ++ans;
        }
    }
    cout << ans;

    return 0;
}
