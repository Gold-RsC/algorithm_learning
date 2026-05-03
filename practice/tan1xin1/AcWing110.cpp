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
const int N = 1001;
int c, l;
vector<pair<int, int>> SPF;
int cover[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> l;

    for (int i = 0; i < c; ++i) {
        int x, y;
        cin >> x >> y;
        SPF.push_back({y, x});
    }
    sort(SPF.begin(), SPF.end());
    for (int i = 0; i < l; ++i) {
        int x, y;
        cin >> x >> y;
        cover[x] += y;
    }
    int ans = 0;
    // int spf = 1;
    for (auto [y, x] : SPF) {

        for (int spf = x; spf <= y; ++spf) {
            if (cover[spf]) {
                --cover[spf];
                ++ans;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
