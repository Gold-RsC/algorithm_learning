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

const int N       = 1e6 + 5;
const int MAXNODE = N * 24;
int lr[MAXNODE];  // lr[node]
int rr[MAXNODE];  // rr[node]

struct Interval {
    int left, right;  // 所管理a的区间
    int node;         // 对应d的节点

    inline int mid(void) const {
        return left + (right - left) / 2;
    }
    inline int len(void) const {
        return right - left + 1;
    }

    inline int left_len(void) const {
        return mid() - left + 1;
    }
    inline int right_len(void) const {
        return right - mid();
    }

    inline int left_node(void) const {
        return lr[node];
    }
    inline int right_node(void) const {
        return rr[node];
    }

    inline Interval left_interval(void) const {
        return {left, mid(), left_node()};
    }
    inline Interval right_interval(void) const {
        return {mid() + 1, right, right_node()};
    }

    inline bool is_leaf(void) const {
        return left == right;
    }
    inline bool is_in(int find_left, int find_right) const {
        return find_left <= left && find_right >= right;
    }
};

int a[N];
int d[MAXNODE];  // d[node]
int node_cnt;

int root[N];  // root[version]
int version_cnt;

inline int new_node() {
    return ++node_cnt;
}
int clone_new_node(int from) {
    int node = new_node();
    lr[node] = lr[from];
    rr[node] = rr[from];
    d[node]  = d[from];
    return node;
}
void push_up(Interval interval) {
    if (!interval.is_leaf()) {
        d[interval.node] = d[interval.left_node()] + d[interval.right_node()];
    }
}
int build(Interval interval) {  // interval.node无需填
    interval.node = new_node();
    if (interval.is_leaf()) {
        d[interval.node] = a[interval.left];
        return interval.node;
    }
    lr[interval.node] = build(interval.left_interval());
    rr[interval.node] = build(interval.right_interval());
    push_up(interval);
    return interval.node;
}

int query(Interval interval, int find_left, int find_right) {
    if (interval.is_in(find_left, find_right)) {
        return d[interval.node];
    }

    int mid = interval.mid();
    int sum = 0;
    if (find_left <= mid) {
        sum += query(interval.left_interval(), find_left, find_right);
    }
    if (find_right > mid) {
        sum += query(interval.right_interval(), find_left, find_right);
    }
    return sum;
}
int update(Interval interval, int find_left, int find_right, int delta_val) {
    interval.node = clone_new_node(interval.node);
    if (interval.is_in(find_left, find_right)) {
        d[interval.node] += delta_val * interval.len();
        return interval.node;
    }

    int mid = interval.mid();
    if (find_left <= mid) {
        lr[interval.node] = update(interval.left_interval(), find_left, find_right, delta_val);
    }
    if (find_right > mid) {
        rr[interval.node] = update(interval.right_interval(), find_left, find_right, delta_val);
    }
    push_up(interval);
    return interval.node;
}

int n, m;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    root[version_cnt++] = build({0, n - 1, 0});
    while (m--) {
        int v, op, p, c;
        cin >> v >> op >> p;
        --p;
        int q = query({0, n - 1, root[v]}, p, p);
        if (op == 1) {
            cin >> c;

            root[version_cnt++] = update({0, n - 1, root[v]}, p, p, c - q);
        }
        else {
            cout << q << '\n';
            root[version_cnt++] = root[v];
        }
    }

    return 0;
}
