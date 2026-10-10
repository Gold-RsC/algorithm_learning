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
unordered_map<int, int> m;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        m[a]++;
    }
    if (m.size() > 2) {
        cout << "No\n";
        return 0;
    }
    else if (m.size() == 1) {
        cout << ((a == n - 1 || 2 * a <= n) ? "Yes\n" : "No\n");
        return 0;
    }

    int k;
    if (m.find(a + 1) != m.end()) {
        k = a + 1;
    }
    else if (m.find(a - 1) != m.end()) {
        k = a;
    }
    else {
        cout << "No\n";
        return 0;
    }

    if (m[k] >= 2 * (k - m[k - 1]) && k - m[k - 1] > 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
