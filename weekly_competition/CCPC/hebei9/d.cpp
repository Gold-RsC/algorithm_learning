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
int n, k;

// x,cnt
vector<pair<int, int>> r;

vector<int> sum;
vector<int> scnt;


bool check(int d) {
    int c = 0;
    for (int i = 0, j = 0; i < n && j < n; ++i) {
        if (j < i) {
            j = i;
        }
        while (j + 1 < n && r[j + 1].first - r[i].first <= d) {
            ++j;
        }

        // cerr << i << " " << j << " " << a[i] << " " << a[j] << endl;
        c += (scnt[j] - scnt[i]) * r[i].second + r[i].second * (r[i].second - 1) / 2;
        // cerr << i << " " << j << " c:" << c << endl;
        if (c >= k) {
            return true;
        }
    }

    // cerr << cnt << endl;
    return c >= k;
}
int get_sum(int d) {
    int ans = 0;
    int c   = 0;
    //[]
    for (int i = 0, j = 0; i < n && j < n; ++i) {
        if (j < i) {
            j = i;
        }
        while (j + 1 < n && r[j + 1].first - r[i].first < d) {
            ++j;
        }


        ans += (sum[j] - sum[i] - r[i].first * (scnt[j] - scnt[i])) * r[i].second;
        c += (scnt[j] - scnt[i]) * r[i].second + r[i].second * (r[i].second - 1) / 2;
    }

    ans += d * (k - c);
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for (auto x : a) {
            if (r.empty() || r.back().first != x) {
                r.push_back({x, 1});
            }
            else {
                ++r.back().second;
            }
        }
    }

    n = r.size();


    for (int i = 0, s = 0, c = 0; i < n; ++i) {
        s += r[i].first * r[i].second;
        c += r[i].second;
        sum.push_back(s);
        scnt.push_back(c);
    }

    // cerr << r.size() << " " << n << endl;
    int L = 0, R = r.back().first - r.front().first;
    while (L < R) {
        int d = L + (R - L >> 1);
        // cerr << L << " " << R << " " << d << endl;
        if (check(d)) {
            R = d;
        }
        else {
            L = d + 1;
        }
    }

    // cerr << l << " " << r << endl;

    cout << get_sum(L);


    return 0;
}
