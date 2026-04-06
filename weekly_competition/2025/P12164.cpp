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

int a[] = {2, 0, 2, 5};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int idx = (i + j) % 4;
            cout << a[idx];
        }
        cout << endl;
    }
    return 0;
}
