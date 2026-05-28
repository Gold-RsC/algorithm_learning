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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    vector<vector<int>> ans;
    for (int d = 1; d < n; ++d) {
        for (int begin_idx = 1; begin_idx <= d && begin_idx <= n - d; ++begin_idx) {
            vector<int> a;
            if (begin_idx != 1) {
                a.push_back(1);
            }
            for (int i = begin_idx; i < n; i += d) {
                a.push_back(i);
            }
            a.push_back(n);
            ans.push_back(a);
        }
    }

    cout << ans.size() << endl;
    for (auto& a : ans) {
        for (auto x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
