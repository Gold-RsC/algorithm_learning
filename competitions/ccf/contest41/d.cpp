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

const int N = 5e5 + 5;
int a[N];
int d[4 * N];
int lazy[4 * N];

int n, m, k;


struct Interval {
    int left, right;
    int root;

    int length() const {
        return right - left + 1;
    }
    int mid() const {
        return left + (right - left) / 2;
    }
    int left_root() const {
        return root * 2;
    }
    int right_root() const {
        return root * 2 + 1;
    }
    Interval left_interval() const {
        return {left, mid(), root * 2};
    }
    Interval right_interval() const {
        return {mid() + 1, right, root * 2 + 1};
    }
};

int cal_plus(int x, int y) {
    int ans = 0;
    for (int s = k; x || y; s *= k) {
        ans += (x % s + y % s) % s;
        x -= (x % s) * (s - 1);
        y -= (y % s) * (s - 1);
    }
    return ans;
}
int cal_multi(int x, int times) {
    int ans = 0;
    for (int s = k; x || y; s *= k) {
        ans += (x % s + y % s) % s;
        x -= (x % s) * (s - 1);
        y -= (y % s) * (s - 1);
    }
    return ans;
}
void build(Interval interval) {
    if (interval.left == interval.right) {
        d[interval.root] = a[interval.left];
        return;
    }
    build(interval.left_interval());
    build(interval.right_interval());

    d[interval.root] = cal_plus(d[interval.left_root()], d[interval.right_root()]);
}
void push_down(Interval interval) {
    if (lazy[interval.root] && interval.left < interval.right) {
        int mid                 = interval.mid();
        d[interval.left_root()] = lazy[interval.root] * ((mid - interval.left + 1) % k);
        d[interval.right_root()] += lazy[interval.root] * (interval.right - mid);

        lazy[interval.left_root()] += lazy[interval.root];
        lazy[interval.right_root()] += lazy[interval.root];
        lazy[interval.root] = 0;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    while (m--) {
        int t, l, r, v;
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> v;
        }
        else {
        }
    }
    return 0;
}
