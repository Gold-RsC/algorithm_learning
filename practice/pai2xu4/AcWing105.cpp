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
const int N = 1e5 + 5;

int n, m, t;

int a[N];
bool row_can, col_can;

int rows[N];
int cols[N];

int c[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        rows[x]++;
        cols[y]++;
    }

    if (t % n == 0) {
        col_can = true;
    }
    if (t % m == 0) {
        row_can = true;
    }
    if (col_can && row_can) {
        cout << "both ";
    }
    else if (col_can) {
        cout << "row ";
    }
    else if (row_can) {
        cout << "column ";
    }
    else {
        cout << "impossible";
        return 0;
    }
    int ans = 0;

    if (row_can) {
        int avr = 0;
        for (int i = 1; i <= m; ++i) {
            avr += cols[i];
        }
        avr /= m;
        for (int i = 1; i <= m; ++i) {
            cols[i] -= avr;
        }
        for (int i = 1; i <= m; ++i) {
            c[i] = c[i - 1] + cols[i];
        }
        sort(c + 1, c + m + 1);
        int mid = m / 2 + 1;
        for (int i = 1; i <= m; ++i) {
            ans += abs(c[i] - c[mid]);
        }
    }
    if (col_can) {
        int avr = 0;
        for (int i = 1; i <= n; ++i) {
            avr += rows[i];
        }
        avr /= n;
        for (int i = 1; i <= n; ++i) {
            rows[i] -= avr;
        }
        for (int i = 1; i <= n; ++i) {
            c[i] = c[i - 1] + rows[i];
        }
        sort(c + 1, c + n + 1);
        int mid = n / 2 + 1;
        for (int i = 1; i <= n; ++i) {
            ans += abs(c[i] - c[mid]);
        }
    }


    cout << ans;


    return 0;
}
