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
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define int long long
unordered_map<string, int> MAP{
    {"OR", 0},
    {"XOR", 1},
    {"AND", 2},
};

const int N = 1e5 + 5;


int n, m;

int op[N];
int t[N];

bool calc(int bit, bool f) {
    for (int i = 1; i <= n; ++i) {
        if (op[i] == 0) {
            f |= (t[i] >> bit) & 1;
        }
        else if (op[i] == 1) {
            f ^= (t[i] >> bit) & 1;
        }
        else {
            f &= (t[i] >> bit) & 1;
        }
    }
    return f;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    string tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp >> t[i];
        op[i] = MAP[tmp];
    }


    // 是否被限制
    bool flag = true;
    int ans   = 0;
    for (int bit = 30; bit >= 0; --bit) {
        bool res0 = calc(bit, 0);
        bool res1 = calc(bit, 1);
        if (flag) {
            if ((m >> bit) & 1) {
                if (res0 >= res1) {
                    flag = false;
                    ans |= res0 << bit;
                }
                else {
                    ans |= res1 << bit;
                }
            }
            else {
                ans |= res0 << bit;
            }
        }
        else {
            ans |= max(res0, res1) << bit;
        }
    }

    cout << ans;
    return 0;
}
