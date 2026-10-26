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
const int N       = 2e5 + 5;
const int MAXNODE = N * 24;

int lr[MAXNODE];
int rr[MAXNODE];
struct Interval {
    int left, right;
    int node;

    int len() const {
        return right - left + 1;
    }
    int mid() const {
        return (left + right) >> 1;
    }
    int left_node() const {
        return lr[node];
    }
    int right_node() const {
        return rr[node];
    }
    Interval left_interval() const {
        return {left, mid(), left_node()};
    }
    Interval right_interval() const {
        return {mid() + 1, right, right_node()};
    }
    bool is_leaf() const {
        return left == right;
    }
    bool is_in(int find_left, int find_right) const {
        return find_left <= left && right <= find_right;
    }
};

int root[N];  // root[v]表示小于等于v的线段树顶点
int tot;
int dd[MAXNODE];  // d[node]表示该版本树上值处在node代表的区间上的个数

int new_node() {
    return ++tot;
}
int build(Interval interval) {
    interval.node = new_node();
    if (interval.is_leaf()) {
        return interval.node;
    }
    lr[interval.node] = build(interval.left_interval());
    rr[interval.node] = build(interval.right_interval());
    return interval.node;
}
int clone_new_node(int from) {
    int node = new_node();
    lr[node] = lr[from];
    rr[node] = rr[from];
    dd[node] = dd[from] + 1;
    return node;
}
void push_up(Interval interval) {
    if (!interval.is_leaf()) {
        dd[interval.node] = dd[interval.left_node()] + dd[interval.right_node()];
    }
}
int update(Interval interval, int v) {
    interval.node = clone_new_node(interval.node);
    if (interval.is_leaf()) {
        return interval.node;
    }
    int mid = interval.mid();
    if (v <= mid) {
        lr[interval.node] = update(interval.left_interval(), v);
    }
    else {
        rr[interval.node] = update(interval.right_interval(), v);
    }
    push_up(interval);
    return interval.node;
}
int query(int rt_l, int rt_r, int interval_l, int interval_r, int k) {
    if (interval_l == interval_r) {
        return interval_l;
    }
    int x   = dd[lr[rt_r]] - dd[lr[rt_l]];
    int mid = (interval_l + interval_r) / 2;
    if (x >= k) {
        return query(lr[rt_l], lr[rt_r], interval_l, mid, k);
    }
    return query(rr[rt_l], rr[rt_r], mid + 1, interval_r, k - x);
}

int n, m;
int a[N];
pair<int, int> b[N];
int toRaw[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b + 1, b + 1 + n);

    int rank       = 0;
    int last_value = -1;
    for (int i = 1; i <= n; ++i) {
        auto [v, idx] = b[i];
        if (v != last_value) {
            ++rank;
            last_value = v;
        }
        a[idx]      = rank;
        toRaw[rank] = v;
    }

    root[0] = build({1, n, -1});
    for (int i = 1; i <= n; ++i) {
        root[i] = update({1, n, root[i - 1]}, a[i]);
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << toRaw[query(root[l - 1], root[r], 1, n, k)] << '\n';
    }

    return 0;
}
