// 只能拿到30%，据说可以达到O(n^0.4)
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

const int N = 1e9 + 5;


int ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // 埃氏筛 O(n loglog n)
    vector<bool> b(n, false);
    b[1] = true;
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
            continue;
        }
        ++ans;
        for (int j = i * 2; j <= n; j += i) {
            b[j] = !b[j];
        }
    }
    cout << ans;


    return 0;
}
