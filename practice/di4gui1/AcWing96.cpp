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
int n;

int h3[20] = {0, 1};
int hannuo3(int x) {
    if (x == 0) {
        return 0;
    }
    if (h3[x]) {
        return h3[x];
    }
    return h3[x] = hannuo3(x - 1) * 2 + 1;
}

int ans[20];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    n = 12;


    memset(ans, 0x3f, sizeof(ans));
    ans[1] = 1;
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i < j; ++i) {
            ans[j] = min(ans[j],
                         2 * ans[i] +
                             2 * hannuo3(j - i - 1) + 1);
        }
    }
    for (int j = 1; j <= n; ++j) {
        cout << ans[j] << endl;
    }

    return 0;
}
