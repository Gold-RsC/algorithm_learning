#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

const int N = 1e5 + 5;
int n, m;
int A[N];
uint64_t B[N];
uint64_t ans = ULLONG_MAX;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B[i] = uint64_t(A[i]) * A[i];
    }
    sort(B + 1, B + 1 + n);
    for (int i = m; i <= n; i++) {
        ans = min(ans, B[i] - B[i - m + 1]);
    }
    cout << ans;
    return 0;
}
