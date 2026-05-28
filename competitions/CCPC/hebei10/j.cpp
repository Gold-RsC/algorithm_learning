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
int n, m;

int ans_id;
int ans_num;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int c = (m / b) * 12 + (m - (m / b) * b) / a;
        int d = m / a;
        c     = max(c, d);
        if (c > ans_num) {
            ans_id  = i + 1;
            ans_num = c;
        }
    }
    cout << ans_num << " " << ans_id;

    return 0;
}
