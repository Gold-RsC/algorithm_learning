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
#define int  long long
#define endl "\n"
const int N = 1e4 + 5;
int n;
int d[N];
int p, h;
map<pair<int, int>, bool> s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int m;
    cin >> n >> p >> h >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
            swap(a, b);
        }
        if (s[{a, b}]) {
            continue;
        }
        s[{a, b}] = true;
        d[a + 1]--;
        d[b]++;
    }


    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        cout << (h - d[p] + d[i]) << endl;
    }

    return 0;
}
