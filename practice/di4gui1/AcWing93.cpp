// 组合型枚举
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


int n, m;
vector<int> ans;
void w(int i, int count) {
    if (ans.size() == m) {
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    if (i > n) {
        return;
    }
    if (count < 0 || n - ans.size() < count) {
        return;
    }
    ans.push_back(i);
    w(i + 1, count - 1);
    ans.pop_back();
    w(i + 1, count);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;

    w(1, m);

    return 0;
}
