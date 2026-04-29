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
vector<int> a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int mid = a.size() / 2;
    for (int i = 0; i < a.size(); ++i) {
        ans += abs(a[i] - a[mid]);
    }
    cout << ans;
    return 0;
}
