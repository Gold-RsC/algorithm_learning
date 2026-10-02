#include <iostream>
using namespace std;
const int N = 1e5 + 10;

/**
 * @note 只有满足结合律的运算才可使用
 * @note 此模板是加法版的SegTree
 */

// 左闭右闭
struct Interval {
    int left, right;  // 所管理a的区间
    int root;         // 对应d的节点

    int mid(void) const {
        return left + (right - left) / 2;
    }
    int len(void) const {
        return right - left + 1;
    }

    int left_root(void) const {
        return root * 2;
    }
    int right_root(void) const {
        return root * 2 + 1;
    }

    int left_len(void) const {
        return mid() - left + 1;
    }
    int right_len(void) const {
        return right - mid();
    }

    Interval left_interval(void) const {
        return {left, mid(), root * 2};
    }
    Interval right_interval(void) const {
        return {mid() + 1, right, root * 2 + 1};
    }

    bool is_in(int find_left, int find_right) const {
        return find_left <= left && find_right >= right;
    }
};
struct SegTree {
    int a[N];  // 原始数据

    int d[4 * N];     // 节点
    int lazy[4 * N];  // 懒标记

    SegTree() {
        fill(d, d + 4 * N, 0);
        fill(lazy, lazy + 4 * N, 0);
    }
    // 由a数组建树
    void build(Interval interval) {
        if (interval.left == interval.right) {
            d[interval.root] = a[interval.left];
            return;
        }
        build(interval.left_interval());
        build(interval.right_interval());

        d[interval.root] = d[interval.left_root()] + d[interval.right_root()];  // 节点结合操作
    }

    // 分发懒标记
    void push_down(Interval interval) {
        // 判断：有懒标记且不是叶子节点
        if (lazy[interval.root] && interval.left < interval.right) {
            // 应用懒标记
            d[interval.left_root()]  = d[interval.left_root()] + lazy[interval.root] * interval.left_len();
            d[interval.right_root()] = d[interval.right_root()] + lazy[interval.root] * interval.right_len();
            // 下发懒标记
            lazy[interval.left_root()]  = lazy[interval.left_root()] + lazy[interval.root];
            lazy[interval.right_root()] = lazy[interval.right_root()] + lazy[interval.root];
            // 清空懒标记
            lazy[interval.root] = 0;
        }
    }

    // 区间查找(find_left==find_right时为单点查找)
    int query(int find_left, int find_right, Interval interval) {
        if (interval.is_in(find_left, find_right)) {
            return d[interval.root];
        }
        push_down(interval);

        int mid = interval.mid();
        int sum = 0;  // 单位元
        if (find_left <= mid) {
            sum += query(find_left, find_right, interval.left_interval());
        }
        if (find_right > mid) {
            sum += query(find_left, find_right, interval.right_interval());
        }
        return sum;
    }

    // 区间更新(update_left==update_right时为单点更新)
    void update(int update_left, int update_right, int delta_val, Interval interval) {
        if (interval.is_in(update_left, update_right)) {
            d[interval.root] += delta_val * interval.len();  // 更新节点
            lazy[interval.root] += delta_val;                // 更新懒标记
            return;
        }
        push_down(interval);

        int mid = interval.mid();
        if (update_left <= mid) {
            update(update_left, update_right, delta_val, interval.left_interval());
        }
        if (update_right > mid) {
            update(update_left, update_right, delta_val, interval.right_interval());
        }
        d[interval.root] = d[interval.left_root()] + d[interval.right_root()];  // 更新节点
    }
};

SegTree seg;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Interval init_interval{1, n, 1};

    for (int i = 1; i <= n; ++i) {
        cin >> seg.a[i];
    }
    seg.build(init_interval);
    int find_left, find_right;
    cin >> find_left >> find_right;
    cout << seg.query(find_left, find_right, init_interval);

    return 0;
}
