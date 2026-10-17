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
void solve() {
    int N;
    cin >> N;

    vector<int> vec;
    multiset<pair<int, int>> s;
    multiset<pair<int, int>> tmp;
    int ans    = 0;
    int sums   = 0;
    int cntW   = 0;
    auto solve = [&] {
        reverse(vec.begin(), vec.end());
        int len = vec.size() + 1;

        // 不够就从回收站取
        while (s.size() < cntW) {
            if (tmp.empty())
                break;
            auto it = tmp.rbegin();
            s.insert(*it);
            sums += it->first;
            tmp.erase(prev(tmp.end()));
        }

        // 插入段内的 F 的收益 (x * d / len, x * d % len)
        for (int i = 0; i < vec.size(); i++) {
            s.insert({vec[i] * (i + 1) / len, vec[i] * (i + 1) % len});
            ans += vec[i] * (i + 1);
        }
        ans += sums * len;

        // 只需要前 cntW 大，剩余都减去
        int num = s.size() - cntW;
        for (auto it = s.begin(); num > 0; it++) {
            num--;
            auto [q, r] = *it;
            ans -= q * len + r;
        }

        // 改换为插入之前的 F 的 (x, 0)
        for (int i = 0; i < vec.size(); i++) {
            s.extract({vec[i] * (i + 1) / len, vec[i] * (i + 1) % len});
            s.insert({vec[i], 0});
            sums += vec[i];
        }

        // 多余的删掉
        while (s.size() > cntW) {
            auto it = s.begin();
            sums -= it->first;
            tmp.insert(*it);
            s.erase(it);
        }

        vec.clear();
    };

    while (N--) {
        char C;
        cin >> C;

        if (C == 'W') {
            solve();
            cntW++;
        }
        else {
            int X;
            cin >> X;
            vec.push_back(X);
        }
    }
    solve();
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
