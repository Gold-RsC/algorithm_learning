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
const int N = 3e5 + 5;

int n, m;
vector<vector<int>> exam;
void solve() {
    int op;
    cin >> op;
    if (op == 1) {
        int idx, x;
        cin >> idx >> x;
        exam[idx].push_back(x);
    }
    else {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        swap(exam[i1][j1], exam[i2][j2]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    exam.assign(n + 1, vector<int>(1, 0));
    while (m--) {
        solve();
    }
    for (int i = 1; i < exam.size(); ++i) {
        cout << exam[i].size() - 1;
        if (exam[i].size() - 1) {
            for (int j = 1; j < exam[i].size(); ++j) {
                cout << ' ' << exam[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
