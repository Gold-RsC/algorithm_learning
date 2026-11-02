// 没做出来
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
#define int long long
const int N = 1e6 + 5;

int l, u;
vector<int> primes;
int v[N];

int last_i = 1;
pair<int, int> ans_min, ans_max;
int mmin = INT_MAX, mmax = 0;
void solve() {

    memset(v, 0, sizeof(v));
    for (int i = 2; i <= sqrt(u); ++i) {
        if (v[i] == 0) {
            v[i] = i;
            primes.push_back(i);
            cerr << i << endl;
        }
        for (auto x : primes) {
            if (x > v[i] || x > sqrt(u) / i) {
                break;
            }
            v[i * x] = x;
        }
        last_i = i;
    }
    memset(v, 0, sizeof(v));
    for (auto x : primes) {

        for (int i = (l == x ? 2 * x : l / x * x + ((l % x == 0) ? 0 : 1)); i <= u; i += x) {
            v[i - l] = 1;
        }
    }
    mmin = INT_MAX, mmax = 0;
    ans_max = ans_min = {0, 0};
    for (int i = l - 1, j = l; i <= u - l && j <= u - l;) {
        cerr << i << " " << j << " ";
        do {
            ++i;
        } while ((i <= u - l) && (v[i - l]));
        do {
            ++j;
        } while ((j <= u - l) && (j <= i || v[j - l]));
        cerr << i << " " << j << endl;

        if (j - i > mmax) {
            mmax    = j - i;
            ans_max = {i, j};
        }
        if (j - i < mmin) {
            mmin    = j - i;
            ans_min = {i, j};
        }
    }
    if (mmax == 0) {
        cout << "There are no adjacent primes.\n";
    }
    else {
        cout << ans_min.first << "," << ans_min.second << " are closest, " << ans_max.first << "," << ans_max.second
             << " are most distant.\n";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // while (!cin.eof()) {
    cin >> l >> u;
    solve();
    // }
    return 0;
}
