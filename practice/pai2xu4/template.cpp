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

/**
 * @name discrete
 * @brief 离散化
 */
vector<int> discrete(vector<int> a) {
    if (a.empty()) {
        return {};
    }
    sort(a.begin(), a.end());
    vector<int> r;
    r.push_back(a.front());
    int last = a.front();
    for (auto x : a) {
        if (last != x) {
            r.push_back(x);
            last = x;
        }
    }
    return r;
}

/**
 * @note 中位数到所有点的距离之和最小
 */


/**
 * @name
 */
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    return 0;
}
