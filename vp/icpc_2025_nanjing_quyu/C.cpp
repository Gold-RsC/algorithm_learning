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
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n" << n / 2 << ' ' << n / 2 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
