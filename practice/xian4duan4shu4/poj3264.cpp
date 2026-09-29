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
const int N = 50005;

int a[N];
pair<int, int> d[4 * N];
int lazy[4 * N];
struct Interval {
    int left, right;  // 所管理的a上的区间
    int root;         // 对应的节点
};

#define MID            interval.left + (interval.right - interval.left) / 2
#define LEFT_INTERVAL  {interval.left, mid, interval.root * 2}
#define RIGHT_INTERVAL {mid + 1, interval.right, interval.root * 2 + 1}

void build(Interval interval) {
    if (interval.left == interval.right) {
        d[interval.root] = {a[interval.left], a[interval.left]};
        return;
    }
    int mid = MID;
    build(LEFT_INTERVAL);
    build(RIGHT_INTERVAL);

    d[interval.root].first  = max(d[interval.root * 2].first, d[interval.root * 2 + 1].first);
    d[interval.root].second = min(d[interval.root * 2].second, d[interval.root * 2 + 1].second);
}


pair<int, int> query_sum(int find_left, int find_right, Interval interval) {
    if (find_left <= interval.left && interval.right <= find_right) {
        return d[interval.root];
    }

    int mid = MID;
    pair<int, int> sum{0, 0x3f3f3f3f};
    if (find_left <= mid) {
        sum.first  = max(sum.first, query_sum(find_left, find_right, LEFT_INTERVAL).first);
        sum.second = min(sum.second, query_sum(find_left, find_right, LEFT_INTERVAL).second);
    }
    if (find_right > mid) {

        sum.first  = max(sum.first, query_sum(find_left, find_right, RIGHT_INTERVAL).first);
        sum.second = min(sum.second, query_sum(find_left, find_right, RIGHT_INTERVAL).second);
    }
    return sum;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build({1, n, 1});

    while (q--) {
        int A, B;
        cin >> A >> B;
        auto s = query_sum(A, B, {1, n, 1});

        cout << s.first - s.second << endl;
    }
    return 0;
}
