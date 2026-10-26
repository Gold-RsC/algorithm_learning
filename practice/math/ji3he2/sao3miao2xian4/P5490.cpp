/**
 * @brief P5490 离散化+存区间的线段树+扫描线
 * @details 给n个边平行于坐标轴的矩形，求它们并集的总面积
 * @details 1 <= n <= 1e5 0 <= x1 < x2 <= 1e9 0 <= y1 < y2 <= 1e9
 */
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
const int N = 2e5 + 5;
struct rec {
    int y1, y2;
    int x1;
    int value;
    bool operator<(const rec& _) const {
        if (x1 != _.x1) {
            return x1 < _.x1;
        }
        return y1 < _.y1;
    }
};
vector<rec> r;
vector<int> y;  // 对y值进行离散化

struct Interval {
    int left;
    int right;
    int root;

    int mid(void) const {
        return left + ((right - left) >> 1);
    }
    int len(void) const {
        return right - left + 1;
    }
    int left_node(void) const {
        return root * 2;
    }
    int right_node(void) const {
        return root * 2 + 1;
    }

    int left_len(void) const {
        return mid() - left + 1;
    }
    int right_len(void) const {
        return right - mid();
    }

    Interval left_interval(void) const {
        return {left, mid(), left_node()};
    }
    Interval right_interval(void) const {
        return {mid() + 1, right, right_node()};
    }

    bool is_in(int find_left, int find_right) const {
        return find_left <= left && find_right >= right;
    }
};

int len[N * 4];  // root对应的区间被覆盖的总长度
int cnt[N * 4];  // root对应的区间被覆盖的次数

void push_up(Interval interval) {
    if (cnt[interval.root] > 0) {
        len[interval.root] = y[interval.right + 1] - y[interval.left];
    }
    else if (interval.left == interval.right) {
        len[interval.root] = 0;
    }
    else {
        len[interval.root] = len[interval.left_node()] + len[interval.right_node()];
    }
}
void update(Interval interval, int find_left, int find_right, int k) {
    if (interval.is_in(find_left, find_right)) {
        cnt[interval.root] += k;
        push_up(interval);
        return;
    }
    int mid = interval.mid();
    if (find_left <= mid) {
        update(interval.left_interval(), find_left, find_right, k);
    }
    if (find_right > mid) {
        update(interval.right_interval(), find_left, find_right, k);
    }
    push_up(interval);
}
int query() {
    return len[1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        r.push_back({y1, y2, x1, 1});
        r.push_back({y1, y2, x2, -1});
        y.push_back(y1);
        y.push_back(y2);
    }

    sort(r.begin(), r.end());

    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    // build(Interval{0, (int)y.size() - 1, 1});

    int ans = 0;
    for (int j = 1; j < 2 * n; ++j) {
        int i  = j - 1;
        int y1 = lower_bound(y.begin(), y.end(), r[i].y1) - y.begin();
        int y2 = lower_bound(y.begin(), y.end(), r[i].y2) - y.begin();
        update(Interval{0, (int)y.size() - 1, 1}, y1, y2 - 1, r[i].value);
        ans += query() * (r[i + 1].x1 - r[i].x1);
    }
    cout << ans;
    return 0;
}
