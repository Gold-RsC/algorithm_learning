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

bool check(int a) {
    int high_bit = 0;
    for (int i = 32; i >= 0; i--) {
        if ((a >> i) & 1) {
            high_bit = i;
            break;
        }
    }
    if (!(high_bit & 1)) {
        return false;
    }
    int cnt = 0;
    while (a) {
        cnt++;
        a &= a - 1;
    }
    return (cnt << 1) == (high_bit + 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int a;
        cin >> a;

        if (check(a)) {
            ans++;
        }
    }
    cout << ans;


    return 0;
}
