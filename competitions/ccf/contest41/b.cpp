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
const int N = 11451, M = 1010;
double sum;
double dp[M];
int cnt;
int al[N];
double bl[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        sum += t;
        if (o == 0) {
            for (int j = 1; j < a; ++j) {
                al[cnt] = 1;
                bl[cnt] = double(b) / a;
                cnt++;
            }
            al[cnt] = 1;
            bl[cnt] = double(b) - (a - 1) * double(b) / a;
            cnt++;
        }
        else {
            al[cnt] = a;
            bl[cnt] = b;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        for (int w = m; w >= al[i]; --w) {
            dp[w] = max(dp[w], dp[w - al[i]] + bl[i]);
        }
    }
    cout << fixed << setprecision(6) << sum - dp[m];


    return 0;
}
