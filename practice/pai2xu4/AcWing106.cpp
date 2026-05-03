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


priority_queue<int, vector<int>, greater<int>> small;
priority_queue<int, vector<int>, less<int>> big;

void pingheng(int n) {
    while (big.size() != n / 2 || big.top() > small.top()) {
        if (big.size() < n / 2) {
            big.push(small.top());
            small.pop();
        }
        else if (big.size() > n / 2) {
            small.push(big.top());
            big.pop();
        }
        else if (big.top() > small.top()) {
            int x = big.top();
            int y = small.top();
            big.pop();
            small.pop();
            big.push(y);
            small.push(x);
        }
    }
}
void solve() {
    small = {};
    big   = {};

    int m;
    cin >> m;
    cout << (m + 1) / 2 << endl;

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;


        big.push(x);
        pingheng(i);

        if (i & 1) {
            cout << small.top() << " \n"[(i + 1) / 2 % 10 == 0];
        }
    }
    if ((m + 1) / 2 % 10) {
        cout << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p;
    cin >> p;
    while (p--) {
        int n;
        cin >> n;
        cout << n << " ";
        solve();
    }
    return 0;
}
