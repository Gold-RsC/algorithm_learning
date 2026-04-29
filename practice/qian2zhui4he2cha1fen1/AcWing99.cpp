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
// #define int long long
struct Point {
    int x;
    int y;
};
int n, r;

const int N = 5e3 + 5;

int s[N][N];
int ans;
int maxx;
int maxy;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x + 1][y + 1] += w;
        maxx = max(maxx, x + 1);
        maxy = max(maxy, y + 1);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }
    if (r >= maxx && r >= maxy) {
        cout << s[maxx][maxy];
        return 0;
    }

    for (int i = 1; i + r - 1 < N; ++i) {
        for (int j = 1; j + r - 1 < N; ++j) {
            ans = max(ans, s[i + r - 1][j + r - 1] - s[i - 1][j + r - 1] - s[i + r - 1][j - 1] + s[i - 1][j - 1]);
        }
    }

    cout << ans;

    return 0;
}
