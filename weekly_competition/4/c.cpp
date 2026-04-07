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
typedef long long ll;
string s;
char b, e;
ll k;
ll ans;
vector<int> e_idx_arr;
vector<int> b_idx_arr;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> s >> b >> e;
    for (int i = 0; i < s.size(); ++i) {
        auto x = s[i];
        if (x == b) {
            b_idx_arr.push_back(i);
        }
        if (x == e) {
            e_idx_arr.push_back(i);
        }
    }
    if (!b_idx_arr.empty() && !e_idx_arr.empty() &&
        (e_idx_arr.back() >= b_idx_arr.front() + k)) {
        for (int b_i = 0, e_i = 0;
             b_i < b_idx_arr.size() &&
             e_i < e_idx_arr.size();) {
            int i = b_idx_arr[b_i];
            int j = e_idx_arr[e_i];
            // cerr << i << " " << j << " "
            //      << e_idx_arr.size() - e_i << endl;
            if (j + 1 < i + k) {
                ++e_i;
            }
            else {
                ans += e_idx_arr.size() - e_i;
                ++b_i;
            }
        }
    }

    cout << ans;

    return 0;
}
