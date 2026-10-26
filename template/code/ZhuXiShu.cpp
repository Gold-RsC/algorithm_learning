const int N       = 1e5 + 5;
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
int d[MAXNODE];     // d[node]
int lazy[MAXNODE];  // lazy[node]
int node_cnt;

int root[N];  // root[version]
int version_cnt;

inline int new_node() {
    return ++node_cnt;
}
int clone_new_node(int from) {
    int node   = new_node();
    lr[node]   = lr[from];
    rr[node]   = rr[from];
    d[node]    = d[from];
    lazy[node] = lazy[from];
    return node;
}
void push_up(Interval interval) {
    if (!interval.is_leaf()) {
        d[interval.node] = d[interval.left_node()] + d[interval.right_node()] + lazy[interval.node] * interval.len();
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

int query(Interval interval, int find_left, int find_right) {  // interval.node填root[version]
    if (interval.is_in(find_left, find_right)) {
        return d[interval.node];
    }

    int mid = interval.mid();
    int sum = lazy[interval.node] * (min(find_right, interval.right) - max(find_left, interval.left) + 1);
    if (find_left <= mid) {
        sum += query(interval.left_interval(), find_left, find_right);
    }
    if (find_right > mid) {
        sum += query(interval.right_interval(), find_left, find_right);
    }
    return sum;
}
int update(Interval interval, int find_left, int find_right, int delta_val) {  // interval.node无需填
    interval.node = clone_new_node(interval.node);
    if (interval.is_in(find_left, find_right)) {
        d[interval.node] += delta_val * interval.len();
        lazy[interval.node] += delta_val;
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

signed main() {
    root[version_cnt++] = build({1, n, 0});
    root[version_cnt++] = update({1, n, root[some_version]}, 1145, 1919, 14810);
    ans                 = query({1, n, root[some_version]}, 1145, 1919);
    return 0;
}
