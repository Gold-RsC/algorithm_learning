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
using namespace std;
#define int long long
const int N = 32005;

int n;
int bit[N];
int level[N];

int lowbit(int x) {
    return x & (-x);
}
void add(int i, int x) {
    for (; i <= N; i += lowbit(i)) {
        bit[i] += x;
    }
}
int sum(int i) {
    int s = 0;
    for (; i > 0; i -= lowbit(i)) {
        s += bit[i];
    }
    return s;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        level[sum(x + 1)]++;
        add(x + 1, 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << level[i] << endl;
    }
    return 0;
}
