#include <iostream>
using namespace std;
#define int uint64_t
const int N = 1e5 + 10;

int a[N];
int d[4 * N];
int lazy[4 * N];
struct Interval {
    int left, right;  // 所管理的区间
    int root;         // 对应的节点
};

void build(Interval interval) {
    if (interval.left == interval.right) {
        d[interval.root] = a[interval.left];
        return;
    }
    int mid = interval.left + (interval.right - interval.left) / 2;
    build({interval.left, mid, interval.root * 2});
    build({mid + 1, interval.right, interval.root * 2 + 1});
    // 求和
    d[interval.root] = d[interval.root * 2] + d[interval.root * 2 + 1];
}

void push_down(Interval interval) {
    if (lazy[interval.root] && interval.left < interval.right) {
        int mid = interval.left + (interval.right - interval.left) / 2;
        d[interval.root * 2] += lazy[interval.root] * (mid - interval.left + 1);
        d[interval.root * 2 + 1] += lazy[interval.root] * (interval.right - mid);

        lazy[interval.root * 2] += lazy[interval.root];
        lazy[interval.root * 2 + 1] += lazy[interval.root];
        lazy[interval.root] = 0;
    }
}
int query_sum(int find_left, int find_right, Interval interval) {
    if (find_left <= interval.left && interval.right <= find_right) {
        return d[interval.root];
    }
    push_down(interval);

    int mid = interval.left + (interval.right - interval.left) / 2;
    int sum = 0;
    if (find_left <= mid) {
        sum += query_sum(find_left, find_right, {interval.left, mid, interval.root * 2});
    }
    if (find_right > mid) {
        sum += query_sum(find_left, find_right, {mid + 1, interval.right, interval.root * 2 + 1});
    }
    return sum;
}

void update(int update_left, int update_right, int delta_val, Interval interval) {
    if (update_left <= interval.left && interval.right <= update_right) {
        d[interval.root] += (interval.right - interval.left + 1) * delta_val;
        lazy[interval.root] += delta_val;
        return;
    }
    push_down(interval);

    int mid = interval.left + (interval.right - interval.left) / 2;
    if (update_left <= mid) {
        update(update_left, update_right, delta_val, {interval.left, mid, interval.root * 2});
    }
    if (update_right > mid) {
        update(update_left, update_right, delta_val, {mid + 1, interval.right, interval.root * 2 + 1});
    }
    d[interval.root] = d[interval.root * 2] + d[interval.root * 2 + 1];
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build({1, n, 1});
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update(x, y, k, {1, n, 1});
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query_sum(x, y, {1, n, 1}) << "\n";
        }
    }

    return 0;
}
