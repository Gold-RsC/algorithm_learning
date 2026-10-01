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
#define int long long

int n;
int k;
int m;

uint64_t state;
void init() {
    m     = 2 * n * (n + 1);
    state = (1ull << (m + 1)) - 2;
}
void clear(int x) {
    state &= ~(1ull << x);
}

bool ck(int x) {
    return state & (1ull << x);
}

bool check() {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            for (int len = 1; x + len <= n && y + len <= n; ++len) {
                for (int i = 0; i < len; ++i) {
                    if (!ck((y) * (2 * n + 1) + x + 1 + i)) {
                        goto ctn;
                    }
                    if (!ck((y + len) * (2 * n + 1) + x + 1 + i)) {
                        goto ctn;
                    }
                    if (!ck((y + i) * (2 * n + 1) + n + x + 1)) {
                        goto ctn;
                    }
                    if (!ck((y + i) * (2 * n + 1) + n + x + len + 1)) {
                        goto ctn;
                    }
                }
                return false;
            ctn:;
            }
        }
    }
    return true;
}


bool dfs(int ans) {
    if (!ans) {
        return check();
    }

    for (int i = 1; i <= m; ++i) {
        if (!ck(i)) {
            continue;
        }
        state &= ~(1ull << i);
        if (dfs(ans - 1)) {
            return true;
        }
        state |= (1ull << i);
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        cin >> k;
        init();
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;

            clear(x);
        }

        for (int ans = 0;; ++ans) {
            if (dfs(ans)) {
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}
