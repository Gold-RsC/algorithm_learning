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

const int N = 1e6 + 5;
int a[N][26];
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    a[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            a[i][j] = a[i - 1][j];
        }
        ++a[i][s[i] - 'a'];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = max(ans, a[r][i] - (l ? a[l - 1][i] : 0));
        }
        cout << ans << endl;
    }


    return 0;
}
