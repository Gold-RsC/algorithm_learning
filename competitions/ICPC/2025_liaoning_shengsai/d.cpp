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
#include <iterator>
#include <cmath>
#include <cstring>
#include <cstdint>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<bitset<3>> b(n + 1, 0);
    vector<int> cc(3, 0);
    for (int i = 1; i <= n; ++i) {
        bool x, y, z;
        cin >> x >> y >> z;
        if (x) {
            b[i].set(0);
            ++cc[0];
        }
        if (y) {
            b[i].set(1);
            ++cc[1];
        }
        if (z) {
            b[i].set(2);
            ++cc[2];
        }
    }

    int final_ans = 5;
    vector<int> permuattion{0, 1, 2};
    do {
        int ans             = 0;
        vector<bitset<3>> a = b;
        vector<int> cnt     = cc;
        for (auto i : permuattion) {
            if (cnt[i] == 0) {
                continue;
            }
            for (int j = 1; j < a.size();) {
                if (a[j].test(i)) {
                    for (int k = 0; k < 3; ++k) {
                        cnt[k] -= a[j].test(k);
                    }
                    a.erase(a.begin() + j);
                }
                else {
                    ++j;
                }
            }
            ++ans;
        }
        final_ans = min(ans, final_ans);
    } while (next_permutation(permuattion.begin(), permuattion.end()));
    cout << final_ans;


    return 0;
}
