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
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

const int N            = 2e3 + 5;
const int M            = 5e3 + 5;
const long double _INF = -1e256l;

int a[N];
int b[N];
int c[N];
int d[N];
int e[N];
int p[N];

template <typename _T>
void chmax(_T& a, const _T& b) {
    a = max(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p[i];
    }

    vector f(m + 1, vector(2, vector<long double>(2, 0)));


    for (int i = n; i >= 1; --i) {
        vector nf(m + 1, vector(2, vector<long double>(2, _INF)));

        long double cp = p[i] * 0.01;
        long double cq = 1 - cp;
        for (int w = 0; w <= m; ++w) {
            // Ê³ÌÃ
            if (w + b[i] <= m) {
                chmax(nf[w + b[i]][0][0], cp * f[w][1][0] + cq * f[w][0][1] + a[i]);
                chmax(nf[w + b[i]][0][1], cp * f[w][1][1] + cq * f[w][0][1] + a[i]);
                chmax(nf[w + b[i]][1][0], cp * f[w][1][0] + cq * f[w][1][1] + a[i]);
                chmax(nf[w + b[i]][1][1], f[w][1][1] + a[i]);
            }
            // ³öÈ¥³Ô
            if (w + d[i] <= m) {
                chmax(nf[w + d[i]][0][0], cp * f[w][1][0] + cq * f[w][0][1] + c[i]);
                chmax(nf[w + d[i]][0][1], cp * f[w][1][1] + cq * f[w][0][1] + c[i]);
                chmax(nf[w + d[i]][1][0], cp * f[w][1][0] + cq * f[w][1][1] + c[i]);
            }
            if (w + d[i] + e[i] <= m) {
                chmax(nf[w + d[i] + e[i]][1][1], f[w][0][0] + c[i]);
            }
        }
        f = move(nf);
    }

    long double ans = -1;
    for (int i = 0; i <= m; ++i) {
        chmax(ans, f[i][0][0]);
    }
    if (ans < 0) {
        cout << "-1";
    }
    else {
        cout << fixed << setprecision(12) << ans;
    }

    return 0;
}
