#include <iostream>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int d[4 * N];
int lazy[4 * N];
struct Interval {
    int left, right;  // 所管理的区间
    int root;         // 对应的节点
};

#define MID                                                \
    interval.left + (interval.right - interval.left) / 2
#define LEFT_INTERVAL                                      \
    {interval.left, mid, interval.root * 2}
#define RIGHT_INTERVAL                                     \
    {mid + 1, interval.right, interval.root * 2 + 1}
void build(Interval interval) {
    if (interval.left == interval.right) {
        d[interval.root] = a[interval.left];
        return;
    }
    int mid = MID;
    build(LEFT_INTERVAL);
    build(RIGHT_INTERVAL);
    // 求和
    d[interval.root] =
        d[interval.root * 2] + d[interval.root * 2 + 1];
}

void push_down(Interval interval) {
    if (lazy[interval.root] &&
        interval.left < interval.right) {
        int mid = MID;
        d[interval.root * 2] +=
            lazy[interval.root] * (mid - interval.left + 1);
        d[interval.root * 2 + 1] +=
            lazy[interval.root] * (interval.right - mid);

        lazy[interval.root * 2] += lazy[interval.root];
        lazy[interval.root * 2 + 1] += lazy[interval.root];
        lazy[interval.root] = 0;
    }
}
int query_sum(int find_left,
              int find_right,
              Interval interval) {
    if (find_left <= interval.left &&
        interval.right <= find_right) {
        return d[interval.root];
    }
    push_down(interval);

    int mid = MID;
    int sum = 0;
    if (find_left <= mid) {
        sum +=
            query_sum(find_left, find_right, LEFT_INTERVAL);
    }
    if (find_right > mid) {
        sum += query_sum(
            find_left, find_right, RIGHT_INTERVAL);
    }
    return sum;
}

void update(int update_left,
            int update_right,
            int delta_val,
            Interval interval) {
    if (update_left <= interval.left &&
        interval.right <= update_right) {
        d[interval.root] +=
            (interval.right - interval.left + 1) *
            delta_val;
        lazy[interval.root] += delta_val;
        return;
    }
    push_down(interval);

    int mid = MID;
    if (update_left <= mid) {
        update(update_left,
               update_right,
               delta_val,
               LEFT_INTERVAL);
    }
    if (update_right > mid) {
        update(update_left,
               update_right,
               delta_val,
               RIGHT_INTERVAL);
    }
    d[interval.root] =
        d[interval.root * 2] + d[interval.root * 2 + 1];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build({1, n, 1});
    int find_left, find_right;
    cin >> find_left >> find_right;
    cout << query_sum(find_left, find_right, {1, n, 1});

    return 0;
}
