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
using namespace std;
#define int uint64_t
const int N = 1e3 + 5;
int n, m;
int a[N];
int b[N];
int c[N];
int cur[4] = {1, 1, 1, 1};
int ans;
int f() {
    int aa = a[cur[1]];
    int bb = b[cur[2]];
    int cc = c[cur[3]];
    if (aa == bb && bb == cc) {


        return 200;
    }
    if ((aa + 1 == bb && bb + 1 == cc) ||
        (aa - 1 == bb && bb - 1 == cc)) {

        return 200;
    }
    if (aa == bb || bb == cc || cc == aa) {

        return 100;
    }
    int s[] = {aa, bb, cc};
    sort(s, s + 2);
    if (s[0] + 1 == s[1] && s[1] + 1 == s[2]) {

        return 100;
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    cin >> m;
    while (m--) {
        int xa, xb, xc;
        cin >> xa >> xb >> xc;
        cur[1] = (cur[1] + xa + n - 1) % n + 1;
        cur[2] = (cur[2] + xb + n - 1) % n + 1;
        cur[3] = (cur[3] + xc + n - 1) % n + 1;
        ans += f();
    }
    cout << ans;

    return 0;
}
