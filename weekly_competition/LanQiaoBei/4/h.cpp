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
#include <bitset>
using namespace std;
#define int uint64_t
const int N = 1e9 + 3;
int n;
bitset<N> a;
int ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            for (int j = i; j <= n; j += i) {
                a[j] = !a[j];
            }
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
