#include <iostream>
using namespace std;
#define int uint64_t
const int N = 1e5 + 10;


int n, m;


int a[N];
int sum[4 * N];
int lazy_add[4 * N];
int lazy_mult[4 * N];

struct Cursor {
    int left, right;
    int idx;
};

inline int get_mid(const Cursor& c) {
    return c.left + (c.right - c.left) / 2;
}
void build(Cursor c) {
    lazy_mult[c.idx] = 1;
    if (c.left == c.right) {
        sum[c.idx] = a[c.left];
        return;
    }
    int mid = get_mid(c);
    build({c.left, mid, c.idx * 2});
    build({mid + 1, c.right, c.idx * 2 + 1});
    sum[c.idx] = sum[c.idx * 2] + sum[c.idx * 2 + 1];
}

void push_down(Cursor c) {
    if (lazy_mult[c.idx] != 1) {
        lazy_mult[c.idx * 2] *= lazy_mult[c.idx];
        lazy_mult[c.idx * 2] %= m;

        lazy_mult[c.idx * 2 + 1] *= lazy_mult[c.idx];
        lazy_mult[c.idx * 2 + 1] %= m;

        lazy_add[c.idx * 2] *= lazy_mult[c.idx];
        lazy_add[c.idx * 2] %= m;

        lazy_add[c.idx * 2 + 1] *= lazy_mult[c.idx];
        lazy_add[c.idx * 2 + 1] %= m;

        sum[c.idx * 2] *= lazy_mult[c.idx];
        sum[c.idx * 2] %= m;

        sum[c.idx * 2 + 1] *= lazy_mult[c.idx];
        sum[c.idx * 2 + 1] %= m;

        lazy_mult[c.idx] = 1;
    }
    if (lazy_add[c.idx]) {
        int mid = get_mid(c);

        lazy_add[c.idx * 2] += lazy_add[c.idx];
        lazy_add[c.idx * 2] %= m;

        lazy_add[c.idx * 2 + 1] += lazy_add[c.idx];
        lazy_add[c.idx * 2 + 1] %= m;

        sum[c.idx * 2] += lazy_add[c.idx] * (mid - c.left + 1);
        sum[c.idx * 2] %= m;

        sum[c.idx * 2 + 1] += lazy_add[c.idx] * (c.right - mid);
        sum[c.idx * 2 + 1] %= m;

        lazy_add[c.idx] = 0;
    }
}


int query(int find_left, int find_right, Cursor c) {
    if (find_left <= c.left && c.right <= find_right) {
        return sum[c.idx] % m;
    }

    push_down(c);

    int mid = get_mid(c);
    int ans = 0;
    if (find_left <= mid) {
        ans += query(find_left, find_right, {c.left, mid, c.idx * 2});
        ans %= m;
    }
    if (find_right > mid) {
        ans += query(find_left, find_right, {mid + 1, c.right, c.idx * 2 + 1});
        ans %= m;
    }
    return ans;
}

void add(int find_left, int find_right, int val, Cursor c) {
    if (find_left <= c.left && c.right <= find_right) {
        lazy_add[c.idx] += val;
        lazy_add[c.idx] %= m;
        sum[c.idx] += val * (c.right - c.left + 1);
        sum[c.idx] %= m;
        return;
    }

    push_down(c);

    int mid = get_mid(c);
    if (find_left <= mid) {
        add(find_left, find_right, val, {c.left, mid, c.idx * 2});
    }
    if (find_right > mid) {
        add(find_left, find_right, val, {mid + 1, c.right, c.idx * 2 + 1});
    }
    sum[c.idx] = (sum[c.idx * 2] + sum[c.idx * 2 + 1]) % m;
}

void mult(int find_left, int find_right, int val, Cursor c) {
    if (find_left <= c.left && c.right <= find_right) {
        lazy_add[c.idx] *= val;
        lazy_add[c.idx] %= m;
        lazy_mult[c.idx] *= val;
        lazy_mult[c.idx] %= m;
        sum[c.idx] *= val;
        sum[c.idx] %= m;
        return;
    }

    push_down(c);

    int mid = get_mid(c);
    if (find_left <= mid) {
        mult(find_left, find_right, val, {c.left, mid, c.idx * 2});
    }
    if (find_right > mid) {
        mult(find_left, find_right, val, {mid + 1, c.right, c.idx * 2 + 1});
    }
    sum[c.idx] = (sum[c.idx * 2] + sum[c.idx * 2 + 1]) % m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> n >> q >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    Cursor init_cursor{1, n, 1};
    build(init_cursor);

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int k;
            cin >> k;
            mult(x, y, k, init_cursor);
        }
        else if (op == 2) {
            int k;
            cin >> k;
            add(x, y, k, init_cursor);
        }
        else {
            cout << query(x, y, init_cursor) << '\n';
        }
    }
    return 0;
}
