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
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdint>
using namespace std;
#define int     long long
#define Moggity "Moggity\n"
#define Larpity "Larpity\n"
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cin >> n;
        cout << Moggity;
        return;
    }
    else if (n == 2) {
        int a, b;
        cin >> a >> b;

        if (a & 1) {
            swap(a, b);
        }

        if (b & 1) {
            if (a & 1) {
                cout << Moggity;
            }
            else {
                cout << Larpity;
            }
        }
        else {
            cout << Moggity;
        }
        return;
    }
    int jishu = 0;
    int s     = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a & 1) {
            ++jishu;
            s ^= 1;
        }
    }
    if (s & 1) {
        if ((jishu >= 3 && n > 3) || ((n - jishu) >= 1 && jishu >= 1)) {
            cout << Moggity;
        }
        else {
            cout << Larpity;
        }
    }
    else {
        cout << Moggity;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
