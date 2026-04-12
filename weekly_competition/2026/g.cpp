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
const int N = 1e5 + 10;
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
istream& operator>>(istream& is, __int128& a) {
    __int128 x = 0, f = 1;
    char ch;
    is.get(ch);
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        is.get(ch);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        is.get(ch);
    }
    a = x * f;
    return is;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}
ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) {
        os << __int128(x / 10);
    }
    os << char(x % 10 + '0');
    return os;
}
__int128 abs(__int128 x) {
    return x < 0 ? -x : x;
}
@
#define int __int128
    int n;
int a[N];
int pre[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                ans =
                    max(ans,
                        abs(pre[i]) + abs(pre[j] - pre[i]) +
                            abs(pre[k] - pre[j]) +
                            abs(pre[n] - pre[k]));
            }
        }
    }
    cout << ans;
    return 0;
}
